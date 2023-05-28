#ifndef _LCOM_I8254_H_
#define _LCOM_I8254_H_

#include <minix/sysutil.h>
#include <lcom/lcf.h>

#define TIMER      0
#define TIMER_FREQ 1193182 
#define TIMER0_IRQ 0
#define TIMER_PORT_0    0x40
#define TIMER_PORT_1    0x41
#define TIMER_PORT_2    0x42
#define TIMER_PORT_CONTROL 0x43
#define TIMER_IS_SEL_0   0x00             
#define TIMER_IS_SEL_1   BIT(6)         
#define TIMER_IS_SEL_2   BIT(7)           
#define READBACK_CMD (BIT(7) | BIT(6))
#define TIMER_LSB_F     BIT(4)                
#define TIMER_MSB_F     BIT(5)                
#define TIMER_LSB_F_MSB (TIMER_LSB_F | TIMER_MSB_F) 
#define TIMER_SQR_WAVE (BIT(2) | BIT(1)) 
#define TIMER_REF_RATE BIT(2)        
#define TIMER_IS_BCD 0x01
#define TIMER_IS_BIN 0x00
#define READBACK_CMD_COUNT_  BIT(5)
#define READBACK_CMD_STATUS_ BIT(4)
#define READBACK_CMD_SEL(n)  BIT((n) + 1)

#endif
