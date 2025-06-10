#include <math.h>
#include "rotation.h"

float rotation_x(float angle, float x , float y){
    return x * cos(angle) - y * sin(angle);
}

float rotation_y(float angle, float x , float y){
   return x * sin(angle) + y * cos(angle);
}