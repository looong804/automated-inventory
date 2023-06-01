#ifndef STORE_H
#define STORE_H

#include "account.h"
#include "classic.h"
#include "command.h"
#include "comedy.h"
#include "drama.h"
#include "inventory.h"
#include "item.h"
#include "hashAccounts.h"
#include "hashPopular.h"
#include "hashWaitlist.h"
#include <vector>

using namespace std;

// - could create a chain class that holds stores and has the num of stores, and 
// you can create a chain by reading in a folder that contains a folder for 
// each store that has the three files needed to make a store
// - could create an item class to be the parent of the dvd class, 
// which enables quick adds of new items in stock
// - could add an accounts class to be the parent class of all account type classes
// such as customer account, IT account, employee account, manager account
// - could create another level of categorizing with classes like video, audio, games
// these would then be parent classes of things like; For video: tvs, cables, movies, players
// For Audio: speakers, music, players, For games: video games, controls, game systems
// 
// - could add a time to return things by and for each day after the return time charge more
// - could add a charge system/ tab system or make customers store money on their account
// - could add prices to all the items in the inventory
// - could add discounting functions that will discount all the prices of items 
// depending on their categories and types, and after a certain time return them to full price

class Store
{
public:
    // Constructor
	// not needed
	Store();
	// takes in 3 files with inventory data, account data, and command data to make the store
	// calls all 3 read file functions
	Store(vector<string> files);

    //Destructor
    // I think this won't have to do anything if all other functions and destructors are made right
	~Store();

	//Getters
    //retrieve the command types
    vector<char> getCommandTypes();
    // return number of customer accounts
    int numAccounts() const;

    //Setters
	// reads everything in stock vector and inserts the items
	// make sure to delete each object in the vector after reading/executing
	void setStock(); 
	//reads everything in stock vector and inserts the accounts
	// make sure to delete each object in the vector after reading/executing
	void setAccounts(); 
	//reads everything in command vector and executes the commands
	// if the commands are borrows or returns put into customer history else delete them after reading/executing
	void executeActions();

    //increase the total stock in the store
    void increaseTotal();

    //Creation Functions
    // open an account
    bool openAccount(Command action);
    // take in a vector to read all files in the vector
    void readFiles();

    //Search Functions
	// find customer account and verify it exists
	Customer* findAccount(int id);
	// find a drama dvd and verify that it exists
	Drama* findDrama(Drama& dramaDvd) const;
	// find a comedy dvd and verify that it exists
	Comedy* findComedy(Comedy& comedyDvd) const;
	// find a classic dvd and verify that it exists
	Classic* findClassic(Classic& classicDvd) const;

    //Command Functions
	// return a borrowed item
	bool returnItem(Command action);
	// borrow an item
	bool borrowItem(Command action);
	// print out account history given the id number
	void accountHistory(int id);

	//stream overloads
	// prints out the inventory object using <<
	//friend ostream& operator<< (ostream& stream, Store& store);
	
private:
	// parsed info of the stock to be added
	vector<Command> stock; 
	// parsed info of the customers to be added
	vector<Command> customers; 
	// parsed info of the actions to be executed (borrow, return, etc.)
	vector<Command> actions;
	// contains all the customer accounts
	HashAccounts accounts;
    // contains top ten most requested items
    HashPopular popularItems;
    // contains all the borrow requests placed on hold due to unavailable stock
    HashWaitlist waitlist;
	// contains all the items
	Inventory inventory;
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