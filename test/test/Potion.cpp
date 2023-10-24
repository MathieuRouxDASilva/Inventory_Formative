#include "Potion.h"
#include <iostream>

void Potion::Use()
{
	std::cout << "[Potion] you used " << Name << " and healed 50 hp\n";
}
