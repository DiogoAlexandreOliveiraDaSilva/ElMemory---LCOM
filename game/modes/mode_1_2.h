/**
 * @file menu.h
 * @brief Functions for the game mode 1 for 2 players.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "menu.h"
#include "game/game.h"

/**
 * @brief Draws the game menu.
 */
void draw_game_menu_2_2();

/**
 * @brief Processes button 1 click.
 *
 * @param cards An array of Sprite cards.
 * @param size The size of the cards array.
 */
void process_button1_2(Sprite *cards, int size);
/**
 * @brief Processes button 2 click.
 *
 * @param cards An array of Sprite cards.
 * @param size The size of the cards array.
 */
void process_button2_2(Sprite *cards, int size);
/**
 * @brief Processes button 3 click.
 *
 * @param cards An array of Sprite cards.
 * @param size The size of the cards array.
 */
void process_button3_2(Sprite *cards, int size);
/**
 * @brief Processes button 4 click.
 *
 * @param cards An array of Sprite cards.
 * @param size The size of the cards array.
 */
void process_button4_2(Sprite *cards, int size);
