#include <stdio.h>
#include <string.h>

void displayBoard(int chess[8][8], char pcs[8][8][4]);

int main(void)
{
	int chess[8][8] = {{0,1,0,1,0,1,0,1}, {1,0,1,0,1,0,1,0}, {0,1,0,1,0,1,0,1}, {1,0,1,0,1,0,1,0}, {0,1,0,1,0,1,0,1}, {1,0,1,0,1,0,1,0}, {0,1,0,1,0,1,0,1}, {1,0,1,0,1,0,1,0}};
	char pcs[8][8][4] = {{"RB","NB","BB","QB","KB","BB","NB","RB"}, {"PB","PB","PB","PB","PB","PB","PB","PB"}, {"0","0","0","0","0","0","0","0"}, {"0","0","0","0","0","0","0","0"}, {"0","0","0","0","0","0","0","0"}, {"0","0","0","0","0","0","0","0"}, {"PW","PW","PW","PW","PW","PW","PW","PW"}, {"RW","NW","BW","QW","KW","BW","NW","RW"}};
	char bCapturedPcs[15][4], wCapturedPcs[15][4];
	int bCaptured = -1, wCaptured = -1;
	
	int x1, y1, x2, y2;
	char temp[4];
	
	displayBoard(chess, pcs);
	
	while (1)
	{
		printf("Enter the PIECE: ");
		scanf("%d.%d", &x1, &y1);
		
		if (x1 == 0 && y1 == 0)
			break;
		
		x1 = 8-x1, y1--;
		
		strcpy(temp, pcs[x1][y1]);
		strcpy(pcs[x1][y1], "0");
		
		printf("Enter the MOVE : ");
		scanf("%d.%d", &x2, &y2);
		
		x2 = 8-x2, y2--;
		
		if (strcmp(pcs[x2][y2], "0") != 0)
		{
			if (pcs[x2][y2][1] == 'B')
			{
				bCaptured++;
			
				strcpy(bCapturedPcs[bCaptured], pcs[x2][y2]);
			}
			else if (pcs[x2][y2][1] == 'W')
			{
				wCaptured++;
				
				strcpy(wCapturedPcs[wCaptured], pcs[x2][y2]);
			}
		}
			
		strcpy(pcs[x2][y2], temp);
		
		puts("");
		
		displayBoard(chess, pcs);
		
		printf("Captured Black PIECES: %d --> ", bCaptured+1);
		for (int c = 0; c <= bCaptured; c++)
		{
			printf("%s, ", bCapturedPcs[c]);
		}
		puts("");
		
		printf("Captured White PIECES: %d --> ", wCaptured+1);
		for (int c = 0; c <= wCaptured; c++)
		{
			printf("%s, ", wCapturedPcs[c]);
		}
		puts("\n");
		
	}
		
	printf("\nCongratulations WINNER!!!");
	
	return 0;
}

void displayBoard(int chess[8][8], char pcs[8][8][4])
{
	printf("      1     2     3     4     5     6     7     8  \n");
	printf("  * * * * * * * * * * * * * * * * * * * * * * * * * **\n");
		
	int row = 8;
		
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 8; j++)
			{	
				
				if (j == 0 && k == 1)
					printf("%d * ", row);
				
				if (j == 0 && k != 1)
					printf("  * ");
					
				if (chess[i][j] == 1)
				{
					if (k == 1 && strcmp(pcs[i][j], "0") != 0)
						printf("**%s**", pcs[i][j]);
							
					else 	
						printf("******");	
				}	
				else if (chess[i][j] == 0)
				{
					if (k == 1 && strcmp(pcs[i][j], "0") != 0)
						printf("  %s  ", pcs[i][j]);
							
					else 	
						printf("      ");
				}
					
				if (j == 7)
					printf(" *");
			}
			puts("");
		}
		row--;	
	}
	printf("  * * * * * * * * * * * * * * * * * * * * * * * * * **\n");
	
	puts("");
	
}
