#include<stdio.h>
#include<math.h>
#include <unistd.h>
#include <stdlib.h>

#define high 30
#define weight 60

float rotation_x(float angle, float x , float y){
    float x1 = x*cos(angle) - y*sin(angle);
    return x1;
}
float rotation_y(float angle, float x , float y){
   float y1 = x*sin(angle) + y*cos(angle);
   return y1;
}

void rotation(char screen[high][weight], float angle){
    float r = 10;

    for (float theta = 0; theta < 2*M_PI; theta += 0.05){
        int screen_x =(int)( weight/2+rotation_x(angle, r*cos(theta), r*sin(theta))*2.0 );
        int screen_y =(int)( high/2+rotation_y(angle, r*cos(theta), r*sin(theta)) );
        if (screen_x >= 0 && screen_x < weight && screen_y >= 0 && screen_y < high) {
            screen[screen_y][screen_x] = '#';
        }
    }
}

void printing(char screen[high][weight]){
    for (int i = 0; i < high; i++) {
        for (int j = 0; j < weight; j++) {
            putchar(screen[i][j]);
        }
        putchar('\n');
    }
}


void clear_screen(char screen[high][weight]){
    for (int i = 0; i < high; i++)
        for (int j = 0; j < weight; j++)
            screen[i][j] = ' ';
}

int main(){
    char screen[high][weight];
    clear_screen(screen);
    ////////////////////////////////////////
    rotation(screen);
    ////////////////////////////////////////
    printing(screen);
    return 0;   
}