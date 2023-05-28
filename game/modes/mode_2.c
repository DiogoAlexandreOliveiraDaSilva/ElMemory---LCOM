#include "mode_2.h"

extern int pre1;
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
extern bool cardPressed1;
extern bool cardPressed2;
extern bool cardPressed3;
extern bool cardPressed4;
extern bool cardPressed5;
extern bool cardPressed6;
extern bool cardPressed7;
extern bool cardPressed8;
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
extern uint8_t scancode; 
extern MenuState to_help;

void process_cardPressed1()
{
    if (mouse_info_s.x >= 0 && mouse_info_s.y >= 0 && mouse_info_s.x <= mode_info.XResolution / 4 && mouse_info_s.y <= mode_info.YResolution / 2)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
                cardPressed1 = true;
            }
        }
    }
    if (cardPressed1)
    {
        printf("Entrei no botao 1\n");
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[0][0].id;
            index_1_bool = &cardPressed1;
            index_1 = &matrix[0][0];
            index_1->state = 1; 
            printf("The value of the variable gamplayCounter is %d\n", gameplayCounter);
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[0][0])
        {
            matrix_id2 = matrix[0][0].id;
            index_2_bool = &cardPressed1;
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
                printf("The value of the cardPressed1 is %d", cardPressed1);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}
void process_cardPressed2()
{
    if (mouse_info_s.x >= mode_info.XResolution / 4 && mouse_info_s.y >= 0 && mouse_info_s.x <= mode_info.XResolution / 2 && mouse_info_s.y <= mode_info.YResolution / 2)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing) {
            cardPressed2 = true;}
        }
    }
    if (cardPressed2)
    {

        printf("Entrei no botao 1\n");
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[0][1].id;
            index_1_bool = &cardPressed2;
            index_1 = &matrix[0][1];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[0][1])
        {
            matrix_id2 = matrix[0][1].id;
            index_2_bool = &cardPressed2;
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
                printf("The value of the cardPressed2 is %d", cardPressed2);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}

void process_cardPressed3()
{
    if (mouse_info_s.x >= mode_info.XResolution / 2 && mouse_info_s.y >= 0 && mouse_info_s.x <= 3 * mode_info.XResolution / 4 && mouse_info_s.y <= mode_info.YResolution / 2)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            cardPressed3 = true;}
        }
    }
    if (cardPressed3)
    {

        printf("Entrei no botao 1\n");
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[0][2].id;
            index_1_bool = &cardPressed3;
            index_1 = &matrix[0][2];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[0][2])
        {
            matrix_id2 = matrix[0][2].id;
            index_2_bool = &cardPressed3;
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
                printf("The value of the cardPressed3 is %d", cardPressed3);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}

void process_cardPressed4()
{
    if (mouse_info_s.x >= 3 * mode_info.XResolution / 4 && mouse_info_s.y >= 0 && mouse_info_s.x <= mode_info.XResolution && mouse_info_s.y <= mode_info.YResolution / 2)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            cardPressed4 = true;}
        }
    }
    if (cardPressed4)
    {
        printf("Entrei no botao 1\n");
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[0][3].id;
            index_1_bool = &cardPressed4;
            index_1 = &matrix[0][3];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[0][3])
        {
            matrix_id2 = matrix[0][3].id;
            index_2_bool = &cardPressed4;
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
                printf("The value of the cardPressed4 is %d", cardPressed4);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}

void process_cardPressed5()
{
    if (mouse_info_s.x >= 0 && mouse_info_s.y >= mode_info.YResolution / 2 && mouse_info_s.x <= mode_info.XResolution / 4 && mouse_info_s.y <= mode_info.YResolution)
    {
        if (mouse_info_s.left_click)
        {
             if(!is_processing){
            cardPressed5 = true;}
        }
    }
    if (cardPressed5)
    {
        printf("Entrei no botao 1\n");
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[1][0].id;
            index_1_bool = &cardPressed5;
            index_1 = &matrix[1][0];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[1][0])
        {
            matrix_id2 = matrix[1][0].id;
            index_2_bool = &cardPressed5;
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
                printf("The value of the cardPressed5 is %d", cardPressed5);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}

void process_cardPressed6()
{
    if (mouse_info_s.x >= mode_info.XResolution / 4 && mouse_info_s.y >= mode_info.YResolution / 2 && mouse_info_s.x <= mode_info.XResolution / 2 && mouse_info_s.y <= mode_info.YResolution)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            cardPressed6 = true;}
        }
    }
    if (cardPressed6)
    {

        printf("Entrei no botao 1\n");
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[1][1].id;
            index_1_bool = &cardPressed6;
            index_1 = &matrix[1][1];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[1][1])
        {
            matrix_id2 = matrix[1][1].id;
            index_2_bool = &cardPressed6;
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
                printf("The value of the cardPressed6 is %d", cardPressed6);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}

