#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "draw.h"

int main(void){
    printf("\e[?25l");
    system("cls||clear");
    char screen[high][weight];
    clear(screen);
    //////////////////////////
    float angle_x = M_PI / 6;
    float angle_y = M_PI / 6;
    while (1) {
        
        clear(screen);
        draw(screen, angle_x, angle_y);
        printf("\033[H");
        printing(screen);
        usleep(3000);
        angle_y += 0.01;
        angle_x += 0.05;
        if (angle_x > 2 * M_PI) angle_x -= 4 * M_PI;
        if (angle_y > 2 * M_PI) angle_y -= 4 * M_PI;
    }
    printf("\e[?25h");
    return 0;
}