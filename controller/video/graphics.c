#include <lcom/lcf.h>
#include "graphics.h"
#include <math.h>


int (set_graphics_mode)(uint16_t submode) {
    reg86_t reg86;
    memset(&reg86, 0, sizeof(reg86)); 
    reg86.intno = 0x10;                   
    reg86.ah = 0x4F;
    reg86.al = 0x02;
    reg86.bx = submode | BIT(14);
    if (sys_int86(&reg86) != 0) {
        printf("Set graphic mode failed\n");
        return 1;
    }
    return 0;
}

int (define_frame_buf)(uint16_t mode, uint8_t** frame_buf) {

  memset(&mode_info, 0, sizeof(mode_info));
  if(vbe_get_mode_info(mode, &mode_info)) return 1;

  unsigned int frame_max_size = (mode_info.XResolution * mode_info.YResolution * mode_info.BitsPerPixel) / 8;
  
  struct minix_mem_range physic_addresses;
  physic_addresses.mr_base = mode_info.PhysBasePtr; 
  physic_addresses.mr_limit = physic_addresses.mr_base + frame_max_size; 
  
  if (sys_privctl(SELF, SYS_PRIV_ADD_MEM, &physic_addresses)) {
    printf("Error allocating the physical memory\n");
    return 1;
  }

  *frame_buf = vm_map_phys(SELF, (void*) physic_addresses.mr_base, frame_max_size);
  if (frame_buf == NULL) {
    printf("The frame buffer is null \n");
    return 1;
  }

  return 0;
}

int (draw_pixel_in_coor)(uint16_t x, uint16_t y, uint32_t color, uint8_t* frame_buf) {

  if(x >= mode_info.XResolution || y >= mode_info.YResolution)
  {
    printf("Coordinates out of bounds\n");
   return 1;
  }
  unsigned Bpp = (mode_info.BitsPerPixel + 7) / 8;

  unsigned int position = (mode_info.XResolution * y + x) * Bpp;

  memcpy(&frame_buf[position], &color, Bpp);

  return 0;
}

int (draw_h_line)(uint16_t x, uint16_t y, uint16_t len, uint32_t color, uint8_t* frame_buf) {
  for (unsigned i = 0 ; i < len ; i++)   {
    if (draw_pixel_in_coor(x+i, y, color, frame_buf) != 0) 
    {
        printf("Error drawing the line");
        return 1;
    }
  }
  return 0;
}

int (draw_rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color, uint8_t* frame_buf) {
  for(unsigned i = 0; i < height ; i++){
    if (draw_h_line(x, y+i, width, color, frame_buf) != 0) {
      continue;
    }
  }
  return 0;
}

