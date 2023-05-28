#ifndef STORE_CPP
#define STORE_CPP

#include "store.h"
#include <fstream>
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

}//close setStock

//
void Store::setAccounts() {

}//close setAccounts

//
void Store::executeActions() {

}//close executeCommands


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
    //TODO: check hashmap for existing account
    //if(customers[0] == hash in accounts)
    //return false
    //account already exists

    //Account newAcct;

    return true;
}//close openAccount

//
Account* Store::findAccount(int id) const{
    return nullptr;
}//close findAccount

//
DVD* Store::findDrama(Drama& dvd) const{
    return nullptr;
}//close findDrama

//
DVD* Store::findComedy(Comedy& dvd) const{
    return nullptr;
}//close findComedy

// find a classic dvd and verify that it exists
DVD* Store::findClassic(Classic& dvd) const{
    return nullptr;
}//close findClassic


// return a borrowed item
bool Store::returnItem(Command action){
    return false;
}//close returnItem

// borrow an item
bool Store::borrowItem(Command action){
    return false;
}//close borrowItem

// print out account history given the id number
void Store::accountHistory(int id) const{

}//close accountHistory

// return number of accounts
int Store::numAccounts() const{
    return 0;
}//close numCustomers



//Operator overloads
// prints out the inventory object using <<
ostream& operator<< (ostream& stream, Store& store){
    return stream;
}//close operator<<

#endif //STORE_CPP