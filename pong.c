#include <stdio.h>
#define visot 25
#define shir 80

void print_field();
void move_players(int i, int j);
void game_rules();
void print_players(int i, int j);
void game();

int main(){
    
    game();
    return 0;
}


void print_field(){
    int i, j;
    for(i = 0; i <= visot; i++){
        for(j = 0; j <= shir; j++){
            if(i == 0 || i == visot)
            {
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

void move_players(int i, int j){   
    if(i == 13 && (j == 1 || j == shir -1))
    {
        printf("|");
    }
    char move;
    move = getchar();
    // int move_ball_player_1 = i;
    // int move_ball_player_2 = i;
    // move = getchar();
    // switch(move){
    //     case 'a': move_ball_player_1++; break;
    //     case 'z': move_ball_player_1--; break;
    //     case 'k': move_ball_player_2++; break;
    //     case 'm': move_ball_player_2--; break;
    //     default: break;
    // }
}
void game(){
    int end_game_flag = 1;
    while (end_game_flag != 10)
    {
        print_field();
        end_game_flag++;
    }
}
