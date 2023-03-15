#include <iostream>
#pragma warning(disable : 4996)

class Game {
	private:
		int price;
		char title[26];
		bool isAvailable;

	public: 
		Game() {}

		Game(const char* title, int price, bool isAvailable) {
			this->price = price;
			this->isAvailable = isAvailable;
			std::strcpy(this->title, title);
		}

		void setPrice(int price) {
			this->price = price;
		}
		void setIsAvailable(bool isAvailable) {
			this->isAvailable = isAvailable;
		}
		void setTitle(const char* title) {
			std::strcpy(this->title, title);
		}
		
		int getPrice() const{
			return price;
		}
		bool getIsAvailable() const{
			return isAvailable;
		}
		const char* getTitle() const {
			return this->title;
		}

		bool isFree() const {
			return price == 0;
		}
		void print() const {
			std::cout << title << ' ' << price << '$' << ' ' << (isAvailable ? "Available" : "Unavailable") << std::endl;
		}
		
};

class GamePlatform {
	private:
		static const int maxNumOfGames = 40;
		int numberOfGames = 0;
		Game games[maxNumOfGames];

	public:
		void addGame(const Game& game) {
			if (numberOfGames >= maxNumOfGames) {
				std::cout << "Full";
				return;
			}

			games[numberOfGames++] = game;
		}
		Game getGameByIndex(int index) const{
			return games[index];
		}
		void printTitles() const {
			for (int i = 0; i < numberOfGames; i++) {
				std::cout << games[i].getTitle() << std::endl;
			}
		}

		void printCheapest() const {
			int indexOfCheapest = 0;

			for (int i = 1; i < numberOfGames; i++) {
				if (games[i].getPrice() < games[indexOfCheapest].getPrice()) {
					indexOfCheapest = i;
				}
			}
			games[indexOfCheapest].print();
		}
		void printMostExpensive() const {
			int indexOfMostExpensive = 0;

			for (int i = 1; i < numberOfGames; i++) {
				if (games[i].getPrice() > games[indexOfMostExpensive].getPrice()) {
					indexOfMostExpensive = i;
				}
			}
			games[indexOfMostExpensive].print();
		}

		void printFree() const {
			for (int i = 0; i < numberOfGames; i++) {
				if (games[i].isFree()) {
					 games[i].print();
				}
			}
		}

		void removeAt(int index) {
			for (int i = index; i < numberOfGames; i++) {
				games[i] = games[i + 1];
			}
			numberOfGames--;
		}

		void removeGame(const char* title) {
			for (int i = 0; i < numberOfGames; i++) {
				if (!std::strcmp(title, games[i].getTitle())) {
					removeAt(i);
					return;
				}
			}
		}
};

int main() {
	Game thewitcher("The Witcher", 40, true);
	Game godofwar("God of war", 30, false);
	Game control("Control", 0, true);

	thewitcher.print();

	GamePlatform platform;

	platform.addGame(thewitcher);
	platform.addGame(godofwar);
	platform.addGame(control);

	platform.removeGame("The Witcher");

	platform.getGameByIndex(0).print();

	platform.printTitles();

	platform.printCheapest();
	platform.printMostExpensive();

	platform.printFree();
}
