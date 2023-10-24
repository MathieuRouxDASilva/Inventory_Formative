#pragma once
#include <vector>

#include "Items.h"
//function to manage items with an inventory
class GlobalInventory
{

	std::vector<Item*> Storage;

public:
	//all functions
	void Add(Item& additem);
	void Display();
	Item* EraseElement(Item* item, int number);
	void Save(const std::string& Save1);
	Item* UseOne(int unsigned number);
	int FindPosition(Item* element);
	bool IsItemAtPosition(int position, Item* itemToCheck);
};
//extern variables
extern char Question;
extern bool Answer;