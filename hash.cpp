#include "hash.h"

// set the vector size to the default
HashMap::HashMap()
{
}

// delete the customer account in each slot in the vector by deleting each node in the linked list
HashMap::~HashMap()
{
}

// call some other premade hashFunction
// to hash the id
// returns the index for the hash
int HashMap::hashFunction(Account account)
{
	
}

//using the hash index, insert key and value into the hashed vector
void HashMap::insert(int hashIndex, Account account)
{
}

//returns a pointer because the customer object needs to be edited
Account* HashMap::search(int hashIndex, int accountID)
{
	return nullptr;
}
