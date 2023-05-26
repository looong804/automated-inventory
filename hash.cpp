#include "hash.h"

// currently does nothing
HashAccounts::HashAccounts()
{
}

// delete the customer account in each slot in the vector by deleting each node in the linked list
HashAccounts::~HashAccounts()
{
}

// uses the accountID to create the hash
// call some other premade hashFunction that returns the hashIndex
int HashAccounts::hashFunction(Account account)
{
	
}

//using the hash index, insert key and value into the hashed vector
void HashAccounts::insert(int hashIndex, Account account)
{
}

//returns a pointer because the customer object needs to be edited
Account* HashAccounts::search(int hashIndex, int accountID)
{
	bool found = false;
	NodeData* looky = accounts[hashIndex];
	while (!found)
	{
		// check if the account id matches the one 
		if (looky->account.getID() != accountID)
		{
		 	looky = looky->next;
		}
		else
		{
			
		}
	}
}
// add a size for the number of accounts
