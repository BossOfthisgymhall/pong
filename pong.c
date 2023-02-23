#include <stdio.h>
#define visot 25
#define shir 80

void print_field();
void move_players();
void game_rules();
void print_players();

int main(){
    
    print_field();
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
            // else if(j == 0 || j == shir){
            //     printf("#");
            // }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

// void move_players(){
//     char move;
//     int move_ball = 0;
//     scanf("%c", &move);
//     switch(move){
//         case "a": move_ball++; break;
//         case "z": move_ball--; break;
//         case "k": move_ball++; break;
//         case "m": move_ball--; break;
//         default: break;
//     }
// }
void print_players(int i, int j){
    if(i == 13 && (j == 1 || j == shir - 2))
    {
        printf("|");
    }
}
