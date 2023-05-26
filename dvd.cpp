/*
    dvd.cpp

*/
#include "dvd.h"
#include "command.h"


	Dvd::Dvd()
    {

    }

	// passes in a command object that contains all the needed data to create a DVD object
	Dvd::Dvd(Command command) 
    {
        // does nothing, not relevent for an abstract class
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
	int Dvd::operator+ (const int& rhs) const 
    {
        //int temp = rhs;
        return rhs + getStock();
        //stock++;
        //this.stock += rhs;
    }

	int Dvd::operator+= (const int& rhs) 
    {
        setStock(getStock() + rhs);
    }

	//stream overloads -- should this just be in the genre class or 
	// should we just create another for the classics where you alos put in a genre parameter
	// output the title 
	ostream& operator<< (ostream& stream, Dvd& dvd) 
    {
        // not relevent for an abstract class.
    }

	/*
    string title = "";
	string director = "";
	int stock = 0;
	int year = 0;
	char genre = 'D';
    */
	
