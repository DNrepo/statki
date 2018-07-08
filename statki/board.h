#pragma once

#include "consts.h"

#include "menu.h"

typedef enum field
{
	empty,
	adjacent,
	busy, 

	hit,
	miss,
	unused,

} field;
 


typedef struct board_struct
{
	int *board; 
	int size;
	
}board_struct;


int read(int x, int y, int size);

board_struct newBoard( int boardSize,int wypelnienie); 
board_struct newRandomBoard(settings game_settings);
