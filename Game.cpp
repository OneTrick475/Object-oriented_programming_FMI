#include <iostream>
#include "Game.h"
#pragma warning(disable : 4996)

Game::Game() {
	this->price = 0;
	this->isAvailable = false;
	this->title = new char[6];
	strcpy(this->title, "undef");
}

Game& Game::operator=(const Game& game) {
	price = game.price;
	isAvailable = game.isAvailable;

	delete[] title;

	this->title = new char[strlen(game.title) + 1];
	strcpy(title, game.title);

	return *this;
}

Game::Game(const char* title, int price, bool isAvailable) {
	this->price = price;
	this->isAvailable = isAvailable;

	this->title = new char[strlen(title) + 1];
	std::strcpy(this->title, title);
}

Game::Game(const Game& game) {
	price = game.price;
	isAvailable = game.isAvailable;

	this->title = new char[strlen(game.title) + 1];
	std::strcpy(this->title, game.title);
}

void Game::setPrice(int price) {
	this->price = price;
}

void Game::setIsAvailable(bool isAvailable) {
	this->isAvailable = isAvailable;
}

void Game::setTitle(const char* title) {
	delete[] this->title;
	this->title = new char[strlen(title) + 1];

	std::strcpy(this->title, title);
}

int Game::getPrice() const {
	return price;
}
bool Game::getIsAvailable() const {
	return isAvailable;
}

const char* Game::getTitle() const {
	return this->title;
}

bool Game::isFree() const {
	return price == 0;
}
void Game::print() const {
	std::cout << title << ' ' << price << '$' << ' ' << (isAvailable ? "Available" : "Unavailable") << std::endl;
}

Game::~Game() {
	if(title)
		delete[] title;
}