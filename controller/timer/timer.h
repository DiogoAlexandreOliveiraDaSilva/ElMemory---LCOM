/**
 * @file
 * @brief Timer handling functions
 */

#ifndef _LCOM_TIMER_H_
#define _LCOM_TIMER_H_

#define TIMER_BIT BIT(0)

#include <minix/sysutil.h>
#include <lcom/lcf.h>
#include "i8254.h"

/**
 * @brief Sets the frequency of a timer
 *
 * @param timer The timer to set the frequency of (0, 1, or 2)
 * @param freq The desired frequency in Hz
 *
 * @return Return 0 upon success, non-zero otherwise
 */
int(timer_set_frequency)(uint8_t timer, uint32_t freq);

/**
 * @brief Subscribes to timer interrupts
 *
 * @return Return 0 upon success, non-zero otherwise
 */
int(timer_subscribe_interrupts)();

/**
 * @brief Unsubscribes from timer interrupts
 *
 * @return Return 0 upon success, non-zero otherwise
 */
int(timer_unsubscribe_interrupts)();

/**
 * @brief Retrieves the configuration of a timer
 *
 * @param timer The timer to retrieve the configuration of (0, 1, or 2)
 * @param st Pointer to store the timer configuration
 *
 * @return Return 0 upon success, non-zero otherwise
 */
int(timer_get_conf)(uint8_t timer, uint8_t *st);

#endif
