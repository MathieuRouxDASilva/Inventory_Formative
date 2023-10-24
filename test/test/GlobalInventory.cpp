#include "GlobalInventory.h"
#include <fstream>
#include <iostream>
#include "Items.h"

//Function to add items to the vector
void GlobalInventory::Add(Item& additem)
{
	Storage.push_back(&additem);
}

//Function to display element from the vector
void GlobalInventory::Display()
{
	int idx = 0;
	for (Item* c : Storage)
	{
		std::cout << idx << ": you have " << c->GetName() << "\n";
		idx++;
	}
}

//Function to find the position of an object
int GlobalInventory::FindPosition(Item* element)
{
	for (auto i = 0; i < Storage.size(); ++i) {
		if (Storage[i] == element) {
			return i;
		}
	}
	return -1;
}

//Function to see if an item is on a specific slot
bool GlobalInventory::IsItemAtPosition(int position, Item* itemToCheck)
{
	if (position >= 0 && position < Storage.size()) {
		return Storage[position] == itemToCheck;
	}
	return false;
}

//thing to erase element from the vector
Item* GlobalInventory::EraseElement(Item* item, int number)
{
	bool Supression = true;
	bool Verification = true;

	std::vector<Item*>::iterator it;
	it = Storage.begin();
	while (it != Storage.end() && Verification)
	{
		if(*it == Storage[number])
		{
			if (Supression && IsItemAtPosition(number, item))
			{
				Storage.erase(it);
				it = Storage.begin();
				Supression = false;
				Verification = false;
			}
		}
		else
		{
			++it; 
		}
	}

	return  EXIT_SUCCESS;

}

//function to use an item
Item* GlobalInventory::UseOne(unsigned int number)
{
	// Attention aux numéros qui marchent pas
	if (number >= 0 && number < Storage.size())
	{
		return Storage[number];
	}
	else
	{
		return nullptr;
	}
}

//function to save an item
void GlobalInventory::Save(const std::string& Save1)
{
	std::ofstream outputFile("Save1.txt");
	if (outputFile.is_open())
	{
		for (const auto& item : Storage)
		{
			outputFile << item->GetName() << std::endl;
		}
		outputFile.close();
	}
}