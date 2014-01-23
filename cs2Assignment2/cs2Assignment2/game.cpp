#include "game.h"

const int EXTRA_ROWS = 2;
const int EXTRA_COLS = 3;

game::game(void)
{
}
	int game::getConnectionSize(void) 
	{
		int size=0;
		//User instructions
		cout<<"You may choose to play a 3, 4, 5 or 6 connection game. \nWhat number do you choose?\n";
		cin>>size;
		//Check for invalid input
		while(size>6 || size<3)
		{
			cout<<"You have chosen an invalid number. \nYou may choose to play a 3, 4, 5 or 6 connection game. \nWhat number do you choose?\n";
			cin >> size;
			cout<< endl;
		}
		return size;
	}
	char** game::buildGameBoard (int size)
	{
		int i=0, j=0, k=0;
		int rowSize=size+EXTRA_ROWS;
		int colSize=size+EXTRA_COLS;
		
		//Assign number of rows to gameBoard
		char** gameBoard=new char* [rowSize];
		
		//Assign number of cols to gameBoard
		for(i=0; i<colSize; i++)
		{
			gameBoard[i]= new char [colSize];
		}
		for(j=0; j<=rowSize; j++)
		{
			for(k=0; k<=colSize; k++)
			{
				gameBoard[j][k]=' ';
			}
		}
		return gameBoard;
	}
	void game::displayBoard(char ** gameBoard, int size)
	{
		int i=0;
		int j=0;
		int k=0;
		int l=0;
		int rowSize=size+EXTRA_ROWS;
		int colSize=size+EXTRA_COLS;
		
		//Pretty stars
		for(l=0; l<colSize; l++)
		{
			cout<<"**";
		}
		cout<<endl;

		//Column numbers
		for(k=1; k<colSize+1; k++)
		{
			cout<<k<<" ";
		}
		cout<< endl<<endl;

		//gameBoard elements set to " " and place walls between them
		for(i=0; i<rowSize; i++)
		{
			for(j=0; j<colSize; j++)
			{
				cout<< gameBoard[i][j]<<"|";
			}
			cout<<endl;
		}

		//More pretty stars
		for(l=0; l<colSize; l++)
		{
			cout<<"**";
		}
		cout<< endl<<endl;
	}
	void game::playerMove(char ** gameBoard, int size)
	{
		int i=0;
		int rowSize=size+EXTRA_ROWS;
		int colSize=size+EXTRA_COLS;
		int columnChoice;
		
		//Instructions to user
		cout<<"Player Move: Into which column would you like to drop your game piece?\n\n";
		cin>>columnChoice;
		
		//Check for input out of bounds
		while(columnChoice<1 || columnChoice>colSize)
		{
			cout<<"You have chosen an invalid number. Into which *valid* column would you like to drop your game piece?\n\n";
			cin>>columnChoice;
			cout<<endl;		
		}
		columnChoice--;

		//Check for full column
		while (gameBoard[0][columnChoice]=='x'|| gameBoard[0][columnChoice]=='o')
		{
			cout<<"There is no available space in this column. Please choose a different column.\n";
			cin>>columnChoice;
		}
		
		//Check availablity through the rows of columnChoice starting at the bottom
		for(i=rowSize-1; i>=0; i--)
		{
			if(gameBoard[i][columnChoice]!='x' && gameBoard[i][columnChoice]!='o')
			{
				gameBoard[i][columnChoice]='o';
				return;
			}
		}
	}
	void game::computerMove (char ** gameBoard, int size)
	{
		int rowSize=size+EXTRA_ROWS;
		int colSize=size+EXTRA_COLS;
		int computerChoice=0;
		int i=0;
		srand(static_cast<unsigned int>(time(NULL)));
		
		cout<<"\nComputer Move:  \n\n";

		//Random number for computer choice
		computerChoice= rand() % colSize;

		//Check for full column
		while (gameBoard[0][computerChoice]=='x'|| gameBoard[0][computerChoice]=='o')
		{
			computerChoice= rand() % colSize;
		}

		//Assign computerChoice to board starting at the bottom
		for(i=rowSize-1; i>=0; i--)
		{
			if(gameBoard[i][computerChoice]!='x' && gameBoard[i][computerChoice]!='o')
			{
				gameBoard[i][computerChoice]='x';
				return;
			}
		}
	}
	bool game::checker(char ** gameBoard, int size)
	{
		int rowSize=size+EXTRA_ROWS;
		int colSize=size+EXTRA_COLS;
		int i=0;
		int j=0;
		int full=0;
		bool win=false;
		bool row=false, col=false, rd=false, ld=false;

		for(i=0; i<colSize-1; i++)
		{
			for(j=0; j<rowSize-1; j++)
			{
				row=checkRowWin (gameBoard, size, i, j);
				col=checkColumnWin (gameBoard, size, i, j);
				rd=checkRightDiagonal (gameBoard, size, i, j);
				ld=checkLeftDiagonal (gameBoard, size, i, j);
				if(row==true) win=row;
				if(col==true) win=col;
				if(rd==true) win=rd;
				if(ld==true) win=ld;
				if(win==true)
				{
					if(gameBoard[i][j]=='x')
					{
						cout<<"Computer Wins!";
						return true;
					}
					else if (gameBoard[i][j]=='o')
					{
						cout<<"Player Wins!";
						return true;
					}
				}
				else if (win == false)
				{
					if(gameBoard[i][j] != ' ')
					{
						full++;
						if(full==(rowSize*colSize))
						{
							cout<<"The board is full. This game is a tie.\n";
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool game::checkRowWin (char ** gameBoard, int size, int x, int y)
	{
		int i=0;
		int j=0;
		//int rowSize=size+EXTRA_ROWS;
		int colSize=size+EXTRA_COLS;

		//If the space is occupied by a player
		if(gameBoard[x][y]=='o' || gameBoard[x][y]=='x')
		{
			//Bounds check
			if(y+size<=colSize)
			{
				j= 1;
				//Check if there are "size" in a row
				while(gameBoard[x][y]==gameBoard[x][y+j])
				{
					j++;
				}
				//Not enough in a row
				if(j<size)
				{
					return false;
				}
				//Winner
				else 
				{
					return true;
				}
			}			
		return false;
		}
	}
	bool game::checkColumnWin (char ** gameBoard, int size, int x, int y)
	{
		int i=0;
		int j=0;
		int rowSize=size+EXTRA_ROWS;
		//int colSize=size+EXTRA_COLS;

		//Check if space is occupied by player
		if(gameBoard[x][y]=='o' || gameBoard[x][y]=='x')
		{
			//Bounds check
			if(x+size<=rowSize)
			{
				i= 1;
				//Check for "size" in a row
				while(gameBoard[x][y]==gameBoard[x+i][y])
				{
					i++;
				}
				//Not enough in a row
				if(i<size)
				{
					return false;
				}
				//winner
				else 
				{
					return true;
				}
			}
		}return false;		
	}
	bool game::checkRightDiagonalWin (char ** gameBoard, int size, int x, int y)
	{
		int i=0;
		int j=0;
		int rowSize=size+EXTRA_ROWS;
		int colSize=size+EXTRA_COLS;

		//Check if space is occupied by player
		if(gameBoard[x][y]=='o' || gameBoard[x][y]=='x')
		{
			//Bounds check
			if(x+size<=rowSize)
			{
				i= 1;
				//Check for "size" in a row
				while(gameBoard[x][y]==gameBoard[x+i][y])
				{
					i++;
				}
				//Not enough in a row
				if(i<size)
				{
					return false;
				}
				//winner
				else 
				{
					return true;
				}
			}
		}return false;		
	}
	
	//bool game::checkLeftDiagonalWin (char ** gameBoard, int size);
	//bool game::checkTie (char ** gameBoard, int size);
	//void game::resetGameBoard (char ** gameBoard, int size);
	

game::~game(void)
{
}
