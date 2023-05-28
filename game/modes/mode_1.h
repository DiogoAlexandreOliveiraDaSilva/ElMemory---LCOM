/**
 * @file mode_1.c
 * @brief Functions for the game mode 1 for 1 player.
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
void draw_game_menu();

/**
 * @brief Processes button 1 click.
 *
 * @param cards An array of Sprite cards.
 * @param size The size of the cards array.
 */
void process_button1(Sprite *cards, int size);

/**
 * @brief Processes button 2 click.
 *
 * @param cards An array of Sprite cards.
 * @param size The size of the cards array.
 */
void process_button2(Sprite *cards, int size);

/**
 * @brief Processes button 3 click.
 *
 * @param cards An array of Sprite cards.
 * @param size The size of the cards array.
 */
void process_button3(Sprite *cards, int size);

/**
 * @brief Processes button 4 click.
 *
 * @param cards An array of Sprite cards.
 * @param size The size of the cards array.
 */
void process_button4(Sprite *cards, int size);
