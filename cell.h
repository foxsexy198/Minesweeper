#include "definegame.h"

void print_cell(int map[ROW][COL], bool state[ROW][COL], bool flag[ROW][COL], int i, int j);

void print_cell_empty(int x, int y);

void print_cell_mine(int x, int y, int boom);

void print_cell_off(int x, int y);

void print_cell_value(int x, int y, int value);

void print_flag(int x, int y);

void print_map(int map[ROW][COL], bool state[ROW][COL], bool flag[ROW][COL], int x, int y);



void read_cell(int *r, int *c);








