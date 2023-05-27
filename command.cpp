#include "command.h"

Command::Command(string command)
{
	// check if the first spot is not an int
	if (!isdigit(command.at(0)))
	{
		// parse off the Letter indicating the command
		commandType = command.at(0);
		
		// bool to mark if command is vaild
		bool vaild = false;
		// check if commandType is one of the vaild ones in the vectors holding 
		// movie creation command types
		for (int i = 0; i < commandTypes.size(); i++)
		{
			// if command is found in vaild command mark it as vaild
			if (commandTypes[i] == commandType)
			{
				vaild = true;
				break;
			}
		}
		// if not vaild command print error
		if (!vaild)
		{
			printErrorMessage(error1);
			cerr << command << endl;	
		}
		
		// cut off the commandType from command string
		command = command.substr(2, command.length());

		// finish parsing the command string and storing in vector
		while (!command.empty())
		{
			// find next comma index
			int end = command.find(",");
			// check if a comma was found
			if (end != -1)
			{
				// parse command string to the next comma and store in vector
				parsedCommand.push_back(command.substr(0, end));
				// fix command - erase piece just parsed 
				command = command.substr((end + 1), (command.length()));
			}
			// put whole command string into the vector index 0
			else
			{
				parsedCommand[0] = command;
			}
		}
	}
	// check is first character is an index
	else if (isdigit(command.at(0)))
	{
		// check if the first 4 index spots are ints
		if (isdigit(command.at(0)) && isdigit(command.at(1)) && isdigit(command.at(2)) && isdigit(command.at(3)))
		{
			// create a new commandType K for customer accounts
			char createCustomer = 'K';
			// put the newly created commandType into index 0 of the vector
			parsedCommand[0] = createCustomer;
			// put the rest of the command into the vector
			parsedCommand[1] = command;
		}
		else
		{
			printErrorMessage(error1);
			cerr << command << endl;
		}
	}
}

// pass in the error message wanted
// enables lots of error printing without changing the function just adding error messages
void Command::printErrorMessage(string errorType)
{
	// print out the error message that was passed in
	cerr << errorType;
}

// getter for the vector storing the parsed command
vector<string>& Command::getVector() const
{
	return parsedCommand; 
}

// return the string at the given index in the vector
string& Command::getVector(int index) const
{
	return parsedCommand[index]; 
}
