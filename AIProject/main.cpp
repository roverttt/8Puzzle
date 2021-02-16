#include "Board.h"
#include "Position.h"

int main() {
	Board myBoard = Board(1, 1, 1, 1, 0, 1, 1, 1, 1);
	myBoard.print_top_row();
	myBoard.print_mid_row();
	myBoard.print_bottom_row();
	Position blankTile = myBoard.get_blank();

	blankTile = myBoard.move_down(blankTile);
	myBoard.print_top_row();
	myBoard.print_mid_row();
	myBoard.print_bottom_row();

	blankTile = myBoard.move_up(blankTile);
	myBoard.print_top_row();
	myBoard.print_mid_row();
	myBoard.print_bottom_row();

	blankTile = myBoard.move_right(blankTile);
	myBoard.print_top_row();
	myBoard.print_mid_row();
	myBoard.print_bottom_row();

	blankTile = myBoard.move_left(blankTile);
	myBoard.print_top_row();
	myBoard.print_mid_row();
	myBoard.print_bottom_row();
	return -1;
}