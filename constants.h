#pragma once

#define FILE_NAME "dictionary.txt"
#define FILE_ACCESS_MODE "r"
#define FILE_LINE_LENGTH 30
#define FILE_SEPARATOR "/"

typedef enum {
	FILE_IS_EMPTY,
	FILE_IS_NOT_EMPTY
}file_status;

typedef enum {
	PLAY_AGAIN,
	QUIT_GAME
}player_choice;

typedef enum {
	GAME_RUNNING,
	GAME_END
}game_status;

typedef enum {
	EASY,
	MEDIUM,
	HARD
}game_difficulty;

typedef enum {
	EASY_MODE_CHALLENGES = 10,
	MEDIUM_MODE_CHALLENGES = 30,
	HARD_MODE_CHALLENGES = 60
}game_challenges;
