#include "mouse.h"

int mouse_hook_id = 2;
uint8_t byte_position = 0;       
uint8_t bytes_from_mouse[3];
uint8_t byte_actual;
Mouse_Info_Struct mouse_info_s = {0, 0, 100, 100};
struct packet packet_from_mouse;
extern vbe_mode_info_t mode_info;


int (mouse_subscribe_interrupts)(){
  if(sys_irqsetpolicy(MOUSE_IRQ_LINE, IRQ_REENABLE | IRQ_EXCLUSIVE, &mouse_hook_id) != 0) {
    printf("Error: Failed to subscribe mouse interrupts!\n");
    return 1;
  }
  return 0;
}

int (mouse_unsubscribe_interrupts)(){
  if(sys_irqrmpolicy(&mouse_hook_id) != 0) { 
    printf("Error: Failed to unsubscribe mouse interrupts!\n");
    return 1;
  }
  return 0;
}

void (mouse_ih)(){
  keyboard_read_output_buffer(KBD_WRITE_CMD, &byte_actual, 1);
}


void mouse_align_bytes() {
  if (byte_position == 0 && (byte_actual & START_BYTE)) { 
    bytes_from_mouse[byte_position]= byte_actual;
    byte_position++;
  }
  else if (byte_position > 0) {                        
    bytes_from_mouse[byte_position] = byte_actual;
    byte_position++;
  }
}


void (mouse_sync_info)(){

  mouse_info_s.right_click = bytes_from_mouse[0] & MOUSE_RIGHT_CLICK;
  mouse_info_s.left_click = bytes_from_mouse[0] & MOUSE_LEFT_CLICK;
  if (bytes_from_mouse[0] & MOUSE_OVERFLOW_X || bytes_from_mouse[0] & MOUSE_OVERFLOW_Y) return;
  int16_t delta_x = mouse_info_s.x + ((bytes_from_mouse[0] & MOUSE_SIGNAL_X) ? (0xFF00 | bytes_from_mouse[1]) : bytes_from_mouse[1]);
  int16_t delta_y = mouse_info_s.y - ((bytes_from_mouse[0] & MOUSE_SIGNAL_Y) ? (0xFF00 | bytes_from_mouse[2]) : bytes_from_mouse[2]);
  if (delta_x < 0 || delta_x > mode_info.XResolution || delta_y < 0 || delta_y > mode_info.YResolution) return;
  mouse_info_s.x = delta_x;
  mouse_info_s.y = delta_y;
}


int (mouse_write)(uint8_t command) {

  uint8_t attemps = MAX_ATTEMPS;
  uint8_t mouse_response;

  do {
    attemps--;
    if (keyboard_writing(KBD_INPUT_CMD, MOUSE_WRITE_B)) return 1;
    if (keyboard_writing(KBD_OUTPUT_CMD, command)) return 1;
    tickdelay(micros_to_ticks(WAIT_4_KBC));
    if (util_sys_inb(KBD_OUTPUT_CMD, &mouse_response)) return 1;
  } while (mouse_response != ACK && attemps);

  return 0;
}
