/* ------------------------------------------------(inventory.h)----------------------------
Steven Wenzel: CSS 343 A Spring 2023
-----------------------------------------------------------------------------------------
This is the header file for a inventory object class to contain all the BST 
that the different types of objects are stored and sorted into, makes for easier printing
of the whole inventory
--------------------------------------------------------------------------------------*/
#ifndef INVEN_H
#define INVEN_H

#include "bstree.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"

class Inventory 
{ 
public:
    //default constructor
    // make the trees and input them into the vector 
    Inventory();
    //destructor
    ~Inventory();

    // returns the roots to their respective trees
    BSTree<Classic>* getClassicTree();
    BSTree<Comedy>* getComedyTree();
    BSTree<Drama>* getDramaTree();
    
    //stream overloads
    // output the whole inventory by going through the vector
    // print out the comedy, then drama, then classic
    friend ostream& operator<< (ostream& stream, Inventory& inven);

private:
    // all the initially needed BSTs
    BSTree<Classic> classicTree;
    BSTree<Comedy> comedyTree;
    BSTree<Drama> dramaTree;
};
#endif
