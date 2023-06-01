#include "inventory.h"

// not needed
Inventory::Inventory()
{
}

// not needed
Inventory::~Inventory()
{
}

// returns the roots to their respective trees
Node* Inventory::getClassicTree()
{
	return classicTree;	
}

Node* Inventory::getComedyTree();
{
	return comedyTree;	
}

Node* Inventory::getDramaTree();
{
	return dramaTree;	
}

// output the whole inventory by going through the vector
// print out the comedy, then drama, then classic
// the above order is how they are stored in the vector
ostream& operator<<(ostream& stream, Inventory& inventory)
{
	// call the inordertraversal on all the trees in inventory
	(inventory.getClassicTree()).inOrderTraversal();
	inventory.getComedyTree().inOrderTraversal();
	inventory.getDramaTree().inOrderTraversal();
}
