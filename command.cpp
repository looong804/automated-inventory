#include "command.h"
#include "store.h"

Command::Command(string command)
{
	// check if the first spot is not an int
	if (!isdigit(command.at(0)))
	{
		// parse off the Letter indicating the command
		commandType = command.at(0);
		// cut off the commandType from command string
		command = command.substr(2, command.length());

		// index for the vector storing command info
		int index = 0;
		// finish parsing the command string and storing in vector
		while (!command.empty())
		{
			// find next comma index
			int end = command.find(",");
			// check if a comma was found
			if (end != -1)
			{
				// parse command string to the next comma and store in vector
				parsedCommand[i] = command.substr(0, end);
				// fix command - erase piece just parsed 
				command = command.substr((end + 1), (command.length() - 1));
				i++;
			}
			// put whole command string into the vector index 0
			else
			{
				parsedCommand[0] = command;
			}
		}

		// check if commandType is one of the vaild ones in the vectors holding 
		// movie creation command types
		if (commandType == "F" || commandType == "D" || commandType == "C")
		{
			// put command object into the stock vector
			Store::stock.push_back(*this);
		}
		// action command types
		else if (commandType == "B" || commandType == "R" || commandType == "H" || commandType == "I")
		{
			// put command object into the actions vector
			Store::actions.push_back(*this);
		}
	}
	else
	{
		// check if the first 4 index spots are ints
		if (isdigit(command.at(0)) && isdigit(command.at(1)) && isdigit(command.at(2)) && isdigit(command.at(3)))
		{
			// put whole command string in the vector
			parsedCommand[0] = command;
			// put the command in the accounts making vector
			Store::accounts.push_back(*this);
		}
	}
	// if it gets here its not a vaild command with a vaild commandType/starting characters
	else
	{
		printErrorMessage(error1);
		cerr << command << endl;
	}
}

// return the commandType
char Command::getCommandType() const
{
	return commandType;
}

// return the failure bool to reflect commandType acceptance
bool Command::failure() const
{
	return failed;
}

// set the failure based on if the commandType is acceptable
void Command::setFailure(bool status)
{
	failed = status;
}

// pass in the error message wanted
// enables lots of error printing without changing the function just adding error messages
void Command::printErrorMessage(string errorType)
{
	cerr << errorType;
}