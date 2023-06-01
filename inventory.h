#ifndef INVEN_H
#define INVEN_H

#include "bstree.h"

class Inventory 
{ 
public:
    //default constructor
    // make the trees and input them into the vector 
    Inventory();
    //destructor
    ~Inventory();

    // returns the roots to their respective trees
    Node* getClassicTree();
    Node* getComedyTree();
    Node* getDramaTree();
    
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
