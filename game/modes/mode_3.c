#include "mode_3.h"

extern int pre2;
extern uint8_t scancode;
extern Sprite **matrix;
extern Sprite *index_1;
extern Sprite *index_2;
extern bool *index_1_bool;
extern bool *index_2_bool;
extern int matrix_id1;
extern int matrix_id2;
extern int timer_interrupts;
extern vbe_mode_info_t mode_info;
extern Mouse_Info_Struct mouse_info_s;
extern real_time_mode_info time_mode_info;
extern MenuState menuState;
extern SystemState systemState;
extern Sprite *mouse;
extern Sprite *hand;
extern Sprite *teste;
extern Sprite *logo;
extern Sprite *quitButton;
extern Sprite *quitButtonPressed;
extern Sprite *button1;
extern Sprite *button2;
extern Sprite *button3;
extern Sprite *button4;
extern Sprite *number1;
extern Sprite *number2;
extern Sprite *number3;
extern Sprite *number4;
extern Sprite *number5;
extern Sprite *number6;
extern Sprite *number7;
extern Sprite *number8;
extern Sprite *back;
extern Sprite *game;
extern Sprite *easy;
extern Sprite *medium;
extern Sprite *hard;
extern Sprite *quit;
extern Sprite *start;
extern bool backPressed1;
extern bool backPressed2;
extern bool backPressed3;
extern bool backPressed4;
extern bool backPressed5;
extern bool backPressed6;
extern bool backPressed7;
extern bool backPressed8;
extern bool backPressed9;
extern bool backPressed10;
extern bool backPressed11;
extern bool backPressed12;
extern bool backPressed13;
extern bool backPressed14;
extern bool backPressed15;
extern bool backPressed16;
extern uint8_t *main_frame_buf;
extern uint8_t *SECONDSondary_frame_buf;
extern uint8_t *drawing_frame_buf;
extern uint32_t frame_buf_size;
extern bool isAnimating;
extern int animationFrame;
extern Sprite *back_anim1;
extern Sprite *back_anim2;
extern Sprite *back_anim3;
extern Sprite *back_anim4;
extern int gameplayCounter;
extern bool is_processing; 
extern MenuState to_help;

