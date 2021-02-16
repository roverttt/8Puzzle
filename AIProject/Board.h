#pragma once
#include "Position.h"

class Board {
public:
	Board(int initialValues[][3]);
	Board(int, int, int, int, int, int, int, int, int);
	Position move_up(Position);
	Position move_down(Position);
	Position move_left(Position);
	Position move_right(Position);
	void print_top_row();
	void print_mid_row();
	void print_bottom_row();
	Position get_blank();
private:
	void swap_board_values(Position, Position);
	Position currentBoard[3][3];
	Position solution[9];
	int swapTempValue;
};
