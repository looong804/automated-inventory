#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "item.h"
#include <vector>
#include "account.h"

class Customer : public Account
{
public:
	// not needed
	Customer();
	// used when reading in the account file
	Customer(Command createCustomerAccount);
	// deletes the command items in the history vector
	~Customer();

	//Functions
	void showHistory(); //prints the customer's history

	void borrow(Item item);

	void returnItem(Item item);


	//stream overloads
	// display the customer history
	friend ostream& operator<< (ostream& stream, const Customer& cus);

private:
	// holds the account history
	vector<Command> commands;
};
#endif //CUSTOMER_H