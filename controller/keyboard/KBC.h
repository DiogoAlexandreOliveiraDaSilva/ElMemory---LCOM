#ifndef _LCOM_KBC_KEY_H_
#define _LCOM_KBC_KEY_H_

#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "i8042.h"

int (keyboard_read_status)(uint8_t* status);

int (keyboard_read_output_buffer)(uint8_t port, uint8_t *output, uint8_t mouse);

int (keyboard_writing)(uint8_t port, uint8_t commandByte);

#endif
