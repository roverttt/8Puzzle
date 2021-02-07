#pragma once

struct Position {
public:
	Position();
	Position(int,int);
	int dist(int);
	void set_pos(int, int, int value = 0);
	int get_tile_x_value();
	int get_tile_y_value();
	int get_tile_value();
private:
	int x_pos;
	int y_pos;
	int val;
};