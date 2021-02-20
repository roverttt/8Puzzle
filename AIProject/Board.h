#pragma once
#include "Position.h"
const int WIDTH = 3;
const int HEIGHT = 3;

enum Direction { UP, DOWN, LEFT, RIGHT, NONE };

class Board {
public:
	Board() {};
	Board(int board_values[HEIGHT][WIDTH]);
//	Board(int initialValues[][3]);
	Board(int, int, int, int, int, int, int, int, int);
	Position move_up(Position);
	Position move_down(Position);
	Position move_left(Position);
	Position move_right(Position);
	bool can_move(Direction);
	void print_top_row();
	void print_mid_row();
	void print_bottom_row();
	Position get_blank();
	Position get_position_of_board_tile(int, int);
	int get_board_total_distance();
	int get_num_correct_tiles();
	Direction get_last_move();
	void print_board();
	void set_last_move(Direction);
private:
	Direction last_direction = NONE;
	void swap_board_values(Position, Position);
	Position currentBoard[3][3];
	Position solution[9];
	int swapTempValue;
};