void process_cardPressed7()
{
    if (mouse_info_s.x >= mode_info.XResolution / 2 && mouse_info_s.y >= mode_info.YResolution / 2 && mouse_info_s.x <= 3 * mode_info.XResolution / 4 && mouse_info_s.y <= mode_info.YResolution)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            cardPressed7 = true;}
        }
    }
    if (cardPressed7)
    {
        printf("Entrei no botao 1\n");
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[1][2].id;
            index_1_bool = &cardPressed7;
            index_1 = &matrix[1][2];
            index_1->state = 1;
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[1][2])
        {
            matrix_id2 = matrix[1][2].id;
            index_2_bool = &cardPressed7;
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
                printf("The value of the cardPressed7 is %d", cardPressed7);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}

void process_cardPressed8()
{
    if (mouse_info_s.x >= 3 * mode_info.XResolution / 4 && mouse_info_s.y >= mode_info.YResolution / 2 && mouse_info_s.x <= mode_info.XResolution && mouse_info_s.y <= mode_info.YResolution)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            cardPressed8 = true;}
        }
    }
    if (cardPressed8)
    {
        printf("Entrei no botao 1\n");
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[1][3].id;
            index_1_bool = &cardPressed8;
            index_1 = &matrix[1][3];
            index_1->state = 1;

            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[1][3])
        {
            matrix_id2 = matrix[1][3].id;
            index_2_bool = &cardPressed8;
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
                index_1->state = 0;
                index_2->state = 0;
                printf("The value of the cardPressed8 is %d", cardPressed8);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
        }
        }
    }
}

void draw_game_menu_2()
{
    Sprite cards2[] = {*number1, *number1, *number2, *number2, *number3, *number3, *number4, *number4};
    if (pre1 == 0)
    {
        is_processing = false;
        cardPressed1 =false;
        cardPressed2 =false;
        cardPressed3 =false;
        cardPressed4 =false;
        cardPressed5 =false;
        cardPressed6 =false;
        cardPressed7 =false;
        cardPressed8 =false;
        matrix = alloc_matrix(4, 2);
        shuffle2(cards2);
        pre1++;
    }

    memset(drawing_frame_buf, 0, mode_info.XResolution * mode_info.YResolution * mode_info.BitsPerPixel / 8);
    animation_trigger(&matrix[0][0], 0, 0);
    animation_trigger(&matrix[0][1], mode_info.XResolution / 4, 0);
    animation_trigger(&matrix[0][2], mode_info.XResolution / 2, 0);
    animation_trigger(&matrix[0][3], 3 * mode_info.XResolution / 4, 0);
    animation_trigger(&matrix[1][0], 0, mode_info.YResolution / 2);
    animation_trigger(&matrix[1][1], mode_info.XResolution / 4, mode_info.YResolution / 2);
    animation_trigger(&matrix[1][2], mode_info.XResolution / 2, mode_info.YResolution / 2);
    animation_trigger(&matrix[1][3], 3 * mode_info.XResolution / 4, mode_info.YResolution / 2);
    if (matrix[0][0].block == false)
    {
        process_cardPressed1();
    }
    else if (matrix[0][0].block == true)
    {
        matrix[0][0].state = 5;
    }
    if (matrix[0][1].block == false)
    {
        process_cardPressed2();
    }
    else if (matrix[0][1].block == true)
    {
        matrix[0][1].state = 5; 
    }
    if (matrix[0][2].block == false)
    {
        process_cardPressed3();
    }
    else if (matrix[0][2].block == true)
    {
        matrix[0][2].state = 5;
    }
    if (matrix[0][3].block == false)
    {
        process_cardPressed4();
    }
    else if (matrix[0][3].block == true)
    {
        matrix[0][3].state = 5;
    }
    if (matrix[1][0].block == false)
    {
        process_cardPressed5();
    }
    else if (matrix[1][0].block == true)
    {
        matrix[1][0].state = 5;
    }
    if (matrix[1][1].block == false)
    {
        process_cardPressed6();
    }
    else if (matrix[1][1].block == true)
    {
        matrix[1][1].state = 5;
    }
    if (matrix[1][2].block == false)
    {
        process_cardPressed7();
    }
    else if (matrix[1][2].block == true)
    {
        matrix[1][2].state = 5;
    }
    if (matrix[1][3].block == false)
    {
        process_cardPressed8();
    }
    else if (matrix[1][3].block == true)
    {
        matrix[1][3].state = 5;
    }
    if (matrix[0][0].block == true && matrix[0][1].block == true && matrix[0][2].block == true && matrix[0][3].block == true && matrix[1][0].block == true && matrix[1][1].block == true && matrix[1][2].block == true && matrix[1][3].block == true)
    {
        if(pre1 == 1) {
        gameplayCounter = 20; 
        pre1++;
        }
        to_help = menuState;
        pre1 = 0;
        menuState = END;
    }
     if(scancode == R_KEY){
        pre1 = 0; 
        menuState = GAME_2;
    }   
}
