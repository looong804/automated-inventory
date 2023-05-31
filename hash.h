#ifndef HASH_H
#define HASH_H

#include "account.h"
#include "item.h"
#include <stdlib.h>

// this is the basic abstract hash class that is the parent for all hash classes
// contains premade hash functions, basic functions and data members
class Hash
{
public:
	// currently does nothing
	Hash();
	// empty the slots of the hash table
	~Hash();

	// insert key and value into the hashed vector after hasing the key
	void insert();
	//returns a pointer because the item needs to be edited
	Item* search(Item* item);
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

	// calls an actual hash function listed below that was taken from online sources
	// to avoid importing a hash class which is the only way we could find to import hash functions
	// returns the index for the hash; Key: account ID; Value: account 
	int hashFunction(Item* item);

	// premade hash functions to be used in this hash class and its children
	// hash function using folding on a string, summed 4 bytes at a time
	int hashStringFold(string key, int tableSize);
	// hash function using mid square method for ints
	int hashMidSquare(int key, int tableSize);
};
#endif
