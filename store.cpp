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
    ////Commands tempCommand 
    while(!stock.empty()){
        //Retrieve first item
        Commands tempCommand = stock.at(0);

        if(tempCommand.getVector(0) == "F"){
            Comedy *newComedy = new Comedy(tempCommand);
            //Comedy *newComedyPtr = &newComedy;

            if(findComedy(*newComedy) == nullptr){
                inventory.getComedyTree() -> insert(newComedy);
                increaseTotal();
            }else{
                if(*newComedy == *findComedy(*newComedy)){
                    *findComedy(*newComedy) += *newComedy;
                }
            }

            newComedy = nullptr;
        }else if(tempCommand.getVector(0) == "D"){
            Drama *newDrama = new Drama(tempCommand);

            //Drama *newDramaPtr = &newDrama;

            if(findDrama(*newDrama) == nullptr){
                inventory.getDramaTree() -> insert(newDrama);
                increaseTotal();
            }else{
                if(*newDrama == *findDrama(*newDrama)){
                    *findDrama(*newDrama) += *newDrama;
                }
            }

            newDrama = nullptr;
        }else if(tempCommand.getVector(0) == "C"){
            //Classic newClassic = Classic(tempCommand);

            Classic *newClassic = new Classic(tempCommand);//&newClassic;

            Classic *classicFromTree = findClassic(*newClassic);

            if(findClassic(*newClassic) == nullptr){ //things are being entered twice
                inventory.getClassicTree() -> insert(newClassic);
                increaseTotal();
            }else{
                if(*newClassic == *findClassic(*newClassic)){
                    *findClassic(*newClassic) += *newClassic;
                }
            }

            newClassic = nullptr;
        } 

        stock.erase(stock.begin());
    }
}//close setStock

//
void Store::setAccounts() {
    while(!customers.empty()){
        Commands tempCommand = customers.at(0);

        if(tempCommand.getVector(0) == "K"){
            if(openAccount(tempCommand)){
                customers.erase(customers.begin());
            }
        }
    }
}//close setAccounts

//
void Store::executeActions() {
    while(!actions.empty()){
        Commands tempCommand = actions.at(0);

        if(tempCommand.getVector(0) == "B"){
            //borrowItem(tempCommand);
            borrowItem();
        }else if(tempCommand.getVector(0) == "R"){
            returnItem(tempCommand);
        }else if(tempCommand.getVector(0) == "I"){
            cout << inventory;
        }else if(tempCommand.getVector(0) == "H"){
            //accountHistory(stoi(tempCommand.spaceParser(tempCommand.getVector(1)).at(0)));
            //"Error: printing history, invalid ID.";
            vector<string> ID = tempCommand.spaceParser(1); 
            int clearID = stoi(ID[0]);
            accountHistory(clearID);
        }

        actions.erase(actions.begin());
    }
}//close executeCommands

//increase the amount of total stock in the store
void Store::increaseTotal(){
    this -> totalStock++;
}//close increaseTotal



//Getters
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
                Commands tempCom(line);
                if (tempCom.isValid()) {
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
                }
            }//close insert items
        }//close last line check
    }//close num files check
}//close files

// open an account
bool Store::openAccount(Commands action){
    Customer* newCustomer = new Customer(action);

    //if account already exists
    if(accounts.isAccount(newCustomer))
        return false;

    //insert account into hashtable, providing ID as key
    accounts.insert(newCustomer);

    return true;
}//close openAccount

//
Customer* Store::findAccount(int id){
    //calls hashAccount's search function
    return accounts.search(id);
}//close findAccount

//
Drama* Store::findDrama(Drama& dramaDvd){
    //checks that the first index is D
    //parse through binary tree for dvd
    //search via director then title
    //return inventory.getDramaTree() -> search(&dramaDvd) -> item;

    if (inventory.getDramaTree() -> minorSearch(&dramaDvd) == nullptr)
    {
        return nullptr;
    } else 
    {
        return inventory.getDramaTree() -> minorSearch(&dramaDvd) -> item;
    }
}//close findDrama

