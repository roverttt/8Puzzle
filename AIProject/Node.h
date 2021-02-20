#pragma once

#include "Board.h"

struct Node {
	Node(int, int, Board);
	int g_n;
	int h_n;
	Board current_board;
};