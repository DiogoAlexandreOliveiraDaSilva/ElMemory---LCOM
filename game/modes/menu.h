/**
 * @file menu.h
 * @brief Header file containing declarations for menu functions and types.
 */

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

/**
 * @brief Enum representing the system state.
 */
typedef enum
{
    RUNNING, /**< The system is running. */
    EXIT     /**< The system should exit. */
} SystemState;

/**
 * @brief Enum representing the menu state.
 */
typedef enum
{
    START,     /**< Start menu state. */
    GAME,      /**< Game menu state. */
    GAME_2P,   /**< Two-player game menu state. */
    GAME_2,    /**< Game mode 2 menu state. */
    END,       /**< End menu state. */
    MODE,      /**< Game mode menu state. */
    MODE_2,    /**< Game mode 2 menu state. */
    SEL_P,     /**< Select number of players menu state. */
    GAME_3,    /**< Three-player game menu state. */
    GAME_4_2P, /**< Four-player game (2 vs 2) menu state. */
    GAME_8_2P  /**< Eight-player game (4 vs 4) menu state. */
} MenuState;

/**
 * @brief Updates the timer frame.
 */
void update_timer_frame();

/**
 * @brief Updates the keyboard frame.
 */
void update_keyboard_frame();

/**
 * @brief Updates the mouse frame.
 */
void update_mouse_frame();

/**
 * @brief Updates the buttons.
 */
void update_buttons();

/**
 * @brief Updates the RTC frame.
 */
void update_rtc_frame();

/**
 * @brief Initializes the sprites.
 */
void start_sprites();

/**
 * @brief Deletes the sprites.
 */
void del_sprites();

#endif
