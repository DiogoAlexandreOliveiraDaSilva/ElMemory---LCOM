#include "mode_1_2.h"

extern int pre;
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
extern Sprite *smile;
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
extern bool button1Pressed;
extern bool button2Pressed;
extern bool button3Pressed;
extern bool button4Pressed;
extern uint8_t *main_frame_buf;
extern uint8_t *SECONDSondary_frame_buf;
extern uint8_t *drawing_frame_buf;
extern uint32_t frame_buf_size;
extern Sprite *back_anim1;
extern Sprite *back_anim2;
extern Sprite *back_anim3;
extern Sprite *back_anim4;
extern bool player1;
extern bool player2;
extern int player_1;
extern int player_2;
extern bool is_processing; 
extern uint8_t scancode; 

extern int gameplayCounter; 

void process_button1_2(Sprite *cards, int size)
{
    if (mouse_info_s.x < mode_info.XResolution / 2 && mouse_info_s.y < mode_info.YResolution / 2)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            printf("BOTAO 1 CLICK\n");
            button1Pressed = true;}
        }
    }
    if (button1Pressed)
    {
        printf("Entrei no botao 1\n");
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[0][0].id;
            index_1_bool = &button1Pressed;
            index_1 = &matrix[0][0];
            index_1->state = 1;
            printf("THe value of the index_1->state on button 1 is %d\n", index_1->state);
            printf("The value of index_1 on button1 is %d\n", index_1);
            printf("The value of matrix_id1 on button1 is %d", matrix_id1);
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[0][0])
        {
            matrix_id2 = matrix[0][0].id;
            index_2_bool = &button1Pressed;
            index_2 = &matrix[0][0];
            index_2->state = 1;
            gameplayCounter = 5;
            printf("THe value of the index_1->state on button 1 is %d\n", index_2->state);
            printf("The value of index_2 on button1 is %d\n", index_2);
            printf("The value of matrix_id2 on button1 is %d", matrix_id2);
            
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            
            if (check_match(matrix_id1, matrix_id2))
            {
                printf("ENTERED HERE");

                if(player1){
                    printf("player1");
                    player_1++;
                }
                else if(player2){
                    printf("player2");
                    player_2++;
                }
                index_1->block = true;
                index_2->block = true;
                
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                player1 = !player1;
                player2 = !player2;
                *index_2_bool = false;
                *index_1_bool = false;
                index_1->state = 0;
                index_2->state = 0;
                
                printf("The value of the button1Pressed is %d", button1Pressed);
            }
            matrix_id1 = -1;
            matrix_id2 = -1;
            is_processing = false;
            }
        }
    }
}

