#include "Position.h"
#include "Board.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int Position::dist_lookup_table[3][3][9];

Position::Position() {
	this->x_pos = -1;
	this->y_pos = -1;
	this->val = -1;
}
Position::Position(int x, int y) {
	this->x_pos = x;
	this->y_pos = y;
}

int Position::dist()
{
	int solution_x;
	int solution_y;
	if (val == 0) {
		solution_x = WIDTH - 1;
		solution_y = HEIGHT - 1;
	}
	else {
		solution_x = (val - 1) % WIDTH;
		solution_y = (val - 1) / WIDTH;
	}

	return abs(this->x_pos - solution_x) + abs(this->y_pos - solution_y);
}


void Position::set_pos(int x, int y, int value) {
	this->x_pos = x;
	this->y_pos = y;
	this->val = value;
}
void Position::set_value(int value) {
	this->val = value;
}
int Position::get_tile_x_value() {
	return this->x_pos;
}
int Position::get_tile_y_value() {
	return this->y_pos;
}
int Position::get_tile_value() {
	return this->val;
}

void Position::tile_update_left() {
	x_pos -= 1;
}
void Position::tile_update_right() {
	x_pos += 1;
}
void Position::tile_update_up() {
	y_pos -= 1;
}
void Position::tile_update_down() {
	y_pos += 1;
}
void Position::init_dist_lookup_table() {
	dist_lookup_table[0][0][1] = 0;
	dist_lookup_table[1][0][1] = 1;
	dist_lookup_table[2][0][1] = 2;
	dist_lookup_table[0][1][1] = 1;
	dist_lookup_table[1][1][1] = 2;
	dist_lookup_table[2][1][1] = 3;
	dist_lookup_table[0][2][1] = 2;
	dist_lookup_table[1][2][1] = 3;
	dist_lookup_table[2][2][1] = 4;
	dist_lookup_table[0][0][2] = 1;
	dist_lookup_table[1][0][2] = 2;
	dist_lookup_table[2][0][2] = 3;
	dist_lookup_table[0][1][2] = 0;
	dist_lookup_table[1][1][2] = 1;
	dist_lookup_table[2][1][2] = 2;
	dist_lookup_table[0][2][2] = 1;
	dist_lookup_table[1][2][2] = 2;
	dist_lookup_table[2][2][2] = 3;
	dist_lookup_table[0][0][3] = 2;
	dist_lookup_table[1][0][3] = 3;
	dist_lookup_table[2][0][3] = 4;
	dist_lookup_table[0][1][3] = 1;
	dist_lookup_table[1][1][3] = 2;
	dist_lookup_table[2][1][3] = 3;
	dist_lookup_table[0][2][3] = 0;
	dist_lookup_table[1][2][3] = 1;
	dist_lookup_table[2][2][3] = 2;
	dist_lookup_table[0][0][4] = 1;
	dist_lookup_table[1][0][4] = 0;
	dist_lookup_table[2][0][4] = 1;
	dist_lookup_table[0][1][4] = 2;
	dist_lookup_table[1][1][4] = 1;
	dist_lookup_table[2][1][4] = 2;
	dist_lookup_table[0][2][4] = 3;
	dist_lookup_table[1][2][4] = 2;
	dist_lookup_table[2][2][4] = 3;
	dist_lookup_table[0][0][5] = 2;
	dist_lookup_table[1][0][5] = 1;
	dist_lookup_table[2][0][5] = 2;
	dist_lookup_table[0][1][5] = 1;
	dist_lookup_table[1][1][5] = 0;
	dist_lookup_table[2][1][5] = 1;
	dist_lookup_table[0][2][5] = 2;
	dist_lookup_table[1][2][5] = 1;
	dist_lookup_table[2][2][5] = 2;
	dist_lookup_table[0][0][6] = 3;
	dist_lookup_table[1][0][6] = 2;
	dist_lookup_table[2][0][6] = 3;
	dist_lookup_table[0][1][6] = 2;
	dist_lookup_table[1][1][6] = 1;
	dist_lookup_table[2][1][6] = 2;
	dist_lookup_table[0][2][6] = 1;
	dist_lookup_table[1][2][6] = 0;
	dist_lookup_table[2][2][6] = 1;
	dist_lookup_table[0][0][7] = 2;
	dist_lookup_table[1][0][7] = 1;
	dist_lookup_table[2][0][7] = 0;
	dist_lookup_table[0][1][7] = 3;
	dist_lookup_table[1][1][7] = 2;
	dist_lookup_table[2][1][7] = 1;
	dist_lookup_table[0][2][7] = 4;
	dist_lookup_table[1][2][7] = 3;
	dist_lookup_table[2][2][7] = 2;
	dist_lookup_table[0][0][8] = 3;
	dist_lookup_table[1][0][8] = 2;
	dist_lookup_table[2][0][8] = 1;
	dist_lookup_table[0][1][8] = 2;
	dist_lookup_table[1][1][8] = 1;
	dist_lookup_table[2][1][8] = 0;
	dist_lookup_table[0][2][8] = 3;
	dist_lookup_table[1][2][8] = 2;
	dist_lookup_table[2][2][8] = 1;
	dist_lookup_table[0][0][0] = 4;
	dist_lookup_table[1][0][0] = 3;
	dist_lookup_table[2][0][0] = 2;
	dist_lookup_table[0][1][0] = 3;
	dist_lookup_table[1][1][0] = 2;
	dist_lookup_table[2][1][0] = 1;
	dist_lookup_table[0][2][0] = 2;
	dist_lookup_table[1][2][0] = 1;
	dist_lookup_table[2][2][0] = 0;
}

