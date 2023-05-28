#ifndef _LCOM_I8042_MOUSE_H_
#define _LCOM_I8042_MOUSE_H_

#define KEYBOARD_IRQ_LINE    1
#define MOUSE_IRQ_LINE       12

#define BREAK_SCAN       0x81
#define MAKE_CODE       BIT(7)
#define IF_TWO_BYTESYTES       0xE0
#define ENABLE_INT      BIT(0)

#define TIMEOUT_ERROR   BIT(6)
#define PARITY_ERROR    BIT(7)
#define FULL_OUTPUT_BUFFERR BIT(0)
#define FULL_INPUT_BUFFER  BIT(1)

#define KEYBOARD_REG  0x64
#define KBD_INPUT_CMD      0x64
#define KBD_OUTPUT_CMD     0x60
#define KBD_READ_CMD    0x20
#define KBD_WRITE_CMD   0x60

#define WAIT_4_KBC        20000
#define MAX_ATTEMPS     10

#define MOUSE_LEFT_CLICK    BIT(0)
#define MOUSE_RIGHT_CLICK            BIT(1)
#define MOUSE_MB            BIT(2)
#define START_BYTE          BIT(3)
#define MOUSE_SIGNAL_X      BIT(4)
#define MOUSE_SIGNAL_Y      BIT(5)
#define MOUSE_OVERFLOW_X    BIT(6)
#define MOUSE_OVERFLOW_Y    BIT(7)
#define OFF_DATA_REP        0xF5
#define ON_DATA_REP         0xF4
#define ON_STREAM           0xEA
#define READ_DATA_M         0xEB
#define MOUSE_WRITE_B       0xD4

#define ACK 0xFA    
#define NACK 0xFE

#endif
