/**
 * @file sprite.h
 * @brief Header file for sprite functions and structure
 */

#ifndef _LCOM_SPRITE_H_
#define _LCOM_SPRITE_H_

#include "controller/video/graphics.h"
#include "../xpm/buttons/quitButton.xpm"
#include "../xpm/buttons/quitButtonPressed.xpm"

/**
 * @struct Sprite
 * @brief Structure representing a sprite
 */
typedef struct
{
    uint16_t height;  /**< Height of the sprite */
    uint16_t width;   /**< Width of the sprite */
    uint32_t *colors; /**< Array of colors representing the sprite */
    uint32_t color;   /**< Color of the sprite */
    uint8_t pressed;  /**< Flag indicating if the sprite is pressed */
    int id;           /**< Identifier of the sprite */
    bool block;       /**< Flag indicating if the sprite is blocked */
    int state;        /**< State of the sprite */
} Sprite;

/**
 * @brief Initializes a sprite using the given XPM map.
 *
 * @param sprite XPM map representing the sprite.
 * @return A pointer to the created sprite structure, or NULL on failure.
 */
Sprite *initiate_xpm(xpm_map_t sprite);

/**
 * @brief Deletes a sprite and frees the associated memory.
 *
 * @param sprite The sprite to be deleted.
 */
void del_sprite(Sprite *sprite);

#endif
