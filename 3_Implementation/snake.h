#include <stdbool.h>
#ifndef __SNAKE_H__
#define __SNAKE_H__
extern bool gameover;
void setup();
void draw();
void input();
void logic();
int check_result1(int);
int check_result2(int);
int check_result3(int);
#endif