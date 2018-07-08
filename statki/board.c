
#include "board.h"
#include "consts.h"
#include "bool.h" 
#include "print.h" 
#include "possiblePostionOfShip.h" 

#include "menu.h"

int read(int x, int y, int size)
{
	return x * size + y ;
}


board_struct newBoard(int boardSize,int wypelnienie)
{
	board_struct boardToReturn;
	boardToReturn.board= malloc(sizeof(int)* boardSize*boardSize);
	boardToReturn.size = boardSize;

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			boardToReturn.board[read(i, j,boardToReturn.size)] = wypelnienie;
		}
	}
	return boardToReturn;
}


board_struct copyToBigerBoard(board_struct boardToCopy)
{
	board_struct boardToReturn = newBoard(boardToCopy.size + 2, adjacent);

	for (int i = 1; i < (boardToReturn.size - 1); i++)
	{
		for (int j = 1; j < (boardToReturn.size - 1); j++)
		{
			boardToReturn.board[read(i, j, boardToReturn.size)] = boardToCopy.board[read(i - 1, j - 1, boardToCopy.size)];
		}
	}
	return boardToReturn;
}

board_struct copyToSmallerBoard(board_struct boardToCopy)
{
	board_struct boardToReturn = newBoard(boardToCopy.size -2, empty);

	for (int i = 0; i < boardToReturn.size; i++)
	{
		for (int j = 0; j < boardToReturn.size; j++)
		{
			boardToReturn.board[read(i, j, boardToReturn.size)] = boardToCopy.board[read(i + 1, j + 1, boardToCopy.size)];
		}
	}
	return boardToReturn;
}





board_struct update(board_struct boardToReturn)
{

	board_struct possibleBoard = copyToBigerBoard(boardToReturn);


	for (int i = 1; i < possibleBoard.size - 1; i++)
	{
		for (int j = 1; j < possibleBoard.size - 1; j++)
		{
			if (possibleBoard.board[read(i, j, possibleBoard.size)] == busy)
			{
				for (int a = (i - 1); a < (i + 2); a++)
					for (int b = (j - 1); b < (j + 2); b++)

						if (possibleBoard.board[read(a, b, possibleBoard.size)] == empty)
							possibleBoard.board[read(a, b, possibleBoard.size)] = adjacent;
			}
			 
		}
	}


	board_struct toReturn = copyToSmallerBoard(possibleBoard);


	return toReturn;

}








board_struct addShip(board_struct boardToReturn,int shipSize)
{
	boardToReturn = update(boardToReturn);

	possiblePostionOfShip *posHead = malloc(sizeof(int));

	int possibleCount = 0;

	for (int i = 0; i < boardToReturn.size - shipSize; i++)
		for (int j = 0; j < boardToReturn.size; j++)
		{
			bool possible = true;

			for (int a = i; a < (i + shipSize); a++)
				if (boardToReturn.board[read(a, j, boardToReturn.size)] != empty)
					possible = false;

			if (possible)
			{
				possibleCount++;
			    possiblePostionOfShip *newPos = (possiblePostionOfShip*)malloc(sizeof(possiblePostionOfShip));
				newPos->x = i;
				newPos->y = j;
				newPos->direction = 1;
				newPos->next = posHead;
				posHead = newPos;
			}
		}


	for (int i = 0; i < boardToReturn.size ; i++)
		for (int j = 0; j < boardToReturn.size - shipSize; j++)
		{
			bool possible = true;

			for (int a = j; a < (j + shipSize); a++)
				if (boardToReturn.board[read(i, a, boardToReturn.size)] != empty)
					possible = false;

			if (possible)
			{
				possibleCount++;
				possiblePostionOfShip *newPos = (possiblePostionOfShip*)malloc(sizeof(possiblePostionOfShip));
				newPos->x = i;
				newPos->y = j;
				newPos->direction = 2;
				newPos->next = posHead;
				posHead = newPos;
			}
		}


	if (possibleCount > 0)
	{
		int a = rand() % possibleCount;
		for (int i = 0; i < a; i++)
		{
			posHead = posHead->next;
		}


		for (int i = 0; i < shipSize; i++)
			if (posHead->direction == 1)
				boardToReturn.board[read(((posHead->x) + i), posHead->y, boardToReturn.size)] = busy;
			else
				boardToReturn.board[read(posHead->x, ((posHead->y) + i), boardToReturn.size)] = busy;

	}
	else
	{
		//return newBoard(boardToReturn.size, busy);
	}

	return boardToReturn;

}








board_struct newRandomBoard(settings game_settings)
{

	board_struct player_board1 = newBoard(game_settings.size,empty);


	for (int i = 0; i < MASTS; i++)
	{
		for (int j = 0; j < game_settings.masts[i]; j++)
			player_board1 = addShip(player_board1, i+1);
	}


	player_board1 = update(player_board1);

	return player_board1;

}