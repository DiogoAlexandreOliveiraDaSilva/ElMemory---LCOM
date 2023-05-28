#ifndef _LCOM_I8042_KEY_H_
#define _LCOM_I8042_KEY_H_
#define KEYBOARD_IRQ_LINE    1
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
#define S_KEY           31
#define G_KEY           34
#define E_KEY           18
#define Q_KEY           16
#define I_KEY           23
#define H_KEY           35
#define J_KEY           36
#define K_KEY           37
#define L_KEY           38
#define P_KEY           25
#define R_KEY           19

#endif
