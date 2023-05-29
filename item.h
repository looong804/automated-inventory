#ifndef ITEM_H
#define ITEM_H

#include "command.h"

class Item 
{
    public: 
        Item();
	// not needed
        ~Item();

        // return the title of the Item
	string getTitle() const;
        // set the title of the Item
        string setTitle(string newTitle);
	// get the stock
        int getStock() const;
        // set the stock
        void SetStock(int amount);
        // up the stock by one
        void upStock();
        // down the stock by one
        void downStock();
	
	//increases the popularity by 1
	void increasePopularity();

        // addition overloads
        int operator+ (const int& rhs) const;
        int operator+= (const int& rhs); 

    private: 
        int stock = 0;
        string title = "";
	int popularity = 0; 
};
#endif
