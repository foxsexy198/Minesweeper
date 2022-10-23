#include <graphics.h>

#include "lib.h"

void init(int map[ROW][COL], bool state[ROW][COL], bool flag[ROW][COL])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			map[i][j] = 0;
			state[i][j] = false;
			flag[i][j] = false;
		}
	}
	
	setfillstyle(1, 15);
	bar(0, 9, 12*30+2, 16*30+1+45);
	floodfill(1, 1, 9);
	
	int temp = 5;
	
	setcolor(15);
	rectangle(0, 1, 12*30, 45-2);
	floodfill(temp+1, 1+temp+1, 15);
	
	setcolor(0);
	rectangle(0, 1, 12*30, 45-1);
	rectangle(0+temp, 1+temp, 12*30 - temp, 45-1 -temp);
	
	setfillstyle(1, 7);
	floodfill(temp+1, 1+temp+1, 0);
	
	smile(181, 23);
	
	setcolor(7);
	rectangle(8*30+1, -38 +45, 8*30+1+30, -38+30 +45);
	
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 16; j++)
		{
			int x = i*30;
			int y = j*30;
			
			setcolor(0);
			rectangle(x, y +45, x+30, y+30 +45);
			line(x, y+30 +45, x+30, y+45);
			
			setfillstyle(1, 15);
			floodfill(x+1, y+1 +45, 0);
			
			setfillstyle(1, 8);
			floodfill(x+30-1, y+30-1 +45, 0);
			
			setcolor(8);
			line(x, y+30 +45, x+30, y+45);
			
			setfillstyle(1, 7);
			temp = 5;
			bar(x+temp, y+temp +45,x+30-temp, y+30-temp +45);
		}	
	}
}

void init_mines(int map[ROW][COL], int k, int r, int c, bool is_inited)
{
	if (!is_inited)
	{
		random_mine(map, k, r, c);
		count_mines(map);
	}
}

void is_lose()
{
	setcolor(0);
	settextstyle(0, 0, 2);
	outtextxy(15, 15, (char*)"You Lose!");
	sadface(181, 23);
}

int is_restart(int r, int c)
{
	return top_restart <= r && r <= bottom_restart && left_restart <= c && c <= right_restart;
}

int is_note_mode(int r, int c)
{
	return top_mode < r && r <= bottom_mode && left_mode <= c && c <= right_mode;
}

void is_win()
{
	setcolor(4);
	settextstyle(0, 0, 2);
	outtextxy(15, 15, (char*)"YOU WIN!");
	smile(181, 23);
}

void set_color(int code)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}

void state_value(bool state[ROW][COL], bool value)
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			state[i][j] = value;
		}
	}
}

void map_value(int map[ROW][COL], int value)
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			map[i][j] = value;
		}
	}
}

bool left_click(int *r, int *c, int *upleft_x, int *upleft_y)
{
	bool left = true;
	do
	{
		delay(0.0001);
		// ---< LEFT >---
		if (ismouseclick(WM_LBUTTONDOWN))
		{
//			left = true;
			getmouseclick(WM_LBUTTONDOWN, *c, *r);
		}
			
		if (ismouseclick(WM_LBUTTONUP))
		{
			left = true;
	        getmouseclick(WM_LBUTTONUP, *upleft_y, *upleft_x);
	    }
	    
	    // ---< RIGHT >---
	    if (ismouseclick(WM_RBUTTONDOWN))
		{
			getmouseclick(WM_RBUTTONDOWN, *c, *r);
		}
			
		if (ismouseclick(WM_RBUTTONUP))
		{
			left = false;
	        getmouseclick(WM_RBUTTONUP, *upleft_y, *upleft_x);
	    }
	}
	while (*r >= Y|| *c >= X || *r < 0 || *c < 0);
	return left;
}

void open_cell(int map[ROW][COL], bool state[ROW][COL], bool flag[ROW][COL], int r, int c)
{
	if (!flag[r][c])
	{
		if (!state[r][c])
		{
			state[r][c] = true;
			print_cell(map, state, flag, r, c);
		}
		
		if (map[r][c] == 0)
		{
			int i, j;
			for (i = r-1; i <= r+1; i++)
			{
				for (j = c-1; j <= c+1; j++)
				{
					if (i >= 0 && i < ROW && j >= 0 && j < COL)
					{
						if (map[i][j] == 0 && !state[i][j] && !flag[i][j])
						{
							open_cell(map, state, flag, i, j);
						}
						
						if (!flag[i][j])
						{
							state[i][j] = true;
							print_cell(map, state, flag, i, j);
						}
			 		}
				}
			}
		}	
	}
}

void while_restart(int *r, int *c, int *upleft_x, int *upleft_y)
{
	while(!is_restart(*r, *c)) //&&
		{
			delay(0.0001);
			left_click(r, c, upleft_x, upleft_y);
		}
}

void mode_mine(int map[ROW][COL], bool state[ROW][COL], bool flag[ROW][COL], int r, int c, int k, int *setflag, bool &is_inited)
{
	if (!state[r][c])
	{
		if (!flag[r][c])
		{
			if (map[r][c] == MINE)
				*setflag = 0;
			else
			{
				init_mines(map, k, r, c, is_inited);
				is_inited = true;
				open_cell(map, state, flag, r, c);
			}
		}
	}
}


void mode_flag(bool state[ROW][COL], bool flag[ROW][COL], int r, int c)
{
	if (!state[r][c])
	{
		if (flag[r][c])
    		print_cell_off(c*30, r*30);
    	else
    		print_flag(c*30, r*30);
		flag[r][c] = !flag[r][c];
	}
}