void process_deck1()
{
    if (mouse_info_s.x > 0 && mouse_info_s.x < mode_info.XResolution / 4 && mouse_info_s.y > 0 && mouse_info_s.y < mode_info.YResolution / 4)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
                backPressed1 = true;}            
        }
    }
    if (backPressed1)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[0][0].id;
            index_1_bool = &backPressed1;
            index_1 = &matrix[0][0];
            index_1->state = 1; 
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[0][0])
        {
            matrix_id2 = matrix[0][0].id;
            index_2_bool = &backPressed1;
            index_2 = &matrix[0][0];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;

            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed1 is %d", backPressed1);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false; 
        }
        }
    }
}
void process_deck2()
{
    if (mouse_info_s.x > mode_info.XResolution / 4 && mouse_info_s.x < mode_info.XResolution / 2 && mouse_info_s.y > 0 && mouse_info_s.y < mode_info.YResolution / 4)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed2 = true;}
            
        }
    }
    if (backPressed2)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[0][1].id;
            index_1_bool = &backPressed2;
            index_1 = &matrix[0][1];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[0][1])
        {
            matrix_id2 = matrix[0][1].id;
            index_2_bool = &backPressed2;
            index_2 = &matrix[0][1];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed2 is %d", backPressed2);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck3()
{
    if (mouse_info_s.x > mode_info.XResolution / 2 && mouse_info_s.x < 3 * mode_info.XResolution / 4 && mouse_info_s.y > 0 && mouse_info_s.y < mode_info.YResolution / 4)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed3 = true;}
            
        }
    }
    if (backPressed3)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[0][2].id;
            index_1_bool = &backPressed3;
            index_1 = &matrix[0][2];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[0][2])
        {
            matrix_id2 = matrix[0][2].id;
            index_2_bool = &backPressed3;
            index_2 = &matrix[0][2];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed3 is %d", backPressed3);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
    }
    }
}
void process_deck4()
{
    if (mouse_info_s.x > 3 * mode_info.XResolution / 4 && mouse_info_s.x < mode_info.XResolution && mouse_info_s.y > 0 && mouse_info_s.y < mode_info.YResolution / 4)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed4 = true;}
            
        }
    }
    if (backPressed4)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[0][3].id;
            index_1_bool = &backPressed4;
            index_1 = &matrix[0][3];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[0][3])
        {
            matrix_id2 = matrix[0][3].id;
            index_2_bool = &backPressed4;
            index_2 = &matrix[0][3];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed4 is %d", backPressed4);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck5()
{
    if (mouse_info_s.x > 0 && mouse_info_s.x < mode_info.XResolution / 4 && mouse_info_s.y > mode_info.YResolution / 4 && mouse_info_s.y < mode_info.YResolution / 2)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed5 = true;}
            
        }
    }
    if (backPressed5)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[1][0].id;
            index_1_bool = &backPressed5;
            index_1 = &matrix[1][0];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[1][0])
        {
            matrix_id2 = matrix[1][0].id;
            index_2_bool = &backPressed5;
            index_2 = &matrix[1][0];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed5 is %d", backPressed5);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck6()
{
    if (mouse_info_s.x > mode_info.XResolution / 4 && mouse_info_s.x < mode_info.XResolution / 2 && mouse_info_s.y > mode_info.YResolution / 4 && mouse_info_s.y < mode_info.YResolution / 2)
    {
        if (mouse_info_s.left_click)
        {
             if(!is_processing){
            backPressed6 = true;}
            
        }
    }
    if (backPressed6)
    {

        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[1][1].id;
            index_1_bool = &backPressed6;
            index_1 = &matrix[1][1];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[1][1])
        {
            matrix_id2 = matrix[1][1].id;
            index_2_bool = &backPressed6;
            index_2 = &matrix[1][1];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed6 is %d", backPressed6);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck7()
{
    if (mouse_info_s.x > mode_info.XResolution / 2 && mouse_info_s.x < 3 * mode_info.XResolution / 4 && mouse_info_s.y > mode_info.YResolution / 4 && mouse_info_s.y < mode_info.YResolution / 2)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed7 = true;}
            
        }
    }
    if (backPressed7)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[1][2].id;
            index_1_bool = &backPressed7;
            index_1 = &matrix[1][2];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[1][2])
        {
            matrix_id2 = matrix[1][2].id;
            index_2_bool = &backPressed7;
            index_2 = &matrix[1][2];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed7 is %d", backPressed7);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck8()
{
    if (mouse_info_s.x > 3 * mode_info.XResolution / 4 && mouse_info_s.x < mode_info.XResolution && mouse_info_s.y > mode_info.YResolution / 4 && mouse_info_s.y < mode_info.YResolution / 2)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed8 = true;}
            
        }
    }
    if (backPressed8)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[1][3].id;
            index_1_bool = &backPressed8;
            index_1 = &matrix[1][3];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[1][3])
        {
            matrix_id2 = matrix[1][3].id;
            index_2_bool = &backPressed8;
            index_2 = &matrix[1][3];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                printf("The value of the backPressed8 is %d", backPressed8);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck9()
{
    if (mouse_info_s.x > 0 && mouse_info_s.x < mode_info.XResolution / 4 && mouse_info_s.y > mode_info.YResolution / 2 && mouse_info_s.y < 3 * mode_info.YResolution / 4)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed9 = true;}
            
        }
    }
    if (backPressed9)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[2][0].id;
            index_1_bool = &backPressed9;
            index_1 = &matrix[2][0];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[2][0])
        {
            matrix_id2 = matrix[2][0].id;
            index_2_bool = &backPressed9;
            index_2 = &matrix[2][0];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {  
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed9 is %d", backPressed9);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck10()
{
    if (mouse_info_s.x > mode_info.XResolution / 4 && mouse_info_s.x < mode_info.XResolution / 2 && mouse_info_s.y > mode_info.YResolution / 2 && mouse_info_s.y < 3 * mode_info.YResolution / 4)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed10 = true;}
            
        }
    }
    if (backPressed10)
    {        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[2][1].id;
            index_1_bool = &backPressed10;
            index_1 = &matrix[2][1];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[2][1])
        {
            matrix_id2 = matrix[2][1].id;
            index_2_bool = &backPressed10;
            index_2 = &matrix[2][1];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed10 is %d", backPressed10);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck11()
{
    if (mouse_info_s.x > mode_info.XResolution / 2 && mouse_info_s.x < 3 * mode_info.XResolution / 4 && mouse_info_s.y > mode_info.YResolution / 2 && mouse_info_s.y < 3 * mode_info.YResolution / 4)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed11 = true;}
            
        }
    }
    if (backPressed11)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[2][2].id;
            index_1_bool = &backPressed11;
            index_1 = &matrix[2][2];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[2][2])
        {
            matrix_id2 = matrix[2][2].id;
            index_2_bool = &backPressed11;
            index_2 = &matrix[2][2];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed11 is %d", backPressed11);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck12()
{
    if (mouse_info_s.x > 3 * mode_info.XResolution / 4 && mouse_info_s.x < mode_info.XResolution && mouse_info_s.y > mode_info.YResolution / 2 && mouse_info_s.y < 3 * mode_info.YResolution / 4)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed12 = true;}
            
        }
    }
    if (backPressed12)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[2][3].id;
            index_1_bool = &backPressed12;
            index_1 = &matrix[2][3];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[2][3])
        {
            matrix_id2 = matrix[2][3].id;
            index_2_bool = &backPressed12;
            index_2 = &matrix[2][3];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed12 is %d", backPressed12);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck13()
{
    if (mouse_info_s.x > 0 && mouse_info_s.x < mode_info.XResolution / 4 && mouse_info_s.y > 3 * mode_info.YResolution / 4 && mouse_info_s.y < mode_info.YResolution)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed13 = true;}
            
        }
    }
    if (backPressed13)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[3][0].id;
            index_1_bool = &backPressed13;
            index_1 = &matrix[3][0];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[3][0])
        {
            matrix_id2 = matrix[3][0].id;
            index_2_bool = &backPressed13;
            index_2 = &matrix[3][0];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed13 is %d", backPressed13);
            }

            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck14()
{
    if (mouse_info_s.x > mode_info.XResolution / 4 && mouse_info_s.x < mode_info.XResolution / 2 && mouse_info_s.y > 3 * mode_info.YResolution / 4 && mouse_info_s.y < mode_info.YResolution)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed14 = true;}
            
        }
    }
    if (backPressed14)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[3][1].id;
            index_1_bool = &backPressed14;
            index_1 = &matrix[3][1];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[3][1])
        {
            matrix_id2 = matrix[3][1].id;
            index_2_bool = &backPressed14;
            index_2 = &matrix[3][1];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed14 is %d", backPressed14);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck15()
{
    if (mouse_info_s.x > mode_info.XResolution / 2 && mouse_info_s.x < 3 * mode_info.XResolution / 4 && mouse_info_s.y > 3 * mode_info.YResolution / 4 && mouse_info_s.y < mode_info.YResolution)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed15 = true;}
            
        }
    }
    if (backPressed15)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[3][2].id;
            index_1_bool = &backPressed15;
            index_1 = &matrix[3][2];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[3][2])
        {
            matrix_id2 = matrix[3][2].id;
            index_2_bool = &backPressed15;
            index_2 = &matrix[3][2];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_deck16()
{
    if (mouse_info_s.x > 3 * mode_info.XResolution / 4 && mouse_info_s.x < mode_info.XResolution && mouse_info_s.y > 3 * mode_info.YResolution / 4 && mouse_info_s.y < mode_info.YResolution)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            backPressed16 = true;}
            
        }
    }
    if (backPressed16)
    {
        
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[3][3].id;
            index_1_bool = &backPressed16;
            index_1 = &matrix[3][3];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[3][3])
        {
            matrix_id2 = matrix[3][3].id;
            index_2_bool = &backPressed16;
            index_2 = &matrix[3][3];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                index_1->block = true;
                index_2->block = true;
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the backPressed16 is %d", backPressed16);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
            
        }
        }
    }
}

