#ifndef HASHACCS_H
#define HASHACCS_H

#include "hash.h"

// this class is using hash chainging
class HashAccounts : public Hash
{
public:
	// currently does nothing
	HashAccounts();
	// delete the customer account in each slot in the vector by deleting each node in the linked list
	~HashAccounts();

	// insert key and value into the hashed vector after hasing the key
	void insert(Account* account);
	//returns a pointer because the account needs to be edited
	Account* search(Account* account);
	// check if the passed account already exists
	bool isAccount(int id);
	
	// calls an actual hash function listed below that was taken from online sources
	// to avoid importing a hash class which is the only way we could find to import hash functions
	// returns the index for the hash; Key: account ID; Value: account 
	int hashFunction(Account* account);

private:
	// vector holding the linked lists of accounts
	vector<NodeData<Account>> accounts[20]; 
};
#endif
