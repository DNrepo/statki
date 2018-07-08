#pragma once


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
	S_game,
	S_settings
} S_states;

typedef struct settings
{
	int a;
}settings;