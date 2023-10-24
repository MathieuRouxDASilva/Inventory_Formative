#include <iostream>
#include "GlobalInventory.h"
#include "Potion.h"
#include "Weapons.h"
#include <fstream>
#include "Map.h"
#include "SaveTechnique.h"

//quick variables settings
char Question;
bool Answer = true;
int Ok;

//function main
int main()
{

	std::cout << "Hello player this is your inventory, pls note that these items can only be used once\n\n";

	//all the diffent items
	Weapons Sword(10, "rusty sword");
	Weapons Bow(10, "casual bow");
	Potion Heal(50, "heal potion");
	Potion Rage(25, "rage potion");
	Map Map("North side of the map", "map");
	class Map Nothing("nothing", "nothing");

	//all the items in inventory
	GlobalInventory AccessInventory;
	AccessInventory.Add(Nothing);
	AccessInventory.Add(Sword);
	AccessInventory.Add(Bow);
	AccessInventory.Add(Heal);
	AccessInventory.Add(Rage);
	AccessInventory.Add(Map);

	//do whule function to make everything work
	do
	{
		//display the things
		AccessInventory.Display();

		std::cout << "Do you want to use an item ? \n";
		std::cout << "[Y] for yes / [N] for no\n";
		std::cin >> Question;

		if (Question == 'Y')
		{
			std::cout << "Wich item do you want to use ? select the correct number\n";
			std::cin >> Ok;

			//block to use/erase the item
			Item* monItem = AccessInventory.UseOne(Ok);
			if (monItem != nullptr)
			{
				monItem->Use();
				AccessInventory.EraseElement(monItem, Ok);
			}
		}
		else
		{
			std::cout << "Ok, your inventory will be autaumatically saved don't worry.\n ";
			Answer = false;
		}
	} while (Answer == true);

	AccessInventory.Save("Save1.txt");
}