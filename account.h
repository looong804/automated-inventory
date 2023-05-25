#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "command.h"
#include <string>

class Account{
    public:
    Account();
    ~Account();

    //actions
    // return the customer's first name
    string getFirst() const;
    // return the customer's last name
    string getLast() const;
    // return the customer's full name
    string getFullName() const;
    // return the customer id
    int getID() const;

    private:
    // account holder's first name
    string first = "";
    // account holder's last name
    string last = "";
    // account id
    int id = 0;
};
#endif //ACCOUNT_H
