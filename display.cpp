#include <graphics.h>

#include "lib.h"

void sadface(int x, int y)
{
	// ve hinh tron
	setcolor(0);
	circle(x, y, 14);
	setfillstyle(1, 14);
	floodfill(x, y, 0);
	// mat buon
	setcolor(14);
	pieslice(x, y-2, 220, 330, 8+2);
	setcolor(0);
	pieslice(x, y+9, 0, 180, 7);
	bar(x-7, y+9, x+7, y+6);
	// eye
	setfillstyle(1, 0);
	circle(x - 4, y -4, 2);
	floodfill(x-4, y-4, 0);
	circle(x+4, y-4, 2);
	floodfill(x+4, y-4, 0);
}


void smile(int x, int y)
{
	// ve hinh tron
	setcolor(0);
	circle(x, y, 14);
	setfillstyle(1, 14);
	floodfill(x, y, 0);
	// mat cuoi
	pieslice(x, y-2, 220, 330, 8+2);
	bar(x-10, y-2, x+10, y+4);
	// eye
	setfillstyle(1, 0);
	circle(x - 4, y -3, 3);
	floodfill(x-4, y-3, 0);
	circle(x + 4, y -3, 3);
	floodfill(x+4, y-3, 0);
}

void note_mine()
{
	print_cell_mine(8*30+1, -38, 0);
	setcolor(7);
	rectangle(8*30+1, -38 +45, 8*30+1+30, -38+30 +45);
}

void note_flag()
{
	setfillstyle(1, 7);
	setcolor(0);
	bar(left_mode, top_mode, right_mode, bottom_mode);
	print_flag(8*30, -38);	
}


