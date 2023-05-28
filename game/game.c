#include "game.h"
#include "../game/modes/menu.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Variáveis externas importantes à visualização do modelo e dos seus estados
uint8_t *main_frame_buf;
uint8_t *SECONDSondary_frame_buf;
uint8_t *drawing_frame_buf;
uint32_t frame_buf_size;
extern int timer_interrupts;
extern vbe_mode_info_t mode_info;
extern Mouse_Info_Struct mouse_info_s;
extern real_time_mode_info time_mode_info;
extern MenuState menuState;
extern SystemState systemState;

// Objetos

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
extern Sprite *back_anim1;
extern Sprite *back_anim2;
extern Sprite *back_anim3;
extern Sprite *back_anim4;
extern Sprite *Menu;
extern Sprite *Start;
extern Sprite *Quit;
extern Sprite *Easy;
extern Sprite *Medium;
extern Sprite *Hard;
extern Sprite *score1;
extern Sprite *score2;
extern Sprite *score3;
extern Sprite *score4;
extern Sprite *score5;
extern Sprite *score6;
extern Sprite *score7;
extern Sprite *score8;
extern Sprite *score9;
extern Sprite *score0;
extern Sprite *player_1_xpm;
extern Sprite *player_2_xpm;
extern Sprite *player_1_menu;
extern Sprite *player_2_menu;
extern int pre;
extern int pre1; 
extern int pre2;
int animationFrame = 0;
bool isAnimating = false;
int chosen;
extern int gameplayCounter;
MenuState to_help;

Sprite **alloc_matrix(int n, int m)
{
    Sprite **mat = (Sprite **)malloc(sizeof(Sprite *) * m);
    for (int i = 0; i < n; i++)
    {
        mat[i] = (Sprite *)malloc(sizeof(Sprite) * n);
    }
    return mat;
}

int define_frame_bufs(uint16_t mode)
{
    if (define_frame_buf(mode, &main_frame_buf))
        return 1;
    frame_buf_size = mode_info.XResolution * mode_info.YResolution * ((mode_info.BitsPerPixel + 7) / 8);
    if (DOUBLE_BUFFER)
    {
        SECONDSondary_frame_buf = (uint8_t *)malloc(frame_buf_size);
        drawing_frame_buf = SECONDSondary_frame_buf;
    }
    else
    {
        drawing_frame_buf = main_frame_buf;
    }
    return 0;
}

void clear_draw_buffer()
{
    memset(main_frame_buf, 0xFFFFFF, mode_info.XResolution * mode_info.YResolution * ((mode_info.BitsPerPixel + 7) / 8));
}

void swap_buffers()
{
    memcpy(main_frame_buf, SECONDSondary_frame_buf, frame_buf_size);
    if (timer_interrupts % FPS == 0)
        rtc_print();
}

void draw_new_fb()
{
    switch (menuState)
    {
    case START:
        draw_initial_menu();
        mouse_info_s.left_click = 0;
        break;
    case GAME:
        draw_game_menu();
        mouse_info_s.left_click = 0;
        break;
    case GAME_2P:
        draw_game_menu_2_2();
        mouse_info_s.left_click = 0;
        break;
    case GAME_4_2P:
        draw_game_menu_4_2();
        mouse_info_s.left_click = 0;
        break;
    case GAME_8_2P:
        draw_game_menu_8_2();
        mouse_info_s.left_click = 0;
        break;
    case END:
        draw_finish_menu();
        mouse_info_s.left_click = 0;
        break;
    case GAME_2:
        draw_game_menu_2();
        mouse_info_s.left_click = 0;
        break;
    case MODE:
        draw_mode_menu();
        mouse_info_s.left_click = 0;
        break;
    case SEL_P:
        draw_select_player();
        mouse_info_s.left_click = 0;
        break;
    case GAME_3:
        draw_game_menu_3();
        mouse_info_s.left_click = 0;
        break;
    case MODE_2:
        draw_mode_2player();
        mouse_info_s.left_click = 0;
        break;
    }
    draw_mouse();
}

void process_start_button()
{
    if (mouse_info_s.x >= mode_info.XResolution / 3 && mouse_info_s.x <= mode_info.XResolution / 3 + Start->width && mouse_info_s.y >= mode_info.YResolution / 3 && mouse_info_s.y <= mode_info.YResolution / 3 + Start->height)
    {
        draw_xpm(Start, mode_info.XResolution / 3, mode_info.YResolution / 3);
        if (mouse_info_s.left_click)
        {
            menuState = SEL_P;
        }
    }
}

