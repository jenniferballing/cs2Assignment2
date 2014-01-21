#include "game.h"

//board display is not updating
void main ()
{
	int connectionSize;
	char** board;
	game g1;
	int input;
	bool winner=false;

	connectionSize=g1.getConnectionSize();
	board=g1.buildGameBoard(connectionSize);
	while (!winner)
	{
		g1.displayBoard(board, connectionSize);
		g1.playerMove(board, connectionSize);
		g1.displayBoard(board, connectionSize);
		g1.computerMove(board, connectionSize);
		winner=g1.checkRowWin(board, connectionSize);
	}
	cin>>input;
}
