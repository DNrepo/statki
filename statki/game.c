
#include "bool.h"
#include "menu.h"
#include "board.h"
#include "print.h"



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


bool checkIfWin(board_struct board)
{
	//sprawdza czy wystêpuj¹ jeszcze jakies nietrafione statki
	for (int i = 0; i < board.size*board.size; i++)
		if (board.board[i] == busy)
			return false;
	return true;
}


void opponentMove(board_struct *opponentShootsBoard, board_struct *playerBoard)
{
	int index;

	do
	{
		index = rand() % ((*opponentShootsBoard).size*(*opponentShootsBoard).size);

	} while ( (*opponentShootsBoard).board[index] != unused);

	if ((*playerBoard).board[index] == busy)
	{
		(*opponentShootsBoard).board[index] = hit;
		(*playerBoard).board[index] = hit;
	}
	else
		(*opponentShootsBoard).board[index] = miss;

}

void playerMove(board_struct *playerShootsBoard, board_struct *opponentShipsBoard)
{
	int x,y,index;


	do
	{

		do
		{
			printf("  Wprowadz numer wiersza\n  ");
			scanf("%d", &x);
		} while (!((x < 10) && (x >= 0)));

		do
		{
			printf("  Wprowadz numer kolumny\n  ");
			scanf("%d", &y);
		} while (!((y < 10) && (y >= 0)));

		index = read(x, y, playerShootsBoard->size);

	} while (playerShootsBoard->board[index] != unused);

	if (opponentShipsBoard->board[index] == busy)
	{
		playerShootsBoard->board[index] = hit;
		opponentShipsBoard->board[index] = hit;
	}

	else
		playerShootsBoard->board[index] = miss;

}


void gameStart(settings game_settings)
{


	board_struct playerShipsBoard = newRandomBoard(game_settings);
	board_struct playerShootsBoard = newBoard(game_settings.size, unused);


	board_struct opponentShipsBoard = newRandomBoard(game_settings);
	board_struct opponentShootsBoard = newBoard(game_settings.size, unused);


	int a = 0; 
	while (1)
	{

		 
		opponentMove(&opponentShootsBoard, &playerShipsBoard);
		if (checkIfWin(playerShipsBoard))
			//opponent win;
		{
			a = 1;
			break;
		}

		playerMove(&playerShootsBoard, &opponentShipsBoard );		
		if (checkIfWin(opponentShipsBoard))
			//opponent win;
		{
			a = 2;
			break;
		}

		printBoard(playerShipsBoard, playerShootsBoard);
		 
	} 




	if (a = 1 )
		printf(" Wygral komputer\n");
	else
		printf(" Wygral gracz\n");

	Sleep(2000);
}