#include "Board.h"
#include "Position.h"
#include <iostream>

using namespace std;

Board::Board(int board_values[HEIGHT][WIDTH]) {
	int i = 0;
	int j = 0;
	for (j = 0; j < HEIGHT; j++) {
		for (i = 0; i < WIDTH; i++) {
			this->currentBoard[i][j].set_value(board_values[i][j]);
		}
	}
}
//Board::Board(int initialValues[3][3] )
//{
//
//}
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

	solution[0].set_pos(2, 2, 0);
	solution[1].set_pos(0, 0, 1);
	solution[2].set_pos(1, 0, 2);
	solution[3].set_pos(2, 0, 3);
	solution[4].set_pos(0, 1, 4);
	solution[5].set_pos(1, 1, 5);
	solution[6].set_pos(2, 1, 6);
	solution[7].set_pos(0, 2, 7);
	solution[8].set_pos(1, 2, 8);
}

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
	if (blank_tile.get_tile_y_value() < 2) {
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
	if (blank_tile.get_tile_x_value() < 2) {
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
int Board::get_num_correct_tiles() {
	int y = 0;
	int x = 0;
	int num_correct = 0;
	bool double_break = false;
	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH; x++) {
			if ((x == WIDTH - 1) && (y == HEIGHT - 1)) {
				double_break = true;
				break;
			}
			if (currentBoard[x][y].get_tile_value() == x + y*WIDTH + 1) {
				num_correct++;
			}
		}
		if (double_break == true) {
			break;
		}
	}
	if (currentBoard[WIDTH - 1][HEIGHT - 1].get_tile_value() == 0) {
		num_correct++;
	}
	return num_correct;
}

Direction Board::get_last_move() {
	return last_direction;
}

int Board::get_board_total_distance() {
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
