#include "hashPopular.h"

HashPopular::HashPopular()
{
}

// set all the item pointers in the popular vector to nullptr
HashPopular::~HashPopular()
{
	// go through each index in the vector
	for (int i = 0; i < popular->size(); i++)
	{
		// a temp pointer for traversing the popular vector
		Item* temp = popular->at(i);
		// set temp to nullptr
		temp = nullptr;
	}
}

int HashPopular::hashFunction(Item* item)
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

void HashPopular::insert(Item* item)
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

// go to the hashIndex and check if the item is there
Item* HashPopular::search(Item* item)
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

// find the passed in item if its in the popular vector
// return its index if found
int HashPopular::searchForSwap(Item* item)
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

// swap out an old popular item with a new one
void HashPopular::swap(Item* oldItem, Item* newItem)
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

bool HashPopular::isFull()
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
