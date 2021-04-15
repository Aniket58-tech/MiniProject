#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
bool gameover;
const int width=20;
const int height=20;
int x,y,fruitx,fruity,score;
enum eDirection { STOP=0,LEFT,RIGHT,UP,DOWN};
enum eDirection dir;
void setup()
{
	gameover = false;
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitx=rand()%width;
	fruity=rand()%height;
	score=0;
}
void draw()
{
	system("cls");
	for(int i=0;i<width;i++)
		printf("#");
	printf("\n");
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0||j==width-1)
				printf("#");
			if(i==y && j==x)
				printf("O");
			else if(i==fruity && j==fruitx)
				printf("F");
			else
				printf(" ");
		}
		printf("\n");
	}
	for(int i=0;i<width;i++)
	{
		printf("#");
	}
	printf("\n");
	printf("score : \n",score);
}
void input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
		case 'a':
			dir=LEFT;
			break;
		case 'd':
			dir=RIGHT;
			break;
		case 'w':
			dir=UP;
			break;
		case 's':
			dir=DOWN;
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
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if(x>width || x<0 || y>height || y<0)
		gameover=true;
	if(x==fruitx && y==fruity)
	{
		score+=10;
		fruitx=rand()%width;
		fruity=rand()%height;
	}
}
int main()
{
	setup();
	while(!gameover)
	{
		draw();
		input();
		logic();
	}
	return 0;
}
