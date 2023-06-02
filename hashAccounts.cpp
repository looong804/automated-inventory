#include "hashAccounts.h"

// currently does nothing
HashAccounts::HashAccounts()
{
}

// set all the account pointers in the vector to nullptr
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

// uses the accountID to create the hash
// call some other premade hashFunction that returns the hashIndex
int HashAccounts::hashFunction(Customer* account)
{
	// check if the item pointer is empty
	if (account == nullptr)
	{
		return -1;
	}
	// get the ID from the account object
	int ID = account->getID();
	// call and return the hashMidSqaure on the id
	return hashMidSquare(ID, accounts->size());
}

// uses the accountID to create the hash
// call some other premade hashFunction that returns the hashIndex
int HashAccounts::hashFunction(int id)
{
	// check if the id is too small
	if (id < 1000)
	{
		return -1;
	}
	// call and return the hashMidSqaure on the id
	return hashMidSquare(id, accounts->size());
}

//using the hash index, insert key and value into the hashed vector
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

// returns a pointer because the account object needs to be edited
// returns nullptr if not found
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

// returns a pointer because the account object needs to be edited
// returns nullptr if not found
Customer* HashAccounts::search(int id)
{
	// check if the id is too small
	if (id < 1000) 
	{
		return nullptr;
	}

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

// check if the passed account exists 
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

// check if the passed account exists 
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
