#ifndef HASH_H
#define HASH_H

#include "account.h"

class HashMap
{
	struct NodeData 
	{
		Dvd* movie;
		Dvd* next; 
	};

public:
	// set the vector size to the default
	HashMap();
	// delete the customer account in each slot in the vector by deleting each node in the linked list
	~HashMap();

	// returns the index for the hash
	int hashFunction(int accountID); 
	//using the hash index, insert key and value into the hashed vector
	void insert(int hashIndex, int accountID, Account* account); 
	//returns a pointer because the customer object needs to be edited
	Account* search(int index);
	
private:
	// vector holding the linked lists of accounts
	vector<NodeData> DVDs[20]; 
};
#endif
