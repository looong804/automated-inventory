#include "store.h"

int main(int argc, char* argv[])
{
	cout << "This is the beginning of the testing of the inventory tracking system purposed for a movie rental store. " << endl; 
	cout << "This system is intended to be easily modified for real world changes: " << endl;
	cout << "This contains the test cases for the Inventory System consisting of the following classes: Store class, Account class, Genre class, DVD class, Command class" << endl;
	cout << "To help with sequential testing and enabling the functions that help you test the others it is recommend to implement the functions in the following order that they are tested in." << endl;
	cout << "The functions of the Inventory System are tested in the following order: " << endl;

	// should probably add just a couple text files to contain the input commands to test everything
	// create a store using given input files
	Store stuff(givenFile1, givenFile2, givenFile3);
	cout << "Finished running the given input files." << endl;
	// create a store using our test files
	Store treasureTrove(testFile1, testFile2, testFile3);
	cout << "Finished running the test files." << endl;
	
	// Testing for Command class
	// testing for BST class
	// testing for inventory class
	// testing for hashing classes
		// testing for hashAccounts
		// testing for hashPopular
		// testing for hashWaitlist

	// end of all testing
	//cout << "This testing is now done:" << endl;
	//cout << "This program can be improved in the following ways:" << endl;
	//cout << "1: can improve the user feedback of test cases." << endl;
	//cout << "2: not nesscessary to use hashing for everywhere it is used" << endl;
	//cout << "All users are free to use and add to these test cases, with the condition that they continue to pass them down to future students with improvements and an updated list on what can be improved." << endl;
	//cout << "P.S. it can always be improved!" << endl;
	
	return 0;
}