void process_quit_button()
{
    if (mouse_info_s.x >= mode_info.XResolution / 3 && mouse_info_s.x <= mode_info.XResolution / 3 + Quit->width && mouse_info_s.y >= mode_info.YResolution / 2 && mouse_info_s.y <= mode_info.YResolution / 2 + Quit->height)
    {
        draw_xpm(Quit, mode_info.XResolution / 3, mode_info.YResolution / 2);
        if (mouse_info_s.left_click)
        {
            menuState = END;
        }
    }
}

void draw_initial_menu()
{
    memset(drawing_frame_buf, 0x000000, frame_buf_size);
    draw_xpm(logo, mode_info.XResolution / 2 - logo->width / 2, mode_info.YResolution / 4 - logo->height);

    draw_xpm(Start, mode_info.XResolution / 3, mode_info.YResolution / 3);
    process_start_button();

    draw_xpm(Quit, mode_info.XResolution / 3, mode_info.YResolution / 2);
    process_quit_button();
}

void process_mode1()
{
    if (mouse_info_s.x >= mode_info.XResolution / 3 && mouse_info_s.x <= mode_info.XResolution / 3 + Easy->width && mouse_info_s.y >= mode_info.YResolution / 4 && mouse_info_s.y <= mode_info.YResolution / 4 + Easy->height)
    {
        draw_xpm(Easy, mode_info.XResolution / 3, mode_info.YResolution / 4);
        if (mouse_info_s.left_click)
        {
            menuState = GAME;
        }
    }
}
void process_mode2()
{
    if (mouse_info_s.x >= mode_info.XResolution / 3 && mouse_info_s.x <= mode_info.XResolution / 3 + Medium->width && mouse_info_s.y >= mode_info.YResolution / 2 && mouse_info_s.y <= mode_info.YResolution / 2 + Medium->height)
    {
        draw_xpm(Medium, mode_info.XResolution / 3, mode_info.YResolution / 2);
        if (mouse_info_s.left_click)
        {
            menuState = GAME_2;
        }
    }
}

void process_mode3()
{
    if (mouse_info_s.x >= mode_info.XResolution / 3 && mouse_info_s.x <= mode_info.XResolution / 3 + Hard->width && mouse_info_s.y >= 3 * mode_info.YResolution / 4 && mouse_info_s.y <= 3 * mode_info.YResolution / 4 + Hard->height)
    {
        draw_xpm(Hard, mode_info.XResolution / 3, 3 * mode_info.YResolution / 4);
        if (mouse_info_s.left_click)
        {
            menuState = GAME_3;
        }
    }
}

void process_player_1() 
{
    if (mouse_info_s.x >= mode_info.XResolution / 3 && mouse_info_s.x <= mode_info.XResolution / 3 + player_1_menu->width && mouse_info_s.y >= mode_info.YResolution / 3 && mouse_info_s.y <= mode_info.YResolution / 3 + player_1_menu->height)
    {
        draw_xpm(player_1_menu, mode_info.XResolution / 3, mode_info.YResolution / 3);
        if (mouse_info_s.left_click)
        {
            menuState = MODE;
        }
    }
}

void process_player_2() 
{

    if (mouse_info_s.x >= mode_info.XResolution / 3 && mouse_info_s.x <= mode_info.XResolution / 3 + player_2_menu->width && mouse_info_s.y >= mode_info.YResolution / 2 && mouse_info_s.y <= mode_info.YResolution / 2 + player_2_menu->height)
    {
        draw_xpm(player_2_menu, mode_info.XResolution / 3, mode_info.YResolution / 2);
        if (mouse_info_s.left_click)
        {
            menuState = MODE_2;
        }
    }
}

void draw_mode_menu()
{

    memset(drawing_frame_buf, 0x000000, frame_buf_size);
    draw_xpm(Easy, mode_info.XResolution / 3, mode_info.YResolution / 4);
    process_mode1();
    draw_xpm(Medium, mode_info.XResolution / 3, mode_info.YResolution / 2);
    process_mode2();
    draw_xpm(Hard, mode_info.XResolution / 3, 3 * mode_info.YResolution / 4);
    process_mode3();
}


