/* ------------------------------------------------(inventory.cpp)----------------------------
Steven Wenzel: CSS 343 A Spring 2023
-----------------------------------------------------------------------------------------
This is the implmentation of a inventory object class to contain all the BST 
that the different types of objects are stored and sorted into, makes for easier printing
of the whole inventory
--------------------------------------------------------------------------------------*/
#include "inventory.h"

/* ------------------------------------(Inventory)--------------------------------------
Description: does nothing
-------------------------------------------------------------------------------------- */
Inventory::Inventory()
{
}

/* ------------------------------------(~Inventory)--------------------------------------
Description: does nothing
-------------------------------------------------------------------------------------- */
Inventory::~Inventory()
{
}

/* ------------------------------------(getClassicTree)--------------------------------------
Description: returns a pointer to the classic tree
-------------------------------------------------------------------------------------- */
BSTree<Classic>* Inventory::getClassicTree()
{
	BSTree<Classic>* classic = &classicTree;
	return classic;	
}

/* ------------------------------------(getComedyTree)--------------------------------------
Description: returns a pointer to the comedy tree
-------------------------------------------------------------------------------------- */
BSTree<Comedy>* Inventory::getComedyTree()
{
	BSTree<Comedy>* comedy = &comedyTree;
	return comedy;	
}

/* ------------------------------------(getDramaTree)--------------------------------------
Description: returns a pointer to the drama tree
-------------------------------------------------------------------------------------- */
BSTree<Drama>* Inventory::getDramaTree()
{
	BSTree<Drama>* drama = &dramaTree;
	return drama;	
}

/* ------------------------------------(operator<<)--------------------------------------
Description: output the whole inventory by going through the vector
print out the comedy, then drama, then classic
the above order is how they are stored in the vector
-------------------------------------------------------------------------------------- */
ostream& operator<<(ostream& stream, Inventory& inventory)
{
	// call the inordertraversal on all the trees in inventory
	//NOT WORKING

	vector<Comedy*> comedy = (*inventory.getComedyTree()).inOrderTraversal();
	for (int i = 0; i < comedy.size(); i++) 
	{
		stream << *comedy[i] << endl;
	}

	vector<Drama*> drama = (*inventory.getDramaTree()).inOrderTraversal();
	for (int i = 0; i < drama.size(); i++) 
	{
		stream << *drama[i] << endl;
	}

	vector<Classic*> classic = ((*inventory.getClassicTree()).inOrderTraversal());
	for (int i = 0; i < classic.size(); i++) 
	{
		stream << *classic[i] << endl;
	}
	//stream << ((*inventory.getClassicTree()).inOrderTraversal()).str();
	//stream << (*inventory.getComedyTree()).inOrderTraversal();
	//stream << (*inventory.getDramaTree()).inOrderTraversal();
 	return stream;
} 
