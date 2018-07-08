
#include "board.h"
#include "consts.h"

void printBoard(board_struct boardToPrint)
{
	system("cls");
	printf("  Dominik Nowocien PK 2017/2018  \n");
	printf("  statki  \n");

	for (int i = 0; i < boardToPrint.size; i++)
	{


		printf("|");
		for (int j = 0; j < boardToPrint.size; j++)
		{
			int a = boardToPrint.board[read(i, j, boardToPrint.size)];

			if ((a == adjacent) || (a == empty))
				printf(" |");
			else
				printf("#|");

		}

		printf("\n-----------------\n");

	}

}