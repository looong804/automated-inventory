/* ------------------------------------------------hash.h----------------------------
Steven Wenzel: CSS 343 A Spring 2023
-----------------------------------------------------------------------------------------
This is the header file for the hash abstract parent class for all hash classes. 
This class is meant to keep all the common data members and a library of premade hash functions
--------------------------------------------------------------------------------------*/
#ifndef HASH_H
#define HASH_H

#include "account.h"
#include "item.h"
#include <stdlib.h>
#include <cmath>

// this is the basic abstract hash class that is the parent for all hash classes
// contains premade hash functions, basic functions and data members
class Hash
{
public:
	// currently does nothing
	Hash();
	// empty the slots of the hash table
	~Hash();

	// get the number of items being stored
	int getSize() const;

	template <typename T>
	struct NodeData
	{
		T* data = nullptr;
		NodeData* next = nullptr;
	};

protected:
	// number of objects in the hashTable
	int size = 0;

	// premade hash functions to be used in this hash class and its children
	// hash function using folding on a string, summed 4 bytes at a time
	int hashStringFold(string key, int tableSize);
	// hash function using mid square method for ints
	int hashMidSquare(int key, int tableSize);
};
#endif
