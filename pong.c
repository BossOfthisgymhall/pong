#include <stdio.h>
#define x_size 80
#define y_size 25


void print_field();
void print_players();
void game_rules();

int main(){
    
    print_field();
    return 0;
}


void print_field()
{
    for(int i = 0; i <= x_size; i++)
    {
        for(int j = 0; j < y_size; j++)
        {
            if(i == 0 || i == x_size)
            {
                printf("#");
            }
            else if(j == 0 || j == y_size)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
    }
}
