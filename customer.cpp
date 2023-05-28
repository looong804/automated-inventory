#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include "customer.h"

//
Customer::Customer(){

}//close default constructor

//
Customer::Customer(Command createCustomerAccount){

}//close create customer constructor



//
Customer::~Customer(){

}//close destructor



//Functions
//
void Customer::showHistory(){
    //parse through vector history
    //print out oldest transaction to most recent
}//close showHistory

//
void Customer::borrow(Item item){
    //checks if Customer has already borrowed this Item
    //checks if the Item exists
    //checks if the Item is available
        //if available, checks item out to Customer
        //add to history that customer borrowed item
        //decrement stock
        //increment request counter
        //if not available, place customer in waitlist
        //consider handing item to customer in waitlist
        //instead of returning to inventory
}//close borrow

//
void Customer::returnItem(Item item){
    //checks if item exists
    //checks if Customer has the item checked out
    //add to history that customer returned item
    //checks if there is a waitlist for item
        //if customer is waiting for item, check out item
        //directly to waiting customer
        //add to that customer's history
        //remove customer from waitlist
        //do not change stock or request counter
        //if there is no waitlist, return item to shelf
        //increase stock
}//close returnItem



//Overload operator
//
ostream& operator<<(ostream& out, const Customer& cus){

}//close operator<<

#endif //CUSTOMER_CPP