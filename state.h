#include "definegame.h"

void init(int map[ROW][COL], bool state[ROW][COL], bool flag[ROW][COL]);

void init_mines(int map[ROW][COL], int k, int r, int c, int *digit);

void is_lose();

int is_restart(int r, int c);

int is_note_mode(int r, int c);

void is_win();

void set_color(int code);

void state_value(bool state[ROW][COL], bool value);

void map_value(int map[ROW][COL], int value);

bool left_click(int *r, int *c, int *upleft_x, int *upleft_y);

void open_cell(int map[ROW][COL], bool state[ROW][COL], bool flag[ROW][COL], int r, int c);

void while_restart(int *r, int *c, int *upleft_x, int *upleft_y);



void mode_mine(int map[ROW][COL], bool state[ROW][COL], bool flag[ROW][COL], int r, int c, int k, int *setflag, bool &is_inited);

void mode_flag(bool state[ROW][COL], bool flag[ROW][COL], int r, int c);
