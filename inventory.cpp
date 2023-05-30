#include "inventory.h"

// not needed
Inventory::Inventory()
{
}

// not needed
Inventory::~Inventory()
{
}

// output the whole inventory by going through the vector
// print out the comedy, then drama, then classic
// the above order is how they are stored in the vector
ostream& operator<<(ostream& stream, Inventory& inventor)
{
	// go through the whole vector
	for (int i = 0; i < 3; i++)
	{
		// print out each tree
		inventor.Inventory::inventory[i].inOrderTraversal(inventor.Inventory::inventory[i].getRoot());
	}
}
