#include <string.h>
#include "game.h"
#include "constants.h"

int startGame(Item *items)
{
	char *playerName = NULL;
	char *answer = NULL;
	game_status gameStatus = GAME_RUNNING;
	game_difficulty gameMode;
	game_challenges challenges;
	int currentChallenge = 1; // keeps track of the level reached by the user
	
	gameMode = getGameMode();
	challenges = getGameChallenges(gameMode);

	showWelcomeMessage(&playerName);
	
	while(gameStatus == GAME_RUNNING)
	{
		printf("\n\n\nLevel %d :\n", currentChallenge);
		printf("What is the capital of %s ?\n", items[currentChallenge - 1].country);
			
		answer = malloc(sizeof(char) * 20);
		gets(answer);
		answer = toUppercase(answer);
			
		if(strcmp(answer, toUppercase(items[currentChallenge - 1].capital)) != 0)
		{
			gameStatus = GAME_END;
			printf("Unfortunately, that's incorrect... The correct answer is \"%s\". Better luck next time !\n\n\n", items[currentChallenge - 1].capital);
		}
		else
		{
			if(currentChallenge == challenges)
			{
				puts("And... WE HAVE A WINNER!\n\n");
				printf("Player name: %s\n", playerName);
				printf("Game mode: %s\n", toString(gameMode));
				printf("\n%s mode CONQUERED.\n", toString(gameMode));
				gameStatus = GAME_END;
			}
			else
			{
				printf("\nThat's correct ! Advancing now to level %d ...\n\n", (currentChallenge + 1));
				currentChallenge++;
			}
		}
	}
	
	return playAgain();
}

void showWelcomeMessage(char **name)
{
	*name = malloc(sizeof(char) * 30);
	
	puts("Type your alias:");
	gets(*name);
	*name =  toUppercase(*name);
	printf("Welcome, %s, to CapitalTrivia.\n", *name);
}

char* toUppercase(char *string)
{
	int i = 0;
	
	for(i = 0; string[i] != '\0'; i++)
	{
		string[i] = (char) toupper(string[i]);
	}
	
	return string;
}

int getItemsCount(Item *items) // Get the total number of items
{
	int i = 0;
	int count = 0;
	
	for(; items[i].order != 0; i++, count++);
	
	return ++count; // The item with the order of 0 is the last one, so we must add 1 to the 'count' variable
}

game_difficulty getGameMode()
{
	char *mode = NULL;
	game_difficulty dif;
	
	puts("\n\n\n\nPossible difficulties:");
	puts("\t1.Easy");
	puts("\t2.Medium");
	puts("\t3.Hard\n");
	
	fflush(stdin);
	mode = malloc(sizeof(char) * 10);
	do
	{
		puts("Choose difficulty:");
		gets(mode);
		mode = toUppercase(mode);
		if(strcmp(mode, "1") == 0)
			strcpy(mode, "EASY");
		else if(strcmp(mode, "2") == 0)
			strcpy(mode, "MEDIUM");
		else if(strcmp(mode, "3") == 0)
			strcpy(mode, "HARD");
			
		if(strcmp(mode, "EASY") == 0)
		{
			printf("\nYou chose the Easy difficulty.\n\n");
			return EASY;
		}
		else if(strcmp(mode, "MEDIUM") == 0)
		{
			printf("\nYou chose the Medium difficulty.\n\n");
			return MEDIUM;
		}
		else if(strcmp(mode, "HARD") == 0)
		{
			printf("\nYou chose the Hard difficulty.\n\n");
			return HARD;
		}
			
	}while(1);
}

game_challenges getGameChallenges(game_difficulty dif)
{
	if(dif == EASY)
		return EASY_MODE_CHALLENGES;
	else if(dif == MEDIUM)
		return MEDIUM_MODE_CHALLENGES;
	else if(dif == HARD)
		return HARD_MODE_CHALLENGES;
}

char* toString(game_difficulty dif)
{
	if(dif == EASY)
		return "EASY";
	else if(dif == MEDIUM)
		return "MEDIUM";
	else if(dif == HARD)
		return "HARD";
}

player_choice playAgain()
{
	return QUIT_GAME;
}

