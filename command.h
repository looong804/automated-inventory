#ifndef COMMAND_H
#define COMMAND_H

#include "store.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Command
{
public:
	// does the parsing of the command and assigns to the data members
	Command(string command);

	// return command type
	char getCommandType() const;
	// return if failure happened
	bool failure() const;
	// set failure
	void setFailure(bool);
	// print out the correct error message based on the error type put int
	void printErrorMessage(string errorType);
	// cerr << this->errorType << endl;

	//stream overloads
	// display all the needed info
	friend ostream& operator<< (ostream& stream, const Command& command);

private:
	// vector of strings to store the command after parsing at commas
	vector<string> parsedCommand;
	// letter indicating the command type
	// borrow is default if not changed by constructor
	char commandType = 'B';
	// bool to show if their was an error with the command
	bool failed = false;

	// all error messages to be eccountered when reading in a command
	// error message for: command type failure - non existant
	string error1 = "ERROR: Command type failure - non-existant command: ";

	//// these errors are no longer needed
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
};
#endif