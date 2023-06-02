/* ------------------------------------------------bstree.cpp----------------------------
Steven Wenzel: CSS 343 A Spring 2023
6/1/2023
6/1/2023
-----------------------------------------------------------------------------------------
This is a templatized binary search tree that takes in the child classes of the parent class item
--------------------------------------------------------------------------------------*/
#ifndef BSTREE_H
#define BSTREE_H

#include "customer.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include <sstream>

template <class T>
class BSTree
{
public:

	struct Node
	{
		T* item;
		Node* right;
		Node* left;
	};
 
	//default constructor
	BSTree();
	//destructor
	~BSTree();

	// traverse the tree in order and print out each item
	void inOrderTraversal() const;
	// traverse the tree in order and print out each item
	void inOrderTraversal(BSTree<T>::Node* look) const;
	// inserts a new item into the tree
	void insert(T* item);
	// find an item and return a pointer to it
	Node* search(T* target) const;
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
	void deleteTree(BSTree<T>::Node* node);
};


// this is the implementaion for the above tree
/* ------------------------------------(~BSTree)--------------------------------------
Description: have it call a helper delete tree function
-------------------------------------------------------------------------------------- */
template <class T>
BSTree<T>::~BSTree()
{
	// call deleteTree recurvise helper function on the root
	deleteTree(root);
}

/* ------------------------------------(inOrderTraversal)--------------------------------------
Description: Recursive function for traversing the BST and printing out what it contains
-------------------------------------------------------------------------------------- */
template <class T>
void BSTree<T>::inOrderTraversal(BSTree<T>::Node* look) const
{
	if (look != nullptr)
	{
		// call inorder again but going to the left
		inOrderTraversal(look->left);
		// print out the left node movie
		cout << (look->left->item) << endl;
		// print out the current node movie
		cout << (look->item) << endl;
		// call inorder for the right
		inOrderTraversal(look->right);
		// print the movie from the right node
		cout << (look->right->item) << endl;
	}
}

template <class T>
void BSTree<T>::inOrderTraversal() const
{
  cout << inOrderTraversal(root);
}

template<class T>
void BSTree<T>::insert(T* item)
{
	// if the tree is empty
	if (this->root == nullptr)
	{
		//		cout << "tree is emtpy so set root to passed in item" << endl;
				// set root movie to item
		root->item = item;
		//increase the tree size
		size++;
		return;
	}
	// if equal to the root
	if (root->item == item)
	{
		//			cerr << "duplicate item" << endl;
		return;
	}
	// go through the rest of the tree
//	cerr << "going through whole tree" << endl;
	// create node pointer for traversing
	Node* p_node = root;
	//	cerr << "where is p_node1: " << *p_node->data << endl;
	//	cerr << "what is p_node->next->data1: " << *p_node->next->data << endl;
	//	cerr << "what is data1: " << *data << endl;
		// while passed item is greater than traveling pointer's item move right
	while ((item > p_node->item) && ((p_node->right) != nullptr))
	{
		//		cout << "inside the move right while loop" << endl;
		p_node = p_node->right;
		//		cerr << "where is p_node3: " << *p_node->data << endl; 
	}
	// while passed item is smaller than traveling pointer's item move right
	while ((item < p_node->item) && ((p_node->left) != nullptr))
	{
		//		cout << "inside the move left while loop" << endl;
		p_node = p_node->left;
		//		cerr << "where is p_node3: " << *p_node->data << endl; 
	}
	// placing new node in tree
	// if passed in item is greater
	if ((item > p_node->item) && (p_node->right) == nullptr)
	{
		//		cout << "the item is greater than the current node put in right" << endl;
				// create new node
		Node* insert_node = new Node;
		// set item pointer in new node to passed in item
		(insert_node->item) = item;
		// have p_node's right point to the new node
		p_node->right = insert_node;
		//increase the tree size
		size++;
		return;
	}
	// if passed in item is less than
	else if ((item < p_node->item) && (p_node->left) == nullptr)
	{
		//		cout << "the id is smaller than the current node put in the left" << endl;
		// create new node
		Node* insert_node = new Node;
		// set item pointer in new node to passed in item
		(insert_node->item) = item;
		// have p_node's right point to the new node
		p_node->left = insert_node;
		//increase the tree size
		size++;
		return;
	}
	// should only get here if its a duplicate
	cout << "ended due to insert being a duplicate. This means there is a bug in the checking for creating the genre objects" << endl;
	return;
}

template<class T>
typename BSTree<T>::Node* BSTree<T>::search(T* target) const
{
	//cout << root->item;
	// if empty tree
	if (root == nullptr)
	{
		//		cout << "tree is empty" << endl;
		return nullptr;
	}
	// first in tree
	if (root->item == target)
	{
		//		cout << "is the root " << endl;
		Node* found = root;
		return found;
	}
	// traverse the rest of the tree
//	cout << "going through the rest of the tree " << endl;
	Node* p_node = root;
	//	cout << p_node->item << endl;
	//	cout << target << endl;
		// while passed item is greater than traveling pointer's item move right
	while (((target) > p_node->item) && ((p_node->right) != nullptr))
	{
		//		cout << "in the moving right while loop in the retrieve function" << endl;
		p_node = p_node->right;
		//		cerr << "where is p_node3: " << *p_node->item << endl; 
	}
	// while passed item is smaller than traveling pointer's item move right
	while ((target < p_node->item) && ((p_node->left) != nullptr))
	{
		//		cout << "in the moving left while loop in the retrieve function" << endl;
		p_node = p_node->left;
		//		cerr << "where is p_node3: " << *p_node->item << endl; 
	}
	// if target is found on the left
	if (((p_node->left) != nullptr) && target == p_node->left->item)
	{
		Node* found = (p_node->left);
		// set p_node pointer to nullptr
		p_node = nullptr;
		// return pointer to item location
		return found;
	}
	// if the target is found on the right
	else if (((p_node->right) != nullptr) && target == p_node->right->item)
	{
		Node* found = (p_node->right);
		// set p_node pointer to nullptr
		p_node = nullptr;
		// return pointer to item location
		return found;
	}
	// if the target is found on current node -- if working right should never get here
	else if (p_node->item == target)
	{
		Node* found = (p_node);
		// set p_node pointer to nullptr
		p_node = nullptr;
		// return pointer to item location
		return found;
	}
	// should never get here but if it does return nullptr
	return nullptr;
}

template<class T>
void BSTree<T>::deleteTree(BSTree<T>::Node* node)
{
	// check if node is nullptr
	if (node != nullptr)
	{
		// call deleteTree again on the left subtree
		deleteTree(node->left);
		// call deleteTree again on the right subtree
		deleteTree(node->right);
		// delete the current node
		delete node;
		// set node to nullptr
		node = nullptr;
	}
}

template<class T>
typename BSTree<T>::Node* BSTree<T>::getRoot() const
{
	//	cout << "in tree root getter" << endl;
	return this->root;
}

template <class T>
int BSTree<T>::getSize() const
{
	return size;
}
#endif
