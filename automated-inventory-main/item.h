#ifndef ITEM_H
#define ITEM_H

#include "command.h"
#include <iostream>

using namespace std;


//make the cpp for this

class Item 
{
    public: 

        Item();
        ~Item();


        void setItemType(char item);

        char getItemType(); 

        // return the title of the Item
	    string getTitle() const;

        // set the title of the Item
        void setTitle(string newTitle);

        int getStock() const;
        // set the stock
        void setStock(int amount);
        // up the stock by one
        void upStock();
        // down the stock by one
        void downStock();

	int getPopularity();
	
        void increasePopularity();

        // addition overloads
        Item operator+ (const Item& rhs) const;
        Item& operator+= (const Item& rhs); 

    private: 
        int stock = 0;
        string title = "";
        char itemType;
        int popularity = 0; 
};

#endif
