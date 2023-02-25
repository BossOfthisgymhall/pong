#include <stdio.h>
#define visot 25
#define shir 80

void print_field();
int move_players(char move);
void game_rules();
void print_players(int i, int j, int player_1, int player_2);
void game(int player_1, int player_2);

int main(){
    int player_1 = 13;
    int player_2 = 13;
    game(player_1, player_2);
    return 0;
}


void print_field(int player_1, int player_2){
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
            print_players(i, j, player_1, player_2);
        }
        printf("\n");
    }
    char move;
    move = getchar();
    move_players(move);
    player_1 = player_1 + move_players(move);
    // move_players(player_1, player_2);
    // char move;
    // move = getchar();
    // switch(move){
    //     case 'a': printf("%d\n",player_1++); break;
    //     case 'z': printf("%d\n",player_1--); break;
    //     case 'k': printf("%d\n",player_2++); break;
    //     case 'm': printf("%d\n",player_2--); break;
    //     default: break;
    // }
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
int move_players(char move){
    switch(move){
        case 'a': return 1; break;
        case 'z': return -1; break;
        default: return 0; break;
    }
}

void game(int player_1, int player_2){
    int end_game_flag = 1;
    while (end_game_flag != 100)
    {
        print_field(player_1, player_2);
        end_game_flag++;
    }
}
