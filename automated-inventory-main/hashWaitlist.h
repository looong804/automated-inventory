/* ------------------------------------------------(hashWaitlist.h)----------------------------
Steven Wenzel: CSS 343 A Spring 2023
-----------------------------------------------------------------------------------------
This is the header file for a hash to store borrow commands on items that are not in stock
this class represents a waitlist and the hash is accessed often and at the end of the program should be empty
--------------------------------------------------------------------------------------*/
#ifndef HASHWAIT_H
#define HASHWAIT_H

#include "hash.h"
#include "customer.h"
#include "command.h"

// this class uses hash chaining
class HashWaitlist : public Hash
{
public:
	// currently does nothing
	HashWaitlist();
	// delete the command object in each slot in the vector by deleting each node in the linked list
	~HashWaitlist();

	// insert key and value into the hashed vector after hasing the key
	void insert(Commands* command);
	// check the waitlist using the hashIndex for the item title
	Commands* search(Commands* command);
	// check the waitlist using the hashIndex for the item title
	// return a customer pointer for customer editing
	int searchGiveCustomer(Commands* command);
	// using the value, hash the key stored in the value, then search the given slot for the value 
	// returns a customer pointer for sending the requested item straight to the customer
	int remove(Commands* command);
	// check if the passed in command is in the waitlist
	bool isInWaitlist(Commands* command);

private:
	// returns the index for the hash; Key: item title; Value: command
	int hashFunction(Commands* command);
	// vector holding the failed borrow commands
	vector<NodeData<Commands>> waitlist[25];
};
#endif
