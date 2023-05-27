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
		Node* next = nullptr;
	};
public:
	// currently does nothing
	HashAccounts();
	// delete the customer account in each slot in the vector by deleting each node in the linked list
	~HashAccounts();

	// returns the index for the hash
	int hashFunction(Account* account); 
	//using the hash index, insert key and value into the hashed vector
	void insert(int hashIndex, int accountID, Account* account); 
	//returns a pointer because the customer object needs to be edited
	Account* search(int hashIndex, int index);
	
protected:
	// number of objects in the hashTable
	size = 0;
	
private:
	// vector holding the linked lists of accounts
	vector<NodeData> accounts[20]; 
};
#endif
