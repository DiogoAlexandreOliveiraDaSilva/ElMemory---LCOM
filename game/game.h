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

Sprite **alloc_matrix(int n, int m);
void draw_new_fb();
bool check_match(int id1, int id2);
void draw_initial_menu();
void draw_game_menu_2();
void draw_game_menu();
void draw_finish_menu();
void draw_mouse();
void swap_buffers();
void rtc_print();
int draw_xpm(Sprite *sprite, int x, int y);
int draw_sprite_button(Sprite *sprite, int x, int y);
int define_frame_bufs(uint16_t mode);
void draw_xpm_draw_buffer(xpm_map_t xpm, uint16_t x, uint16_t y);
int get_number(Sprite *cards, int size);
void draw_game_menu_3();
void shuffle(Sprite *cards, int size);
void shuffle2(Sprite *cards);
void shuffle3(Sprite *cards);
void draw_mode_menu();
void draw_select_player();
void process_player_1();
void process_player_2();
void draw_mode_2player();
void process_mode1_2();
void process_mode2_2();
void process_mode3_2();

void draw_card_animation(uint16_t x, uint16_t y);
void animation_trigger(Sprite *card, int x, int y);

#endif
