/*
    dvd.cpp

*/
#include "dvd.h"

	Dvd::Dvd()
    {

    }

	Dvd::~Dvd() 
    {

    }

	// return the director of the movie
	string Dvd::getDirector() const 
    {
        return director;
    }

	// return the title of the DVD
	string Dvd::getTitle() const 
    {
        return title;
    }

	// return the genre
	char Dvd::getGenre() const 
    {
        return genre;
    }

	// return the year
	int Dvd::getYear() const 
    {   
        return year;
    }

	// return the stock of the DVD
	int Dvd::getStock() const 
    {
        return getStock();
    }

	// set the stock
	void Dvd::SetStock(int amount) 
    {
        Item::setStock(amount);
    }

	// up the stock by one
	void Dvd::upStock() 
    {
        Item::setStock(getStock() + 1);
    }

	// down the stock by one
	void Dvd::downStock() 
    {
        if (getStock() > 0) 
        {
            Item::setStock(getStock() - 1);
        } else 
        {
            cout << "Error: movie not in stock - stock is 0" << endl;
        }
    }

	void increasePopularity()
	{
		popularity++;
	}

	// addition overloads (combines the stock for most DVDs, except for classic also )
	Dvd Dvd::operator+ (const Dvd& rhs) const 
    {
        //int temp = rhs;
        return rhs + getStock();
        //stock++;
        //this.stock += rhs;
    }

	Dvd Dvd::operator+= (const Dvd& rhs) 
    {
        setStock(getStock() + rhs);
    }
