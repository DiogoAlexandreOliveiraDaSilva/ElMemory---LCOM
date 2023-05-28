#ifndef __MENU_H
#define __MENU_H

#include "../../controller/video/VBE.h"
#include "../../controller/video/graphics.h"
#include "../../controller/mouse/mouse.h"
#include "game/game.h"
#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "controller/keyboard/KBC.h"
#include "controller/mouse/mouse.h"
#include "controller/video/graphics.h"
#include "controller/rtc/rtc.h"
#include "game/xpm/hand.xpm"
#include "game/xpm/mouse.xpm"
#include "game/xpm/smile.xpm"
#include "game/xpm/teste.xpm"
#include "game/xpm/logo.xpm"
#include "game/game.h"
#include "game/sprite/sprite.h"
#include "config.h"
#include "game/xpm/back.xpm"
#include "game/xpm/game.xpm"
#include "game/xpm/number1.xpm"
#include "game/xpm/number2.xpm"
#include "game/xpm/number3.xpm"
#include "game/xpm/number4.xpm"
#include "game/xpm/number5.xpm"
#include "game/xpm/number6.xpm"
#include "game/xpm/number7.xpm"
#include "game/xpm/number8.xpm"
#include "game/xpm/start.xpm"
#include "game/xpm/hard.xpm"
#include "game/xpm/easy.xpm"
#include "game/xpm/medium.xpm"
#include "game/xpm/quit.xpm"
#include "game/xpm/back_anim1.xpm"
#include "game/xpm/back_anim2.xpm"
#include "game/xpm/back_anim3.xpm"
#include "game/xpm/back_anim4.xpm"
#include "game/xpm/Start.xpm"
#include "game/xpm/Quit.xpm"
#include "game/xpm/Easy.xpm"
#include "game/xpm/Medium.xpm"
#include "game/xpm/Hard.xpm"
#include "game/xpm/1.xpm"
#include "game/xpm/2.xpm"
#include "game/xpm/3.xpm"
#include "game/xpm/4.xpm"
#include "game/xpm/5.xpm"
#include "game/xpm/6.xpm"
#include "game/xpm/7.xpm"
#include "game/xpm/8.xpm"
#include "game/xpm/9.xpm"
#include "game/xpm/0.xpm"
#include "game/xpm/1player.xpm"
#include "game/xpm/2player.xpm"
#include "game/xpm/player1.xpm"
#include "game/xpm/player2.xpm"
#include "game/xpm/victory.xpm"

typedef enum
{
    RUNNING,
    EXIT,
} SystemState;

typedef enum
{
    START,
    GAME,
    GAME_2P,
    GAME_2,
    END,
    MODE,
    MODE_2, 
    SEL_P,
    GAME_3,
    GAME_4_2P,
    GAME_8_2P,
} MenuState;

void update_timer_frame();
void update_keyboard_frame();
void update_mouse_frame();
void update_buttons();
void update_rtc_frame();
void start_sprites();
void del_sprites();
#endif