void draw_select_player() 
{ 
    memset(drawing_frame_buf,0x000000,frame_buf_size);
    draw_xpm(player_1_menu,mode_info.XResolution / 3, mode_info.YResolution / 3);
    process_player_1();
    draw_xpm(player_2_menu,mode_info.XResolution / 3, mode_info.YResolution / 2);
    process_player_2();
}

void process_mode1_2()
{
     if (mouse_info_s.x >= mode_info.XResolution / 3 && mouse_info_s.x <= mode_info.XResolution / 3 + Easy->width && mouse_info_s.y >= mode_info.YResolution / 4 && mouse_info_s.y <= mode_info.YResolution / 4 + Easy->height)
    {
        draw_xpm(Easy, mode_info.XResolution / 3, mode_info.YResolution / 4);
        if (mouse_info_s.left_click)
        {
            menuState = GAME_2P;
        }
    }

}

void process_mode2_2() 
{
    if (mouse_info_s.x >= mode_info.XResolution / 3 && mouse_info_s.x <= mode_info.XResolution / 3 + Medium->width && mouse_info_s.y >= mode_info.YResolution / 2 && mouse_info_s.y <= mode_info.YResolution / 2 + Medium->height)
    {
        draw_xpm(Medium, mode_info.XResolution / 3, mode_info.YResolution / 2);
        if (mouse_info_s.left_click)
        {
            menuState = GAME_4_2P;
        }
    }
}

void process_mode3_2() 
{
    if (mouse_info_s.x >= mode_info.XResolution / 3 && mouse_info_s.x <= mode_info.XResolution / 3 + Hard->width && mouse_info_s.y >= 3 * mode_info.YResolution / 4 && mouse_info_s.y <= 3 * mode_info.YResolution / 4 + Hard->height)
    {
        draw_xpm(Hard, mode_info.XResolution / 3, 3 * mode_info.YResolution / 4);
        if (mouse_info_s.left_click)
        {
            menuState = GAME_8_2P;
        }
    }
}

void draw_mode_2player() { 
    memset(drawing_frame_buf,0x000000,frame_buf_size);
    draw_xpm(Easy,mode_info.XResolution / 3, mode_info.YResolution / 4);
    process_mode1_2();
    draw_xpm(Medium,mode_info.XResolution / 3, mode_info.YResolution / 2);
    process_mode2_2();
    draw_xpm(Hard,mode_info.XResolution / 3, 3 * mode_info.YResolution / 4);
    process_mode3_2();
}

Sprite **matrix;
Sprite *index_1;
Sprite *index_2;
bool *index_1_bool;
bool *index_2_bool;

int id1 = 0;
int id2 = 0;
int matrix_id1 = -1;
int matrix_id2 = -1;
bool button1Pressed = false;
bool button2Pressed = false;
bool button3Pressed = false;
bool button4Pressed = false;
bool auxiliar1Pressed = false;
bool auxiliar2Pressed = false;
int counter_cards = 0;
int random_position = 0;
int aux = 0;
int aux2 = 0;
int aux3 = 0;
int aux4 = 0;
int pre = 0;
int j = 0;
int k = 0;
int id_sprite1;
int id_sprite2;
int id_sprite3;
int id_sprite4;
int final = 0;
bool block1 = false;
bool block2 = false;
bool block3 = false;
bool block4 = false;
bool player1 = true;
bool player2 = false;
int player_1 = 0;
int player_2 = 0;
// game_2
bool cardPressed1 = false;
bool cardPressed2 = false;
bool cardPressed3 = false;
bool cardPressed4 = false;
bool cardPressed5 = false;
bool cardPressed6 = false;
bool cardPressed7 = false;
bool cardPressed8 = false;
bool cardBlock1 = false;
bool cardBlock2 = false;
bool cardBlock3 = false;
bool cardBlock4 = false;
bool cardBlock5 = false;
bool cardBlock6 = false;
bool cardBlock7 = false;
bool cardBlock8 = false;
int pre1 = 0;
int prato = 0;
// game_3
int pre2 = 0;
bool backPressed1 = false;
bool backPressed2 = false;
bool backPressed3 = false;
bool backPressed4 = false;
bool backPressed5 = false;
bool backPressed6 = false;
bool backPressed7 = false;
bool backPressed8 = false;
bool backPressed9 = false;
bool backPressed10 = false;
bool backPressed11 = false;
bool backPressed12 = false;
bool backPressed13 = false;
bool backPressed14 = false;
bool backPressed15 = false;
bool backPressed16 = false;
bool backBlock1 = false;
bool backBlock2 = false;
bool backBlock3 = false;
bool backBlock4 = false;
bool backBlock5 = false;
bool backBlock6 = false;
bool backBlock7 = false;
bool backBlock8 = false;
bool backBlock9 = false;
bool backBlock10 = false;
bool backBlock11 = false;
bool backBlock12 = false;
bool backBlock13 = false;
bool backBlock14 = false;
bool backBlock15 = false;
bool backBlock16 = false;
extern Sprite *victory;

