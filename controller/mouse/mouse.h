/**
 * @file mouse.h
 * @brief Mouse functions and definitions
 */

#ifndef _LCOM_MOUSE_H_
#define _LCOM_MOUSE_H_

#define MOUSE_BIT BIT(2)

#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "i8042.h"
#include "KBC.h"
#include "controller/video/graphics.h"

/**
 * @brief Structure to hold mouse information.
 */
typedef struct
{
    uint8_t right_click; /**< Flag indicating right click */
    uint8_t left_click;  /**< Flag indicating left click */
    int16_t x;           /**< X coordinate */
    int16_t y;           /**< Y coordinate */
} Mouse_Info_Struct;

/**
 * @brief Subscribes mouse interrupts.
 *
 * This function subscribes mouse interrupts using sys_irqsetpolicy().
 *
 * @return Return 0 upon success, non-zero otherwise.
 */
int(mouse_subscribe_interrupts)();

/**
 * @brief Unsubscribes mouse interrupts.
 *
 * This function unsubscribes mouse interrupts using sys_irqrmpolicy().
 *
 * @return Return 0 upon success, non-zero otherwise.
 */
int(mouse_unsubscribe_interrupts)();

/**
 * @brief Mouse interrupt handler.
 *
 * This function is the interrupt handler for mouse interrupts. It reads the byte from the output buffer.
 */
void(mouse_ih)();

/**
 * @brief Aligns mouse bytes.
 *
 * This function aligns the mouse bytes received from the output buffer.
 */
void(mouse_align_bytes)();

/**
 * @brief Synchronizes mouse information.
 *
 * This function synchronizes the mouse information by updating the mouse_info_s structure with the received bytes.
 */
void(mouse_sync_info)();

/**
 * @brief Writes a command to the mouse.
 *
 * This function writes a command byte to the mouse and waits for the acknowledgement.
 *
 * @param command The command byte to write.
 * @return Return 0 upon success, non-zero otherwise.
 */
int(mouse_write)(uint8_t command);

#endif
