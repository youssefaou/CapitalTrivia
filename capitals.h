#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

typedef struct {
	char *country;
	char *capital;
	int order; // used to keep track of the size of the 'items' array
}Item;

game_status fileIsEmpty(FILE *file);
Item* getItems(FILE *file);
