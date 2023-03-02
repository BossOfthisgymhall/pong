#include <stdio.h>
#define visot 25
#define shir 80

void print_field();
void game_rules();
void print_players();
void game();

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
                    (player_1 - 1 >= i && player_1 - 1 <= i)) && j == 1)
            {
                printf("]");
            }
            else if((((player_2 >= i && player_2 <= i)) || (player_2 + 1 >= i && player_2 + 1 <= i) || 
                    (player_2 - 1 >= i && player_2 - 1 <= i)) && j == shir - 1)
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
    int x_ball_prev = x_ball - 1, y_ball_prev = y_ball - 1;
    while (end_game_flag != 100)
    {
        print_field(player_1, player_2, x_ball, y_ball);
        char move;
        scanf("%c", &move);
        switch(move){
            case 'a': player_1--; break;
            case 'z': player_1++; break;
            case 'k': player_2--; break;
            case 'm': player_2++; break;

            default: break;
        }
        if((x_ball <= shir && x_ball >= 0) && y_ball == visot - 1){
           flag = 1;
        }
        // else if((y_ball <= visot && y_ball >= 0) && (x_ball == player_2 ||
        //  x_ball == player_2 -1 || x_ball == player_2 + 1 )){
        //    flag = 2;
        // }
        else if((x_ball == shir - 1 && x_ball >= 0) && (y_ball == player_2 || y_ball == player_2 + 1 || y_ball == player_2 - 1)){
            flag = 2;
        }
        else if((x_ball <= shir && x_ball >= 0) && (y_ball == 1)){
            flag = 3;
        }

        printf("%d\n%d\n%d\n", x_ball, y_ball, flag);
        if(flag == 0)
        {
            x_ball++;
            y_ball++;
        }
        else if(flag == 1){
            x_ball++;
            y_ball--;
        }
        else if(flag == 2){
            x_ball--;
            y_ball++;
        }
        else if(flag == 3){
            x_ball--;
            y_ball--;
        }
    }
}
