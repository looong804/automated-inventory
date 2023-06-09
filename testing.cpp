#include "store.h"
#include <vector>

int main(int argc, char* argv[])
{
	// cout << "This is the beginning of the testing of the inventory tracking system purposed for a movie rental store. " << endl; 
	// cout << "This system is intended to be easily modified for real world changes: " << endl;
	// cout << "This contains the test cases for the Inventory System consisting of the following classes: Store class, Account class, Genre class, DVD class, Command class" << endl;
	// cout << "To help with sequential testing and enabling the functions that help you test the others it is recommend to implement the functions in the following order that they are tested in." << endl;
	// cout << "The functions of the Inventory System are tested in the following order: " << endl;

	// types of errors to be checking for:
	//// error message for: stock amount failure - no negatives
	//string error2 = "Error: Stock amount failure - no negatives";
	//// error message for: account id failure - no negatives, non existant
	//string error3 = "Error: Account id failure - no negatives, non existant";
	//// error message for: returning a movie - never borrowed
	//string error4 = "Error: returning a movie - never borrowed";
	//// error message for: movie not in stock - stock is 0
	//string error5 = "Error: movie not in stock - stock is 0";
	//// error message for: not all fields filled **** is this needed? **************
	//string error6 = "Error: ";
	//// error message for: movie genre - non existant
	//string error7 = "Error: movie genre - non existant";
	//// error message for: movie data - non existant title/year/month/actor/director
	//string error8 = "Error: movie data - non existant title/year/month/actor/director";
	
	
	// should probably add just a couple text files to contain the input commands to test everything
	// create a store using given input files

	vector<string> files; 
	files.push_back("data4commands.txt");
	files.push_back("data4customers.txt");
	files.push_back("data4movies.txt");


	Store store(files);
	//Store stuff(givenFile1, givenFile2, givenFile3);
	cout << "Finished running the given input files." << endl;
	// create a store using our test files
	//Store treasureTrove(testFile1, testFile2, testFile3);
	//cout << "Finished running the test files." << endl;
	
	// Testing for Command class - covered a couple that should fail and others that should work 
	/*Command fail0("Z 1000 D C 10 1941 Humphrey Bogart");
	Command fail1("X");
	Command fail2("Z, 10, Frank Capra, It's a Wonderful Life, James Steward 11 1946");
	Command work0("I");
	Command work1("H");
	Command work2("B 1000 D D Steven Spielberg, Bogus Title,");
	Command work3("R 5000 D C 3 1971 Ruth Gordon");
	Command work4("2000 Duck Donald");
	Command work5("D, 10, Nancy Savoca, Dogfight, 1991");
	Command work6("F, 10, Nora Ephron, You've Got Mail, 1998")
	Command work7("C, 10, George Cukor, The Philadelphia Story, Cary Grant 5 1940");
	// testing for BST class - can use the items made for testing the item class here as well
	BST tree;
	tree.insert()
	// testing for inventory class - can test after constructing some BSTs
		
	// testing for hashing classes - can test once all the command, item, account and other functions are working
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
	
	// to be added above
		// - could create a chain class that holds stores and has the num of stores, and 
		// you can create a chain by reading in a folder that contains a folder for 
		// each store that has the three files needed to make a store
		// - could create an item class to be the parent of the dvd class, 
		// which enables quick adds of new items in stock
		// - could add an accounts class to be the parent class of all account type classes
		// such as customer account, IT account, employe account, manager account
		// - could create another level of catagorizing with classes like video, audio, games
		// these would then be parent classes of things like; For video: tvs, cables, movies, players
		// For Audio: speakers, music, players, For games: video games, controls, game systems
		// 
		// - could add a time to return things by and for each day after the return time charge more
		// - could add a charge system/ tab system or make customers store money on their account
		// - could add prices to all the items in the inventoy
		// - could add discounting functions that will discount all the prices of items 
		// depending on their catagories and types, and after a certain time return them to full price
		*/
	return 0;
}
