#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>

using namespace std;

class game
{
	int connectionSize;
	char** gameBoard;
public:
	game(void);
	int getConnectionSize(void);
	char** buildGameBoard (int size);
	void displayBoard(char ** gameBoard, int size);
	void playerMove(char ** gameBoard, int size);
	void computerMove (char ** gameBoard, int size);
	//bool checkRowWin (char ** gameBoard, int size);
	//bool checkColumnWin (char ** gameBoard, int size);
	//bool checkRightDiagonalWin (char ** gameBoard, int size);
	//bool checkLeftDiagonalWin (char ** gameBoard, int size);
	//bool checkTie (char ** gameBoard, int size);
	//void resetGameBoard (char ** gameBoard, int size);
	~game(void);
};

