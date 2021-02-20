#include "Board.h"
#include "Position.h"
#include <iostream>

using namespace std;

Board::Board(int board_values[HEIGHT][WIDTH]) {
	int i = 0;
	int j = 0;
	for (j = 0; j < HEIGHT; j++) {
		for (i = 0; i < WIDTH; i++) {
			this->currentBoard[i][j].set_pos(i, j,board_values[i][j]);
		}
	}
}
//Board::Board(int initialValues[3][3] )
//{
//
//}

bool Board::can_move(Direction dir) {
	Position blank_tile = get_blank();
	switch (dir) {
	case UP:
		if (blank_tile.get_tile_y_value() == 0 || last_direction == DOWN) {
			return false;
		}
		else {
			return true;
		}
		break;
	case DOWN:
		if (blank_tile.get_tile_y_value() == HEIGHT - 1 || last_direction == UP) {
			return false;
		}
		else {
			return true;
		}
		break;
	case RIGHT:
		if (blank_tile.get_tile_x_value() == WIDTH - 1 || last_direction == LEFT) {
			return false;
		}
		else {
			return true;
		}
		break;
	case LEFT:
		if (blank_tile.get_tile_x_value() == 0 || last_direction == RIGHT) {
			return false;
		}
		else {
			return true;
		}
		break;
	case NONE:

		break;
	default:
		break;
	}
	return false;
}


void Board::swap_board_values(Position pos1, Position pos2) {
	this->swapTempValue = this->currentBoard[pos1.get_tile_x_value()][pos1.get_tile_y_value()].get_tile_value();
	this->currentBoard[pos1.get_tile_x_value()][pos1.get_tile_y_value()].set_value(pos2.get_tile_value());
	this->currentBoard[pos2.get_tile_x_value()][pos2.get_tile_y_value()].set_value(this->swapTempValue);
}

Position Board::move_up(Position blank_tile) {
	if (blank_tile.get_tile_y_value() > 0) {
		this->swap_board_values(blank_tile, this->currentBoard[(blank_tile.get_tile_x_value())][(blank_tile.get_tile_y_value() - 1)]);
		last_direction = UP;
		return this->currentBoard[(blank_tile.get_tile_x_value())][(blank_tile.get_tile_y_value() - 1)];
	}
	else {
		return Position();
	}
}
Position Board::move_down(Position blank_tile) {
	if (blank_tile.get_tile_y_value() < HEIGHT - 1) {
		this->swap_board_values(blank_tile, this->currentBoard[(blank_tile.get_tile_x_value())][(blank_tile.get_tile_y_value() + 1)]);
		last_direction = DOWN;
		return this->currentBoard[(blank_tile.get_tile_x_value())][(blank_tile.get_tile_y_value() + 1)];
	}
	else {
		return Position();
	}
}
Position Board::move_left(Position blank_tile) {
	if (blank_tile.get_tile_x_value() > 0) {
		this->swap_board_values(blank_tile, this->currentBoard[(blank_tile.get_tile_x_value() - 1)][(blank_tile.get_tile_y_value())]);
		last_direction = LEFT;
		return this->currentBoard[(blank_tile.get_tile_x_value() - 1)][(blank_tile.get_tile_y_value())];
	}
	else {
		return Position();
	}
}
Position Board::move_right(Position blank_tile) {
	if (blank_tile.get_tile_x_value() < WIDTH - 1) {
		this->swap_board_values(blank_tile, this->currentBoard[(blank_tile.get_tile_x_value() + 1)][(blank_tile.get_tile_y_value())]);
		last_direction = RIGHT;
		return this->currentBoard[(blank_tile.get_tile_x_value() + 1)][(blank_tile.get_tile_y_value())];
	}
	else {
		return Position();
	}
}

void Board::print_top_row() {
	int y = 0;

	for (int x = 0; x < 3; x++)
	{
		Position positionInRow = currentBoard[x][y];
		cout << positionInRow.get_tile_value() << " ";
	}
	cout << "\n";
}
void Board::print_mid_row() {
	int y = 1;

	for (int x = 0; x < 3; x++)
	{
		Position positionInRow = currentBoard[x][y];
		cout << positionInRow.get_tile_value() << " ";
	}
	cout << "\n";
}
void Board::print_bottom_row() {
	int y = 2;

	for (int x = 0; x < 3; x++)
	{
		Position positionInRow = currentBoard[x][y];
		cout << positionInRow.get_tile_value() << " ";
	}
	cout << "\n";
}

Position Board::get_blank() {
	int flag = 0;
	Position blank;
	for (Position positionInColumn : currentBoard[0]) {
		if (positionInColumn.get_tile_value() == 0) {
			if (flag == 1) {
				cout << "error 2 zero values on board" << "\n";
				return blank;
			}
			blank = positionInColumn;
			flag = 1;
		}
	}
	for (Position positionInColumn : currentBoard[1]) {
		if (positionInColumn.get_tile_value() == 0) {
			if (flag == 1) {
				cout << "error 2 zero values on board" << "\n";
				return blank;
			}
			blank = positionInColumn;
			flag = 1;
		}
	}
	for (Position positionInColumn : currentBoard[2]) {
		if (positionInColumn.get_tile_value() == 0) {
			if (flag == 1) {
				cout << "error 2 zero values on board" << "\n";
				return blank;
			}
			blank = positionInColumn;
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << "no zero found on board" << "\n";
	}
	return blank;
}
void Board::set_last_move(Direction d) {
	last_direction = d;
	return;
}
Position Board::get_position_of_board_tile(int x, int y) {
	return currentBoard[x][y];
}

void Board::print_board() {
	int i = 0;
	int j = 0;
	for (j = 0; j < HEIGHT; j++) {
		for (i = 0; i < WIDTH; i++) {
			cout << currentBoard[i][j].get_tile_value() << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}
int Board::get_num_incorrect_tiles() {
	int y = 0;
	int x = 0;
	int num_incorrect = 0;
	bool double_break = false;
	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH; x++) {
			if ((x == WIDTH - 1) && (y == HEIGHT - 1)) {
				double_break = true;
				break;
			}
			if (currentBoard[x][y].get_tile_value() != x + y*WIDTH + 1) {
				num_incorrect++;
			}
		}
		if (double_break == true) {
			break;
		}
	}
	if (currentBoard[WIDTH - 1][HEIGHT - 1].get_tile_value() != 0) {
		num_incorrect++;
	}
	return num_incorrect;
}

Direction Board::get_last_move() {
	return last_direction;
}

int Board::get_board_total_distance() {

	/*
		for (j = 0; j < HEIGHT; j++) {
		for (i = 0; i < WIDTH; i++) {
	*/
	return currentBoard[0][0].dist() + 
		currentBoard[0][1].dist() + 
		currentBoard[0][2].dist() +
		currentBoard[1][0].dist() + 
		currentBoard[1][1].dist() + 
		currentBoard[1][2].dist() +
		currentBoard[2][0].dist() + 
		currentBoard[2][1].dist() + 
		currentBoard[2][2].dist();
}
