#ifndef STORE_CPP
#define STORE_CPP

#include "store.h"
#include <fstream>

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
Store::~Store() {

}//close destructor



//Setters
//
void Store::setStock(){

}//close setStock

//
void Store::setAccounts() {

}//close setAccounts

//
void Store::executeCommands() {

}//close executeCommands


//Functions
//read all files in the files vector
void Store::readFiles(){
    int index = 0;

    //iterate through file names
    //TODO: check if names should be in order; assumes files are in order
    while(index != filesNames.size()){
        //items file
        if(index == 0){
            ifstream itemFile(filesNames[index]);

            //insert items
            while(!itemFile.eof()){
                string line;

                while(getline(itemFile, line)){
                    stock.push_back(Command(line));
                }//close insert items
            }//close last line check

            index++;
            continue;
        }//close items file check

        //accounts file
        if(index == 1){
            ifstream accountFile(filesNames[index]);

            //insert accounts
            while(!accountFile.eof()){
                string line;

                while(getline(accountFile,line)){
                    customers.push_back(Command(line));
                }//close insert accounts
            }//close last line check

            index++;
            continue;
        }//close accounts file check

        //commands file
        if(index == 2){
            ifstream commandFile(filesNames[index]);

            //insert commands
            while(!commandFile.eof()){
                string line;

                while(getline(commandFile,line)){
                    commands.push_back(Command(line));
                }//close insert commands
            }//close last line check

            index++;
            continue;
        }//close commands file check
    }//close num files check
}//close files

// open an account
bool Store::openAccount(Command action){
    return false;
}//close openAccount

//
Customer* Store::findAccount(int id) const{
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

// find a classic dvd and verify that it exsits
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

// return number of customer accounts
int Store::numCustomers() const{
    return 0;
}//close numCustomers



//Operator overloads
// prints out the inventory object using <<
ostream& operator<< (ostream& stream, Store& store){
    return stream;
}//close operator<<

#endif //STORE_CPP