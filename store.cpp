#ifndef STORE_CPP
#define STORE_CPP

#include "store.h"
#include <fstream>
#include <sstream>
#include <string>

//constructors
//default -- unused at the moment
Store::Store(){

}//close default constructor

//
Store::Store(vector<string> files){
    this -> filesNames = files;
    readFiles();
}//close files constructor

//destructor
Store::~Store(){

}//close destructor



//Setters
//
void Store::setStock(){
    //
    while(!stock.empty()){
        //Retrieve first item
        Command temp = stock.at(0);

        if(temp.getVector(0) == "F"){
            Item newItem;

            if(newItem.getTitle() == comedyTree.search(newItem).getTitle()){
                newItem.SetStock(comedyTree.search(newItem).getStock() + temp.getVector(1));
            }else{
                newItem.setTitle(temp.getVector(3));
                newItem.SetStock(stoi(temp.getVector(1)));
                inventory().getVector()[0]; //TODO: insert in right index
            }
        }else if(temp.getVector(0) == "D"){
            Item newItem;

            if(newItem.getTitle() == dramaTree.search(newItem).getTitle()){
                newItem.SetStock(dramaTree.search(newItem).getStock() + temp.getVector(1));
            }else{
                newItem.setTitle(temp.getVector(3));
                newItem.SetStock(stoi(temp.getVector(1)));
                inventory().getVector()[0]; //TODO: insert in right index
            }
        }else if(temp.getVector(0) == "C"){
            Item newItem;

            if(newItem.getTitle() == classicTree.search(newItem).getTitle()){
                newItem.SetStock(classicTree.search(newItem).getStock() + temp.getVector(1));
            }else{
                newItem.setTitle(temp.getVector(3));
                newItem.SetStock(stoi(temp.getVector(1)));
                inventory().getVector()[0]; //TODO: insert in right index
            }
        }

        stock.erase(stock.begin());
    }
}//close setStock

//
void Store::setAccounts() {
    while(!customers.empty()){
        Command temp = customers.at(0);

        if(temp.getVector(0) == "K"){
            Customer newCustomer;

            if(!isAccount(newCustomer)){
                newCustomer.setID(stoi(temp.spaceParser(0)[0])); //TODO: check
                newCustomer.setLast(temp.spaceParser(1)[1]); //TODO: check
                newCustomer.setFirst(temp.spaceParser(2)[2]); //TODO: check

                insert(newCustomer);
            }
        }

        customers.erase(customers.begin());
    }
}//close setAccounts

//
void Store::executeActions() {
    while(!actions.empty()){
        Command temp = actions.at(0);

        if(temp.getVector(0) == "B"){
            borrowItem(temp);
        }else if(temp.getVector(0) == "R"){
            returnItem(temp);
        }else if(temp.getVector(0) == "I"){
            //list inventory
        }else if(temp.getVector(0) == "H"){
            accountHistory(stoi(temp.getVector(1)));
        }

        actions.erase(actions.begin());
    }
}//close executeCommands


//Getters
//
vector<char> Store::getCommandTypes(){
    return this -> commandTypes;
}//close getCommand

// return number of accounts
int Store::numAccounts() const{
    //return hash account's size
    return 0;
}//close numCustomers



//Functions
//read all files in the files vector
void Store::readFiles(){
    //iterate through file names
    for(auto &filesName : filesNames){
        ifstream file(filesName);

        //insert items
        while(!file.eof()){
            string line;

            while(getline(file, line)){
                Command tempCom(line);
                string letter = tempCom.getVector().at(0);

                //checks if this is a movie command
                if(letter == "F" || letter == "D" || letter == "C"){
                    stock.push_back(tempCom);
                //checks if this is a customer command
                }else if(letter == "K"){
                    customers.push_back(tempCom);
                //checks if this is a command
                }else if(letter == "B" || letter == "R"
                    || letter == "I" || letter == "H"){
                    actions.push_back(tempCom);
                //not a recognized command
                }//close command check
            }//close insert items
        }//close last line check
    }//close num files check
}//close files

// open an account
bool Store::openAccount(Command action){
    Customer newAcct(action);

    //if account already exists
    if(customers[0] == isAccount(newAcct))
        return false;

    //insert account into hashtable, providing ID as key
    insert(newAcct);

    return true;
}//close openAccount

//
Account* Store::findAccount(int id) const{
    //calls hashAccount's search function
    
    return nullptr;
}//close findAccount

//
DVD* Store::findDrama(Drama& dvd) const{
    //checks that the first index is D
    //parse through binary tree for dvd
    //search via director then title
    return nullptr;
}//close findDrama

//
DVD* Store::findComedy(Comedy& dvd) const{
    //checks that the first index is F
    //parse through binary tree for dvd
    //search via title then year released
    return nullptr;
}//close findComedy

// find a classic dvd and verify that it exists
DVD* Store::findClassic(Classic& dvd) const{
    //checks the first index is C
    //parse through binary tree for dvd
    //search via release date then major actor

    return nullptr;
}//close findClassic


// return a borrowed item
bool Store::returnItem(Command action){
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

    return false;
}//close returnItem

// borrow an item
bool Store::borrowItem(Command action){
    //checks if the Item exists
    //checks if Customer has already borrowed this Item
    //checks if the Item is available
        //if available, checks item out to Customer
        //add to history that customer borrowed item
        //decrement stock
        //increment request counter
        //if not available, place customer in waitlist
        //consider handing item to customer in waitlist
        //instead of returning to inventory
    return false;
}//close borrowItem

// print out account history given the id number
void Store::accountHistory(int id) const{
    //use id to find account in hash table
    //retrieve account
    //use account showHistory
}//close accountHistory



//Operator overloads
// prints out the inventory object using <<
ostream& operator<< (ostream& stream, Store& store){
    return stream;
}//close operator<<

#endif //STORE_CPP