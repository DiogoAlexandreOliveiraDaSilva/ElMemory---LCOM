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

  // Atualização da frequência
  if (timer_set_frequency(TIMER, FPS) != 0)
    return 1;

  // Inicialização dos buffers de vídeo (double buffering)
  if (define_frame_bufs(RESOLUTION) != 0)
    return 1;

  // Inicialização do modo gráfico
  if (set_graphics_mode(RESOLUTION) != 0)
    return 1;

  start_sprites();

  // Ativação das interrupções dos dispositivos
  if (timer_subscribe_interrupts() != 0)
    return 1;
  if (keyboard_subscribe_interrupts() != 0)
    return 1;
  if (mouse_subscribe_interrupts() != 0)
    return 1;
  if (rtc_subscribe_interrupts() != 0)
    return 1;

  // Ativar stream-mode e report de dados do rato
  if (mouse_write(ON_STREAM) != 0)
    return 1;
  if (mouse_write(ON_DATA_REP) != 0)
    return 1;

  // Setup do Real Time Clock
  start_rtc();

  return 0;
}

int teardown()
{

  // Volta ao modo de texto
  if (vg_exit() != 0)
    return 1;

  // Destruição dos sprites
  del_sprites();

  // Desativa todas as interrupções
  if (timer_unsubscribe_interrupts() != 0)
    return 1;
  if (keyboard_unsubscribe_interrupts() != 0)
    return 1;
  if (mouse_unsubscribe_interrupts() != 0)
    return 1;
  if (rtc_unsubscribe_interrupts() != 0)
    return 1;

  // Desativar o report de dados do rato
  if (mouse_write(OFF_DATA_REP) != 0)
    return 1;

  return 0;
}

int(proj_main_loop)(int argc, char *argv[])
{

  // Setup do Minix
  if (setup() != 0)
    return teardown();

  // Desenha a primeira frame
  draw_new_fb();

  // Tratamento das interrupções
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
        if (msg.m_notify.interrupts & TIMER_MASK)
          update_timer_frame();
        if (msg.m_notify.interrupts & KEYBOARD_MASK)
          update_keyboard_frame();
        if (msg.m_notify.interrupts & MOUSE_MASK)
          update_mouse_frame();
        if (msg.m_notify.interrupts & MASK_OF_RTC)
          update_rtc_frame();
      }
    }
  }

  // Tear-down do Minix
  if (teardown() != 0)
    return 1;

  return 0;
}
