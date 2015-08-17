#pragma once

#include "capitals.h"

int startGame(Item *items);
void showWelcomeMessage(char **name);
char* toUppercase(char *string);
int getItemsCount(Item *items);
game_difficulty getGameMode();
game_challenges getGameChallenges(game_difficulty dif);
char* toString(game_difficulty dif);
player_choice playAgain();
