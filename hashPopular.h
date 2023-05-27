#ifndef HASHPOP_H
#define HASHPOP_H

#include "hashAccounts.h"

// this class uses open addressing and stores a pointer to the item
class HashPopular : public HashAccounts
{

public:
	// currently does nothing
	HashPopular();
	// set all the pointers in each slot in the vector to nullptr
	~HashPopular();

	// returns the index for the hash; Key: item title; Value: item 
	int hashFunction(Item* item);
	// insert key and value into the hashed vector after hashing the title
	void insert(Item* item);
	// check the popular vector for the item using the hashIndex for the item title
	Item* search(Item* item);
	// won't work using hashing but you can just use linear searching won't be bad since its only 10 slots
	void swap(Item* newitem, Item* olditem);
	// check if the passed in item is in the popular vector
	// call the hashFunction on item and check if its in the slot thats given 
	bool isPopular(Item* item);

protected:
	int size = 10;

private:
	// vector holding the failed borrow commands
	vector<Item*> popular[10];
};
#endif
