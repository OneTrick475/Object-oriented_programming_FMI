#pragma once

const int nameLen = 25;
const int effectLen = 100;

enum class SpellType {
	trap,
	buff,
	spell
};

class MagicCard {
private:
	char name[nameLen + 1];
	char effect[effectLen + 1];
	SpellType type;

public:
	MagicCard() = default;
	MagicCard(const char* name, const char* effect, SpellType type);

	void setName(const char* name);
	void setEffect(const char* effect);
	void setType(SpellType type);
	const char* getName() const;
	const char* getEffect() const;
	SpellType getType() const;
};