void draw_game_menu_3()
{
    Sprite cards3[] = {*number1, *number1, *number2, *number2, *number3, *number3, *number4, *number4, *number5, *number5, *number6, *number6, *number7, *number7, *number8, *number8};
    if (pre2 == 0)
    {
        backPressed1 = false;
        backPressed2 = false;
        backPressed3 = false;
        backPressed4 = false;
        backPressed5 = false;
        backPressed6 = false;
        backPressed7 = false;
        backPressed8 = false;
        backPressed9 = false;
        backPressed10 = false;
        backPressed11 = false;
        backPressed12 = false;
        backPressed13 = false;
        backPressed14 = false;
        backPressed15 = false;
        backPressed16 = false;
        is_processing = false;
        matrix = alloc_matrix(4, 4);
        shuffle3(cards3);
        pre2++;
    }
    memset(drawing_frame_buf, 0x000000, mode_info.XResolution * mode_info.YResolution * mode_info.BitsPerPixel / 8);
    animation_trigger(&matrix[0][0], 0, 0);
    animation_trigger(&matrix[0][1], mode_info.XResolution / 4, 0);
    animation_trigger(&matrix[0][2], mode_info.XResolution / 2, 0);
    animation_trigger(&matrix[0][3],3 * mode_info.XResolution / 4, 0);
    animation_trigger(&matrix[1][0], 0, mode_info.YResolution / 4);
    animation_trigger(&matrix[1][1], mode_info.XResolution / 4, mode_info.YResolution / 4);
    animation_trigger(&matrix[1][2], mode_info.XResolution / 2, mode_info.YResolution / 4);
    animation_trigger(&matrix[1][3], 3 * mode_info.XResolution / 4, mode_info.YResolution / 4);
    animation_trigger(&matrix[2][0], 0, mode_info.YResolution / 2);
    animation_trigger(&matrix[2][1], mode_info.XResolution / 4, mode_info.YResolution / 2);
    animation_trigger(&matrix[2][2], mode_info.XResolution / 2, mode_info.YResolution / 2);
    animation_trigger(&matrix[2][3], 3 * mode_info.XResolution / 4, mode_info.YResolution / 2);
    animation_trigger(&matrix[3][0], 0, 3 * mode_info.YResolution / 4);
    animation_trigger(&matrix[3][1], mode_info.XResolution / 4, 3 * mode_info.YResolution / 4);
    animation_trigger(&matrix[3][2], mode_info.XResolution / 2, 3 * mode_info.YResolution / 4);
    animation_trigger(&matrix[3][3], 3 * mode_info.XResolution / 4, 3 * mode_info.YResolution / 4);

    if (matrix[0][0].block == false)
    {
        process_deck1();
    }
    else if (matrix[0][0].block == true)
    {
        matrix[0][0].state = 5;
    }
    if (matrix[0][1].block == false)
    {
        process_deck2();
    }
    else if (matrix[0][1].block == true)
    {
        matrix[0][1].state = 5;
    }
    if (matrix[0][2].block == false)
    {
        process_deck3();
    }
    else if (matrix[0][2].block == true)
    {
        matrix[0][2].state = 5;
    }
    if (matrix[0][3].block == false)
    {
        process_deck4();
    }
    else if (matrix[0][3].block == true)
    {
        matrix[0][3].state = 5;
    }
    if (matrix[1][0].block == false)
    {
        process_deck5();
    }
    else if (matrix[1][0].block == true)
    {
        matrix[1][0].state = 5;
    }
    if (matrix[1][1].block == false)
    {
        process_deck6();
    }
    else if (matrix[1][1].block == true)
    {
        matrix[1][1].state = 5;
    }
    if (matrix[1][2].block == false)
    {
        process_deck7();
    }
    else if (matrix[1][2].block == true)
    {
        matrix[1][2].state = 5;
    }
    if (matrix[1][3].block == false)
    {
        process_deck8();
    }
    else if (matrix[1][3].block == true)
    {
        matrix[1][3].state = 5;
    }
    if (matrix[2][0].block == false)
    {
        process_deck9();
    }
    else if (matrix[2][0].block == true)
    {
        matrix[2][0].state = 5;
    }
    if (matrix[2][1].block == false)
    {
        process_deck10();
    }
    else if (matrix[2][1].block == true)
    {
        matrix[2][1].state = 5;
    }
    if (matrix[2][2].block == false)
    {
        process_deck11();
    }
    else if (matrix[2][2].block == true)
    {
        matrix[2][2].state = 5;
    }
    if (matrix[2][3].block == false)
    {
        process_deck12();
    }
    else if (matrix[2][3].block == true)
    {
        matrix[2][3].state = 5;
    }
    if (matrix[3][0].block == false)
    {
        process_deck13();
    }
    else if (matrix[3][0].block == true)
    {
        matrix[3][0].state = 5;
    }
    if (matrix[3][1].block == false)
    {
        process_deck14();
    }
    else if (matrix[3][1].block == true)
    {
        matrix[3][1].state = 5;
    }
    if (matrix[3][2].block == false)
    {
        process_deck15();
    }
    else if (matrix[3][2].block == true)
    {
        matrix[3][2].state = 5;
    }
    if (matrix[3][3].block == false)
    {
        process_deck16();
    }
    else if (matrix[3][3].block == true)
    {
        matrix[3][3].state = 5;
    }
    if (matrix[0][0].block == true && matrix[0][1].block == true && matrix[0][2].block == true && matrix[0][3].block == true && matrix[1][0].block == true && matrix[1][1].block == true && matrix[1][2].block == true && matrix[1][3].block == true && matrix[2][0].block == true && matrix[2][1].block == true && matrix[2][2].block == true && matrix[2][3].block == true && matrix[3][0].block == true && matrix[3][1].block == true && matrix[3][2].block == true && matrix[3][3].block == true)
    {
        if(pre2 == 1) {
        gameplayCounter = 20; 
        pre2++;
        }
        to_help = menuState;
        pre2 = 0;
        menuState = END;
    }

    if(scancode == R_KEY){
        pre2 = 0; 
        menuState = GAME_3;
    }    
    
}
