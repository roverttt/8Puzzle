#pragma once

struct Position {
public:
	Position();
	Position(int,int);
	int dist();
	void set_pos(int, int, int value = 0);
	void set_value(int value);
	int get_tile_x_value();
	int get_tile_y_value();
	int get_tile_value();
	void tile_update_left();
	void tile_update_right();
	void tile_update_up();
	void tile_update_down();

	static void init_dist_lookup_table();
private:
	int x_pos;
	int y_pos;
	int val;

	static int dist_lookup_table[3][3][9];
};