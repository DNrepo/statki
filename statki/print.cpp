
#include "board.h"
#include "consts.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void printBoard(board_struct boardToPrint)
{
	system("cls");
	printf("  Dominik Nowocien PK 2017/2018  \n");
	printf("  statki  \n\n");

	for (int i = 0; i < boardToPrint.size; i++)
	{


		printf("  |");
		for (int j = 0; j < boardToPrint.size; j++)
		{
			int a = boardToPrint.board[read(i, j, boardToPrint.size)];

			if (a == empty)
				printf("   |");
			else  if (a == adjacent)
				printf("   |");
			else
				printf(" # |");

		}

		printf("\n  -");
		for (int i = 0; i < boardToPrint.size; i++)
			printf("----");
		printf("\n");

	}

	Sleep(2000);

}