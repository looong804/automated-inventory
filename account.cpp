#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP

#include "account.h"

//Constructor
Account::Account(){
    this -> first = "";
    this -> last = "";
    this -> id = 0;
}//close constructor



//Destructor
Account::~Account(){

}//close destructor



//Setters
//Set the first name associated with this account
void Account::setFirst(const string firstName){
    this -> first = firstName;
}//close setFirst

//Set the last name associated with this account
void Account::setLast(const string lastName){
    this -> last = lastName;
}//close setLast

//Set the unique ID associated with this account
void Account::setID(const int idNum){
    this -> id = idNum;
}//close setID



//Getters
//Returns the first name associated with this account
string Account::getFirst() const{
    return this -> first;
}//close getFirst

//Returns the last name associated with this account
string Account::getLast() const{
    return this -> last;
}//close getLast

//Returns the full name associated with this account
string Account::getFullName() const{
    return first + " " + last;
}//close getFullName

//Returns the unique ID associated with this account
int Account::getID() const{
    return this -> id;
}//close getID
#endif //ACCOUNT_CPP