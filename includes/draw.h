#ifndef RENDER_H
#define RENDER_H

#define high 30
#define weight 60

void clear(char screen[high][weight]);
void draw(char screen[high][weight], float angle_x, float angle_y);
void printing(char screen[high][weight]);

#endif