#ifndef HASHACCS_H
#define HASHACCS_H

#include "account.h"

// this class and all its children are using hash chaining
class HashAccounts
{
	template <typename T>
	struct NodeData
	{
		T* data;
		NodeData* next = nullptr;
	};

public:
	// currently does nothing
	HashAccounts();
	// delete the customer account in each slot in the vector by deleting each node in the linked list
	~HashAccounts();

	// returns the index for the hash; Key: account ID; Value: account 
	int hashFunction(Account* account); 
	// insert key and value into the hashed vector after hasing the key
	void insert(Account* account);
	//returns a pointer because the account needs to be edited
	Account* search(Account* account);
	
protected:
	// number of objects in the hashTable
	int size = 0;
	
private:
	// vector holding the linked lists of accounts
	vector<NodeData<Account>> accounts[20]; 
};
#endif
