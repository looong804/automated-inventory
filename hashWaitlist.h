#ifndef HASHWAIT_H
#define HASHWAIT_H

#include "hashAccounts.h"

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
	// using the value, hash the key stored in the value, then search the given slot for the value 
	Command remove(Command* command);

private:
	// returns the index for the hash; Key: item title; Value: command
	int hashFunction(Command* command);
	// vector holding the failed borrow commands
	vector<NodeData<Command>> waitlist[25];
};
#endif
