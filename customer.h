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
	Customer(Commands createCustomerAccount);
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
	void borrow(Commands action);
	void returnItem(Commands action);


	//stream overloads
	// display the customer history
	friend ostream& operator<< (ostream& out, const Customer& cus);
    bool operator==(const Customer& cus) const;
    bool operator!=(const Customer& cus) const;
private:
	// holds the account history
	vector<Commands> history;
    vector<string> itemsOut;
};
#endif //CUSTOMER_H