#pragma once

#include "consts.h"

void menu(); 



typedef enum M_states
{
	M_end,
	M_game,
	M_settings
} M_states;


typedef enum S_states
{
	S_end,
	S_size = 9
} S_states;

typedef struct settings
{
	int masts[MASTS];
	int size;		
}settings;