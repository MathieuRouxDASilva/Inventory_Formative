#include <fstream>
#include <iostream>
#include <string>

void Load()
{
	int idxLine = 0;
	std::ifstream Saving;
	std::cout << "your inventory looks like this : \n";

	Saving.open("Save1.txt");
	if (Saving.is_open())
	{
		while (!Saving.eof())
		{
			std::string line;
			std::getline(Saving, line);
			if (line == "rusty sword")
			{
				std::cout << "rusty sword\n";
			}
			else if (line == "casual bow")
			{
				std::cout << "casual bow\n";
			}
			else if (line == "heal potion")
			{
				std::cout << "heal potion\n";
			}
			else if (line == "rage potion")
			{
				std::cout << "rage potion\n";
			}
			else if (line == "map")
			{
				std::cout << "map\n";
			}
			else
			{
				std::cout << "\n";
			}

		}
		Saving.close();
	}
}
