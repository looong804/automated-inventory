#ifndef STORE_H
#define STORE_H

#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "hashAccounts.h"
#include "hashWaitlist.h"
#include "hashPopular.h"
#include "inventory.h"
#include "item.h"
#include "command.h"
#include "account.h"

class Store
{
public:
	// not needed
	Store();
	// takes in 3 files with inventory data, account data, and command data to make the store
	// calls all 3 read file functions
	Store(vector<string> files);
	// I think this won't have to do anything if all other functions and destructors are made right
	~Store();

	//actions
	// reads everything in stock vector and inserts the items
	// make sure to delete each object in the vector after reading/executing
	void setStock(); 
	//reads everything in stock vector and inserts the accounts
	// make sure to delete each object in the vector after reading/executing
	void setAccounts(); 
	//reads everything in command vector and exceutes the commands
	// if the commands are borrows or returns put into customer history else delete them after reading/executing
	void executeCommands(); 
	// find customer account and verify it exsits
	Customer* findAccount(int id) const;
	// find a drama dvd and verify that it exsits
	DVD* findDrama(Drama& dvd) const;
	// find a comedy dvd and verify that it exsits
	DVD* findComedy(Comedy& dvd) const;
	// find a classic dvd and verify that it exsits
	DVD* findClassic(Classic& dvd) const;
	// open an account
	bool openAccount(Command action);
	// take in a vector to read all files in the vector
	void readFiles();
	// return number of customer accounts
	int numCustomers() const;

	//stream overloads
	// prints out the inventory object using <<
	friend ostream& operator<< (ostream& stream, Store& store);
	
private:
	// parsed info of the stock to be added
	vector<Command> stock; 
	// parsed info of the customers to be added
	vector<Command> customers; 
	// parsed info of the commands to be executed (borrow, return, etc.)
	vector<Command> actions; 
	// contains all the customer accounts
	HashAccounts accounts;
	// contains all the most requested items
	HashPopular popularItems;
	// contains all the borrow commands that failed due to no avaliable stock
	HashWaitlist waitlist;
	// contains all the items
	Inventory inventory();
	// total number of all items
	int totalStock = 0;
	// vector of strings storing all the file names
	vector<string> filesNames;
	// chars for their indicated command type
	char createComedy = 'F';
	char createDrama = 'D';
	char createClassic = 'C';
	char showInventory = 'I';
	char showCustomerHistory = 'H';
	char checkoutItem = 'B';
	char givebackItem = 'R';
	// vector that stores all accepted command types
	vector<char> commandTypes {createComedy, createDrama, createClassic, 
		showInventory, showCustomerHistory, checkoutItem, givebackItem};
};
#endif
