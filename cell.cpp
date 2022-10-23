#include <graphics.h>

#include "lib.h"


void print_cell(int map[ROW][COL], bool state[ROW][COL], bool flag[ROW][COL], int i, int j)
{
	if (state[i][j] && !flag[i][j])
	{
		if (map[i][j] == 0)
		{
			print_cell_empty(j*30, i*30);
		}
		else if (map[i][j] == MINE)
		{	
			print_cell_mine(j*30, i*30, 0);
		}
		else
		{
			int value = map[i][j];
			int color;
			
			if (value == 1)
				color = 3;
			else if (value == 2)
				color = 6;
			else if (value == 3)
				color = 12;
			else if (value == 4)
				color = 4;
			else
				color = 1;
			
			print_cell_value(j*30, i*30, value);
		}
	}
}

void print_cell_empty(int x, int y)
{
	moveto(x, y);
	
	setcolor(0);
	rectangle(x, y +45, x+30, y+30 +45);
	
	setfillstyle(1, 7);
	bar(x+1, y+1 +45, x+30-1, y+30-1 +45);
}

void print_cell_mine(int x, int y, int boom)
{
	print_cell_empty(x, y);
	
	if (boom)
	{
		setfillstyle(1, 12);
		bar(x+1, y+1+45, x+30 -1, y+30 -1 +45);
		
	}
	
	
	setcolor(0);
	circle(x+15, y+15 +45, 9);
	setfillstyle(1, 0);
	floodfill(x+15, y+15 +45, 0);
	
	line(x+7, y+5 +45, x+24, y+23 +45);
	line(x+7, y+23 +45, x+23, y+6 +45);
	
	bar(x+4, y+14 +45, x+10+16, y+16+1 +45);
	bar(x+14, y+4+ 45, x+16+1, y+10+16 +45);
	
	setcolor(15);
	circle(x+12, y+12+45, 2);
	setfillstyle(1, 15);
	floodfill(x+12, y+12+45, 15);
}


void print_cell_off(int x, int y)
{
	moveto(x, y);
	setcolor(8);
	rectangle(x, y +45, x+30, y+30 +45);
	line(x, y+30 +45, x+30, y+45);
	
	setfillstyle(1, 15);
	floodfill(x+1, y+1 +45, 8);
	
	setfillstyle(1, 8);
	floodfill(x+30-1, y+30-1 +45, 8);
	
	setfillstyle(1, 7);
	int temp = 5;
	bar(x+temp, y+temp +45,x+30-temp, y+30-temp +45);
}

void print_cell_value(int x, int y, int value)
{
	print_cell_empty(x, y);
	setbkcolor(7);
	settextstyle(0, 0, 3);
				
	int color;
	if (value == 1)
		color = 1;
	else if (value == 2)
		color = 2;
	else if (value == 3)
		color = 12;
	else if (value == 4)
		color = 4;
	else
		color = 0;
	setcolor(color);
		
	char s[2] = "0";
	s[0] = value+48;
	outtextxy(x+3, y+3 +45, s);
}

void print_flag(int x, int y)
{
	setfillstyle(1, 0);
	bar(x+ 18, y+ 7 +45, x+ 19, y+23 +45);
	bar(x+ 14, y+21 +45, x+23 , y+23 +45);
	
	setcolor(0);
	line(x + 10, y+12 +45, x+18, y+7 +45);
	line(x+10, y+12 +45, x+18, y+18 +45);
	setfillstyle(1, 12);
	floodfill(x+10+2, y+12 +45, 0);
}

void print_map(int map[ROW][COL], bool state[ROW][COL], bool flag[ROW][COL], int x, int y)
{
	int i, j;
	
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (flag[i][j])
			{
				setcolor(4);
				line(j*30, i*30 +45, j*30+30, i*30+30 +45); // \ .
				
				line(j*30, i*30+30 +45, j*30+30, i*30 +45); // /
			}
			else if (state[i][j])
			{
				if (map[i][j] == 0)
				{
					print_cell_empty(j*30, i*30);
				}
				else if (map[i][j] == MINE)
				{	
					int boom = 0;
					if (i == x && j == y)
					{
						boom = 1;
					}
					print_cell_mine(j*30, i*30, boom);
				}
				else
				{
					int value = map[i][j];
					print_cell_value(j*30, i*30, value);
				}
			}
		}
	}
}
