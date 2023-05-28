#ifndef _LCOM_RTC_H_
#define _LCOM_RTC_H_

#include <minix/sysutil.h>
#include <lcom/lcf.h>

// Macros
#define MASK_OF_RTC             5
#define RTC_IRQ_LINE            8
#define IN_REG                  0x70
#define OUT_REG                 0x71
#define REGISTER_IS_REFRESHING  10
#define REGISTER_IN_COUNT       11
#define SECONDS                0
#define MINUTES                 2
#define HOURS                   4   
#define DAY                     7
#define MONTH                   8
#define YEAR                    9
#define BIN                   BIT(2)
#define REFRESHING            BIT(7)

// Estrutura que reune todos os dados importantes
typedef struct {
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
} real_time_mode_info;

// Functions
void start_rtc();
int rtc_subscribe_interrupts();
int rtc_unsubscribe_interrupts();
int read_output_rtc(uint8_t command, uint8_t *output);
int rtc_refreshing();
int rtc_check_BIN();
int rtc_check_bcd();
int rtc_update_display();
uint8_t rtc_2_BIN(uint8_t bcd_convert_number);

#endif
