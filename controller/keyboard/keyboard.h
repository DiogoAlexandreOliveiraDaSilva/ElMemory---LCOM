/**
 * @file keyboard.h
 * @brief Keyboard functions and definitions
 */

#ifndef _LCOM_KEYBOARD_H_
#define _LCOM_KEYBOARD_H_

#define KEYBOARD_BIT BIT(1)

#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "i8042.h"
#include "KBC.h"

/**
 * @brief Subscribes keyboard interrupts.
 *
 * This function subscribes keyboard interrupts using sys_irqsetpolicy().
 *
 * @return Return 0 upon success, non-zero otherwise.
 */
int(keyboard_subscribe_interrupts)();

/**
 * @brief Unsubscribes keyboard interrupts.
 *
 * This function unsubscribes keyboard interrupts using sys_irqrmpolicy().
 *
 * @return Return 0 upon success, non-zero otherwise.
 */
int(keyboard_unsubscribe_interrupts)();

/**
 * @brief Keyboard interrupt handler.
 *
 * This function is the interrupt handler for keyboard interrupts. It reads the scancode from the output buffer.
 */
void(kbc_ih)();

/**
 * @brief Refreshes the keyboard.
 *
 * This function refreshes the keyboard by reading and updating the command byte in the keyboard controller.
 *
 * @return Return 0 upon success, non-zero otherwise.
 */
int(keyboard_refresh)();

#endif
