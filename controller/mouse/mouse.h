#ifndef _LCOM_MOUSE_H_
#define _LCOM_MOUSE_H_

#define MOUSE_BIT BIT(2)

#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "i8042.h"
#include "KBC.h"
#include "controller/video/graphics.h"

typedef struct {
    uint8_t right_click;
    uint8_t left_click;
    int16_t x;
    int16_t y;
} Mouse_Info_Struct;   

int (mouse_subscribe_interrupts)();

int (mouse_unsubscribe_interrupts)();

void (mouse_ih)();

void (mouse_align_bytes)();

void (mouse_sync_info)();

int (mouse_write)(uint8_t command);

#endif
