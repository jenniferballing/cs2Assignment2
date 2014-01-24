/* Jennifer Balling
CS2 Assignment 2 */

#include "game.h"

int main ()
{
	int connectionSize;
	char** board;
	game g1;
	string input;
	bool winner=false;
	
	//Prompt user for connection size
	//Create and initialize the board
	connectionSize=g1.getConnectionSize();
	board=g1.buildGameBoard(connectionSize);
	g1.displayBoard(board, connectionSize);
	
	//Puppet Master loop
	while (!winner)
	{
		g1.playerMove(board, connectionSize);
		g1.displayBoard(board, connectionSize);
		winner=g1.checker(board, connectionSize);
		//Pause the game after winning to allow time for gloating and basking in one's own connectN supremacy
		if(winner==true)
		{
			getline(cin,input);
			getline(cin,input);
			break;
		}
		g1.computerMove(board, connectionSize);
		g1.displayBoard(board, connectionSize);
		winner=g1.checker(board, connectionSize);
		//Pause the game after the computer wins to allow time for making up excuses for losing to a computer with the AI strategy of random.
		if(winner==true)
		{
			getline(cin,input);
			getline(cin,input);
		}
	}
	//Let my people go. (Emancipate the memory and set the board to NULL)
	g1.deleteGameBoard(board, connectionSize);
return 0;
}
