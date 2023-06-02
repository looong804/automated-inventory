#include "command.h"

Commands::~Commands()
{
}

Commands::Commands(string command)
{
	// check if the first spot is not an int
	if (!isdigit(command.at(0)))
	{
		// parse off the Letter indicating the command
		char commandType = command.at(0);

		// bool to mark if command is vaild
		bool valid = false;
		// check if commandType is one of the vaild ones in the vectors holding 
		// movie creation command types
		for (int i = 0; i < getCommandTypes().size(); i++)
		{
			// if command is found in vaild command mark it as vaild
			if (getCommandTypes().at(i) == commandType)
			{
				valid = true;
				string letter = "";
				letter += commandType;
				parsedCommand.push_back(letter);
				break;
			}
		}
		// if not vaild command print error
		if (!valid)
		{
			printErrorMessage(error1);
			cerr << command << endl;
		}
		else if (valid)
		{
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
					parsedCommand.push_back(command.substr(0 + 1, end));
					// fix command - erase piece just parsed 
					command = command.substr((end + 2), (command.length()));
				}
				// put whole command string into the vector
				else
				{
					parsedCommand.push_back(command);
					// empty the command ok
					command.clear();
				}
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
			string createCustomer = "k";
			// put the newly created commandType into index 0 of the vector
			parsedCommand.push_back(createCustomer);
			// put the rest of the command into the vector
			parsedCommand.push_back(command);
		}
		else
		{
			printErrorMessage(error1);
			cerr << command << endl;
		}
	}
}

//
vector<char> Commands::getCommandTypes()
{
	return this->commandTypes;
}//close getCommand

// pass in the error message wanted
// enables lots of error printing without changing the function just adding error messages
void Commands::printErrorMessage(string errorType)
{
	// print out the error message that was passed in
	cerr << errorType;
}

// getter for the vector storing the parsed command
vector<string> Commands::getVector()
{
	return parsedCommand;
}

// return the string at the given index in the vector
string Commands::getVector(int index)
{
	return parsedCommand[index];
}

// parse the passed in string by spaces
stringstream Commands::convertToStringstream(string stringToSplit)
{
	// string stream set equal to the passed string
	stringstream stringStream(stringToSplit);
	// return the stringstream 
	return stringStream;
}

// parse the passed in string by spaces
vector<string> Commands::spaceParser(string stringToSplit)
{
	// string stream set equal to the passed string
	stringstream stringStream(stringToSplit);
	// create a vector to return
	vector<string> parsed;
	// whole the stringstream isn't empty
	while (stringStream.rdbuf()->in_avail() != 0)
	{
		// string to hold the individual strings from stringStream
		string temp = "";
		// put the first string into temp
		stringStream >> temp;
		// put temp into the vector
		parsed.push_back(temp);
	}
	// return the vector 
	return parsed;
}

// use the passed in index to get the string in the parsedCommand vector
vector<string> Commands::spaceParser(int index)
{
	// string stream set equal to the passed string
	stringstream stringStream(parsedCommand[index]);
	// create a vector to return
	vector<string> parsed;
	// while the stringstream isn't empty
	while (stringStream.rdbuf()->in_avail() != 0)
	{
		// string to hold the individual strings from stringStream
		string temp = "";
		// put the first string into temp
		stringStream >> temp;
		// put temp into the vector
		parsed.push_back(temp);
	}
	// return the vector 
	return parsed;
}

// compare all values in the parsed command
bool Commands::operator==(const Commands& rhs) const
{
	// compare the vector sizes first
	if (this->parsedCommand.size() != rhs.parsedCommand.size())
	{
		return false;
	}
	// go through the vectors
	else
	{
		for (int i = 0; i < this->parsedCommand.size(); i++)
		{
			// if any value is not equal
			if (this->parsedCommand.at(i) != rhs.parsedCommand.at(i))
			{
				return false;
			}
		}
		return true;
	}
}

// compare all values in the parsed command
bool Commands::operator!=(const Commands& rhs) const
{
	if (!(*this == rhs))
	{
		return true;
	}
	else
	{
		return false;
	}
}
