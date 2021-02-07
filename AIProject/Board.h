#pragma once
#include "Position.h"

class Board {
public:
	Board(int initialValues[][3]);
	Board(int, int, int, int, int, int, int, int, int);
	int move_up(Position);
	int move_down(Position);
	int move_left(Position);
	int move_right(Position);
	void print_top_row();
	void print_mid_row();
	void print_bottom_row();
private:
	void swap_pos(Position, Position);
	Position currentBoard[3][3];
	Position solutionBoard[3][3];
	Position solution[9];
	Position swapTempPosition;
};
