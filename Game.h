#pragma once

class Game {
private:
	int price;
	char* title;
	bool isAvailable;

public:
	Game();

	Game(const char* title, int price, bool isAvailable);

	Game(const Game& game);

	Game& operator=(const Game&);

	void setPrice(int price);

	void setIsAvailable(bool isAvailable);

	void setTitle(const char* title);

	int getPrice() const;

	bool getIsAvailable() const;

	const char* getTitle() const;

	bool isFree() const;

	void print() const;

	~Game();
};