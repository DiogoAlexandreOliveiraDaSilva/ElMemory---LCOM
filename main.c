#include <lcom/lcf.h>
#include "controller/timer/timer.h"
#include "controller/video/graphics.h"
#include "controller/keyboard/keyboard.h"
#include "controller/mouse/mouse.h"
#include "controller/rtc/rtc.h"
#include "game/modes/menu.h"
#include "game/game.h"
#include "config.h"

extern SystemState systemState;
extern struct packet packet_from_mouse;
extern int x;
extern int y;
extern int mouse_counter;
extern vbe_mode_info_t mode_info;
extern uint8_t *imgBuffer;
extern uint16_t xRes;
extern uint16_t yRes;
extern int gameplayCounter;
extern int prevX, prevY;

int(main)(int argc, char *argv[])
{
  lcf_set_language("EN-US");
  lcf_trace_calls("/home/lcom/labs/g1/proj/ElMemory/debug/trace.txt");
  lcf_log_output("/home/lcom/labs/g1/proj/ElMemory/debug/output.txt");
  if (lcf_start(argc, argv))
    return 1;
  lcf_cleanup();
  return 0;
}

int setup()
{

  if (timer_set_frequency(TIMER, FPS) != 0)
  {
    printf("Error setting timer frequency\n");
    return 1;
  }

  if (define_frame_bufs(RESOLUTION) != 0)
  {
    printf("Error defining frame buffers\n");
    return 1;
  }

  if (set_graphics_mode(RESOLUTION) != 0)
  {
    printf("Error setting graphics mode\n");
    return 1;
  }

  start_sprites();

  if (timer_subscribe_interrupts() != 0)
  {
    printf("Error subscribing timer interrupts\n");
    return 1;
  }

  if (keyboard_subscribe_interrupts() != 0)
  {
    printf("Error subscribing keyboard interrupts\n");
    return 1;
  }

  if (mouse_subscribe_interrupts() != 0)
  {
    printf("Error subscribing mouse interrupts\n");
    return 1;
  }

  if (rtc_subscribe_interrupts() != 0)
  {
    printf("Error subscribing rtc interrupts\n");
    return 1;
  }

  if (mouse_write(ON_STREAM) != 0)
  {
    printf("Error activating stream mode\n");
    return 1;
  }

  if (mouse_write(ON_DATA_REP) != 0)
  {
    printf("Error activating data reporting\n");
    return 1;
  }

  start_rtc();

  return 0;
}

int turn_off()
{
  if (vg_exit() != 0)
  {
    printf("Error exiting graphics mode\n");
    return 1;
  }
  del_sprites();

  if (timer_unsubscribe_interrupts() != 0)
  {
    printf("Error unsubscribing timer interrupts\n");
    return 1;
  }
  if (keyboard_unsubscribe_interrupts() != 0){
    printf("Error unsubscribing keyboard interrupts\n");
    return 1;
  }
  if (mouse_unsubscribe_interrupts() != 0)
  {
    printf("Error unsubscribing mouse interrupts\n");
    return 1;
  }
    return 1;
  if (rtc_unsubscribe_interrupts() != 0)
  {
    printf("Error unsubscribing rtc interrupts\n");
    return 1;
  }

  // Desativar o report de dados do rato
  if (mouse_write(OFF_DATA_REP) != 0)
    return 1;

  return 0;
}

int(proj_main_loop)(int argc, char *argv[])
{

  if (setup() != 0)
    return turn_off();

  draw_new_fb();

  int ipc_status;
  message msg;
  while (systemState == RUNNING)
  {

    if (driver_receive(ANY, &msg, &ipc_status) != 0)
    {
      printf("Error");
      continue;
    }

    if (is_ipc_notify(ipc_status))
    {
      switch (_ENDPOINT_P(msg.m_source))
      {
      case HARDWARE:
        if (msg.m_notify.interrupts & TIMER_BIT)
          update_timer_frame();
        if (msg.m_notify.interrupts & KEYBOARD_BIT)
          update_keyboard_frame();
        if (msg.m_notify.interrupts & MOUSE_BIT)
          update_mouse_frame();
        if (msg.m_notify.interrupts & MASK_OF_RTC)
          update_rtc_frame();
      }
    }
  }

  if (turn_off() != 0)
    return 1;

  return 0;
}
