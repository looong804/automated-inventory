#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include "customer.h"

//
Customer::Customer(){

}//close default constructor

//
Customer::Customer(Command createCustomerAccount){
    stringstream strstrm(createCustomerAccount.getVector(1)); //retrieves account info
    string tempInfo;

    strstrm >> tempInfo;
    this -> setID(stoi(tempInfo));
    strstrm >> tempInfo;
    this -> setLast(tempInfo);
    strstrm >> tempInfo;
    this -> setFirst(tempInfo);
}//close create customer constructor



//
Customer::~Customer(){

}//close destructor



//Getters
//
vector<string> Customer::getItemsOut()
{
    return itemsOut;
}//close getItemsOut

//
string Customer::getItemsOut(int index){
    return itemsOut[index];
}//close getItemsOut index

//
string Customer::getFirst() const{
    return Account::getFirst();
}//close getFirst

//
string Customer::getLast() const{
    return Account::getLast();
}//close getLast

//
string Customer::getFullName() const{
    return Account::getFullName();
}//close getFullName

//
int Customer::getID() const{
    return Account::getID();
}//close getID



//Functions
//
void Customer::showHistory(){
    //print out oldest transaction to most recent

    //parse through vector history
    for(int i = 0; i < history.size(); i++){
        string transaction;

        for(int j = 0; j < history[i].getVector().size(); j++){
            transaction += history[i].getVector(j) + " ";
        }

        cout << transaction << endl;
    }
}//close showHistory

//
//Pseudocode
//if available, checks item out to Customer
//add to history that customer borrowed item
void Customer::borrow(Command action){
    itemsOut.push_back(action.getVector(1));
    history.push_back(action);
}//close borrow

//
//Pseudocode
//checks if item exists
//checks if Customer has the item checked out
//add to history that customer returned item
//remove from itemsOut
void Customer::returnItem(Command action){
    for(auto it = itemsOut.begin(); it < itemsOut.end(); it++){
        if(action.getVector(1) == *it){
            itemsOut.erase(it);
        }
    }

    history.push_back(action);
}//close returnItem



//Overload operator
//
ostream& operator<<(ostream& out, const Customer& cus){
    return out << cus.getID() << cus.getLast() << cus.getFirst();
}//close operator<<

//
bool Customer::operator==(const Customer& cus){
    return this -> getID() == cus.getID() &&
        this -> getLast() == cus.getLast() &&
        this -> getFirst() == cus.getFirst();
}//close operator==

//
bool Customer::operator!=(const Customer &cus){
    return this -> getID() != cus.getID() ||
        this -> getLast() != cus.getLast() ||
        this -> getFirst() != cus.getFirst();
}//close operator!=

#endif //CUSTOMER_CPP