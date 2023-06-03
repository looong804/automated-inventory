#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "command.h"
#include <string>

using namespace std;

class Account{
    public:
    //Constructors
    Account();

    //Destructors
    ~Account();

    //Setters
    void setFirst(const string firstName);
    void setLast(const string lastName);
    void setID(const int idNum);

    //Getters
    // return the customer's first name
    virtual string getFirst() const;
    // return the customer's last name
    virtual string getLast() const;
    // return the customer's full name
    virtual string getFullName() const;
    // return the customer id
    virtual int getID() const;

    private:
    // account holder's first name
    string first;
    // account holder's last name
    string last;
    // account id
    int id;
};//close Account

#endif //ACCOUNT_H
