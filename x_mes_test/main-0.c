#include <stdio.h>
#include <math.h>

float rotation_x(float angle, float x , float y){
    float x1 = x*cos(angle) - y*sin(angle);
    return x1;
}

float rotation_y(float angle, float x , float y){
    float y1 = x*sin(angle) + y*cos(angle);
    return y1;
}

int main(){
    float x1 = rotation_x(-M_PI/4, 1, 0);
    float y1 = rotation_y(-M_PI/4, 1, 0);
    printf("%.2f %.2f\n", x1, y1);
    return 0;
}