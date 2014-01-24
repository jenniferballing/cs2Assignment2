#include "game.h"

const int EXTRA_ROWS = 2;
const int EXTRA_COLS = 3;

//Function prototypes of pragmatic whimsy
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
		for(i=0; i<rowSize; i++)
		{
			gameBoard[i]= new char [colSize];
		}

		//Initialize the board
		for(j=0; j<rowSize; j++)
		{
			for(k=0; k<colSize; k++)
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
		
		//Pretty pretty stars
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

		//Places walls between gameBoard elements
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
			columnChoice--;
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
			columnChoice--;
		}
		
		//Check availablity through the rows of columnChoice starting at the bottom
		for(i=rowSize-1; i>=0; i--)
		{
			if(gameBoard[i][columnChoice]!='x' && gameBoard[i][columnChoice]!='o')
			{
				gameBoard[i][columnChoice]='x';
				return;
			}
		}
		/*int rowSize=size+EXTRA_ROWS;
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
		}*/
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

		//Iterate through the board
		for(i=0; i<rowSize; i++)
		{
			for(j=0; j<colSize; j++)
			{
				gameBoard[i][j];
				
				//Check for a win
				row=checkRowWin (gameBoard, size, i, j);
				col=checkColumnWin (gameBoard, size, i, j);
				rd=checkRightDiagonalWin (gameBoard, size, i, j);
				ld=checkLeftDiagonalWin (gameBoard, size, i, j);
				if(row==true) win=row;
				if(col==true) win=col;
				if(rd==true) win=rd;
				if(ld==true) win=ld;
				
				//Determine who won
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
				//Check for a full board
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
		int colSize=size+EXTRA_COLS;


		//If the space is occupied by a player
		if(gameBoard[x][y]=='o' || gameBoard[x][y]=='x')
		{
			//Bounds check
			if(y+size-1<colSize)
			{
				j= 1;
				//Check if there are "size" in a row
				while(gameBoard[x][y]==gameBoard[x][y+j])
				{
					j++;
					if(i+x> colSize-1)
					{
						break;
					}
				}
				//Not enough in a row
				if(j<size)
				{
					return false;
				}
				//Winner
				else if(j==size)
				{
					return true;
				}
			}			
		}return false;
	}
	bool game::checkColumnWin (char ** gameBoard, int size, int x, int y)
	{
		int i=0;
		int j=0;
		int rowSize=size+EXTRA_ROWS;
		
		//Check if space is occupied by player
		if(gameBoard[x][y]=='o' || gameBoard[x][y]=='x')
		{
			//Bounds check
			if(x+size-1<rowSize)
			{
				i= 1;
				//Check for "size" in a row
				while(gameBoard[x][y]==gameBoard[x+i][y])
				{
					i++;
					if(i+x> rowSize-1)
					{
						break;
					}
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
			if(x+size-1<rowSize && y+size-1<colSize)
			{
				i= 1;
				//Check for "size" in a row
				while(gameBoard[x][y]==gameBoard[x+i][y+i])
				{
					i++;
					if(i+x> rowSize-1)
					{
						break;
					}
				}
				//Not enough in a row
				if(i<size)
				{
					return false;
				}
				//winner
				else if(i==size)
				{
					return true;
				}
			}
		}return false;		
	}
	bool game::checkLeftDiagonalWin (char ** gameBoard, int size, int x, int y)
	{
		int i=0;
		int j=0;
		int k=0;
		int rowSize=size+EXTRA_ROWS;
		int colSize=size+EXTRA_COLS;

		//Check if space is occupied by player
		if(gameBoard[x][y]=='o' || gameBoard[x][y]=='x')
		{
			//Bounds check
			if(x+size-1<rowSize && y-(size-1)>=0)
			{
				//MOST RECENT CHANGE
				j=1;
				//Check for "size" in a row
				while(gameBoard[x][y]==gameBoard[x+j][y-j])
				{
					j++;
					if(j+x> rowSize-1)
					{
						break;
					}
				}
				//Not enough in a row
				if(j<size)
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
	void game::deleteGameBoard (char ** gameBoard, int size)
	{
		int rowSize=size+EXTRA_ROWS;
		//int colSize=size+EXTRA_COLS;
		int i=0;
		for(i =0; i<rowSize; i++)
		{
			delete[] gameBoard[i];
			gameBoard[i]=NULL;	
		}
		delete [] gameBoard;
		gameBoard=NULL;
	}
	

game::~game(void)
{
}
