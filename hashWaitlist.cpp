/* ------------------------------------------------(hashWaitlist.cpp)----------------------------
Steven Wenzel: CSS 343 A Spring 2023
-----------------------------------------------------------------------------------------
This is the implementation for a hash to store borrow commands on items that are not in stock
this class represents a waitlist and the hash is accessed often and at the end of the program should be empty
--------------------------------------------------------------------------------------*/
#include "hashWaitlist.h"

/* ------------------------------------HashWaitlist--------------------------------------
Description: does nothing
-------------------------------------------------------------------------------------- */
HashWaitlist::HashWaitlist()
{
}

/* ------------------------------------(~HashWaitlist)--------------------------------------
Description: does nothing
-------------------------------------------------------------------------------------- */
HashWaitlist::~HashWaitlist()
{
}

/* ------------------------------------(insert)--------------------------------------
Description: using the hash index, insert key and value into the hashed vector
-------------------------------------------------------------------------------------- */
void HashWaitlist::insert(Commands* command)
{
	// check if the command pointer is empty
	if (command != nullptr)
	{
		// get the hashIndex from the hashFunction
		int hashIndex = hashFunction(command);
		// if the slot is empty
		if (waitlist->at(hashIndex).data == nullptr)
		{
			// set the data pointer in the NodeData in the waitlist vector at the hashIndex
			waitlist->at(hashIndex).data = command;
		}
		// if the slot is not empty
		else
		{
			// create a nodedata equal to the first node in the linked list
			NodeData<Commands> start = waitlist->at(hashIndex);
			// create a pointer to traverse the linked list starting at the 2 node
			NodeData<Commands>* temp = start.next;

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
				temp->next = new NodeData<Commands>;
				// set the new node data to passed command
				temp->next->data = command;
				// set the new node's next pointer to nullptr
				temp->next->next = nullptr;
			}
			// if temp is empty
			else
			{
				// add in a new node to temps current location
				start.next = new NodeData<Commands>;
				// set the new node data to passed command
				start.next->data = command;
				// set the new node's next pointer to nullptr
				start.next->next = nullptr;
			}
		}
		// up the size
		size++;
	}
}

