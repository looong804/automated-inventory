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
BSTree<Classic>* Inventory::getClassicTree()
{
	BSTree<Classic>* classic = &classicTree;
	return classic;	
}

BSTree<Comedy>* Inventory::getComedyTree()
{
	BSTree<Comedy>* comedy = &comedyTree;
	return comedy;	
}

BSTree<Drama>* Inventory::getDramaTree()
{
	BSTree<Drama>* drama = &dramaTree;
	return drama;	
}

// output the whole inventory by going through the vector
// print out the comedy, then drama, then classic
// the above order is how they are stored in the vector
ostream& operator<<(ostream& stream, Inventory& inventory)
{
	// call the inordertraversal on all the trees in inventory
  stream << inventory.getClassicTree().inOrderTraversal();
	stream << inventory.getComedyTree().inOrderTraversal();
	stream << inventory.getDramaTree().inOrderTraversal();
 return stream;
}
