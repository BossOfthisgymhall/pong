#include <stdio.h>
#define visot 25
#define shir 80

void print_field();
void game_rules();
void print_players();
void game();
void move_ball();

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
                printf("-");
            }
            else if (j == x_ball && i == y_ball){
                printf("*");
            }
            else{
                printf(" ");
            }
            print_players(i, j, player_1, player_2);
        }
        printf("\n");
    }
    printf("%d\n%d\n", player_1, player_2);
}

void print_players(int i, int j, int player_1, int player_2){
    if((player_1 >= i && player_1 <= i) && j == 1)
    {
        printf("]");
    }
    else if((player_2 >= i && player_2 <= i) && j == shir - 1){
        printf("[");
    }
}

void game(int player_1, int player_2){
    int end_game_flag = 1;
    int x_ball = shir / 2;
    int y_ball = visot / 2;
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
        move_ball(x_ball, y_ball);
        end_game_flag++; // временное условие для проверки работы
    }
}
void move_ball(int *x_ball, int *y_ball){
    if((shir >= *x_ball) && (visot >= *y_ball)){
        x_ball++;
        y_ball++;
    }
}
//      else if((x_ball >= i && x_ball <= i) && (y_ball >=j && y_ball <= j)){
//         x_ball--;
//         y_ball--;
//     }
//      else if((x_ball >= i && x_ball <= i) && (y_ball >=j && y_ball <= j)){
//         x_ball++;
//         y_ball--;
//     }
//      else if((x_ball >= i && x_ball <= i) && (y_ball >=j && y_ball <= j)){
//         x_ball--;
//         y_ball++;
//     }
// }
