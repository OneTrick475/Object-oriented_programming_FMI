#include <iostream>
#include "GamePlatform.h"
#include "Game.h"

void GamePlatform::addGame(const Game& game) {
	if (numberOfGames >= maxNumOfGames) {
		std::cout << "Full";
		return;
	}
	games[numberOfGames++] = game;
}

Game GamePlatform::getGameByIndex(int index) const {
	return games[index];
}

void GamePlatform::printTitles() const {
	for (int i = 0; i < numberOfGames; i++) {
		std::cout << games[i].getTitle() << std::endl;
	}
}

void GamePlatform::printCheapest() const {
	int indexOfCheapest = 0;

	for (int i = 1; i < numberOfGames; i++) {
		if (games[i].getPrice() < games[indexOfCheapest].getPrice()) {
			indexOfCheapest = i;
		}
	}
	games[indexOfCheapest].print();
}

void GamePlatform::printMostExpensive() const {
	int indexOfMostExpensive = 0;

	for (int i = 1; i < numberOfGames; i++) {
		if (games[i].getPrice() > games[indexOfMostExpensive].getPrice()) {
			indexOfMostExpensive = i;
		}
	}
	games[indexOfMostExpensive].print();
}

void GamePlatform::printFree() const {
	for (int i = 0; i < numberOfGames; i++) {
		if (games[i].isFree()) {
			games[i].print();
		}
	}
}

void GamePlatform::removeAt(int index) {
	for (int i = index; i < numberOfGames; i++) {
		games[i] = games[i + 1];
	}
	numberOfGames--;
}

void GamePlatform::removeGame(const char* title) {
	for (int i = 0; i < numberOfGames; i++) {
		if (!std::strcmp(title, games[i].getTitle())) {
			removeAt(i);
			return;
		}
	}
}