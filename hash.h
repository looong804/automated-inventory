#ifndef HASH_H
#define HASH_H

#include "account.h"

class HashAccounts
{
	template <typename T>
	struct NodeData
	{
		T* data;
		Node* next = nullptr;
	};
public:
	// currently does nothing
	HashMap();
	// delete the customer account in each slot in the vector by deleting each node in the linked list
	~HashMap();

	// returns the index for the hash
	int hashFunction(Account* account); 
	//using the hash index, insert key and value into the hashed vector
	void insert(int hashIndex, int accountID, Account* account); 
	//returns a pointer because the customer object needs to be edited
	Account* search(int hashIndex, int index);
	
private:
	// vector holding the linked lists of accounts
	vector<NodeData> accounts[20]; 
};
#endif