int get_number(Sprite *cards, int size)
{

    int random_number = rand() % size;
    return random_number;
}
void shuffle(Sprite *cards, int size)
{
    srand(time(NULL));
    for (int i = size - 1; i >= 0; i--)
    {
        int j = rand() % (i + 1);
        Sprite temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

    matrix[0][0] = cards[0];
    matrix[0][1] = cards[1];
    matrix[1][0] = cards[2];
    matrix[1][1] = cards[3];
    // how can I compare the values  ?
    //  Compare all elements in the matrix
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            // Compare the current element to all other elements in the matrix
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    // If the current element is not being compared to itself and has the same id as another element,
                    // print a message indicating that there is a match
                    if (i != k || j != l)
                    {
                        if (matrix[i][j].id == matrix[k][l].id)
                        {
                            printf("Match found: matrix[%d][%d].id = %d and matrix[%d][%d].id = %d\n",
                                   i, j, matrix[i][j].id, k, l, matrix[k][l].id);
                        }
                    }
                }
            }
        }
    }
}

void shuffle2(Sprite *cards)
{
    int size = 8;

    srand(time(NULL));
    for (int i = size - 1; i >= 0; i--)
    {
        int j = rand() % (i + 1);
        Sprite temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
    matrix[0][0] = cards[0];
    matrix[0][1] = cards[1];
    matrix[0][2] = cards[2];
    matrix[0][3] = cards[3];
    matrix[1][0] = cards[4];
    matrix[1][1] = cards[5];
    matrix[1][2] = cards[6];
    matrix[1][3] = cards[7];

    // Printing the shuffled matrix
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matrix[i][j].id);
        }
        printf("\n");
    }
}

void shuffle3(Sprite *cards)
{
    int size = 16;

    srand(time(NULL));
    for (int i = size - 1; i >= 0; i--)
    {
        int j = rand() % (i + 1);
        Sprite temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
    matrix[0][0] = cards[0];
    matrix[0][1] = cards[1];
    matrix[0][2] = cards[2];
    matrix[0][3] = cards[3];
    matrix[1][0] = cards[4];
    matrix[1][1] = cards[5];
    matrix[1][2] = cards[6];
    matrix[1][3] = cards[7];
    matrix[2][0] = cards[8];
    matrix[2][1] = cards[9];
    matrix[2][2] = cards[10];
    matrix[2][3] = cards[11];
    matrix[3][0] = cards[12];
    matrix[3][1] = cards[13];
    matrix[3][2] = cards[14];
    matrix[3][3] = cards[15];

    // Printing the shuffled matrix
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matrix[i][j].id);
        }
        printf("\n");
    }
}

