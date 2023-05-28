/**
 * @file graphics.h
 * @brief Header file for graphic functions
 */

#ifndef __GRAPHICS_H
#define __GRAPHICS_H

#include <lcom/lcf.h>
#include "VBE.h"

/**
 * @brief The VBE mode info.
 *
 */
vbe_mode_info_t mode_info;

/**
 * @brief Sets the graphics mode using VBE.
 *
 * @param submode The VBE submode to set.
 * @return 0 on success, non-zero otherwise.
 */
int set_graphics_mode(uint16_t submode);

/**
 * @brief Defines the frame buffer for the specified graphics mode.
 *
 * @param mode The graphics mode to define the frame buffer for.
 * @param frame_buf Pointer to store the frame buffer address.
 * @return 0 on success, non-zero otherwise.
 */
int define_frame_buf(uint16_t mode, uint8_t **frame_buf);

/**
 * @brief Draws a pixel at the specified coordinates.
 *
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color of the pixel.
 * @param frame_buf The frame buffer address.
 * @return 0 on success, non-zero otherwise.
 */
int draw_pixel_in_coor(uint16_t x, uint16_t y, uint32_t color, uint8_t *frame_buf);

/**
 * @brief Draws a horizontal line at the specified coordinates.
 *
 * @param x The x-coordinate of the starting point.
 * @param y The y-coordinate of the starting point.
 * @param len The length of the line.
 * @param color The color of the line.
 * @param frame_buf The frame buffer address.
 * @return 0 on success, non-zero otherwise.
 */
int draw_h_line(uint16_t x, uint16_t y, uint16_t len, uint32_t color, uint8_t *frame_buf);

/**
 * @brief Draws a rectangle at the specified coordinates.
 *
 * @param x The x-coordinate of the top-left corner of the rectangle.
 * @param y The y-coordinate of the top-left corner of the rectangle.
 * @param width The width of the rectangle.
 * @param height The height of the rectangle.
 * @param color The color of the rectangle.
 * @param frame_buf The frame buffer address.
 * @return 0 on success, non-zero otherwise.
 */
int draw_rectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color, uint8_t *frame_buf);

#endif
