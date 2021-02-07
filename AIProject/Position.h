#pragma once

struct Position {
public:
	Position();
	Position(int,int);
	int dist(int);
	void set_pos(int, int, int value = 0);
private:
	int x_pos;
	int y_pos;
	int val;
};