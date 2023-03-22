#include <iostream>
#include "Game.h"
#pragma once

class GamePlatform {
private:
	static const int maxNumOfGames = 40;
	int numberOfGames = 0;
	Game games[maxNumOfGames];

public:
	void addGame(const Game& game);

	Game getGameByIndex(int index) const;

	void printTitles() const;

	void printCheapest() const;

	void printMostExpensive() const;

	void printFree() const;

	void removeAt(int index);

	void removeGame(const char* title);
};