#ifndef HASH_H
#define HASH_H

#include <string>
#include <vector>
#include "DVD.h"
#include "customer.h"

using namespace std;

class HashMap
{
public:
	HashMap();
	~HashMap();

	//this class is just for the class ID storage, returns the index for the hash
	int hashFunction(int customerID); 

	//using the hash index, insert key and value into the hashed vector
	void insert(int hashIndex, int customerID, Customer *account); 

	//returns a pointer because the customer object needs to be edited
	Customer* search(int index); 
	//deletes the object with the given key from the hash
	Customer remove(int customerID); 
	// return the hash size
	int getSize(); 
	
	struct NodeData 
	{
		Item* item;
		NodeData* next;
	};
	
private:
	int size;
};
#endif //HASH_H
