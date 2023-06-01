#include "hashWaitlist.h"

// not needed
HashWaitlist::HashWaitlist()
{
}

// not needed
HashWaitlist::~HashWaitlist()
{
}

void HashWaitlist::insert(Command* command)
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
			NodeData<Command> start = waitlist->at(hashIndex);
			// create a pointer to traverse the linked list starting at the 2 node
			NodeData<Command>* temp = start.next;

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
				temp->next = new NodeData<Command>;
				// set the new node data to passed command
				temp->next->data = command;
				// set the new node's next pointer to nullptr
				temp->next->next = nullptr;
			}
			// if temp is empty
			else
			{
				// add in a new node to temps current location
				start.next = new NodeData<Command>;
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

Command* HashWaitlist::search(Command* command)
{
	// check if the command pointer is empty
	if (command == nullptr)
	{
		return nullptr;
	}

	// nodeData equal to the first node in the linked list 
	NodeData<Command> start = waitlist->at(hashFunction(command));

	// check if its the first node
	if (start.data == command)
	{
		return start.data;
	}
	// go through the whole list
	else
	{
		// nodeData pointer to traverse the list starting at the second node
		NodeData<Command>* looky = start.next;

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

// return a pointer to customer
int HashWaitlist::searchGiveCustomer(Command* command)
{
	// check if the command pointer is empty
	if (command == nullptr)
	{
		return -1;
	}

	// nodeData equal to the first node in the linked list 
	NodeData<Command> start = waitlist->at(hashFunction(command));

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
		NodeData<Command>* looky = start.next;

		// while the account isn't found
		while (true)
		{
			// check if the command matches the one being looked for  
			if (looky->data == command && looky->data != nullptr)
			{
				// get the id from the command
				int id = start.data->spaceParser(1).at(0);
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

// remove the command from the linked list
int HashWaitlist::remove(Command* command)
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
			NodeData<Command> start = waitlist->at(hashIndex);
			// create a pointer to traverse the linked list starting at the 2 node
			NodeData<Command>* temp = start.next;

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
					int id = command->spaceParser(1).at(0);
					
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
					int id = command->spaceParser(1).at(0);
					
					// delete the temp next data
					delete temp->next->data;
					// set temp next data to nullptr
					temp->next->data = nullptr;
					// have temp point to temps next next
					temp->next = temp->next->next;
					// set temps next to nullptr
					temp->next = nullptr;
					
					// search for the account using the id
					// and return the pointer to the account
					return id;
				}
			}
		}
	}
}

// check if the passed in command is in the waitlist
bool HashWaitlist::isInWaitlist(Command* command)
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

// is dependent on the genre type
int HashWaitlist::hashFunction(Command* command)
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
