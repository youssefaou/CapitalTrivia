#include "constants.h"
#include "capitals.h"
#include <time.h>

game_status fileIsEmpty(FILE *file)
{
	fseek(file, 0, SEEK_END);
	
	if(! ftell(file))
		return FILE_IS_EMPTY;
	else
		return FILE_IS_NOT_EMPTY;
}

Item* getItems(FILE *file) // from the text file
{
	Item *items = NULL;
	Item *rand_items = NULL;
	int counter = 0;
	
	// Seek the beginning of the text file 
	fseek(file, 0, SEEK_SET);
	
	while(! feof(file)) 
	{
		char *str = malloc(sizeof(char) * FILE_LINE_LENGTH);
				
		items = realloc(items, sizeof(Item) * (counter + 1)); // Resize the 'items' array to contain a new 'item'
		rand_items = realloc(rand_items, sizeof(Item) * (counter + 1));
		items[counter].country = malloc(sizeof(char) * 20); // Allocate memory
		items[counter].capital = malloc(sizeof(char) * 20);
		rand_items[counter].country = malloc(sizeof(char) * 20); // Allocate memory
		rand_items[counter].capital = malloc(sizeof(char) * 20);
		fgets(str, FILE_LINE_LENGTH, file); // Retrieve 1 line from the text file
		items[counter].country = (char*) strtok(str, FILE_SEPARATOR); // Extract the country from the "str" string
		items[counter].capital = (char*) strtok(NULL, FILE_SEPARATOR); // Extract the capital from the "str" string
		items[counter].capital = (char*) strtok(items[counter].capital, "\n");
		
		counter++;
		items[counter - 1].order = counter;
	}
	
	items[counter - 1].order = 0;
	
	int i = 0, max = counter;
	srand(time(NULL));
	
	while(max > 0)
	{
		int random = rand() % max;
		Item item;
		
		rand_items[i] = items[random];
		item = items[random];
		items[random] = items[max - 1];
		items[max - 1] = item;
		items = realloc(items, sizeof(Item) * (max - 1));
		i++;
		max--;
	}
	
	return rand_items;
}
