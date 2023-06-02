/* ------------------------------------------------command.h----------------------------
Steven Wenzel: CSS 343 A Spring 2023
-----------------------------------------------------------------------------------------
This is the header file for the command object meant to help with command string parsing
--------------------------------------------------------------------------------------*/
#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Commands
{
public:
	~Commands();
	// does the parsing of the command and assigns to the data members
	Commands(string command);
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
	// returns a vector holding a parsed string, by spaces; give it an index from the parsedCommand vector
	vector<string> spaceParser(int index);
	//retrieve the command types
	vector<char> getCommandTypes();

	//comparison overloads - checks for identical command objects
	bool operator==(const Commands& rhs) const;
	bool operator!=(const Commands& rhs) const;

private:
	// vector of strings to store the command after parsing at commas
	vector<string> parsedCommand;

	// all error messages to be eccountered when reading in a command
	// error message for: command type failure - non existant
	string error1 = "ERROR: Command type failure - non-existant command: ";

	// chars for their indicated command type
	char createComedy = 'F';
	char createDrama = 'D';
	char createClassic = 'C';
	char showInventory = 'I';
	char showCustomerHistory = 'H';
	char checkoutItem = 'B';
	char givebackItem = 'R';

	// vector that stores all accepted command types
	vector<char> commandTypes{ createComedy, createDrama, createClassic,
									  showInventory, showCustomerHistory, checkoutItem, givebackItem };
};
#endif
