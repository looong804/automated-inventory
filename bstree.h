#ifndef BSTREE_H
#define BSTREE_H

#include "customer.h"
#include "dvd.h"

struct Node
{
    Item* item;
    Node* right;
    Node* left;
};

class BSTree
{
public:
    //default constructor
    BSTree(); 
    //destructor
    ~BSTree(); 

    // traverse the tree in order and print out each item
    void inOrderTraversal(Node* look) const;
    // inserts a new item into the tree
    void insert(Node* item);
    // find an item and return a pointer to it
    Node* search(Node* target) const; 
    // remove an item from the tree -- EXTENSION
    void remove(Node* target, Node& item);
    // return the root of the tree
    Node* getRoot() const;
    // return the size
    int getSize() const;

private:
    // start of the tree
    Node* root = nullptr;
    // number of items in the tree
    int size = 0;
    // recursive helper function for the destructor
    void deleteTree(Node* node);
};
#endif
