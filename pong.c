#include <stdio.h>
#define visot 25
#define shir 80

void print_field();
int move_players(int player_1, int player_2);
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
            print_players(i, j);
        }
        printf("\n");
    }
}

void print_players(int i, int j){
    int player_1 = 13;
    int player_2 = 13;
    if((i >= player_1) && j == 1)
    {
        printf("]");
    }
    else if((i >= player_2) && j == shir - 1){
        printf("[");
    }
    move_players(player_1, player_2);
}
int move_players(int player_1, int player_2){
    char move;
    int flag = 1;
    move = getchar();
        switch(move){
            case 'a': return player_1++; break;
            case 'z': return player_1--; break;
            case 'k': return player_2++; break;
            case 'm': return player_2--; break;
            default: break;
    }
    return flag;
}
void game(){
    char move;
    move = getchar();
    int end_game_flag = 1;
    while (end_game_flag != 10)
    {
        print_field();
        end_game_flag++;
    }
}
