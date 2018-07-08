#pragma once

#include "consts.h"

typedef enum field
{
	empty,
	adjacent,
	busy,
	possible

} field;
 


typedef struct board_struct
{
	int *board; 
	int size;
	
}board_struct;


int read(int x, int y);

board_struct newBoard( int boardSize);
board_struct newRandomBoard(); 
