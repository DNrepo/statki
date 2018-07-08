
#include "board.h"
#include "consts.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void printBoard(board_struct shipsBoard, board_struct shootsBoard)
{
	system("cls");
	printf("  Dominik Nowocien PK 2017/2018  \n");
	printf("  statki  \n\n");


	printf("      0   1   2   3   4   5   6   7   8   9             0   1   2   3   4   5   6   7   8   9 ");
	
	printf("\n    -");
	for (int i = 0; i < shipsBoard.size; i++)
		printf("----");

	printf("         -");
	for (int i = 0; i < shipsBoard.size; i++)
		printf("----");
	printf("\n");

	for (int i = 0; i < shipsBoard.size; i++)
	{


		printf("  ");
		printf("%i",i);
		printf(" |");

		for (int j = 0; j < shipsBoard.size; j++)
		{
			int a = shipsBoard.board[coordinatesXYtoIndex(i, j, shipsBoard.size)];

			if (a == empty)
				printf("   |");
			else  if (a == adjacent)
				printf("   |");
			else  if (a == busy)
				printf(" # |");
			else  if (a == unused)
				printf("   |");
			else  if (a == hit)
				printf(" * |");
			else  if (a == miss)
				printf(" @ |");
			else
				printf("   |");

		}


		printf("       ");
		printf("%i", i);
		printf(" |");
		for (int j = 0; j < shootsBoard.size; j++)
		{
			int a = shootsBoard.board[coordinatesXYtoIndex(i, j, shootsBoard.size)];

			if (a == empty)
				printf("   |");
			else  if (a == adjacent)
				printf("   |");
			else  if (a == busy)
				printf(" # |");
			else  if (a == unused)
				printf("   |");
			else  if (a == hit)
				printf(" * |");
			else  if (a == miss)
				printf(" @ |");
			else
				printf("   |");

		}

		printf("\n    -");
		for (int i = 0; i < shipsBoard.size; i++)
			printf("----");

		printf("         -");
		for (int i = 0; i < shipsBoard.size; i++)
			printf("----");
		printf("\n");

	}

	printf("\n\n");


}