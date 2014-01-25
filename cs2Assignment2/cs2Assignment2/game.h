#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>

using namespace std;

class game
{
public:
	game(void);
	//Functions of power and inspiration
	int getConnectionSize(void);
	char** buildGameBoard (int size);
	void displayBoard(char ** gameBoard, int size);
	void playerMove(char ** gameBoard, int size);
	void computerMove (char ** gameBoard, int size);
	bool checkRowWin (char ** gameBoard, int size, int x, int y);
	bool checker(char ** gameBoard, int size);
	bool checkColumnWin (char ** gameBoard, int size, int x, int y);
	bool checkRightDiagonalWin (char ** gameBoard, int size, int x, int y);
	bool checkLeftDiagonalWin (char ** gameBoard, int size, int x, int y);
	void deleteGameBoard (char ** gameBoard, int size);
	~game(void);
};
#endif

