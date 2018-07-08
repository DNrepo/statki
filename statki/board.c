
#include "board.h"
#include "consts.h"
#include "bool.h"
#include "listaPomocnicza.h" 

int read(int x, int y, int size)
{
	return x * size + y ;
}


board_struct newBoard(int boardSize)
{
	board_struct boardToReturn;
	boardToReturn.board= malloc(sizeof(int)* boardSize*boardSize);
	boardToReturn.size = boardSize;

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			boardToReturn.board[read(i, j,boardToReturn.size)] = empty;
		}
	}
	return boardToReturn;
}


board_struct copyToBigerBoard(int newBoardSize,board_struct boardToCopy)
{
	board_struct boardToReturn = newBoard(newBoardSize);

	for (int i = 1; i < newBoardSize; i++)
	{
		for (int j = 1; j < newBoardSize; j++)
		{
			boardToReturn.board[read(i, j, newBoardSize)] = boardToCopy.board[read(i-1,j-1, boardToCopy.size)] ;
		}
	}
	return boardToReturn;
}




void analizujPodKatemJedynki(board_struct boardToReturn)
{

	board_struct possibleBoard = newBoard(boardToReturn.size + 2);
	int possibleFieldsCount = 0;

	for (int i = 1; i < boardToReturn.size + 1; i++)
	{
		for (int j = 1; j < boardToReturn.size + 1; j++)
		{
			bool possibleToPlace = true;
			for (int a = i + 1; a < 3; a++)
				for (int b = j + 1; b < 3; b++)

					if (boardToReturn.board[read(a, b, boardToReturn.size)] != empty)
						possibleToPlace = false;

			if (possibleToPlace)
			{
				possibleFieldsCount++;
				possibleBoard.board[read(i, j, boardToReturn.size)] = possible;
			}
		}
	}

	if (possibleFieldsCount > 0)
	{
		int i = 0;
		int *possibleArray = malloc(sizeof(int) *possibleFieldsCount);

		for (int a = 0; a < boardToReturn.size; a++)
			for (int b = 0; b < boardToReturn.size; b++)

				if (boardToReturn.board[read(a, b, boardToReturn.size)] != possible)
				{
					possibleArray[i] = read(a, b, boardToReturn.size);
					i++;
				}
	}
	 

}




void add3(board_struct boardToReturn)
{

	board_struct possibleBoard = newBoard(boardToReturn.size + 2);
	int possibleFieldsCount = 0;

	for (int i = 1; i < boardToReturn.size + 1; i++)
	{
		for (int j = 1; j < boardToReturn.size + 1; j++)
		{
			bool possibleToPlace = true;
			for (int a = i + 1; a < 3; a++)
				for (int b = j + 1; b < 3; b++)

					if (boardToReturn.board[read(a, b, boardToReturn.size)] != empty)
						possibleToPlace = false;

			if (possibleToPlace)
			{
				possibleFieldsCount++;
				possibleBoard.board[read(i, j, boardToReturn.size)] = possible;
			}
		}
	}

	if (possibleFieldsCount > 0)
	{
		int i = 0;
		int *possibleArray = malloc(sizeof(int) *possibleFieldsCount);

		for (int a = 0; a < boardToReturn.size; a++)
			for (int b = 0; b < boardToReturn.size; b++)

				if (boardToReturn.board[read(a, b, boardToReturn.size)] != possible)
				{
					possibleArray[i] = read(a, b, boardToReturn.size);
					i++;
				}
	}






}


board_struct dodajJedynke(board_struct boardToReturn)
{

}


board_struct addFourMastedShip(board_struct boardToReturn)
{
	int direction = (int)(rand() % 2);

	int x, y;
	if (direction < 1)//pionowo
	{
		x = (int)(rand() % (boardToReturn.size));
		y = (int)(rand() % (boardToReturn.size - four_masted_size));
		for (int i = 0; i < four_masted_size; i++)
			boardToReturn.board[read(x, y + i, boardToReturn.size)] = busy;
	}
	else
	{
		x = (int)(rand() % (boardToReturn.size - four_masted_size));
		y = (int)(rand() % (boardToReturn.size));

		for (int i = 0; i < four_masted_size; i++)
			boardToReturn.board[read(x + i, y, boardToReturn.size)] = busy;
	}

	return boardToReturn;
}

 




board_struct newRandomBoard()
{

	board_struct player_board1 = newBoard(BoardSize);

	player_board1 = addFourMastedShip(player_board1);

	 


	return player_board1;

}