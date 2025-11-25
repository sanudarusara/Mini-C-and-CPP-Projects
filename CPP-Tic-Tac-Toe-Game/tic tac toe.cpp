#include <iostream>

void displayTicTacGrid(char tictac[3][3]);
char winChecker(char tictac[3][3]);
int drawChecker(char tictac[3][3]);
int invalidMoveChecker(char tictac[3][3], int x, int y);

using namespace std;

int main(void)
{
	char tictac[3][3] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};
	char player = 'X';
	int x, y;
	char win;
	int empty, invalid;
	
	cout << "Welcome to Tic-Tac-Toe !X!O!" << endl << endl;
	
	displayTicTacGrid(tictac);
	
	while (1)
	{
		if (player == 'X')
			cout << endl << "X's Turn" << endl;
			
		else 
			cout << endl << "O's Turn" << endl;
		
		while (1)
		{
			while (1)
			{
				cout << "Enter a cell: ";
				cin >> x >> y;
				
				//checking for invalid cell range inputs
				if ((x < 1 || x > 3) || (y < 1 || y > 3))
					cout << "Error: Invalid cell range!!! Please enter a cell in the range 1-3." << endl << endl;
				else
					break;
			}
			x--, y--;
			
			invalid = invalidMoveChecker(tictac, x, y);//cheking invalid cell inputs for already occupied cells
			
			if (invalid == 0)
				break;
				
			cout << "Error: Cell already occupied!!! Please enter an empty cell." << endl << endl;	
		}
		
		//updating the cell of the array with X or O according to the player & then changing the player type for the next turn
		if (player == 'X')
		{
			tictac[x][y] = 'X';
			player = 'O';
		}
		else if (player == 'O')
		{
			tictac[x][y] = 'O';			
			player = 'X';
		}
		cout << endl;	
		
		displayTicTacGrid(tictac);//displaying the updated tictac grid
		
		win = winChecker(tictac);//checking if a player has won with the updated moves
		
		if (win != '0')
			break;
			
		empty = drawChecker(tictac);//checking if the game is drawn
		
		if (empty == 0)
			break;
	}
	
	if (win != '0')
		cout << endl << "Congratulations " << win << ". You are the Winner!!!";
		
	if (empty == 0)
		cout << endl << "Great game X and O. The Game is Drawn!!!";
		
	return 0;
}

void displayTicTacGrid(char tictac[3][3])
{
	for (int x = 0; x < 3; x++)
	{
		cout << "|";
		for (int y = 0; y < 3; y++)
		{
			cout << " " << tictac[x][y] << " |";	
		}
		cout << endl;
	}
}

char winChecker(char tictac[3][3])
{
	char win = '0';
	
	for (int x = 0; x < 3; x++)
	{
		//checking horizontal rows of grid for XXX or OOO
			if (tictac[x][0] == 'X' && tictac[x][1] == 'X' && tictac[x][2] == 'X')
			{
				win = 'X';
				return win;				
			}
			
			if (tictac[x][0] == 'O' && tictac[x][1] == 'O' && tictac[x][2] == 'O')
			{
				win = 'O';
				return win;				
			}	
	}
	
	//checking vertical columns of gird for XXX or OOO
	for (int y = 0; y < 3; y++)
	{
			if(tictac[0][y] == 'X' && tictac[1][y] == 'X' && tictac[2][y] == 'X')
			{
				win = 'X';
				return win;				
			}
			if(tictac[0][y] == 'O' && tictac[1][y] == 'O' && tictac[2][y] == 'O')
			{
				win = 'O';
				return win;				
			}
	}
	
	//checking the diagonals of the grid for XXX
	if (tictac[0][0] == 'X' && tictac[1][1] == 'X' && tictac[2][2] == 'X')//leading diagonal
	{
		win = 'X';
		return win;
	}
	 
	if (tictac[0][2] == 'X' && tictac[1][1] == 'X' && tictac[2][0] == 'X')//secondary diagonal
	{
		win = 'X';
		return win;
	}
	
	//checking the diagonals of the grid for OOO
	if (tictac[0][0] == 'O' && tictac[1][1] == 'O' && tictac[2][2] == 'O')//leading diagonal
	{
		win = 'O';
		return win;
	}
	
	if (tictac[0][2] == 'O' && tictac[1][1] == 'O' && tictac[2][0] == 'O')//secondary diagonal
	{
		win = 'O';
		return win;
	}
	
	return win;
}

int drawChecker(char tictac[3][3])
{
	int empty;
	
	//checking for any empty cells in the tictac grid. If there are no empty cells and the game is not won, then its a draw.
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (tictac[x][y] == '_')
			{
				empty = 1;
				return empty;
			}	
			else 
				empty = 0;	
		}
	}
	
	return empty;
}

int invalidMoveChecker(char tictac[3][3], int x, int y)
{
	int invalid = 0;
	
	//checking if the input cell already has a X or an O
	if (tictac[x][y] == 'X' || tictac[x][y] == 'O')
		invalid = 1;
		
	return invalid;	
}
