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

	this->solutionBoard[0];
}

void Board::swap_pos(Position pos1, Position pos2) {
	int swapValue = pos1.get_tile_value();
	this->swapTempPosition = this->currentBoard[pos1.get_tile_x_value()][pos1.get_tile_y_value()];
	this->currentBoard[pos1.get_tile_x_value()][pos1.get_tile_y_value()] = pos2;
	this->currentBoard[pos2.get_tile_x_value()][pos2.get_tile_y_value()] = swapTempPosition;
}

Position Board::move_up(Position blank_tile) {
	if (blank_tile.get_tile_x_value() > 0) {
		this->swap_pos(blank_tile, this->currentBoard[(blank_tile.get_tile_x_value() - 1)][(blank_tile.get_tile_y_value())]);
		return this->currentBoard[(blank_tile.get_tile_x_value() - 1)][(blank_tile.get_tile_y_value())];
	}
	else {
		return Position();
	}
}
Position Board::move_down(Position blank_tile) {
	if (blank_tile.get_tile_x_value() < 2) {
		this->swap_pos(blank_tile, this->currentBoard[(blank_tile.get_tile_x_value() + 1)][(blank_tile.get_tile_y_value())]);
		return this->currentBoard[(blank_tile.get_tile_x_value() + 1)][(blank_tile.get_tile_y_value())];
	}
	else {
		return Position();
	}
}
Position Board::move_left(Position blank_tile) {
	if (blank_tile.get_tile_y_value() > 0) {
		this->swap_pos(blank_tile, this->currentBoard[(blank_tile.get_tile_x_value())][(blank_tile.get_tile_y_value() - 1)]);
		return this->currentBoard[(blank_tile.get_tile_x_value())][(blank_tile.get_tile_y_value() - 1)];
	}
	else {
		return Position();
	}
}
Position Board::move_right(Position blank_tile) {
	if (blank_tile.get_tile_y_value() < 2) {
		this->swap_pos(blank_tile, this->currentBoard[(blank_tile.get_tile_x_value() - 1)][(blank_tile.get_tile_y_value() + 1)]);
		return this->currentBoard[(blank_tile.get_tile_x_value() - 1)][(blank_tile.get_tile_y_value() + 1)];
	}
	else {
		return Position();
	}
}
void Board::print_top_row() {
	for (Position positionInRow : currentBoard[0])
	{
		cout << positionInRow.get_tile_value() << " ";
	}
	cout << "\n";
}
void Board::print_mid_row() {
	for (Position positionInRow : currentBoard[1])
	{
		cout << positionInRow.get_tile_value() << " ";
	}
	cout << "\n";
}
void Board::print_bottom_row() {
	for (Position positionInRow : currentBoard[2])
	{
		cout << positionInRow.get_tile_value() << " ";
	}
	cout << "\n";
}

Position Board::get_blank() {
	int flag = 0;
	Position blank;
	for (Position positionInRow : currentBoard[0]) {
		if (positionInRow.get_tile_value() == 0) {
			if (flag == 1) {
				cout << "error 2 zero values on board" << "\n";
				return blank;
			}
			blank = positionInRow;
			flag = 1;
		}
	}
	for (Position positionInRow : currentBoard[1]) {
		if (positionInRow.get_tile_value() == 0) {
			if (flag == 1) {
				cout << "error 2 zero values on board" << "\n";
				return blank;
			}
			blank = positionInRow;
			flag = 1;
		}
	}
	for (Position positionInRow : currentBoard[2]) {
		if (positionInRow.get_tile_value() == 0) {
			if (flag == 1) {
				cout << "error 2 zero values on board" << "\n";
				return blank;
			}
			blank = positionInRow;
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << "no zero found on board" << "\n";
	}
	return blank;
}