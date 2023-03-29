#include "MonsterCard.h"
#include <iostream>
#pragma warning(disable: 4996)

MonsterCard::MonsterCard() {
	name = new char[1];
	name[0] = '\0';
	attack = defense = 0;
}

MonsterCard::MonsterCard(const char* name, unsigned attack, unsigned defense) : attack(), defense() {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

MonsterCard::MonsterCard(MonsterCard& other) {
	copyFrom(other);
}

MonsterCard& MonsterCard::operator=(MonsterCard& other) {
	if (this == &other) {
		return *this;
	}
	delete[] name;
	copyFrom(other);
	return *this;
}

MonsterCard::~MonsterCard() {
	delete[] name;
}

void MonsterCard::copyFrom(MonsterCard& other) {
	attack = other.attack;
	defense = other.defense;

	setName(other.name);
}

const char* MonsterCard::getName() const{
	return this->name;
}

int MonsterCard::getAttack() const{
	return attack;
}

int MonsterCard::getDefense() const{
	return defense;
}

void MonsterCard::setName(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void MonsterCard::setAttack(unsigned attack){
	this->attack = attack;
}

void MonsterCard::setDefense(unsigned defense){
	this->defense = defense;
}
