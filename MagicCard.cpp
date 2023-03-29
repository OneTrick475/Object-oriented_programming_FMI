#include "MagicCard.h"
#include <iostream>
#pragma warning(disable: 4996)

MagicCard::MagicCard(const char* name, const char* effect, SpellType type) : type(type)
{
    setName(name);
    setEffect(effect);
}

void MagicCard::setName(const char* name)
{
    if (strlen(name) > nameLen) {
        return;
    }
    strcpy(this->name, name);
}

void MagicCard::setEffect(const char* effect)
{
    if (strlen(effect) > effectLen) {
        return;
    }
    strcpy(this->effect, effect);
}

void MagicCard::setType(SpellType type)
{
    this->type = type;
}

const char* MagicCard::getName() const
{
    return name;
}

const char* MagicCard::getEffect() const
{
    return effect;
}

SpellType MagicCard::getType() const
{
    return type;
}
