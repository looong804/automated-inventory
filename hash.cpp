#include "hash.h"

HashMap::HashMap()
{
}

HashMap::~HashMap()
{
}

// call some other premade hashFunction
int HashMap::hashFunction(int customerID)
{
	
}

void HashMap::insert(int hashIndex, int customerID, Account* account)
{
}

Account* HashMap::search(int index)
{
	return nullptr;
}

Account HashMap::remove(int customerID)
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
