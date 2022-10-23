#include <graphics.h>

#include "lib.h"

int main ()
{
	// MINESWEEPER
	ShowWindow(GetConsoleWindow(), SW_HIDE); // hide screen console

	int map[16][12];
	bool state[16][12], flag[16][12];
	bool is_mode_mine;
	int digit = 0, k = 30, r, c;
	int upleft_x = -1, upleft_y = -1;
	int x, y;
	
	initwindow(X, Y, "MINESWEEPER", 560, 140); // khoi tao man hinh do hoa
    cleardevice(); // clear all screen graphic
	do{
		delay(0.0001);
		bool is_inited = false;
		
		k = 30;
		r = c = -1;
		
		init(map, state, flag);
		
		int setflag = 1, x = -1, y = -1, count;
		print_map(map, state, flag, x, y);
		
		while (count_remain(state) > k)
		{
			delay(0.0001);
			is_mode_mine = left_click(&r, &c, &upleft_x, &upleft_y);
			
			if (absx(upleft_x - r) >= 15 || absx(upleft_y - c) >= 15)
				continue;
			
			if (is_restart(r, c))
				break;
			
//			if (is_note_mode(r, c))
//			{
//				is_mode_mine = !is_mode_mine;
//				if (is_mode_mine)
//				{
//					note_mine();
//				}
//				else
//				{
//					note_flag();
//				}
//				r = c = -1; // khoi tao lai gia tri r, c;
//				continue;
//			}
			if (r < 45 && !is_restart(r, c)) // &&
				continue;
			convert(&r, &c);
			
			if (is_mode_mine) // mode mine
	        {
	        	printf("MINE\n");
	        	mode_mine(map, state, flag, r, c, k, &setflag, is_inited);
				r = c  = -1;
				if (!setflag)
					break;
			}
			else // mode flag
			{
				mode_flag(state, flag, r, c);
				r = c = -1;
			}
		}
			
		if (!is_restart(r, c))
		{
			if (!setflag)
			{
				x = r;
				y = c;
			}
			state_value(state, 1);
			print_map(map, state, flag, x, y);
			
			settextstyle(0, 0, 2);
			if (x == r && y == c)
				is_lose();
			else
				is_win();
		}
//		
		while_restart(&r, &c, &upleft_x, &upleft_y);
	}while(is_restart(r, c));
	 
	closegraph();
	return 0;
}
