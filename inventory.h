#ifndef INVEN_H
#define INVEN_H

#include "bstree.h"
#include <vector>

class Inventory 
{ 
public:
    //default constructor
    // make the trees and input them into the vector 
    Inventory();
    //destructor
    ~Inventory();

    //stream overloads
    // output the whole inventory by going through the vector
    // print out the comedy, then drama, then classic
    friend ostream& operator<< (ostream& stream, Inventory& inven);

private:
    // vector to hold the BSTree
    vector<BSTree> inventory;
};
#endif