#pragma once
#include "Position.h"

class Board {
public:
	Board(int initialValues[][3]);
	Board(int, int, int, int, int, int, int, int, int);
	
private:
	Position currentBoard[3][3];
	Position solution[9];
	
};
