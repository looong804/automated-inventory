#ifndef HASH_H
#define HASH_H

#include <string>
#include <vector>
#include "DVD.h"
#include "customer.h"
//#include <hash>

using namespace std;

class HashMap
{
	struct NodeData 
	{
		DVD *item;
		DVD *next;
	};



public:
	HashMap();
	~HashMap();

	int hashFunction(int customerID); //this class is just for the class ID storage, returns the index for the hash


	void insert(int hashIndex, int customerID, Customer *account); //using the hash index, insert key and value into the hashed vector

	//returns a pointer because the customer object needs to be edited
	Customer* search(int index); //returns the customer, does not remove it from the heap
	Customer remove(int customerID); //deletes the object with the given key from the hash
	
private:
	vector<NodeData> DVDs; 
};
#endif //HASH_H
