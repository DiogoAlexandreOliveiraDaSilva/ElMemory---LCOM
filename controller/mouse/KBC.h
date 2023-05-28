/**
 * @file KBC.h
 * @brief Keyboard Controller (KBC) functions
 */

#ifndef _LCOM_KBC_MOUSE_H_
#define _LCOM_KBC_MOUSE_H_

#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "i8042.h"

/**
 * @brief Reads the keyboard controller status register.
 *
 * This function reads the status register of the keyboard controller and stores the value in the status parameter.
 *
 * @param status Pointer to a variable where the status register value will be stored.
 * @return Return 0 upon success, non-zero otherwise.
 */
int(keyboard_read_status)(uint8_t *status);

/**
 * @brief Reads the output buffer of the keyboard controller.
 *
 * This function reads the output buffer of the keyboard controller and stores the value in the output parameter.
 *
 * @param port The port to read from.
 * @param output Pointer to a variable where the output buffer value will be stored.
 * @param mouse Flag indicating whether the output is from the mouse.
 * @return Return 0 upon success, non-zero otherwise.
 */
int(keyboard_read_output_buffer)(uint8_t port, uint8_t *output, uint8_t mouse);

/**
 * @brief Writes a command byte to the keyboard controller.
 *
 * This function writes a command byte to the keyboard controller.
 *
 * @param port The port to write to.
 * @param commandByte The command byte to write.
 * @return Return 0 upon success, non-zero otherwise.
 */
int(keyboard_writing)(uint8_t port, uint8_t commandByte);

#endif
