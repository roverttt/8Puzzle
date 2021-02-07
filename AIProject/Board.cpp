#include "Board.h"
#include "Position.h"
Board::Board(int initialValues[3][3] )
{

}
Board::Board(int tile1val, int tile2val, int tile3val, int tile4val, int tile5val, int tile6val, int tile7val, int tile8val, int tile9val)
{
	this->currentBoard[0][0].set_pos(0, 0, tile1val);
	this->currentBoard[0][1].set_pos(0, 0, tile1val);
	this->currentBoard[0][2].set_pos(0, 0, tile1val);
	this->currentBoard[1][0].set_pos(0, 0, tile1val);
	this->currentBoard[1][1].set_pos(0, 0, tile1val);
	this->currentBoard[1][2].set_pos(0, 0, tile1val);
	this->currentBoard[2][0].set_pos(0, 0, tile1val);
	this->currentBoard[2][1].set_pos(0, 0, tile1val);
	this->currentBoard[2][2].set_pos(0, 0, tile1val);
}