bool check_match(int id1, int id2)
{
    if (id1 == id2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// O menu do jogo é constituído por quatro botões

// O menu final é apenas um retângulo com tamanho máximo, com um smile ao centro
void draw_finish_menu()
{
    Sprite final[] = {*score0,*score1,*score2,*score3,*score4,*score5,*score6,*score7,*score8};
    printf("The value of player_1 is %d\n", player_1);
    printf("The value of player_2 is %d\n", player_2);
    memset(drawing_frame_buf, 0, mode_info.XResolution * mode_info.YResolution * mode_info.BitsPerPixel / 8);
        if(to_help == GAME || to_help == GAME_2 || to_help == GAME_3)
        {
            draw_xpm(victory,mode_info.XResolution / 3, 0);
            draw_xpm(player_1_menu,mode_info.XResolution / 3, mode_info.YResolution / 2); 
        }
        else if(to_help == GAME_2P || to_help == GAME_4_2P || to_help == GAME_8_2P){
        if(player_1 > player_2) { 
            draw_xpm(victory,mode_info.XResolution /2 ,0);
        }
        if(player_1 < player_2) { 
            draw_xpm(victory,mode_info.XResolution /2 ,mode_info.YResolution / 2);
        }
        draw_xpm(player_1_xpm, 0, 0);
        draw_xpm(&final[player_1], mode_info.XResolution / 3, 0);

        draw_xpm(player_2_xpm, 0, mode_info.YResolution / 2);
        draw_xpm(&final[player_2], mode_info.XResolution / 3, mode_info.YResolution / 2);}
}

void draw_mouse()
{
    switch (menuState)
    {
    case START:
    case END:
        draw_xpm(mouse, mouse_info_s.x, mouse_info_s.y);
        break;
    case GAME:
        draw_xpm(hand, mouse_info_s.x, mouse_info_s.y);
        break;
    case GAME_2P: 
        draw_xpm(hand,mouse_info_s.x,mouse_info_s.y);
        break;
    case GAME_2:
        draw_xpm(hand, mouse_info_s.x, mouse_info_s.y);
        break;
    case MODE:
        draw_xpm(mouse, mouse_info_s.x, mouse_info_s.y);
        break;
    case GAME_3:
        draw_xpm(hand, mouse_info_s.x, mouse_info_s.y);
        break;
    case GAME_4_2P:
        draw_xpm(hand, mouse_info_s.x, mouse_info_s.y);
        break;
    case GAME_8_2P:
        draw_xpm(hand, mouse_info_s.x, mouse_info_s.y);
        break;
    case SEL_P:
        draw_xpm(mouse, mouse_info_s.x, mouse_info_s.y);
        break;
    case MODE_2:
        draw_xpm(mouse, mouse_info_s.x, mouse_info_s.y);
        break;
    }
}

int draw_xpm(Sprite *sprite, int x, int y)
{
    uint16_t height = sprite->height;
    uint16_t width = sprite->width;
    uint32_t current_color;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            current_color = sprite->colors[w + h * width];
            if (current_color == TRANSPARENT)
                continue;
            if (draw_pixel_in_coor(x + w, y + h, current_color, drawing_frame_buf) != 0)
                return 1;
        }
    }
    return 0;
}

int draw_sprite_button(Sprite *sprite, int x, int y)
{
    uint16_t height = sprite->height;
    uint16_t width = sprite->width;
    uint32_t color = sprite->color;

    if (menuState == START)
    {
        if (sprite->pressed == 1)
        {
            if (mouse_info_s.x > 0 && mouse_info_s.x < mode_info.XResolution / 2 && mouse_info_s.y > 0 && mouse_info_s.y < mode_info.YResolution / 2)
            {
                menuState = START;
            }
            else if (mouse_info_s.x > mode_info.XResolution / 2 && mouse_info_s.x < mode_info.XResolution && mouse_info_s.y > 0 && mouse_info_s.y < mode_info.YResolution / 2)
            {
                menuState = GAME;
            }
            else if (mouse_info_s.x > 0 && mouse_info_s.x < mode_info.XResolution / 2 && mouse_info_s.y > mode_info.YResolution / 2 && mouse_info_s.y < mode_info.YResolution)
            {
                menuState = GAME_2;
            }
            else if (mouse_info_s.x > mode_info.XResolution / 2 && mouse_info_s.x < mode_info.XResolution && mouse_info_s.y > mode_info.YResolution / 2 && mouse_info_s.y < mode_info.YResolution)
            {
                systemState = EXIT;
            }
        }
    }
    

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            if (draw_pixel_in_coor(x + w, y + h, color, drawing_frame_buf) != 0)
                return 1;
        }
    }
    return 0;
}

void rtc_print()
{
    printf("NOW: %d/%d/%d @%d:%d:%d\n", 2000 + time_mode_info.year, time_mode_info.month, time_mode_info.day, time_mode_info.hours, time_mode_info.minutes, time_mode_info.seconds);
}

void animation_trigger(Sprite *card, int x, int y)
{
    switch (card->state)
    {
    case 0:
        draw_xpm(back, x, y);
        break;
    case 1:
        draw_xpm(back_anim1, x, y);
        card->state = 2;
        break;
    case 2:
        draw_xpm(back_anim2, x, y);
        card->state = 3;
        break;
    case 3:
        draw_xpm(back_anim3, x, y);
        card->state = 4;
        break;
    case 4:
        draw_xpm(back_anim4, x, y);
        card->state = 5;
        break;
    case 5:
        draw_xpm(card, x, y);
        break;
    }
}
