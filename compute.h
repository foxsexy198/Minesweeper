#include "definegame.h"

int absx(int x);

void convert(int *x, int *y);

void count_mine(int map[ROW][COL], int r, int c);

void count_mines(int map[ROW][COL]);

int count_remain(bool state[ROW][COL]);

void random_mine(int map[ROW][COL], int k, int x, int y);


