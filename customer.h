#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "item.h"
#include <vector>
#include <sstream>
#include "account.h"

class Customer : public Account{
public:
	// not needed
	Customer();
	// used when reading in the account file
	explicit Customer(Command createCustomerAccount);
	// deletes the command items in the history vector
	~Customer();

    //Getters
    vector<string> getItemsOut();
    string getItemsOut(int index);
    string getFirst() const;
    string getLast() const;
    string getFullName() const;
    int getID() const;

	//Functions
	void showHistory(); //prints the customer's history
	void borrow(Command action);
	void returnItem(Command action);


	//stream overloads
	// display the customer history
	friend ostream& operator<< (ostream& out, const Customer& cus);
    bool operator==(const Customer& cus);
    bool operator!=(const Customer& cus);
private:
	// holds the account history
	vector<Command> history;
    vector<string> itemsOut;
};
#endif //CUSTOMER_H