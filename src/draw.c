#include <stdio.h>
#include <math.h>
#include "draw.h"
#include "rotation.h"

void clear(char screen[high][weight]){
    for (int i = 0; i < high; i++)
        for (int j = 0; j < weight; j++)
            screen[i][j] = ' ';
}

void draw(char screen[high][weight], float angle_x, float angle_y){
    float R = 10;
    float r = 4;
    char chars [] = "$@^#!*-+<=.&:?,~>";
    
    for (float theta = 0; theta < 2 * M_PI; theta += 0.1){
        for (float phi = 0; phi < 2 * M_PI; phi += 0.1){
            float rot_x = rotation_x(angle_x, (R + r * cos(theta)) * sin(phi), r * sin(theta));
            float rot_y = rotation_y(angle_x, (R + r * cos(theta)) * sin(phi), r * sin(theta));
            float rot_z = rotation_y(angle_y, (R + r * cos(theta)) * cos(phi), rot_x);
            float final_x = rotation_x(angle_y, (R + r * cos(theta)) * cos(phi), rot_x);

            int screen_x = (int)(weight / 2 + final_x * 2.0);
            int screen_y = (int)(high / 2 + rot_y);

            if (screen_x >= 0 && screen_x < weight && screen_y >= 0 && screen_y < high) {
                screen[screen_y][screen_x] = chars[(int)(theta * 10) % 17];
            }
        }
    }
}

void printing(char screen[high][weight]){
    for (int i = 0; i < high; i++) {
        for (int j = 0; j < weight; j++) {
            printf("\033[1;33m%c\033[0m", screen[i][j]);
        }
        putchar('\n');
    }
}