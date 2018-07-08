 

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "bool.h"
#include "menu.h"





struct settings Settings(settings set)
{

	while (1)
	{
		system("cls");
		printf("  Dominik Nowocien PK 2017/2018  \n");
		printf("  statki  \n");
		printf("  1 - tu  \n");
		printf("  2 - jjakies  \n");
		printf("  0 - wyjscie  \n");

		int keyPressed = _getch();

		switch (keyPressed - 48)
		{
		case S_game: //gra
		{
			//gameStart(settings) ;
			break;
		}
		case S_settings: //wyjscie
		{
			break;
		}
		case S_end: //wyjscie
		{
			return set ;
		}
		}
	}

	 
return set ;


}

 

void menu()
{

	settings game_settings;

	game_settings.a = 2;
	while(1)
	{
		system("cls");
		printf("  Dominik Nowocien PK 2017/2018  \n");
		printf("  statki  \n");
		printf("  1 - graj  \n");
		printf("  2 - opcje  \n");
		printf("  0 - wyjscie  \n");

		int keyPressed = _getch();

		switch (keyPressed - 48)
		{
		case M_game: //gra
		{
			gameStart(game_settings) ;
			break;
		}
		case M_settings: //wyjscie
		{ 
			game_settings = Settings(game_settings);
			break;
		}
		case M_end: //wyjscie
		{
			return ;
		}
		}
	} 
}