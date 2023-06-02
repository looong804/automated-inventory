#ifndef ITEM_CPP
#define ITEM_CPP

#include "item.h"

        Item::Item() 
        {
            setStock(0);
            setTitle("");
        }

        void Item::setItemType(char const item) 
        {
            itemType = item; 
        }

        char Item::getItemType() 
        {
            return itemType;
        }

        // return the title of the Item
	    string Item::getTitle() const 
        {
            return title;
        }

        // set the title of the Item
        void Item::setTitle(string const newTitle) 
        {
            title = newTitle; 
        }

        int Item::getStock() const 
        {   
            return stock;
        }
        // set the stock
        void Item::setStock(int const amount) 
        {
            stock = amount;
        }
        // up the stock by one
        void Item::upStock() 
        {   
            stock++;
        }
        // down the stock by one
        void Item::downStock() 
        {
             if (stock > 0) 
            {
                stock--;
            } else 
            {
                cout << "Error: movie not in stock - stock is 0" << endl;
            }
        }

        void Item::increasePopularity() 
        {
            popularity++;
        }

	int Item::getPopularity() 
        {
            return popularity;
        }


        // addition overloads
        Item Item::operator+ (const Item& rhs) const 
        {
            Item item;

            //int hi = item.getStock();

            item.setStock(rhs.getStock() + stock);
            return item;
            //return rhs.getStock() + stock;
        }

        Item& Item::operator+= (const Item& rhs) 
        {
            stock += rhs.getStock();
            return *this;
        }


#endif
