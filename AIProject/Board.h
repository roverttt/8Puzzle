#pragma once
#include "Position.h"
const int WIDTH = 3;
const int HEIGHT = 3;

enum Direction { UP, DOWN, LEFT, RIGHT, NONE };

class Board {
public:
	Board() {};
	Board(int board_values[HEIGHT][WIDTH]);
	Position move_up(Position);
	Position move_down(Position);
	Position move_left(Position);
	Position move_right(Position);
	bool can_move(Direction);
	Position get_blank();
	Position get_position_of_board_tile(int, int);
	int get_board_total_distance();
	int get_num_incorrect_tiles();
	Direction get_last_move();
	void print_board();
	void set_last_move(Direction);
private:
	Direction last_direction = NONE;
	void swap_board_values(Position, Position);
	Position currentBoard[HEIGHT][WIDTH];
	int swapTempValue;
};
