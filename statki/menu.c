 

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "bool.h"
#include "menu.h"
#include "consts.h"





struct settings Settings(settings set)
{


	while (1)
	{
		system("cls");
		printf("  Dominik Nowocien PK 2017/2018  \n");
		printf("  statki  \n");
		for (int i = 0; i < MASTS; i++)
		printf("  %i - ilosc statkow %i-masztowych: %i \n",i+1,i+1,set.masts[i] );

		printf("  9 -rozmiar planszy %ix%i  \n",set.size, set.size);
		printf("  0 - wyjscie  \n");

		int keyPressed = _getch();

		if ((keyPressed - 48) == M_end)
			return set;

		if ((keyPressed - 48) < MASTS)
		{
			int i = (keyPressed - 48);
			set.masts[i - 1]++;
			if (set.masts[i - 1] > MASTS - i)
				set.masts[i - 1] = 0;

		}
	}

	 
return set ;


}

 

void menu()
{

	settings game_settings;

	for (int i = 0; i < MASTS; i++)
		game_settings.masts[i] = MASTS - i;
	game_settings.size = 10;

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