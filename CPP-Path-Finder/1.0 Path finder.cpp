#include <iostream>

using namespace std;
	
int main(void)
{
	int maze[3][3];
	int s1, s2, e1, e2;
	
	cout << "Enter the maze values: " << endl << endl;
	
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter row " << i+1 << ": ";
		for (int  j = 0; j < 3; j++)
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
	
	cout << endl;
	for (int n = 0; n < 10; n++)
	{
		if (n == 10)
			cout << "*";
		else
			cout << "* ";
	}
	cout << endl;
	
	for (int i = 0; i < 3; i++)
	{
		for (int  k = 0; k < 3; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j == 0)
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
					
				if (j == 2)
					cout << " *";
			}
			cout << endl;
		}
	}
	
	for (int n = 0; n < 10; n++)
	{
		if (n == 10)
			cout << "*";
		else
			cout << "* ";
	}
	cout << endl << endl;
	
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
			j = j;
		}	
		else if (maze[i+1][j] == 0 && i+1 <= 2)
		{
			cout << "Go down";
			
			maze[i][j] = 1;
			i = i+1;
			j = j;
		}
		else if (maze[i][j+1] == 0 && j+1 <= 2)
		{
			cout << "Go right";
			
			maze[i][j] = 1;
			i = i;
			j = j+1;
		}	
		else if (maze[i][j-1] == 0 && j-1 >= 0)
		{
			cout << "Go left";
			
			maze[i][j] = 1;
			i = i;
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
