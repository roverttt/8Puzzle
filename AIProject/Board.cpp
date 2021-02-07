#include "Board.h"
#include "Position.h"
#include <iostream>

using namespace std;

Board::Board(int initialValues[3][3] )
{

}
Board::Board(int tile1val, int tile2val, int tile3val, int tile4val, int tile5val, int tile6val, int tile7val, int tile8val, int tile9val)
{
	this->currentBoard[0][0].set_pos(0, 0, tile1val);
	this->currentBoard[0][1].set_pos(0, 1, tile2val);
	this->currentBoard[0][2].set_pos(0, 2, tile3val);
	this->currentBoard[1][0].set_pos(1, 0, tile4val);
	this->currentBoard[1][1].set_pos(1, 1, tile5val);
	this->currentBoard[1][2].set_pos(1, 2, tile6val);
	this->currentBoard[2][0].set_pos(2, 0, tile7val);
	this->currentBoard[2][1].set_pos(2, 1, tile8val);
	this->currentBoard[2][2].set_pos(2, 2, tile9val);

	this->solution[0].set_pos(2, 2, 0);
	this->solution[1].set_pos(0, 0, 1);
	this->solution[2].set_pos(0, 1, 2);
	this->solution[3].set_pos(0, 2, 3);
	this->solution[4].set_pos(1, 0, 4);
	this->solution[5].set_pos(1, 1, 5);
	this->solution[6].set_pos(1, 2, 6);
	this->solution[7].set_pos(2, 0, 7);
	this->solution[8].set_pos(2, 1, 8);

	this->solutionBoard[0]
};

void Board::swap_pos(Position pos1, Position pos2) {
	this->swapTempPosition = pos1;
	this->currentBoard[pos1.get_tile_x_value][pos1.get_tile_y_value] = pos2;
	this->currentBoard[pos2.get_tile_x_value][pos2.get_tile_y_value] = swapTempPosition;
}

int Board::move_up(Position blank_tile) {
	if (blank_tile.get_tile_x_value > 0) {
		this->swap_pos(blank_tile, this->currentBoard[(blank_tile.get_tile_x_value - 1)][(blank_tile.get_tile_y_value)]);
		return 0;
	}
	else {
		return -1;
	}
}
int Board::move_down(Position blank_tile) {
	if (blank_tile.get_tile_x_value < 2) {
		this->swap_pos(blank_tile, this->currentBoard[(blank_tile.get_tile_x_value + 1)][(blank_tile.get_tile_y_value)]);
		return 0;
	}
	else {
		return -1;
	}
}
int Board::move_left(Position blank_tile) {
	if (blank_tile.get_tile_y_value > 0) {
		this->swap_pos(blank_tile, this->currentBoard[(blank_tile.get_tile_x_value)][(blank_tile.get_tile_y_value - 1)]);
		return 0;
	}
	else {
		return -1;
	}
}
int Board::move_right(Position blank_tile) {
	if (blank_tile.get_tile_y_value < 2) {
		this->swap_pos(blank_tile, this->currentBoard[(blank_tile.get_tile_x_value - 1)][(blank_tile.get_tile_y_value + 1)]);
		return 0;
	}
	else {
		return -1;
	}
}
void Board::print_top_row() {
	cout << this->currentBoard[0] << "\n";
}
void Board::print_mid_row() {
	cout << this->currentBoard[0] << "\n";
}
void Board::print_bottom_row() {
	cout << this->currentBoard[0] << "\n";
}