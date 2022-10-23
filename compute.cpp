#include <time.h>
#include <stdlib.h>

#include "lib.h"


int absx(int x)
{
	if (x < 0)
		x = -x;
	return x;
}

void convert(int *x, int *y)
{
	*x -= 45;
	*x /= 30;
	*y /= 30;
}

// dem so min xung quanh cac o
void count_mine(int map[ROW][COL], int r, int c)
{
	int i, j;
	for (i = r-1; i <= r+1; i++)
	{
		for (j = c-1; j <= c+1; j++)
		{
			if (i >= 0 && i < ROW && j >= 0 && j < COL) // xet tat ca o hop le xung quanh no
				if (map[i][j] != MINE)
					map[i][j]++;
		}
	}
}

void count_mines(int map[ROW][COL])
{
	int i, j, x, y;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (map[i][j] == MINE)
				count_mine(map, i, j);
		}
	}
}


// dem so mine con lai
int count_remain(bool state[ROW][COL])
{
	int i, j, count = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (!state[i][j])
				count++;
		}
	}
	return count;
}


void random_mine(int map[ROW][COL], int k, int x, int y)
{
	int r, c;
	int i;
	
	srand((int)time(NULL));
	for (i = 0; i < k; i++)
	{
		do{
			r = rand() % ROW;
			c = rand() % COL;
		}while (map[r][c] == MINE || (x-1 <= r && r <= x+1 && y-1 <= c  && c <= y+1));
		map[r][c] = MINE;
	}
}

