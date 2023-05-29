#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "store.h"

using namespace std;

class Command
{
public:
	// does the parsing of the command and assigns to the data members
	Command(string command);
	// print out the correct error message based on the error type put int
	void printErrorMessage(string errorType);
	// getter for the vector storing the parsed command
	vector<string> getVector();
	// getter for the string at the given index in the vector
	string getVector(int index);
	// converts the passed in string to a stringstream
	stringstream convertToStringstream(string stringToSplit);
	// returns a vector holding the passed in string parsed by spaces
	vector<string> spaceParser(string stringToSplit);
	// returns a vector holding a parsed string, by spaces
	vector<string> spaceParser(int index);

	//comparison overloads - checks for identical command objects
	bool operator==(const Command& rhs) const;
	bool operator!=(const Command& rhs) const;

private:
	// vector of strings to store the command after parsing at commas
	vector<string> parsedCommand;

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
