#include <stdio.h>
#define visot 25
#define shir 80

void print_field();
void move_players(int i);
void game_rules();
void print_players(int i, int j);
void game();

int main(){
    
    game();
    return 0;
}


void print_field(){
    for(int i = 0; i <= visot; i++){
        for(int j = 0; j <= shir; j++){
            print_players(i, j);
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

void move_players(int i){
    char move;
    int move_ball_player_1 = i;
    int move_ball_player_2 = i;
    scanf("%c", &move);
    switch(move){
        case 'a': move_ball_player_1++; break;
        case 'z': move_ball_player_1--; break;
        case 'k': move_ball_player_2++; break;
        case 'm': move_ball_player_2--; break;
        default: break;
    }
}
void print_players(int i, int j){
    if(i == 13 && (j == 1 || j == shir - 2))
    {
        printf("|");
    }
}
void game(){
    int end_game_flag = 1;

    do{
        print_field();
        move_players();
    }while(end_game_flag);
}