//
Comedy* Store::findComedy(Comedy& comedyDvd){
    //parse through binary tree for dvd
    //search via title then year released
    //return 
    if(inventory.getComedyTree() -> minorSearch(&comedyDvd) == nullptr)//-> item)
    {
        return nullptr;
    } else 
    {
        return inventory.getComedyTree() -> minorSearch(&comedyDvd) -> item;
    }
}//close findComedy

// find a classic dvd and verify that it exists
Classic* Store::findClassic(Classic& classic){ //search can't be searching for addres
    //parse through binary tree for dvd
    //search via release date then major actor

    //return 
    if(((inventory.getClassicTree()) -> minorSearch(&classic)) == nullptr)
    {
        return nullptr; 
    } else 
    {
        //return 
        return inventory.getClassicTree() -> minorSearch(&classic) -> item;
    }
    // -> item;
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
bool Store::returnItem(Commands &action){
    vector<string> fields = action.spaceParser(action.getVector(1));

    //checks if account exists
    if(!accounts.isAccount(stoi(fields[0]))){
        cout << "Account " << fields[0] << " does not exist" << endl;
        return false;
    }

    Customer *tempCustomer = accounts.search(stoi(fields[0]));
    bool borrowed = false;

    //checks if command requests DVD
    if(fields[1] != "D"){
        cout << "Item is unavailable" << endl;

        tempCustomer = nullptr;
        delete tempCustomer;

        return false;
    }

    //checks request for comedy
    if(fields[2] == "F"){
        string title;

        for (int i = 3; i < fields.size() - 1; i++) {
            title += fields[i] + " ";
        }

        title += fields[fields.size() - 1];

        vector<string> yearVector = (action.spaceParser(action.getVector(2)));
        int year = stoi(yearVector[0]);

        Comedy tempComedy(title, year);

        //checks if the Item exists
        if(findComedy(tempComedy) == nullptr){
            cout << "Comedy item is unavailable" << endl;

            tempCustomer = nullptr;
            delete tempCustomer;

            return false;
        }

        //checks if Customer has this Item borrowed
        for(int i = 0; i < tempCustomer -> getItemsOut().size(); i++){
            if(action.getVector(1) == tempCustomer -> getItemsOut(i)){
                borrowed = true;
                break;
            }
        }

        //if item is not borrowed, do not return
        if(!borrowed){
            cout << "This item is not checked out to account " << fields[0] << endl;

            tempCustomer = nullptr;
            delete tempCustomer;

            return false;
        }

        Comedy *requestedItem = findComedy(tempComedy);

        //checks if there is a waitlist for Item
        if(waitlist.isInWaitlist(&action)){
            tempCustomer -> returnItem(action);
            Customer *waitCustomer = accounts.search(waitlist.remove(&action));
            waitCustomer -> borrow(action);

            tempCustomer = nullptr;
            delete tempCustomer;
            requestedItem = nullptr;
            delete requestedItem;

            return true;
        //no waitlist for Item
        }else{
            tempCustomer -> returnItem(action);
            requestedItem -> upStock();

            tempCustomer = nullptr;
            delete tempCustomer;
            requestedItem = nullptr;
            delete requestedItem;

            return true;
        }
        //checks request for drama
    }else if(fields[2] == "D"){
        string director = fields[3] + " " + fields[4];

        //vector<string> yearVector = (action.spaceParser(action.getVector(2)));
        //int year = stoi(yearVector[0]);

        string title = action.getVector(2);

        Drama tempDrama(director, title);

        //checks if the Item exists
        if(findDrama(tempDrama) == nullptr){
            cout << "Drama item is unavailable" << endl;

            tempCustomer = nullptr;
            delete tempCustomer;

            return false;
        }

        //checks if Customer has this Item borrowed
        for(int i = 0; i < tempCustomer -> getItemsOut().size(); i++){
            if(action.getVector(1) == tempCustomer -> getItemsOut(i)){
                borrowed = true;
                break;
            }
        }

        //if item is not borrowed, do not return
        if(!borrowed){
            cout << "This item is not checked out to account " << fields[0] << endl;

            tempCustomer = nullptr;
            delete tempCustomer;

            return false;
        }

        Drama *requestedItem = findDrama(tempDrama);

        //checks if there is a waitlist for Item
        if(waitlist.isInWaitlist(&action)){
            tempCustomer -> returnItem(action);
            Customer *waitCustomer = accounts.search(waitlist.remove(&action));
            waitCustomer -> borrow(action);

            tempCustomer = nullptr;
            delete tempCustomer;
            requestedItem = nullptr;
            delete requestedItem;

            return true;
            //no waitlist for Item
        }else{
            tempCustomer -> returnItem(action);
            requestedItem -> upStock();

            tempCustomer = nullptr;
            delete tempCustomer;
            requestedItem = nullptr;
            delete requestedItem;

            return true;
        }
        //checks request for classic
    }else if(fields[2] == "C"){
        int month = stoi(fields[3]);
        int year = stoi(fields[4]);

        Classic tempClassic(month, year, fields[5], fields[6]);

        //checks if the Item exists
        if(findClassic(tempClassic) == nullptr){
            cout << "Classic item is unavailable" << endl;

            tempCustomer = nullptr;
            delete tempCustomer;

            return false;
        }

        //checks if Customer has this Item borrowed
        for(int i = 0; i < tempCustomer -> getItemsOut().size(); i++){
            if(action.getVector(1) == tempCustomer -> getItemsOut(i)){
                borrowed = true;
                break;
            }
        }

        //if item is not borrowed, do not return
        if(!borrowed){
            cout << "This item is not checked out to account " << fields[0] << endl;

            tempCustomer = nullptr;
            delete tempCustomer;

            return false;
        }

        Classic *requestedItem = findClassic(tempClassic);

        //checks if there is a waitlist for Item
        if(waitlist.isInWaitlist(&action)){
            tempCustomer -> returnItem(action);
            Customer *waitCustomer = accounts.search(waitlist.remove(&action));
            waitCustomer -> borrow(action);

            tempCustomer = nullptr;
            delete tempCustomer;
            requestedItem = nullptr;
            delete requestedItem;

            return true;
            //no waitlist for Item
        }else{
            tempCustomer -> returnItem(action);
            requestedItem -> upStock();

            tempCustomer = nullptr;
            delete tempCustomer;
            requestedItem = nullptr;
            delete requestedItem;

            return true;
        }
    }else{
        cout << "Item requested is not recognized" << endl;

        tempCustomer = nullptr;
        delete tempCustomer;

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
//bool Store::borrowItem(Commands &action){
bool Store::borrowItem(){
    Commands action = actions.at(0);

    vector<string> fields = action.spaceParser(action.getVector(1));

    //checks if account exists
    if(!accounts.isAccount(stoi(fields[0]))){
        cout << "Account " << fields[0] << " does not exist" << endl;
        return false;
    }

    Customer *tempCustomer = accounts.search(stoi(fields[0]));

    //checks if command requests DVD
    if(fields[1] != "D"){
        cout << "Item is not recognized" << endl;

        tempCustomer = nullptr;
        delete tempCustomer;

        return false;
    }

    //checks request for comedy
    if(fields[2] == "F"){
        //Comedy tempComedy(action); //This doesn't work, at all  
        //how to get data for comedy:
        //starting at the 3 index of feilds combine everthing together, 
        //action[3] is the date (it was seperated by a comma)

        //I don't think we need to check if it's in the bstree, we can just check if
        //it's in history. 

        string title;
        for (int i = 3; i < fields.size() - 1; i++) {
            title += fields[i] + " ";
        }

        title += fields[fields.size() - 1];

        vector<string> yearVector = (action.spaceParser(action.getVector(2)));
        int year = stoi(yearVector[0]);

        Comedy tempComedy(title, year);

        //checks if the Item exists
        //if(findComedy(tempComedy) == nullptr){
        if(inventory.getComedyTree() -> minorSearch(&tempComedy) == nullptr)//-> item) 
        //if (findComedy(tempComedy)) {
        {
            cout << "Comedy item is unavailable" << endl;

            tempCustomer = nullptr;
            delete tempCustomer;

            return false;
        }
        

        //checks if Customer has already borrowed this Item
        for(int i = 0; i < tempCustomer -> getItemsOut().size(); i++){
            //replace vector(1) for all the data smushed together except a
            if(action.getVector(1) == tempCustomer -> getItemsOut(i)){
                cout << "Account" << fields[0] << "has already checked this comedy item out" << endl;

                tempCustomer = nullptr;
                delete tempCustomer;

                return false;
            }
        }

        Comedy *requestedComedy;

        //retrieve popular item
        if(popularComedy.isPopular(&tempComedy)){
            requestedComedy = popularComedy.search(&tempComedy);
        }else{
            requestedComedy = findComedy(tempComedy);
        }

        //checks if the Item is available
        if(requestedComedy -> getStock() > 0){
            tempCustomer -> borrow(action);
            requestedComedy -> downStock();
            requestedComedy -> increasePopularity();

            //set comedy item in popularity list
            //not full
            if(!popularComedy.isFull()){
                //item is already in list
                if(*requestedComedy != *popularComedy.search(requestedComedy)){
                    popularComedy.insert(requestedComedy);
                }
            //full
            }else{
                if(requestedComedy -> getPopularity() > popularComedy.getLowestPopular() -> getPopularity()){
                    popularComedy.swap(requestedComedy, popularComedy.getLowestPopular());
                }
            }

            tempCustomer = nullptr;
            delete tempCustomer;
            requestedComedy = nullptr;
            delete requestedComedy;

            return true;
        //item unavailable
        }else{
            waitlist.insert(&action);

            tempCustomer = nullptr;
            delete tempCustomer;
            requestedComedy = nullptr;
            delete requestedComedy;

            return false;
        }
    //checks request for drama
    }else if(fields[2] == "D"){
        string director = fields[3] + " " + fields[4];

        //vector<string> yearVector = (action.spaceParser(action.getVector(2)));
        //int year = stoi(yearVector[0]);

        string title = action.getVector(2);

        Drama tempDrama(director, title);

        //checks if the Item exists
        //if(findComedy(tempComedy) == nullptr){
        if(inventory.getDramaTree() -> minorSearch(&tempDrama) == nullptr)//-> item) 
        //if (findComedy(tempComedy)) {
        {
            cout << "Drama item is unavailable" << endl;

            tempCustomer = nullptr;
            delete tempCustomer;

            return false;
        }


        /*
        Drama tempDrama(action);

        //checks if the Item exists
        if(findDrama(tempDrama) == nullptr){
            cout << "Drama item is unavailable";
            return false;
        }*/

        //checks if Customer has already borrowed this Item
        for(int i = 0; i < tempCustomer -> getItemsOut().size(); i++){
            if(action.getVector(1) == tempCustomer -> getItemsOut(i)){
                cout << "Account " << fields[0] << " has already checked this drama item out" << endl;

                tempCustomer = nullptr;
                delete tempCustomer;

                return false;
            }
        }

        Drama *requestedDrama;

        //retrieve popular item
        if(popularDrama.isPopular(&tempDrama)){
            requestedDrama = popularDrama.search(&tempDrama);
        }else{
            requestedDrama = findDrama(tempDrama);
        }

        //checks if the Item is available
        if(requestedDrama -> getStock() > 0){
            tempCustomer -> borrow(action);
            requestedDrama -> downStock();
            requestedDrama -> increasePopularity();

            //set num of requests for popularity list
            //not full
            if(!popularDrama.isFull()){
                //item is already in list
                if(*requestedDrama != *popularDrama.search(requestedDrama)){
                    popularDrama.insert(requestedDrama);
                }
                //full
            }else{
                if(requestedDrama -> getPopularity() > popularDrama.getLowestPopular() -> getPopularity()){
                    popularDrama.swap(requestedDrama, popularDrama.getLowestPopular());
                }
            }

            tempCustomer = nullptr;
            delete tempCustomer;
            requestedDrama = nullptr;
            delete requestedDrama;

            return true;
        //item unavailable
        }else{
            waitlist.insert(&action);

            tempCustomer = nullptr;
            delete tempCustomer;
            requestedDrama = nullptr;
            delete requestedDrama;

            return false;
        }
    //checks request for classic
    }else if(fields[2] == "C"){
        //string majorActor = fields[3] + " " + fields[4];
        //vector<string> yearVector = (action.spaceParser(action.getVector(2)));
        //int year = stoi(yearVector[0]);

        int month = stoi(fields[3]);
        int year = stoi(fields[4]);

        //Drama tempDrama(director, title);
        Classic tempClassic(month, year, fields[5], fields[6]);

        //checks if the Item exists
        //if(findComedy(tempComedy) == nullptr){
        if(inventory.getClassicTree() -> minorSearch(&tempClassic) == nullptr)//-> item) 
        //if (findComedy(tempComedy)) {
        {
            cout << "Classic item is unavailable" << endl;

            tempCustomer = nullptr;
            delete tempCustomer;

            return false;
        }

        //Classic tempClassic(action);

        //Duplicate checker
        //checks if the Item exists
        /*if(findClassic(tempClassic) == nullptr){
            cout << "Classic item is unavailable";

            tempCustomer = nullptr;
            delete tempCustomer;

            return false;
        }*/

        //checks if Customer has already borrowed this Item
        for(int i = 0; i < tempCustomer -> getItemsOut().size(); i++){
            if(action.getVector(1) == tempCustomer -> getItemsOut(i)){
                cout << "Account " << fields[0] << " has already checked this classic item out" << endl;

                tempCustomer = nullptr;
                delete tempCustomer;

                return false;
            }
        }

        Classic *requestedClassic;

        //MAKE ANOTHER minorSearch for popularHash

        //retrieve popular item
        if(popularClassic.isPopular(&tempClassic)){
            requestedClassic = popularClassic.search(&tempClassic);
        }else{
            requestedClassic = findClassic(tempClassic);
        }

        //checks if the Item is available
        if(requestedClassic -> getStock() > 0){
            tempCustomer -> borrow(action);
            requestedClassic -> downStock();
            requestedClassic -> increasePopularity();

            //set num of requests for popularity list
            //not full
            if(!popularClassic.isFull()){
                //item is already in list
                if(*requestedClassic != *popularClassic.search(requestedClassic)){
                    popularClassic.insert(requestedClassic);
                }
                //full
            }else{
                if(requestedClassic -> getPopularity() > popularClassic.getLowestPopular() -> getPopularity()){
                    popularClassic.swap(requestedClassic, popularClassic.getLowestPopular());
                }
            }

            tempCustomer = nullptr;
            delete tempCustomer;
            requestedClassic = nullptr;
            delete requestedClassic;

            return true;
            //item unavailable
        }else{
            waitlist.insert(&action);

            tempCustomer = nullptr;
            delete tempCustomer;
            requestedClassic = nullptr;
            delete requestedClassic;

            return false;
        }
    }else{
        cout << "Item requested is not recognized" << endl;

        tempCustomer = nullptr;
        delete tempCustomer;

        return false;
    }
}//close borrowItem

// print out account history given the id number
void Store::accountHistory(int id){
    //use id to find account in hash table
    //retrieve account
    //use account showHistory
    if (accounts.search(id) != nullptr) {
        accounts.search(id) -> showHistory();
    } else 
    {
        cout << "Error: AccountHistory, ID " << id << " doesn't exist." << endl;
    }
}//close accountHistory



//Operator overloads
// prints out the inventory object using <<
/*ostream& operator<< (ostream& stream, Store& store){
    return stream;
}//close operator<<*/

#endif //STORE_CPP