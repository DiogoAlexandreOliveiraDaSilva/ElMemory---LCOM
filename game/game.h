/**
 * @file lcom_menu.h
 * @brief Header file containing function declarations for the menu module.
 */

#ifndef _LCOM_MENU_H_
#define _LCOM_MENU_H_

#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "config.h"
#include "controller/video/graphics.h"
#include "controller/mouse/mouse.h"
#include "controller/rtc/rtc.h"
#include "sprite/sprite.h"
#include "game/modes/mode_1.h"
#include "game/modes/mode_2.h"
#include "game/modes/mode_3.h"
#include "game/modes/mode_1_2.h"
#include "game/modes/mode_2_2.h"
#include "game/modes/mode_3_2.h"

/**
 * @brief Allocates memory for a matrix of sprites.
 *
 * @param n The number of rows in the matrix.
 * @param m The number of columns in the matrix.
 * @return Pointer to the allocated matrix of sprites.
 */
Sprite **alloc_matrix(int n, int m);

/**
 * @brief Draws a new framebuffer.
 */
void draw_new_fb();

/**
 * @brief Checks if two sprites have matching IDs.
 *
 * @param id1 The ID of the first sprite.
 * @param id2 The ID of the second sprite.
 * @return True if the IDs match, false otherwise.
 */
bool check_match(int id1, int id2);

/**
 * @brief Draws the initial menu.
 */
void draw_initial_menu();

/**
 * @brief Draws the game menu for mode 2.
 */
void draw_game_menu_2();

/**
 * @brief Draws the game menu.
 */
void draw_game_menu();

/**
 * @brief Draws the finish menu.
 */
void draw_finish_menu();

/**
 * @brief Draws the mouse cursor.
 */
void draw_mouse();

/**
 * @brief Swaps the front and back buffers.
 */
void swap_buffers();

/**
 * @brief Prints the current time using the RTC.
 */
void rtc_print();

/**
 * @brief Draws a sprite at the specified coordinates.
 *
 * @param sprite The sprite to draw.
 * @param x The x-coordinate of the sprite.
 * @param y The y-coordinate of the sprite.
 * @return 0 on success, non-zero otherwise.
 */
int draw_xpm(Sprite *sprite, int x, int y);

/**
 * @brief Draws a sprite button at the specified coordinates.
 *
 * @param sprite The sprite button to draw.
 * @param x The x-coordinate of the sprite button.
 * @param y The y-coordinate of the sprite button.
 * @return 0 on success, non-zero otherwise.
 */
int draw_sprite_button(Sprite *sprite, int x, int y);

/**
 * @brief Defines the frame buffers for the specified video mode.
 *
 * @param mode The video mode to set.
 * @return 0 on success, non-zero otherwise.
 */
int define_frame_bufs(uint16_t mode);

/**
 * @brief Draws an XPM image at the specified coordinates directly to the draw buffer.
 *
 * @param xpm The XPM image to draw.
 * @param x The x-coordinate of the top-left corner of the XPM image.
 * @param y The y-coordinate of the top-left corner of the XPM image.
 */
void draw_xpm_draw_buffer(xpm_map_t xpm, uint16_t x, uint16_t y);

/**
 * @brief Gets the number of sprites in an array of cards.
 *
 * @param cards The array of cards.
 * @param size The size of the array.
 * @return The number of sprites in the array.
 */
int get_number(Sprite *cards, int size);

/**
 * @brief Draws the game menu for mode 3.
 */
void draw_game_menu_3();

/**
 * @brief Shuffles the sprites in an array of cards.
 *
 * @param cards The array of cards.
 * @param size The size of the array.
 */
void shuffle(Sprite *cards, int size);

/**
 * @brief Shuffles the sprites in an array for mode 2.
 *
 * @param cards The array of cards.
 */
void shuffle2(Sprite *cards);

/**
 * @brief Shuffles the sprites in an array for mode 3.
 *
 * @param cards The array of cards.
 */
void shuffle3(Sprite *cards);

/**
 * @brief Draws the mode menu.
 */
void draw_mode_menu();

/**
 * @brief Draws the select player menu.
 */
void draw_select_player();

/**
 * @brief Processes the player 1 selection.
 */
void process_player_1();

/**
 * @brief Processes the player 2 selection.
 */
void process_player_2();

/**
 * @brief Draws the 2-player mode menu.
 */
void draw_mode_2player();

/**
 * @brief Processes the mode 1 for 2 players.
 */
void process_mode1_2();

/**
 * @brief Processes the mode 2 for 2 player.
 */
void process_mode2_2();

/**
 * @brief Processes the mode 3 for 2 player.
 */
void process_mode3_2();

/**
 * @brief Draws a card animation at the specified coordinates.
 *
 * @param x The x-coordinate of the animation.
 * @param y The y-coordinate of the animation.
 */
void draw_card_animation(uint16_t x, uint16_t y);

/**
 * @brief Triggers an animation for a card at the specified coordinates.
 *
 * @param card The card sprite to animate.
 * @param x The x-coordinate of the animation.
 * @param y The y-coordinate of the animation.
 */
void animation_trigger(Sprite *card, int x, int y);

#endif
