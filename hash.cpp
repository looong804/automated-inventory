/* ------------------------------------------------hash.cpp----------------------------
Steven Wenzel: CSS 343 A Spring 2023
-----------------------------------------------------------------------------------------
This is the parent class for all the hash classes and contains the premade hash functions
used in all the other hash classes and contains the hash size data member 
--------------------------------------------------------------------------------------*/
#include "hash.h"

/* ------------------------------------Hash--------------------------------------
Description: does nothing this is an abstract class
-------------------------------------------------------------------------------------- */
Hash::Hash()
{
}

/* ------------------------------------(~Hash)--------------------------------------
Description: does nothing this is an abstract class
-------------------------------------------------------------------------------------- */
Hash::~Hash()
{
}

/* ------------------------------------(getSize)--------------------------------------
Description: return the size of the hash
-------------------------------------------------------------------------------------- */
int Hash::getSize() const
{
	return size;
}

/* ------------------------------------(hashStringFold)--------------------------------------
Description: hash function using folding on a string, summed 4 bytes at a time.
this is a common premade hash function found online by instructor permission
-------------------------------------------------------------------------------------- */
int Hash::hashStringFold(string key, int tableSize)
{
	long sum = 0, mul = 1;
	for (int i = 0; i < key.length(); i++) {
		mul = (i % 4 == 0) ? 1 : mul * 256;
		sum += key.at(i) * mul;
	}
	return (int)(abs(sum) % tableSize);
}

/* ------------------------------------(hashMidSquare)--------------------------------------
Description: hash function using mid square method for ints.
this is a common premade hash function found online by instructor permission
-------------------------------------------------------------------------------------- */
int Hash::hashMidSquare(int key, int tableSize)
{
    // Square the key
    int squared = key * key;

    // Convert the squared value to a string
    std::string squaredStr = std::to_string(squared);

    // Calculate the number of middle digits to extract
    int middleDigits = static_cast<int>(log10(squared)) / 2;

    // Extract the middle digits as a substring
    std::string middleStr = squaredStr.substr(squaredStr.length() / 2 - middleDigits, middleDigits);

    // Convert the middle string back to an integer
    int hashValue = std::stoi(middleStr);

    // Calculate the actual hash value within the table size
    return hashValue % tableSize;
}
