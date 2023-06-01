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
    setStock();
    setAccounts();
    executeActions();
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

            if(newItem.getTitle() == inventory.comedyTree.search(newItem).getTitle()){
                newItem.setStock(inventory.comedyTree.search(newItem).getStock() + temp.getVector(1));
            }else{
                newItem.setTitle(temp.getVector(3));
                newItem.setStock(stoi(temp.getVector(1)));
                inventory.getInventory()[0].insert(); //TODO: insert in right index
                increaseTotal();
            }
        }else if(temp.getVector(0) == "D"){
            Item newItem;

            if(newItem.getTitle() == inventory.dramaTree.search(newItem).getTitle()){
                newItem.setStock(inventory.dramaTree.search(newItem).getStock() + temp.getVector(1));
            }else{
                newItem.setTitle(temp.getVector(3));
                newItem.setStock(stoi(temp.getVector(1)));
                inventory.getInventory()[1].insert(); //TODO: insert in right index
                increaseTotal();
            }
        }else if(temp.getVector(0) == "C"){
            Item newItem;

            if(newItem.getTitle() == inventory.classicTree.search(newItem).getTitle()){
                newItem.setStock(inventory.classicTree.search(newItem).getStock() + temp.getVector(1));
            }else{
                newItem.setTitle(temp.getVector(3));
                newItem.setStock(stoi(temp.getVector(1)));
                inventory.getInventory()[2].insert(); //TODO: insert in the right index
                increaseTotal();
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

            if(!accounts.isAccount(&newCustomer)){
                newCustomer.setID(stoi(temp.spaceParser(1)[0])); //TODO: check
                newCustomer.setLast(temp.spaceParser(1)[1]); //TODO: check
                newCustomer.setFirst(temp.spaceParser(1)[2]); //TODO: check

                accounts.insert(&newCustomer);
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

//increase the amount of total stock in the store
void Store::increaseTotal(){
    this -> totalStock++;
}//close increaseTotal



//Getters
//
vector<char> Store::getCommandTypes(){
    return this -> commandTypes;
}//close getCommand

// return number of accounts
int Store::numAccounts() const{
    return accounts.getSize(); //return hash account's size
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
    if(newAcct == *accounts.search(&newAcct))
        return false;

    //insert account into hashtable, providing ID as key
    accounts.insert(&newAcct);

    return true;
}//close openAccount

//
Customer* Store::findAccount(int id){
    //calls hashAccount's search function
    return accounts.search(id);
}//close findAccount

//
Drama* Store::findDrama(Drama& dramaDvd) const{
    //checks that the first index is D
    //parse through binary tree for dvd
    //search via director then title
    return inventory.getInventory()[1].search(dramaDvd) -> movie;
}//close findDrama

//
Comedy* Store::findComedy(Comedy& dvd) const{
    //parse through binary tree for dvd
    //search via title then year released
    return inventory.getInventory()[0].search(dvd) -> movie;
}//close findComedy

// find a classic dvd and verify that it exists
Classic* Store::findClassic(Classic& dvd) const{
    //parse through binary tree for dvd
    //search via release date then major actor

    return inventory.getInventory()[2].search(dvd) -> movie;
}//close findClassic


// return a borrowed item
//Pseudocode
//checks if Customer account exists
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
bool Store::returnItem(Command action){
    vector<string> fields = action.spaceParser(action.getVector(1));

    //checks if account exists
    if(!accounts.isAccount(stoi(fields[1]))){
        cout << "Account does not exist";
        return false;
    }

    Customer tempCustomer = *accounts.search(stoi(fields[1]));
    bool borrowed = false;

    //checks if command requests DVD
    if(fields[2] != "D"){
        cout << "Item is unavailable";
        return false;
    }

    //checks request for comedy
    if(fields[3] == "F"){
        Comedy tempComedy(action);

        //checks if the Item exists
        //TODO: check if this works
        if(findComedy(tempComedy) == nullptr){
            cout << "Comedy item is unavailable";
            return false;
        }

        //checks if Customer has this Item borrowed
        for(int i = 0; i < tempCustomer.getItemsOut().size(); i++){
            if(tempComedy == tempCustomer.getItemsOut()[i]){
                borrowed = true;
                break;
            }
        }

        //if item is not borrowed, do not return
        if(!borrowed){
            cout << "This item is not checked out to this account";
            return false;
        }

        Comedy requestedItem = findComedy(tempComedy);

        //checks if there is a waitlist for Item
        //TODO: bool function to check if item is on the waitlist or not
        if(waitlist.isInWaitlist(&action)){
            tempCustomer.returnItem(requestedItem);
            Customer waitCustomer = *waitlist.remove(&action);
            waitCustomer.borrow(requestedItem);

            return true;
        //no waitlist for Item
        }else{
            tempCustomer.returnItem(requestedItem);
            requestedItem.upStock();

            return true;
        }
        //checks request for drama
    }else if(fields[3] == "D"){
        Drama tempDrama(action);

        //checks if the Item exists
        if(findDrama(tempDrama) == nullptr){
            cout << "Drama item is unavailable";
            return false;
        }

        //checks if Customer has this Item borrowed
        for(int i = 0; i < tempCustomer.getItemsOut().size(); i++){
            if(tempDrama == tempCustomer.getItemsOut()[i]){
                borrowed = true;
                break;
            }
        }

        //if item is not borrowed, do not return
        if(!borrowed){
            cout << "This item is not checked out to this account";
            return false;
        }

        Drama requestedItem = findDrama(tempDrama);

        //checks if there is a waitlist for Item
        //TODO: bool function to check if item is on the waitlist or not
        if(waitlist.isInWaitlist(&action)){
            tempCustomer.returnItem(requestedItem);
            Customer waitCustomer = *waitlist.remove(&action);
            waitCustomer.borrow(requestedItem);

            return true;
            //no waitlist for Item
        }else{
            tempCustomer.returnItem(requestedItem);
            requestedItem.upStock();

            return true;
        }
        //checks request for classic
    }else if(fields[3] == "C"){
        Classic tempClassic(action);

        //checks if the Item exists
        if(findClassic(tempClassic) == nullptr){
            cout << "Classic item is unavailable";
            return false;
        }

        //checks if Customer has this Item borrowed
        for(int i = 0; i < tempCustomer.getItemsOut().size(); i++){
            if(tempClassic == tempCustomer.getItemsOut()[i]){
                borrowed = true;
                break;
            }
        }

        //if item is not borrowed, do not return
        if(!borrowed){
            cout << "This item is not checked out to this account";
            return false;
        }

        Classic requestedItem = *findClassic(tempClassic);

        //checks if there is a waitlist for Item
        //TODO: bool function to check if item is on the waitlist or not
        if(waitlist.isInWaitlist(&action)){
            tempCustomer.returnItem(requestedItem);
            Customer waitCustomer = *waitlist.remove(&action);
            waitCustomer.borrow(requestedItem);

            return true;
            //no waitlist for Item
        }else{
            tempCustomer.returnItem(requestedItem);
            requestedItem.upStock();

            return true;
        }
    }else{
        cout << "Item requested is not recognized";
        return false;
    }
}//close returnItem

// borrow an item
// inventory comedy, drama, classic
// Pseudocode
//checks if Customer account exists
//checks if the Item exists
//checks if Customer has already borrowed this Item
//checks if the Item is available
    //if available, checks item out to Customer
    //add to history that customer borrowed item in Customer
    //decrement stock
    //increment request counter
    //if not available, place customer in waitlist
    //consider handing item to customer in waitlist
    //instead of returning to inventory
bool Store::borrowItem(Command action){
    vector<string> fields = action.spaceParser(action.getVector(1));

    //checks if account exists
    if(!accounts.isAccount(stoi(fields[1]))){
        cout << "Account does not exist";
        return false;
    }

    Customer tempCustomer = *accounts.search(stoi(fields[1]));

    //checks if command requests DVD
    if(fields[2] != "D"){
        cout << "Item is not recognized";
        return false;
    }

    //checks request for comedy
    if(fields[3] == "F"){
        Comedy tempComedy(action);

        //checks if the Item exists
        if(findComedy(tempComedy) == nullptr){
            cout << "Comedy item is unavailable";
            return false;
        }

        //checks if Customer has already borrowed this Item
        for(int i = 0; i < tempCustomer.getItemsOut().size(); i++){
            if(tempComedy == tempCustomer.getItemsOut()[i]){
                cout << "Account has already checked this comedy item out";
                return false;
            }
        }

        Comedy requestedItem = findComedy(tempComedy);

        //checks if the Item is available
        if(requestedItem.getStock() > 0){
            tempCustomer.borrow(requestedItem);
            requestedItem.downStock();
            requestedItem.increasePopularity();

            //set num of requests for popularity list
            //TODO: need function to search if item is already in popular list
            //not full
            if(!popularItems.isFull()){
                //item is already in list
                if(requestedItem != popularItems.search(requestedItem)){
                    popularItems.insert(requestedItem);
                }
            //full
            }else{
                for(int i = 0; i < popularItems.getSize(); i++){
                    //TODO: getter for num requests for each item
                    //TODO: getter for item in the list
                    if(requestedItem.getPopularity() > popularItems.getLowestPopular() -> getPopularity()){
                        popularItems.swap(requestedItem, popularItems.getLowestPopular());
                    }
                }
            }

            return true;
        //item unavailable
        }else{
            waitlist.insert(&action);

            return false;
        }
    //checks request for drama
    }else if(fields[3] == "D"){
        Drama tempDrama(action);

        //checks if the Item exists
        if(findDrama(tempDrama) == nullptr){
            cout << "Drama item is unavailable";
            return false;
        }

        //checks if Customer has already borrowed this Item
        for(int i = 0; i < tempCustomer.getItemsOut().size(); i++){
            if(tempDrama == tempCustomer.getItemsOut()[i]){
                cout << "Account has already checked this drama item out";
                return false;
            }
        }

        Drama requestedItem = findDrama(tempDrama);

        //checks if the Item is available
        if(requestedItem.getStock() > 0){
            tempCustomer.borrow(requestedItem);
            requestedItem.downStock();
            requestedItem.increasePopularity();

            //set num of requests for popularity list
            //TODO: need function to search if item is already in popular list
            //not full
            if(!popularItems.isFull()){
                //item is already in list
                if(requestedItem != popularItems.search(requestedItem)){
                    popularItems.insert(requestedItem);
                }
                //full
            }else{
                for(int i = 0; i < popularItems.getSize(); i++){
                    //TODO: getter for num requests for each item
                    //TODO: getter for item in the list
                    if(requestedItem.getPopularity() > popularItems.getLowestPopular() -> getPopularity()){
                        popularItems.swap(requestedItem, popularItems.getLowestPopular());
                    }
                }
            }

            return true;
        //item unavailable
        }else{
            waitlist.insert(&action);

            return false;
        }
    //checks request for classic
    }else if(fields[3] == "C"){
        Classic tempClassic(action);

        //checks if the Item exists
        if(findClassic(tempClassic) == nullptr){
            cout << "Classic item is unavailable";
            return false;
        }

        //checks if Customer has already borrowed this Item
        for(int i = 0; i < tempCustomer.getItemsOut().size(); i++){
            if(tempClassic == tempCustomer.getItemsOut()[i]){
                cout << "Account has already checked this classic item out";
                return false;
            }
        }

        Classic requestedItem = *findClassic(tempClassic);

        //checks if the Item is available
        if(requestedItem.getStock() > 0){
            tempCustomer.borrow(requestedItem, action);
            requestedItem.downStock();
            requestedItem.increasePopularity();

            //set num of requests for popularity list
            //TODO: need function to search if item is already in popular list
            //not full
            if(!popularItems.isFull()){
                //item is already in list
                if(requestedItem != popularItems.search(requestedItem)){
                    popularItems.insert(requestedItem);
                }
                //full
            }else{
                for(int i = 0; i < popularItems.getSize(); i++){
                    //TODO: getter for popularity for each item
                    //TODO: getter for item in the list
                    if(requestedItem.getPopularity() > popularItems.getLowestPopular() -> getPopularity()){
                        popularItems.swap(requestedItem, popularItems.getLowestPopular());
                    }
                }
            }

            return true;
            //item unavailable
        }else{
            waitlist.insert(&action);

            return false;
        }
    }else{
        cout << "Item requested is not recognized";
        return false;
    }
}//close borrowItem

// print out account history given the id number
void Store::accountHistory(int id){
    //use id to find account in hash table
    //retrieve account
    //use account showHistory
    Customer tempCustomer = *accounts.search(id);

    tempCustomer.showHistory();
}//close accountHistory



//Operator overloads
// prints out the inventory object using <<
/*ostream& operator<< (ostream& stream, Store& store){
    return stream;
}//close operator<<*/

#endif //STORE_CPP