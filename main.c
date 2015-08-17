#include <stdlib.h>
#include "game.h"
#include "capitals.h"
#include "constants.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	Item *items = NULL;
	
	FILE *file = fopen(FILE_NAME, FILE_ACCESS_MODE);
	
	if(!file)
	{
		puts("Cannot reach dictionary file.");
	}
	else
	{
		// Check if the text file is empty
		if(fileIsEmpty(file) == FILE_IS_EMPTY)
			puts("The dictionary file is empty.");
		// else start the game
		else
		{			
			while(startGame(getItems(file)) == PLAY_AGAIN);
			/*  so that each time the user starts a new game,
				the items are loaded once more from the text
				file, just in case the text file was updated.
			*/
		}
	}
	
	return 0;
}
