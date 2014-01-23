#include "game.h"

//Check for deletes and NULLS
//Check only the most recent play
void main ()
{
	int connectionSize;
	char** board;
	game g1;
	int input;
	bool winner=false;

	connectionSize=g1.getConnectionSize();
	board=g1.buildGameBoard(connectionSize);
	g1.displayBoard(board, connectionSize);
	while (!winner)
	{
		g1.playerMove(board, connectionSize);
		g1.displayBoard(board, connectionSize);
		winner=g1.checker(board, connectionSize);
		g1.computerMove(board, connectionSize);
		g1.displayBoard(board, connectionSize);
		winner=g1.checker(board, connectionSize);
	}
	cin>>input;
}