/* ------------------------------------(search)--------------------------------------
Description: searches for the passsed command and 
returns a pointer because the command object needs to be edited,
returns nullptr if not found, mostly for inside use
-------------------------------------------------------------------------------------- */
Commands* HashWaitlist::search(Commands* command)
{
	// check if the command pointer is empty
	if (command == nullptr)
	{
		return nullptr;
	}

	// nodeData equal to the first node in the linked list 
	NodeData<Commands> start = waitlist->at(hashFunction(command));

	// check if its the first node
	if (start.data == command)
	{
		return start.data;
	}
	// go through the whole list
	else
	{
		// nodeData pointer to traverse the list starting at the second node
		NodeData<Commands>* looky = start.next;

		// while the account isn't found
		while (true)
		{
			// check if the command matches the one being looked for  
			if (looky->data == command && looky->data != nullptr)
			{
				// return the found command
				return looky->data;
			}
			else if (looky->next != nullptr)
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

/* ------------------------------------(searchGiveCustomer)--------------------------------------
Description: searches for the passed in command 
returns an int for easier use for searching for the account that made the request
-------------------------------------------------------------------------------------- */
int HashWaitlist::searchGiveCustomer(Commands* command)
{
	// check if the command pointer is empty
	if (command == nullptr)
	{
		return -1;
	}

	// nodeData equal to the first node in the linked list 
	NodeData<Commands> start = waitlist->at(hashFunction(command));

	// check if its the first node
	if (start.data == command)
	{
		// get the id from the command
		int id = stoi(start.data->spaceParser(1).at(0));
		// search for the account using the id
		// and return the pointer to the account
		return id;
	}
	// go through the whole list
	else
	{
		// nodeData pointer to traverse the list starting at the second node
		NodeData<Commands>* looky = start.next;

		// while the account isn't found
		while (true)
		{
			// check if the command matches the one being looked for  
			if (looky->data == command && looky->data != nullptr)
			{
				// get the id from the command
				int id = stoi(start.data->spaceParser(1).at(0));
				// search for the account using the id
				// and return the pointer to the account
				return id;
			}
			else if (looky->next != nullptr)
			{
				looky = looky->next;
			}
			else
			{
				return -1;
			}
		}
	}
}

/* ------------------------------------(remove)--------------------------------------
Description: remove the command from the linked list and return an int for easier accessing of
the customer account that made the request
-------------------------------------------------------------------------------------- */
int HashWaitlist::remove(Commands* command)
{
	// check if the command pointer is empty
	if (command != nullptr)
	{
		// if the command is in the waitlist
		if (search(command) != nullptr)
		{
			// find the hashindex
			int hashIndex = hashFunction(command);
			// create a nodedata equal to the first node in the linked list
			NodeData<Commands> start = waitlist->at(hashIndex);
			// create a pointer to traverse the linked list starting at the 2 node
			NodeData<Commands>* temp = start.next;

			// if the command is at the start
			if (command == start.data)
			{
				// get the id from the command
				int id = stoi(command->spaceParser(1).at(0));

				// insert start's next into the slot in the vector
				waitlist->at(hashIndex) = *start.next;
				// delete the start data
				delete start.data;
				// set start data to nullptr
				start.data = nullptr;
				// set the start next to nullptr
				start.next = nullptr;

				// search for the account using the id
				// and return the pointer to the account
				return id;
			}
			// if the command is not at the start
			else
			{
				// if command is at temp
				if (command == temp->data)
				{
					// get the id from the command
					int id = stoi(command->spaceParser(1).at(0));

					// have start point to temps next
					start.next = temp->next;
					// delete the temp data
					delete temp->data;
					// set temp data to nullptr
					temp->data = nullptr;
					// set temps next to nullptr
					temp->next = nullptr;

					// search for the account using the id
					// and return the pointer to the account
					return id;
				}
				// if temp is not empty and not command
				else if (temp != nullptr && command != temp->data)
				{
					// search the rest of the linked list
					while (temp->next != nullptr && command != temp->next->data)
					{
						// move temp to the next node
						temp = temp->next;
					}
					// get the id from the command
					int id = stoi(command->spaceParser(1).at(0));
					if (temp->next != nullptr)
					{
						// delete the temp next data
						delete temp->next->data;
						// set temp next data to nullptr
						temp->next->data = nullptr;
						// have temp point to temps next next
						temp->next = temp->next->next;
						if (temp->next != nullptr)
						{
							// set temps next to nullptr
							temp->next = nullptr;
						}
					}
					// search for the account using the id
					// and return the pointer to the account
					return id;
				}
				else
				{
					return -1;
				}
			}
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}

/* ------------------------------------(isInWaitlist)--------------------------------------
Description: check if the passed in command is in the waitlist, return true if found
-------------------------------------------------------------------------------------- */
// check if the passed in command is in the waitlist
bool HashWaitlist::isInWaitlist(Commands* command)
{
	// search the hash and return true if the command is found
	if (search(command) != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* ------------------------------------(hashFunction)--------------------------------------
Description: uses the one of the names in the command object to create the hash, 
call some other premade hashFunction that returns the hashIndex, converts used items into
usable types for premade hash functions, for inside use
-------------------------------------------------------------------------------------- */
int HashWaitlist::hashFunction(Commands* command)
{
	// check if the command pointer is empty
	if (command == nullptr)
	{
		return -1;
	}

	// since the borrow commands for each type of genre is different need to check the genre type
	// call the space parsing function in command 
	// use what is put into the 1 index
	vector<string> index1 = command->spaceParser(command->getVector(1));
	// turn the needed string from th array into a char
	char genreType = *index1[2].c_str();
	// check what kind of genre it is
	// if a classic
	if (genreType == 'C')
	{
		// get the major actor name
		string fullName = index1[5] + " " + index1[6];
		// hash the major actor name 
		return hashStringFold(fullName, waitlist->size());
	}
	// if a comedy
	else if (genreType == 'F')
	{
		// get the first and last words of the movie title
		string title = index1[3] + " " + index1[index1.size() - 1];
		// hash the title from above
		return hashStringFold(title, waitlist->size());
	}
	// if a drama
	else if (genreType == 'D')
	{
		// grab the title from the 2 index from the command vector
		string title = command->getVector(2);
		// hash the title from above
		return hashStringFold(title, waitlist->size());
	}
	// if not valid
	else
	{
		return -1;
	}
}
