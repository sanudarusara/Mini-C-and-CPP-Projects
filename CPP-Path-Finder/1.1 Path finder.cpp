#include <iostream>
#include <cmath>

using namespace std;
	
int main(void)
{
	int r, c;
	
	//taking the inputs
	cout << "Enter the no.of rows of the maze   : ";
	cin >> r;
	
	cout << "Enter the no.of columns of the maze: ";
	cin >> c;
	
	int maze[r][c];
	int s1, s2, e1, e2;
	
	cout << endl << "Enter the maze values: " << endl;
	
	for (int i = 0; i < r; i++)
	{
		cout << "Enter row " << i+1 << ": ";
		for (int  j = 0; j < c; j++)
		{
			cin >> maze[i][j];
		}
	}
	
	cout << endl << "Enter the start point : ";
	cin >> s1 >> s2;
	s1--, s2--;
	
	cout << "Enter the end point   : ";
	cin >> e1 >> e2;
	e1--, e2--;
	
	//drawing the upper border
	int colParity = c%2;
	
	cout << endl;
	if (colParity == 1)
	{
		float n = round((5*c)/2.0)+2;
			
		for (int b = 0; b < n; b++)
		{
			if (b == n)
				cout << "*";
			else
				cout << "* ";
		}
	}
	else if (colParity == 0)
	{
		int n = (5*c)/2 + 2;
		
		for (int b = 0; b < n; b++)
		{
			if (b == n-1)
				cout << "**";
			else
				cout << "* ";
		}
	}
	cout << endl;
	
	//drawing the maze
	for (int i = 0; i < r; i++)
	{
		for (int  k = 0; k < 3; k++)
		{
			for (int j = 0; j < c; j++)
			{
				if (j == 0)//drawing the left border
					cout << "* ";
					
				if (maze[i][j] == 1)
					cout << "*****";
					
				else
				{
					if (i == s1 && j == s2 && k == 1)
						cout << "  S  ";
						
					else if (i == e1 && j == e2 && k == 1)
						cout << "  E  ";
						
					else
						cout << "     ";
				} 
					
				if (j == c-1)//drawing the right border
					cout << " *";
			}
			cout << endl;
		}
	}
	
	//drawing the lower border
	if (colParity == 1)
	{
		float n = round((5*c)/2.0)+2;
			
		for (int b = 0; b < n; b++)
		{
			if (b == n)
				cout << "*";
			else
				cout << "* ";
		}
	}
	else if (colParity == 0)
	{
		int n = (5*c)/2 + 2;
		
		for (int b = 0; b < n; b++)
		{
			if (b == n-1)
				cout << "**";
			else
				cout << "* ";
		}
	}
	cout << endl << endl;
	
	//calculating the path
	int i = s1;
	int j = s2;
	int end = 0;
	
	do 
	{
		if (maze[i-1][j] == 0 && i-1 >= 0)
		{
			cout << "Go up";
			maze[i][j] = 1;			
			i = i-1;
		}	
		else if (maze[i+1][j] == 0 && i+1 <= (r-1))
		{
			cout << "Go down";
			maze[i][j] = 1;			
			i = i+1;
		}
		else if (maze[i][j+1] == 0 && j+1 <= (c-1))
		{
			cout << "Go right";
			maze[i][j] = 1;			
			j = j+1;
		}	
		else if (maze[i][j-1] == 0 && j-1 >= 0)
		{
			cout << "Go left";
			maze[i][j] = 1;
			j = j-1;
		}
		
		if (i == e1 && j == e2)
			end = 1;
			
		if (end == 0)
			cout << ", ";
		else
			cout << ".";
		
	}while(end != 1);
	
	return 0;
}
