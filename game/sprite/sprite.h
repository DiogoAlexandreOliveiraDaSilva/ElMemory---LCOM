#ifndef _LCOM_SPRITE_H_
#define _LCOM_SPRITE_H_

#include "controller/video/graphics.h"
#include "../xpm/buttons/quitButton.xpm"
#include "../xpm/buttons/quitButtonPressed.xpm"

typedef struct
{
    uint16_t height;
    uint16_t width;
    uint32_t *colors;
    uint32_t color;
    uint8_t pressed;
    int id;
    bool block;
    int state;
} Sprite;

Sprite *initiate_xpm(xpm_map_t sprite);
void destroy_sprite(Sprite *sprite);

#endif
