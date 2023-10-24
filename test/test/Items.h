#pragma once
#include <string>
//class item
class Item
{
protected:
	std::string Name;
public:
	Item(std::string name);
	std::string GetName() { return Name; }
	virtual void Use() = 0;
};
