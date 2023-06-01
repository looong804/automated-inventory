#ifndef HASHPOP_H
#define HASHPOP_H

#include "hash.h"
#include "item.h"
#include <limits.h>

// this class uses open addressing and stores a pointer to the item
class HashPopular : public Hash
{
public:
	// currently does nothing
	HashPopular();
	// set all the pointers in each slot in the vector to nullptr
	~HashPopular();

	// insert key and value into the hashed vector after hashing the title
	void insert(Item* item);
	// check the popular vector for the item using the hashIndex for the item title
	Item* search(Item* item);
	// won't work using hashing but you can just use linear searching won't be bad since its only 10 slots
	// pass in an old item and if its in the popular hash then the new item that you passed in will replace it. 
	// they can't be equal and they can't be empty
	// only works if the hash slots are full
	void swap(Item* newitem, Item* olditem);
	// check if all slots are taken
	bool isFull();
	// check if the passed in item is in the hash
	bool isPopular(Item* item);
	// returns the item with the lowest popularity thats in the hash
	Item* getLowestPopular();
	
private:
	// returns the index for the hash; Key: item title; Value: item 
	int hashFunction(Item* item);

	// vector holding the failed borrow commands
	vector<Item*> popular[10];
	// check the popular vector for the item and return its index if found
	int searchForSwap(Item* item);
};
#endif
