#pragma once
#include "Items.h"
//class map
class Map : public Item
{
protected:
	std::string ReavaledLocation;
public:
	Map(std::string reavelLocation, std::string name) : Item(name), ReavaledLocation(reavelLocation) {};

	void Use() override;
};

