#include "rtc.h"

int hook_id_rtc = MASK_OF_RTC; 
real_time_mode_info time_mode_info;  
uint8_t BIN_mode;


void start_rtc() {
    BIN_mode = rtc_check_BIN();
    rtc_update_display();
}


int rtc_subscribe_interrupts() {
    if(sys_irqsetpolicy(RTC_IRQ_LINE, IRQ_REENABLE, &hook_id_rtc) != 0){
        printf("Error in the function sys_irqsetpolicy in rtc");
        return 1;
    }
    return 0;
}


int rtc_unsubscribe_interrupts() {
    if(sys_irqrmpolicy(&hook_id_rtc) != 0) {
        printf("Error in the function sys_irqrmpolicy in rtc");
        return 1;
    }
    return 0;
}


int read_output_rtc(uint8_t command, uint8_t *output) {
    if (sys_outb(IN_REG, command) != 0){
     printf("Error reading the register input");
     return 1;}
	if (util_sys_inb(OUT_REG, output) != 0) {
    printf("Error in the function util_sys_inb in rtc");
    return 1;}
    return 0;
}


int rtc_refreshing() {
    uint8_t time;
    if (read_output_rtc(REGISTER_IS_REFRESHING, &time)) return 1;
	return time & REFRESHING;
}


int rtc_check_BIN() {
    uint8_t time;
    if (read_output_rtc(REGISTER_IN_COUNT, &time)) {
        printf("Error in the function read_output_rtc in rtc");
        return 1;
        }
    
	return time & BIN;
}


int rtc_check_bcd() {
    return !rtc_check_BIN();
}

uint8_t rtc_2_BIN(uint8_t bcd_convert_number) {
    return ((bcd_convert_number >> 4) * 10) + (bcd_convert_number & 0xF);
}

int rtc_update_display() {
    
    if (rtc_refreshing() != 0) return 1;
    uint8_t output;

    if (read_output_rtc(SECONDS, &output) != 0) 
    {
        printf("Error in the function read_output_rtc in rtc");
        return 1;
    }
    time_mode_info.seconds = BIN_mode ? output : rtc_2_BIN(output);

    if (read_output_rtc(MINUTES, &output) != 0)
    { 
        printf("Error in the function read_output_rtc in rtc");
        return 1;
    }
    time_mode_info.minutes = BIN_mode ? output : rtc_2_BIN(output);

    if (read_output_rtc(HOURS, &output) != 0) 
    {
        printf("Error in the function read_output_rtc in rtc");
        return 1;
    }
    time_mode_info.hours = BIN_mode ? output : rtc_2_BIN(output);

    if (read_output_rtc(DAY, &output) != 0) 
    {
        printf("Error in the function read_output_rtc in rtc");
        return 1;
    }

    time_mode_info.day = BIN_mode ? output : rtc_2_BIN(output);

    if (read_output_rtc(MONTH, &output) != 0)
    {
        printf("Error in the function read_output_rtc in rtc");
        return 1;
    } 
    time_mode_info.month = BIN_mode ? output : rtc_2_BIN(output);

    if (read_output_rtc(YEAR, &output) != 0)
    {
        printf("Error in the function read_output_rtc in rtc");
        return 1;
    }
    time_mode_info.year = BIN_mode ? output : rtc_2_BIN(output);

    return 0;
}
