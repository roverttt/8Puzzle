#include "Position.h"

Position::Position() {
	this->x_pos = -1;
	this->y_pos = -1;
	this->val = -1;
}
Position::Position(int x, int y) {
	this->x_pos = x;
	this->y_pos = y;
}

int Position::dist(int)
{
	return 0;
}

void Position::set_pos(int x, int y, int value = 0) {
	this->x_pos = x;
	this->y_pos = y;
	this->val = value;
}