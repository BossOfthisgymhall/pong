#include <stdio.h>
#define visot 25
#define shir 80

void print_field();
void game_rules();
void print_players();
void game();
int situation_1();
int situation_2();
int situation_3();
int situation_4();

int main(){
    int player_1 = 13;
    int player_2 = 13;

    game(player_1, player_2);
    return 0;
}


void print_field(int player_1, int player_2, int x_ball, int y_ball){
    int i, j;    
    for(i = 0; i <= visot; i++){
        for(j = 0; j <= shir; j++){
            if(i == 0 || i == visot)
            {
                printf("#");
            }
            else if (j == x_ball && i == y_ball){
                printf("*");
            }
            else if((((player_1 >= i && player_1 <= i)) || (player_1 + 1 >= i && player_1 + 1 <= i) || 
                    (player_1 - 1 >= i && player_1 - 1 <= i)) && j == 2)
            {
                printf("]");
            }
            else if((((player_2 >= i && player_2 <= i)) || (player_2 + 1 >= i && player_2 + 1 <= i) || 
                    (player_2 - 1 >= i && player_2 - 1 <= i)) && j == shir - 2)
            {
                printf("[");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("%d\n%d\n", player_1, player_2);
}
void game(int player_1, int player_2){
    int end_game_flag = 1;
    int x_ball = shir / 2;
    int y_ball = visot / 2;
    int flag = 0;
    while (end_game_flag != 100)
    {
        print_field(player_1, player_2, x_ball, y_ball);
        // printf("%d\n%d\n", x_ball, y_ball);
        char move;
        scanf("%c", &move);
        switch(move){
            case 'a': player_1++; break;
            case 'z': player_1--; break;
            case 'k': player_2++; break;
            case 'm': player_2--; break;

            default: break;
        }
        end_game_flag++; // временное условие для проверки работы
        // move_ball(x_ball, y_ball);
        if((x_ball <= shir && x_ball >= 0) && (y_ball <= visot && y_ball >= 0))
        {
            x_ball++;
            y_ball++;
        }
        printf("%d\n%d\n", x_ball, y_ball);
    }
}


int situation_1(int x_ball, int y_ball, int flag){
    if((x_ball <= shir && x_ball >= 0) && y_ball == visot){
        flag = 1;
    }
    return flag;
}
int situation_2(int x_ball, int y_ball, int flag){
    
}
