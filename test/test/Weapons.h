#pragma once
#include "Items.h"

class Weapons : public Item
{

	int Atk;

public:

	Weapons(int atk, std::string name) : Item(name), Atk(atk) {};

	void Use();
};

