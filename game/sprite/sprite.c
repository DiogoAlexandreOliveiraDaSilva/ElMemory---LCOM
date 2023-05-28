#include "sprite.h"

int counter_test = 0;
Sprite *initiate_xpm(xpm_map_t sp)
{

  Sprite *mec = (Sprite *)malloc(sizeof(Sprite));
  if (mec == NULL){
    printf("THe sprite is null\n");
    return NULL;}

  xpm_image_t img;
  mec->colors = (uint32_t *)xpm_load(sp, XPM_8_8_8_8, &img);
  mec->height = img.height;
  mec->width = img.width;
  mec->id = counter_test++;
  mec->block = false;
  mec->pressed = 0;
  mec->state = 0;

  if (mec->colors == NULL)
  {
    printf("The colors are null\n");
    free(mec);
    return NULL;
  }
  return mec;
}
void del_sprite(Sprite *sp)
{
  if (sp == NULL){
    printf("The sprite is null\n");
    return;}
  if (sp->colors){
    free(sp->colors);}
  free(sp);
  sp = NULL;
}