void process_button2_2(Sprite *cards, int size)
{
    if (mouse_info_s.x >= mode_info.XResolution / 2 && mouse_info_s.y <= mode_info.YResolution / 2)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            button2Pressed = true;
            }
        }
    }

    if (button2Pressed)
    {
        printf("ENTREI NO BOTAO 2\n");
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[0][1].id;
            index_1_bool = &button2Pressed;
            index_1 = &matrix[0][1];
            index_1->state = 1;
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[0][1])
        {
            matrix_id2 = matrix[0][1].id;
            index_2_bool = &button2Pressed;
            index_2 = &matrix[0][1];
            index_2->state = 1;
            gameplayCounter = 5;        
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            
            if (check_match(matrix_id1, matrix_id2))
            {
                printf("ENTERED HERE");

                if(player1){
                    printf("player 1");
                    player_1++;
                }
                else if(player2){
                    printf("player 2");
                    player_2++;
                }
                index_1->block = true;
                index_2->block = true;
                
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {

                player1 = !player1;
                player2 = !player2;
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

void process_button3_2(Sprite *cards, int size)
{
    if (mouse_info_s.x < mode_info.XResolution / 2 && mouse_info_s.y >= mode_info.YResolution / 2)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            button3Pressed = true;
            }
        }
    }
    if (button3Pressed)
    {
        printf("ENTREI NO BOTAO 3\n");
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[1][0].id;
            index_1_bool = &button3Pressed;
            index_1 = &matrix[1][0];
            index_1->state = 1;
        }

        else if (matrix_id2 == -1 && index_1 != &matrix[1][0])
        {
            matrix_id2 = matrix[1][0].id;
            index_2_bool = &button3Pressed;
            index_2 = &matrix[1][0];
            index_2->state = 1;
            gameplayCounter = 5;
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4) {
            if (check_match(matrix_id1, matrix_id2))
            {
                printf("ENTERED HERE");
                if(player1){
                    printf("ENTERED HERE player1");
                    player_1++;
                }
                else if(player2){
                    printf("ENTERED HERE player2");
                    player_2++;
                }
                index_1->block = true;
                index_2->block = true;
                
            }
            else if (!check_match(matrix_id1, matrix_id2))
            {
                player1 = !player1;
                player2 = !player2;
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

void process_button4_2(Sprite *cards, int size)
{
    if (mouse_info_s.x >= mode_info.XResolution / 2 && mouse_info_s.y > mode_info.YResolution / 2)
    {
        if (mouse_info_s.left_click)
        {
            if(!is_processing){
            button4Pressed = true;
            }
        }
    }
    if (button4Pressed)
    {
        printf("ENTREI NO BOTAO 4\n");
        if (matrix_id1 == -1)
        {
            matrix_id1 = matrix[1][1].id;
            index_1_bool = &button4Pressed;
            index_1 = &matrix[1][1];
            index_1->state = 1;
        }
        else if (matrix_id2 == -1 && index_1 != &matrix[1][1])
        {
            matrix_id2 = matrix[1][1].id;
            index_2_bool = &button4Pressed;
            index_2 = &matrix[1][1];
            index_2->state = 1;
            gameplayCounter = 5;
        }
        if (matrix_id1 != -1 && matrix_id2 != -1)
        {
            is_processing = true;
            if(gameplayCounter % 2 == 0 && gameplayCounter != 4){
            if (check_match(matrix_id1, matrix_id2))
            {
                if(player1){
                    printf("ENTERED HERE player1");
                    player_1++;
                }
                else if(player2){
                    printf("ENTERED HERE player2");
                    player_2++;
                }
                index_1->block = true;
                index_2->block = true;
                
            }
            else
            {
                player1 = !player1;
                player2 = !player2;
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

void draw_game_menu_2_2()
{

    Sprite cards[] = {*number1, *number1, *number2, *number2};
    int j = sizeof(cards) / sizeof(cards[0]);

    if (pre == 0)
    {
        player1 = true;
        player2 = false;
        player_1 = 0;
        player_2 = 0;
        matrix = alloc_matrix(2, 2);
        shuffle(cards, j);
        printf("matrix allocated\n,%d", matrix);
        pre++;
    }
    
    memset(drawing_frame_buf, 0, mode_info.XResolution * mode_info.YResolution * mode_info.BitsPerPixel / 8);
    animation_trigger(&matrix[0][0], 0, 0);
    animation_trigger(&matrix[0][1], mode_info.XResolution / 2, 0);
    animation_trigger(&matrix[1][0], 0, mode_info.YResolution / 2);
    animation_trigger(&matrix[1][1], mode_info.XResolution / 2, mode_info.YResolution / 2);
    printf("gameplayCounter %d",gameplayCounter);
    printf("player1 %d", player1);
    printf("player2 %d", player2);
    printf("player1score %d", player_1);
    printf("player2score %d", player_2);
    printf("matrix: %d\n", matrix_id1);
    

    if (matrix[0][0].block == false)
    {
        process_button1_2(cards, j);
    }
    if (matrix[0][0].block == true)
    {
        printf("CONSEGUIU BLOQUEAR");
        matrix[0][0].state = 5;
    }

    if (matrix[0][1].block == false)
    {
        process_button2_2(cards, j);
        
    }
    else if (matrix[0][1].block == true)
    {
        printf("CONSEGUIU BLOQUEAR");
        matrix[0][1].state = 5;
    }
    if (matrix[1][0].block == false)
    {
        process_button3_2(cards, j);
    }
    else if (matrix[1][0].block == true)
    {
        printf("CONSEGUIU BLOQUEAR");
        matrix[1][0].state = 5;
    }
    if (matrix[1][1].block == false)
    {
        process_button4_2(cards, j);
    }
    else if (matrix[1][1].block == true)
    {
        printf("CONSEGUIU BLOQUEAR");
        matrix[1][1].state = 5;
    }
    if (matrix[0][0].block == true && matrix[0][1].block == true && matrix[1][0].block == true && matrix[1][1].block == true)
    {
        printf("player1Score %d", player_1);
        printf("player2Score %d", player_2);
        menuState = END;
    }
     if(scancode == R_KEY){
        pre = 0; 
        menuState = GAME_2P;
    }   
}
