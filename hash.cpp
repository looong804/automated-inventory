#include "hash.h"

Hash::Hash()
{
}

int Hash::getSize() const
{
	return size;
}


// hash function using folding on a string, summed 4 bytes at a time
int Hash::hashStringFold(string key, int tableSize)
{
	long sum = 0, mul = 1;
	for (int i = 0; i < key.length(); i++) {
		mul = (i % 4 == 0) ? 1 : mul * 256;
		sum += key.at(i) * mul;
	}
	return (int)(abs(sum) % tableSize);
}

// hash function using mid square method for ints
int Hash::hashMidSquare(int key, int tableSize)
{
    // Square the key
    int squared = key * key;

    // Convert the squared value to a string
    std::string squaredStr = std::to_string(squared);

    // Calculate the number of middle digits to extract
    int middleDigits = static_cast<int>(std::log10(squared)) / 2;

    // Extract the middle digits as a substring
    std::string middleStr = squaredStr.substr(squaredStr.length() / 2 - middleDigits, middleDigits);

    // Convert the middle string back to an integer
    int hashValue = std::stoi(middleStr);

    // Calculate the actual hash value within the table size
    return hashValue % tableSize;
}
