#include "keyboard.h"

uint8_t scancode = 0;
int hook_id_keyboard = 1;

int (keyboard_subscribe_interrupts)() {
    return sys_irqsetpolicy(KEYBOARD_IRQ_LINE, IRQ_REENABLE | IRQ_EXCLUSIVE, &hook_id_keyboard);
}

int (keyboard_unsubscribe_interrupts)() {
    return sys_irqrmpolicy(&hook_id_keyboard);
}

void (kbc_ih)() {
    keyboard_read_output_buffer(KBD_OUTPUT_CMD, &scancode, 0);
}

int (keyboard_refresh)() {
    uint8_t commandByte;

    if (keyboard_writing(KBD_INPUT_CMD, KBD_READ_CMD) != 0){
        printf("Error: Failed to write command to KBC!\n");
        return 1;
    }          
    if (keyboard_read_output_buffer(KBD_OUTPUT_CMD, &commandByte, 0) != 0){
        printf("Error: Failed to read command from KBC!\n");
        return 1;
    }
    commandByte |= ENABLE_INT;  

    if (keyboard_writing(KBD_INPUT_CMD, KBD_WRITE_CMD) != 0){
        printf("Error: Failed to write command to KBC!\n");
        return 1;
    }
    if (keyboard_writing(KBD_WRITE_CMD, commandByte) != 0){
        printf("Error: Failed to write command to KBC!\n");
        return 1;
    } 
    return 0;
}
