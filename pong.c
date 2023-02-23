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
            if(i == 0 || i == visot)
            {
                printf("#");
            }
            else if(j == 0 || j == shir){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

void move_players(){             //добавить в main
    char move;
    int move_ball = 0;
    scanf("%c", &move);
    switch(move){
        case "a": ball++; break;
        case "z": ball--; break;
        case "k": ball++; break;
        case "m": ball--; break;
        default: break;
    }
}
//void print_players(){
//    
//}
