#include <lcom/lcf.h>
#include <stdint.h>
#include "timer.h"

int hook_id = 0;
int counter = 0;

int(timer_set_frequency)(uint8_t timer, uint32_t freq)
{

  if (freq > TIMER_FREQ || freq < 19){
    printf("Error: Invalid frequency!\n");
    return 1;
  }
  uint8_t controlWord;
  if (timer_get_conf(timer, &controlWord) != 0){
    printf("Error: Failed to get timer configuration!\n");
    return 1;
  }
  controlWord = (controlWord & 0x0F) | TIMER_LSB_F_MSB;
  uint32_t startingVal = TIMER_FREQ / freq;
  uint8_t MSB, LSB;
  util_get_MSB(startingVal, &MSB);
  util_get_LSB(startingVal, &LSB);

  uint8_t isSelected;
  switch (timer)
  {
  case 0:
    controlWord |= TIMER_IS_SEL_0;
    isSelected = TIMER_PORT_0;
    break;
  case 1:
    controlWord |= TIMER_IS_SEL_1;
    isSelected = TIMER_PORT_1;
    break;
  case 2:
    controlWord |= TIMER_IS_SEL_2;
    isSelected = TIMER_PORT_2;
    break;
  default:
    return 1;
  }

  if (sys_outb(TIMER_PORT_CONTROL, controlWord) != 0)
  {
    printf("Error: Failed to write control word to timer!\n");
    return 1;
  }
    

  if (sys_outb(isSelected, LSB) != 0)
  {
    printf("Error: Failed to write LSB to timer!\n");
    return 1;
  }
  if (sys_outb(isSelected, MSB) != 0)
  {
    printf("Error: Failed to write MSB to timer!\n");
    return 1;

  }
  return 0;
}

int(timer_subscribe_interrupts)()
{
  return sys_irqsetpolicy(TIMER0_IRQ, IRQ_REENABLE, &hook_id);
}

int(timer_unsubscribe_interrupts)()
{
  if (sys_irqrmpolicy(&hook_id) != 0)
    return 1; 
  return 0;
}

int(timer_get_conf)(uint8_t timer, uint8_t *st)
{
  if (st == NULL || timer > 2 || timer < 0)
    return 1;                                                          
  uint8_t read_back_command = (READBACK_CMD | READBACK_CMD_COUNT_ | READBACK_CMD_SEL(timer));
  if (sys_outb(TIMER_PORT_CONTROL, read_back_command) != 0)
  {
    printf("Error: Failed to write control word to timer!\n");
    return 1;
  }
  if (util_sys_inb(TIMER_PORT_0 + timer, st))
  {
    printf("Error: Failed to read timer configuration!\n");
    return 1;

  }
  return 0;
}
