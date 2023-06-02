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
	// stringstreams to hold the output of inOrderTraversal
	stringstream ssclassic;
	stringstream sscomedy;
	stringstream ssdrama;

	// call the inordertraversal on all the trees in inventory and put into the stringstreams
	ssclassic = (*inventory.getClassicTree()).inOrderTraversal();
	sscomedy = (*inventory.getComedyTree()).inOrderTraversal();
	ssdrama = (*inventory.getDramaTree()).inOrderTraversal();

	// turn all the stringstreams into strings
	string sclassic = ssclassic.str();
	string scomedy = sscomedy.str();
	string sdrama = ssdrama.str();

	// feed all the strings into the stream
	stream << sclassic;
	stream << scomedy;
	stream << sdrama;

 return stream;
}
