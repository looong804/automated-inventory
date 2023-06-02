/* ------------------------------------------------hashAccounts.cpp----------------------------
Steven Wenzel: CSS 343 A Spring 2023
-----------------------------------------------------------------------------------------
This is hash class for Accounts this stores them using hash chaining and is meant to increase
the speed of account retrival for executing transactions
--------------------------------------------------------------------------------------*/
#include "hashAccounts.h"

/* ------------------------------------HashAccounts--------------------------------------
Description: does nothing
-------------------------------------------------------------------------------------- */
HashAccounts::HashAccounts()
{
}

/* ------------------------------------(~HashAccounts)--------------------------------------
Description: set all the account pointers in the vector to nullptr
-------------------------------------------------------------------------------------- */
HashAccounts::~HashAccounts()
{
	// go through each index in the vector
	for (int i = 0; i < accounts->size(); i++)
	{
		// nodeData equal to the first node in the linked list 
		NodeData<Customer> start = accounts->at(i);
		// pointer to traverse the list starting at the 2 node
		NodeData<Customer>* temp = start.next;

		// delete start data
		delete start.data;
		// set the start node to nullptr
		start.data = nullptr;

		// if next node is not empty
		if (temp != nullptr)
		{	
			// while the next next node is not empty
			while (temp->next != nullptr) 
			{
				// delete temp data
				delete temp->data;
				// set temp data to nullptr
				temp->data = nullptr;
				// set temp to next node
				temp = temp->next;
			}

			// delete temp data
			delete temp->data;
			// set temp data to nullptr
			temp->data = nullptr;
			// delete temp 
			delete temp;
			// set temp to nullptr
			temp = nullptr;
		}
	}
}

/* ------------------------------------(hashFunction)--------------------------------------
Description: uses the accountID to create the hash, 
call some other premade hashFunction that returns the hashIndex, converts used items into
usable types for premade hash functions, mostly for inside use
-------------------------------------------------------------------------------------- */
int HashAccounts::hashFunction(Customer* account)
{
	// get the ID from the account object
	int ID = account->getID();
	// call and return the hashMidSqaure on the id
	return hashMidSquare(ID, accounts->size());
}

/* ------------------------------------(hashFunction)--------------------------------------
Description: uses the accountID to create the hash
call some other premade hashFunction that returns the hashIndex converts used items into
usable types for premade hash functions, mostly for outside use
-------------------------------------------------------------------------------------- */
int HashAccounts::hashFunction(int id)
{
	// call and return the hashMidSqaure on the id
	return hashMidSquare(id, accounts->size());
}

/* ------------------------------------(insert)--------------------------------------
Description: using the hash index, insert key and value into the hashed vector
-------------------------------------------------------------------------------------- */
void HashAccounts::insert(Customer* account)
{
	// check if the account pointer is empty
	if (account != nullptr)
	{
		// get the hashIndex from the hashFunction
		int hashIndex = hashFunction(account);
		// if the slot is empty
		if (accounts->at(hashIndex).data == nullptr)
		{
			// set the data pointer in the NodeData in the accounts vector at the hashIndex
			accounts->at(hashIndex).data = account;
		}
		// if the slot is not empty
		else
		{
			// create a nodedata equal to the first node in the linked list
			NodeData<Customer> start = accounts->at(hashIndex);
			// create a pointer to traverse the linked list starting at the 2 node
			NodeData<Customer>* temp = start.next;

			// if temp is not empty
			if (temp != nullptr)
			{
				// go to the end of the linked list
				while (temp->next != nullptr)
				{
					// move temp to the next node
					temp = temp->next;
				}
				// add in a new node after temp
				temp->next = new NodeData<Customer>;
				// set the new node data to passed account
				temp->next->data = account;
				// set the new node's next pointer to nullptr
				temp->next->next = nullptr;
			}
			// if temp is empty
			else
			{
				// add in a new node to temps current location
				start.next = new NodeData<Customer>;
				// set the new node data to passed account
				start.next->data = account;
				// set the new node's next pointer to nullptr
				start.next->next = nullptr;
			}
		}
		// up the size
		size++;
	}
}

/* ------------------------------------(search)--------------------------------------
Description: searches for the passsed in account and 
returns a pointer because the account object needs to be edited,
returns nullptr if not found, mostly for inside use
-------------------------------------------------------------------------------------- */
Customer* HashAccounts::search(Customer* account)
{
	// check if the account pointer is empty
	if (account == nullptr) 
	{
		return nullptr;
	}

	// nodeData equal to the first node in the linked list 
	NodeData<Customer> start = accounts->at(hashFunction(account));

	// check if its the first node
	if (start.data == account)
	{
		return start.data;
	}
	// go through the whole list
	else
	{
		// nodeData pointer to traverse the list starting at the second node
		NodeData<Customer>* looky = start.next;

		// while the account isn't found
		while (true)
		{
			// check if the account ID matches the one being looked for  
			if (looky->data == account && looky->data != nullptr)
			{
				// return the found account
				return looky->data;
			}
			else if(looky->next != nullptr)
			{
				looky = looky->next;
			}
			else
			{
				return nullptr;
			}
		}
	}
}

/* ------------------------------------(search)--------------------------------------
Description: searches for the account that matches the passed in id and 
returns a pointer because the account object needs to be edited
returns nullptr if not found, mostly for outside use
-------------------------------------------------------------------------------------- */
Customer* HashAccounts::search(int id)
{
	// nodeData equal to the first node in the linked list 
	NodeData<Customer> start = accounts->at(hashFunction(id));

	// check if its the first node
	if (start.data -> getID() == id)
	{
		return start.data;
	}
	// go through the whole list
	else
	{
		// nodeData pointer to traverse the list starting at the second node
		NodeData<Customer>* looky = start.next;

		// while the account isn't found
		while (true)
		{
			// check if the account ID matches the one being looked for  
			if (looky->data != nullptr && looky->data->getID() == id)
			{
				// return the found account
				return looky->data;
			}
			else if(looky->next != nullptr)
			{
				looky = looky->next;
			}
			else
			{
				return nullptr;
			}
		}
	}
}

/* ------------------------------------(isAccount)--------------------------------------
Description: check if the passed in id is used by an account that exists, return true if it does,
mostly for outside use
-------------------------------------------------------------------------------------- */
bool HashAccounts::isAccount(int id)
{
	if (search(id) != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* ------------------------------------(isAccount)--------------------------------------
Description: check if the passed account exists, return true if it does, mostly for inside use
-------------------------------------------------------------------------------------- */
bool HashAccounts::isAccount(Customer* account)
{
	if (search(account) != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
