#include "Board.h"
#include "Position.h"

int main() {
	Board myBoard = Board(0, 0, 0, 0, 1, 0, 0, 0, 0);
	myBoard.print_top_row();
	myBoard.print_mid_row();
	myBoard.print_bottom_row();
	return -1;
}