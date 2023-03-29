#include "Deck.h"
#include <iostream>
#pragma warning(disable: 4996)

int Deck::getMonsterCount() const
{
    return monstersCount;
}

int Deck::getSpellsCount() const
{
    return spellsCount;
}

void Deck::addMonster(MonsterCard& monster)
{
    monsters[monstersCount++] = monster;
}

void Deck::addSpell(MagicCard& spell)
{
    spells[spellsCount++] = spell;
}

void Deck::changeMonster(int index, MonsterCard& monster)
{
    if (index >= monstersCount) {
        std::cout << "no card at this index";
        return;
    }

    monsters[index] = monster;
}

void Deck::changeSpell(int index, MagicCard& spell)
{
    if (index >= spellsCount) {
        std::cout << "no card at this index";
        return;
    }

    spells[index] = spell;
}

void Deck::removeMonster(int index)
{
    shiftLeft(monsters, index, monstersCount--);
}

void Deck::removeSpell(int index)
{
    shiftLeft(spells, index, spellsCount--);
}

template <typename T>
void Deck::shiftLeft(T* arr, int start, int end) const {
    for (int i = start; i < end - 1; i++)
        arr[i] = arr[i + 1];
}
