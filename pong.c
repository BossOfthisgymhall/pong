#include <stdio.h>
#define visot 26
#define shir 80

void print_field();
void print_players();
void game();

int main(){
    int player_1 = 13;
    int player_2 = 13;

    game(player_1, player_2);
    return 0;
}


void print_field(int player_1, int player_2, int x_ball, int y_ball, int score_player_1, int score_player_2){
    int i, j;    
    for(i = 0; i <= visot; i++){
        for(j = 0; j <= shir; j++){
            if(i == 0 || i == visot - 1) // рисую верхнюю и нижнюю границу поля
            {
                printf("#");
            }
            else if (j == x_ball && i == y_ball){ // рисуем мяч
                printf("*");
            }
            else if((((player_1 >= i && player_1 <= i)) || (player_1 + 1 >= i && player_1 + 1 <= i) || 
                    (player_1 - 1 >= i && player_1 - 1 <= i)) && j == 1)  //первый игрок
            {
                printf("]");
            }
            else if((((player_2 >= i && player_2 <= i)) || (player_2 + 1 >= i && player_2 + 1 <= i) || 
                    (player_2 - 1 >= i && player_2 - 1 <= i)) && j == shir - 1)//второй игрок
            {
                printf("[");
            }
            else if(i == 26 && (j == 20)){
                printf("%d", score_player_1);
            }
            else if(i == 26 && j == 60){
                printf("%d", score_player_2);
            }
            else{
                printf(" ");
            }
        }
        printf("\n"); // обязательно перенос строки
    }
    // printf("%d\n%d\n", player_1, player_2);
}
void game(int player_1, int player_2){
    int end_game_flag = 1;
    int x_ball = shir / 2;
    int y_ball = visot / 2;
    int flag = 0;
    int x_ball_prev = x_ball;
    int y_ball_prev = y_ball;  
    int score_player_1 = 0;
    int score_player_2 = 0;
    while (end_game_flag) // дописать нормальные условия для завершения игры
    {
        print_field(player_1, player_2, x_ball, y_ball, score_player_1, score_player_2);
        char move;
        scanf("%c", &move);
        if((player_1 > 2 && player_1 < 24) || (player_2 > 2 && player_2 < 24)) // проблема с краем поля, нужно переделать
        {
            switch(move){
                case 'a': player_1--; break;
                case 'z': player_1++; break;
                case 'k': player_2--; break;
                case 'm': player_2++; break;
                case 'e': end_game_flag = 0; break;
                default: break;
            }
        }
        if((x_ball <= shir && x_ball >= 0) && ((y_ball == visot - 2) && (x_ball - 1 == x_ball_prev))){ //условия для отскока от пола слева направо | 
           flag = 1;
        }
        else if((x_ball <= shir && x_ball >= 0) && ((y_ball == visot - 2) && (x_ball + 1 == x_ball_prev))){  //условия для отскока от пола справа налево | 
           flag = 3;
        }
        else if((x_ball == (shir - 1) && ((y_ball == player_2 || y_ball == player_2 + 1 || y_ball == player_2 - 1)) && (y_ball_prev == y_ball - 1))){  //условия для отскока от игрока 2 сверху вниз |
            flag = 2;
        }
        else if(((x_ball == (shir - 1) && (y_ball == player_2 || y_ball == player_2 + 1 || y_ball == player_2 - 1)) && (y_ball_prev == y_ball + 1))){ //условия для отскока от игрока 2 снизу вверх | 
            flag = 3;
        }
        else if((x_ball <= shir && x_ball >= 0) && ((y_ball == 1) && (x_ball - 1 == x_ball_prev))){ //условия для отскока от потолка слева направо | 
            flag = 0;
        }
        else if((x_ball <= shir && x_ball >= 0) && ((y_ball == 1) && (x_ball + 1 == x_ball_prev))){ //условия для отскока от потолка справа налево | 
            flag = 2;
        }
        else if((x_ball == 1) && ((y_ball == player_1 || y_ball == player_1 + 1 || y_ball == player_1 - 1) && (y_ball_prev == y_ball - 1))){ //условия для отскока от игрока 1 сверху вниз |
            flag = 1;
        }
        else if(((x_ball == 1) && ((y_ball == player_1 || y_ball == player_1 + 1 || y_ball == player_1 - 1)) && (y_ball_prev == y_ball + 1))){ //условия для отскока от игрока 1 снизу вверх |
            flag = 1;
        }
        else if(x_ball > shir){
            flag = 4;
            score_player_1++;
        }
        else if(x_ball < 0)
        {
            flag = 4;
            score_player_2++;
        }
        printf("%d %d\n%d %d\n", x_ball, y_ball, x_ball_prev, y_ball_prev);
        x_ball_prev = x_ball;
        y_ball_prev = y_ball;
        if(flag == 0) // вправо вниз
        {
            x_ball++;
            y_ball++;
        }
        else if(flag == 1){ //вправо вверх
            x_ball++;
            y_ball--;
        }
        else if(flag == 2){ // влево вниз
            x_ball--;
            y_ball++;
        }
        else if(flag == 3){ // влево вверх
            x_ball--;
            y_ball--;
        }
        else if(flag == 4){
            x_ball = shir / 2;
            y_ball = visot / 2;
            flag = 0;
        }
    }
}
