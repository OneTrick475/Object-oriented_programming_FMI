#pragma once
#include "MonsterCard.h"
#include "MagicCard.h"

class Deck {
private:
	MonsterCard monsters[20];
	int monstersCount = 0;
	MagicCard spells[20];
	int spellsCount = 0;

	template <typename T>
	void shiftLeft(T* arr, int start, int end) const;

public:
	int getMonsterCount() const;
	int getSpellsCount() const;

	void addMonster(MonsterCard& monster);
	void addSpell(MagicCard& spell);

	void changeMonster(int index, MonsterCard& monster);
	void changeSpell(int index, MagicCard& spell);

	void removeMonster(int index);
	void removeSpell(int index);
};