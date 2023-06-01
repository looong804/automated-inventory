#ifndef HASHWAIT_H
#define HASHWAIT_H

#include "hash.h"
#include "customer.h"

// this class uses hash chaining
class HashWaitlist : public Hash
{
public:
	// currently does nothing
	HashWaitlist();
	// delete the command object in each slot in the vector by deleting each node in the linked list
	~HashWaitlist();

	// insert key and value into the hashed vector after hasing the key
	void insert(Command* command);
	// check the waitlist using the hashIndex for the item title
	Command* search(Command* command);
	// check the waitlist using the hashIndex for the item title
	// return a customer pointer for customer editing
	Customer* searchGiveCustomer(Command* command);
	// using the value, hash the key stored in the value, then search the given slot for the value 
	// returns a customer pointer for sending the requested item straight to the customer
	Customer* remove(Command* command);
	// check if the passed in command is in the waitlist
	bool isInWaitlist(Command* command);

private:
	// returns the index for the hash; Key: item title; Value: command
	int hashFunction(Command* command);
	// vector holding the failed borrow commands
	vector<NodeData<Command>> waitlist[25];
};
#endif
