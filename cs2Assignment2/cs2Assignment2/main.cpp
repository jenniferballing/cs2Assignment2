#include "game.h"

//board display is not updating
void main ()
{
	int connectionSize;
	char** board;
	game g1;
	
	connectionSize=g1.getConnectionSize();
	board=g1.buildGameBoard(connectionSize);
	g1.displayBoard(board, connectionSize);
	g1.playerMove(board, connectionSize);
	g1.displayBoard(board, connectionSize);


}
