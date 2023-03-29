#pragma once

class MonsterCard {
private:
	char* name = nullptr;
	unsigned attack;
	unsigned defense;

	void copyFrom(MonsterCard& other);

public:
	MonsterCard();
	MonsterCard(const char* name, unsigned attack, unsigned defense);
	MonsterCard(MonsterCard& other);
	MonsterCard& operator=(MonsterCard& other);
	~MonsterCard();

	const char* getName() const;
	int getAttack() const;
	int getDefense() const;
	void setName(const char* name);
	void setAttack(unsigned attack);
	void setDefense(unsigned defense);
};