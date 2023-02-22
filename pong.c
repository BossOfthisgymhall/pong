#include <stdio.h>
#define shir 25
#define visot 80

void print_field();
void print_players();
void game_rules();

int main(){
    
    print_field();
    return 0;
}


void print_field(){
    for(int i = 0; i <= shir; i++){
        for(int j = 0; j <= visot; j++){
            if(i == 0 || i == shir)
            {
                printf("#");
            }
            else if(j == 0 || j == visot){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
void print_players(){
    char move;
    int move_ball = 0;
    scanf("%c", &move);
    switch(move){
        case "a": ball++; break;
        case "z": ball--; break;
        case "k": ball++; break;
        case "m": ball--; break;
    }
}
