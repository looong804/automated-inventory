/*
    dvd.cpp

*/
#include "dvd.h"
#include "command.h"


	Dvd::Dvd()
    {
        setItemType('D');
    }

	// addition overloads (combines the stock for most DVDs, except for classic also )
	Dvd Dvd::operator+ (const Dvd& rhs) const 
    {
        Dvd dvd;
        //int temp = rhs;
        dvd.setStock(rhs.getStock() + getStock());
        return dvd;
        //stock++;
        //this.stock += rhs;
    }

	Dvd& Dvd::operator+= (const Dvd& rhs) 
    {
        setStock(getStock() + rhs.getStock());
        return *this;
    }


    string Dvd::getDirector() const 
    {
        return director;
    }

	void Dvd::setDirector(string newDirector) 
    {   
        director = newDirector;
    }
	// return the genre
	char Dvd::getGenre() const 
    {
        return genre;
    }

	void Dvd::setGenre(const char newGenre) 
    {
        genre = newGenre;
    }

	// return the year
	int Dvd::getYear() const 
    {
        return year;
    }

	void Dvd::setYear(int newYear) 
    {
        year = newYear;    
    }



	//stream overloads -- should this just be in the genre class or 
	// should we just create another for the classics where you alos put in a genre parameter
	// output the title 
	ostream& operator<< (ostream& stream, Dvd& dvd) 
    {
        stream << dvd.getTitle() << " " << dvd.getYear() << endl;

        return stream;
    }

	/*
    string title = "";
	string director = "";
	int stock = 0;
	int year = 0;
	char genre = 'D';
    */
	
