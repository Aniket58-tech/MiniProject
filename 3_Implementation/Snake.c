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
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
bool gameover;
const int width=20;			// width of rectangle
const int height=20;		// height of rectangle
int x,y,fruitx,fruity,score;
enum eDirection { STOP=0,LEFT,RIGHT,UP,DOWN};
enum eDirection dir;		// dir is used to represent direction of snake to move
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
	printf("score : \n",score);					// score gets printed
}
void input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
		case 'a':
			dir=LEFT;							// moves snake in left direction 
			break;
		case 'd':
			dir=RIGHT;							// moves snake in right direction
			break;
		case 'w':
			dir=UP;								// moves snake in up direction
			break;
		case 's':
			dir=DOWN;							// moves snake in down direction
			break;
		case 'x':
			gameover=true;
			break;
		}
	}
}
void logic()
{
	switch(dir)
	{
	case LEFT:
		x--;									// when moves left x is decremented by 1
		break;
	case RIGHT:
		x++;									// when moves left x is incremented by 1
		break;
	case UP:
		y--;									// when moves left y is decremented by 1
		break;
	case DOWN:
		y++;									// when moves left y is incremented by 1
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
}
int main()
{
	setup();
	while(!gameover)							// runs until gameover has true value 
	{
		draw();
		input();
		logic();
	}
	return 0;
}
