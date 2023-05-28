/**
 * @file rtc.h
 * @brief Header file for RTC functions and definitions
 */

#ifndef _LCOM_RTC_H_
#define _LCOM_RTC_H_

#include <minix/sysutil.h>
#include <lcom/lcf.h>

/**
 * @defgroup rtc RTC
 * @{
 *
 * Functions and definitions for RTC (Real-Time Clock) operations.
 */

/**
 * @brief RTC interrupt hook ID.
 */
#define MASK_OF_RTC 5

/**
 * @brief RTC IRQ line.
 */
#define RTC_IRQ_LINE 8

/**
 * @brief RTC input register port.
 */
#define IN_REG 0x70

/**
 * @brief RTC output register port.
 */
#define OUT_REG 0x71

/**
 * @brief Command to check if the register is refreshing.
 */
#define REGISTER_IS_REFRESHING 10

/**
 * @brief Command to check the input count.
 */
#define REGISTER_IN_COUNT 11

/**
 * @brief Command to read the seconds.
 */
#define SECONDS 0

/**
 * @brief Command to read the minutes.
 */
#define MINUTES 2

/**
 * @brief Command to read the hours.
 */
#define HOURS 4

/**
 * @brief Command to read the day.
 */
#define DAY 7

/**
 * @brief Command to read the month.
 */
#define MONTH 8

/**
 * @brief Command to read the year.
 */
#define YEAR 9

/**
 * @brief Bit to indicate BIN mode in RTC.
 */
#define BIN BIT(2)

/**
 * @brief Bit to indicate refreshing in RTC.
 */
#define REFRESHING BIT(7)

/**
 * @brief Structure that holds real-time mode information.
 */
typedef struct
{
    uint8_t year;    ///< Year
    uint8_t month;   ///< Month
    uint8_t day;     ///< Day
    uint8_t hours;   ///< Hours
    uint8_t minutes; ///< Minutes
    uint8_t seconds; ///< Seconds
} real_time_mode_info;

/**
 * @brief Initializes the RTC and sets the BIN mode.
 */
void start_rtc();

/**
 * @brief Subscribes to RTC interrupts.
 *
 * @return Return 0 upon success, non-zero otherwise.
 */
int rtc_subscribe_interrupts();

/**
 * @brief Unsubscribes from RTC interrupts.
 *
 * @return Return 0 upon success, non-zero otherwise.
 */
int rtc_unsubscribe_interrupts();

/**
 * @brief Reads the output from RTC registers.
 *
 * @param command Command to send to the RTC.
 * @param output Pointer to store the output value.
 * @return Return 0 upon success, non-zero otherwise.
 */
int read_output_rtc(uint8_t command, uint8_t *output);

/**
 * @brief Checks if the RTC register is refreshing.
 *
 * @return Return 1 if refreshing, 0 otherwise.
 */
int rtc_refreshing();

/**
 * @brief Checks if the RTC is in BIN mode.
 *
 * @return Return 1 if in BIN mode, 0 otherwise.
 */
int rtc_check_BIN();

/**
 * @brief Checks if the RTC is in BCD mode.
 *
 * @return Return 1 if in BCD mode, 0 otherwise.
 */
int rtc_check_bcd();

/**
 * @brief Converts a BCD value to BIN.
 *
 * @param bcd_convert_number BCD value to convert.
 * @return Converted BIN value.
 */
uint8_t rtc_2_BIN(uint8_t bcd_convert_number);

/**
 * @brief Updates the display with the current time information.
 *
 * @return Return 0 upon success, non-zero otherwise.
 */
int rtc_update_display();

#endif
