#pragma once
#include "Items.h"
//class potion
class Potion : public Item
{
protected:
	int HealStat;
public:
	Potion(int healstat, std::string name) : Item(name), HealStat(healstat) {};

	void Use() override;
};
