/* ------------------------------------------------hashPopular.h----------------------------
Steven Wenzel: CSS 343 A Spring 2023
-----------------------------------------------------------------------------------------
This is a template class that stores the 10 most popular genre objects in a hash 
using a modified open addressing that doesn't increase the amount of slots when full
--------------------------------------------------------------------------------------*/
#ifndef HASHPOP_H
#define HASHPOP_H

#include "hash.h"
#include <limits.h>

// this class uses open addressing and stores a pointer to the item
template <class T>
class HashPopular : public Hash
{
public:
	// currently does nothing
	HashPopular();
	// set all the pointers in each slot in the vector to nullptr
	~HashPopular();
  
	// insert key and value into the hashed vector after hashing the title
	void insert(T* item);
	// check the popular vector for the item using the hashIndex for the item title
	T* search(T* item);
	// won't work using hashing but you can just use linear searching won't be bad since its only 10 slots
	// pass in an old item and if its in the popular hash then the new item that you passed in will replace it. 
	// they can't be equal and they can't be empty
	// only works if the hash slots are full
	void swap(T* newitem, T* olditem);
	// check if all slots are taken
	bool isFull();
	// check if the passed in item is in the hash
	bool isPopular(T* item);
	// returns the item with the lowest popularity thats in the hash
	T* getLowestPopular();
	
private:
	// returns the index for the hash; Key: item title; Value: item 
	int hashFunction(T* item);

	// vector holding the failed borrow commands
	vector<T*> popular[10];
	// check the popular vector for the item and return its index if found
	int searchForSwap(T* item);
};


// this is the implementation 

/* ------------------------------------HashPopular--------------------------------------
Description: does nothing
-------------------------------------------------------------------------------------- */
template <class T>
HashPopular<T>::HashPopular()
{
}

/* ------------------------------------(~HashPopular)--------------------------------------
Description: set all the item pointers in the popular vector to nullptr
-------------------------------------------------------------------------------------- */
template <class T>
HashPopular<T>::~HashPopular()
{
	// go through each index in the vector
	for (int i = 0; i < popular->size(); i++)
	{
		// a temp pointer for traversing the popular vector
		T* temp = popular->at(i);
		// set temp to nullptr
		temp = nullptr;
	}
}

/* ------------------------------------(hashFunction)--------------------------------------
Description: uses item title to create the hash, 
call some other premade hashFunction that returns the hashIndex, converts used items into
usable types for premade hash functions, mostly for inside use
-------------------------------------------------------------------------------------- */
template <class T>
int HashPopular<T>::hashFunction(T* item)
{
	// check if the item pointer is empty
	if (item == nullptr)
	{
		return -1;
	}
	// get the item title from the item object
	string title = item->getTitle();
	// call and return the hashMidSqaure on the id
	return hashStringFold(title, popular->size());
}

/* ------------------------------------(insert)--------------------------------------
Description: using the hash index, insert key and value into the hashed vector
-------------------------------------------------------------------------------------- */
template <class T>
void HashPopular<T>::insert(T* item)
{
	// check if the item pointer is empty
	if (item != nullptr)
	{
		// check if all slots are full
		if (!isFull())
		{
			// get the hashIndex from the hashFunction
			int hashIndex = hashFunction(item);
			// set the item pointer at the hashIndex to the passed in item 
			popular->at(hashIndex) = item;
			// up the slots taken
			size++;
		}
	}
}

/* ------------------------------------(search)--------------------------------------
Description: searches for the passsed in item and 
returns a pointer because the account object needs to be edited,
returns nullptr if not found, mostly for inside use
-------------------------------------------------------------------------------------- */
template <class T>
T* HashPopular<T>::search(T* item)
{
	// check if the item pointer is empty
	if (item == nullptr)
	{
		return nullptr;
	}

	// find the hashIndex of the passed in item 
	int hashIndex = hashFunction(item);

	// go to the hashIndex in the popular vector and compare with the passed in item
	if (popular->at(hashIndex) == item)
	{
		return popular->at(hashIndex);
	}
	// if not found at hashIndex
	else
	{
		// search the whole popular vector linearly
		for (int i = 0; i < 10; i++)
		{
			if (popular->at(i) == item)
			{
				return popular->at(i);
			}
		}
		// if not found in the popular vector
		return nullptr;
	}
}

/* ------------------------------------(searchForSwap)--------------------------------------
Description: searches for the passsed in item and return its index if found,
mostly for inside use and is a helper function for swap()
-------------------------------------------------------------------------------------- */
template <class T>
int HashPopular<T>::searchForSwap(T* item)
{
	// check if the item pointer is empty
	if (item == nullptr)
	{
		return -1;
	}

	// find the hashIndex of the passed in item 
	int hashIndex = hashFunction(item);

	// go to the hashIndex in the popular vector and compare with the passed in item
	if (popular->at(hashIndex) == item)
	{
		return hashIndex;
	}
	// if not found at hashIndex
	else
	{
		// search the whole popular vector linearly
		for (int i = 0; i < 10; i++)
		{
			if (popular->at(i) == item)
			{
				return i;
			}
		}
		// if not found in the popular vector
		return -1;
	}
}

/* ------------------------------------(swap)--------------------------------------
Description: swap out an old popular item with a new one, only works if the popular hash is already full
-------------------------------------------------------------------------------------- */
template <class T>
void HashPopular<T>::swap(T* oldItem, T* newItem)
{
	if (isFull())
	{
		// make sure both items are not empty
		if (newItem != nullptr && oldItem != nullptr)
		{
			int index = searchForSwap(oldItem);
			// check if the oldItem is in the popular vector
			if (index != -1)
			{
				popular->at(index) = newItem;
			}
		}
	}
}

/* ------------------------------------(isFull)--------------------------------------
Description: checks if the hash is full, returns true if its full
-------------------------------------------------------------------------------------- */
template <class T>
bool HashPopular<T>::isFull()
{
	if (size == 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* ------------------------------------(isPopular)--------------------------------------
Description: check if the passed in item is in the hash, return true if found
-------------------------------------------------------------------------------------- */
template <class T>
bool HashPopular<T>::isPopular(T* item)
{
	// search the hash and return true if item is found
	if (search(item) != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* ------------------------------------(getLowestPopular)--------------------------------------
Description: return the lowest popular item in the hash
-------------------------------------------------------------------------------------- */
template <class T>
T* HashPopular<T>::getLowestPopular()
{
	// check if the hash is empty
	if (size == 0)
	{
		return nullptr;
	}
	int lowest = INT_MAX;
	int index = 0;
	// search the whole popular vector for the lowest popular item
	for (int i = 0; i < 10; i++)
	{
		if (popular->at(i)->getPopularity() < lowest)
		{
			index = i;
			lowest = popular->at(i)->getPopularity();
		}
	}
	// return the lowest popular item
	return popular->at(index);
}
#endif
