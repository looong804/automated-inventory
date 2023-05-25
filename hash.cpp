#include "hash.h"

// set the vector size to the default
HashMap::HashMap()
{
}

// delete the customer account in each slot in the vector by deleting each node in the linked list
HashMap::~HashMap()
{
}

// call some other premade hashFunction
// to hash the id
// returns the index for the hash
int HashMap::hashFunction(Account account)
{
	
}

//using the hash index, insert key and value into the hashed vector
void HashMap::insert(int hashIndex, Account account)
{
}

//returns a pointer because the customer object needs to be edited
Account* HashMap::search(int accountID)
{
	return nullptr;
}

//deletes the object with the given key from the hash
Account HashMap::remove(int accountID)
{
	// if empty list
	if (head_ == nullptr)
	{
		return false;
	}
	// if head is greater than the target
	if (*(head_->data) > target)
	{
		return false;
	}
	// first in line
	if (*(head_->data) == target)
	{
		Node<T>* temp = head_;
		head_ = head_->next;
		size_--;
		delete (temp->data);
		delete temp;
		temp = nullptr;
		result = *(head_->data);
		return true;
	}
	// for all others
	Node<T>* p_node = head_;
	while ((p_node->next != nullptr) && (*(p_node->next->data) < target))
	{
		p_node = p_node->next;
	}
	if ((p_node->next != nullptr) && ((*p_node->next->data) == target))
	{
		Node<T>* temp = p_node->next;
		p_node->next = temp->next;
		size_--;
		result = *(temp->data);
		delete temp;
		return true;
	}
	return false;
}
