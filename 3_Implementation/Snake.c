/**
 * @file Snake.c
 * @author your Aniket (garganiket58@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "unity.h"
#include "unity_internals.h"
#include <conio.h>
#include <stdbool.h>
bool gameover;
const int width=20;			// width of rectangle
const int height=20;		// height of rectangle
int x,y,fruitx,fruity,score;
enum eDirection { STOP=0,LEFT,RIGHT,UP,DOWN};
enum eDirection dir;		// dir is used to represent direction of snake to move
int result;
void setup()
{
	gameover = false;		
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitx=rand()%width;		// randomly set the x coordinate of fruit
	fruity=rand()%height;		// randomly set the y coordinate of fruit
	score=0;					// shows the score count
}
/**
 * @brief 
 * draw() function is used to draw rectangle within which the snake can move
 * @return * void 
 */
void draw()
{
	system("cls");
	for(int i=0;i<width;i++)
		printf("#");							// border is represented as hash(#)
	printf("\n");
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0||j==width-1)
				printf("#");					// border is represented as hash(#)
			if(i==y && j==x)
				printf("O");					// snake is represented as O
			else if(i==fruity && j==fruitx)
				printf("F");					// fruit is represented as F
			else
				printf(" ");
		}
		printf("\n");
	}
	for(int i=0;i<width;i++)
	{
		printf("#");							// border is represented as hash(#)
	}
	printf("\n");
	printf("score : %d\n",score);					// score gets printed
}
/**
 * @brief 
 * input() function is used to move snake in different directions
 * @return * void 
 */
void input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
		case 'a':								// To move left press A
			dir=LEFT;							// moves snake in left direction 
			break;
		case 'd':								// To move right press D
			dir=RIGHT;							// moves snake in right direction
			break;
		case 'w':								// To move up press W
			dir=UP;								// moves snake in up direction
			break;
		case 's':								// To move down press S
			dir=DOWN;							// moves snake in down direction
			break;
		case 'x':								// To end the game press X
			gameover=true;						// sets the value of gameover to 'true' and the game ends
			break;
		}
	}
}
/**
 * @brief 
 * logic() function is used when we want to perform a task when player moves the snake to different directions
 * @return * void 
 */
void logic()
{
	switch(dir)
	{
	case LEFT:									// when player presses A to move to left
		x--;									// when moves left, x is decremented by 1
		break;
	case RIGHT:									// when player presses D to move to right
		x++;									// when moves right, x is incremented by 1
		break;
	case UP:									// when player presses W to move to up
		y--;									// when moves up, y is decremented by 1
		break;
	case DOWN:									// when player presses S to move to down
		y++;									// when moves down, y is incremented by 1
		break;
	}
	if(x>width || x<0 || y>height || y<0)
		gameover=true;
	if(x==fruitx && y==fruity)
	{
		score+=10;								// 10 is added if snake eats a fruit
		fruitx=rand()%width;					// randomly set the x coordinate of fruit
		fruity=rand()%height;					// randomly set the y coordinate of fruit
	}
	result=score;
}
int check_result1(int minscore1)
{
	if(result!=minscore1)						// minscore1 is 10 from test_snake.c file
		return result;
	return result;
}
int check_result2(int minscore2)
{
	if(result!=minscore2)						// minscore1 is 50 from test_snake.c file
		return result;
	return result;
}
int check_result3(int minscore3)
{
	if(result!=minscore3)						// minscore1 is 100 from test_snake.c file
		return result;
	return result;
}
