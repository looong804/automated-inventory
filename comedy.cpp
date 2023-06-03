#include "dvd.h"
#include "bstree.h"
#include "comedy.h"


/*
char type = 'D'; // Dvd is default if not changed by contructor
	// dvd title
	string title = "";
	// if the command failed
	bool failure_ = false;
	// customer account id
	int id = 0;
	// how many of the movie are in stock
	int stock = 0;
	// the year of the movie release
	int year = 0;
	// the month of the movie release
	int month = 0;

	//if a classic genre dvd and the command is to make a Classic object/effect a classic object, store major actor here
	string majorActorFirstName = "";

	string majorActorLastName = "";


*/


	Comedy::Comedy() 
    {
        setGenre('F');
    }

	// passes in a command that contains all the needed data to create a Comedy object
	Comedy::Comedy(Commands command) //build the item with the data from the command object. 
    {
        setTitle(command.getVector(3));
        setDirector(command.getVector(2)); 
        setStock(stoi(command.getVector(1)));
        setYear(stoi(command.getVector(4)));
        setGenre('F');

    }
	
    Comedy::Comedy(string title, int year) 
    {
        setTitle(title);
        setYear(year);
    }

    Comedy::~Comedy() 
    {
        
    }

	//comparison overloads - sorted by title then year
	bool Comedy::operator==(const Comedy& rhs) const {
        if(&rhs != nullptr)
        {
            if(getTitle() == rhs.getTitle() && getDirector() == rhs.getDirector()
                && getStock() == rhs.getStock() && getYear() == rhs.getYear()
                    && getGenre() == rhs.getGenre())
            {
                return true;
            }
        }

        return false;
    }

    bool Comedy::isEqual(const Comedy& rhs) const 
    {
        if(&rhs != nullptr)
        {
            if(getTitle() == rhs.getTitle() && getYear() == rhs.getYear())
            {
                return true;
            }
        }

        return false;
    }

	bool Comedy::operator!=(const Comedy& rhs) const 
    {
        return !(*this == rhs);
    }

	bool Comedy::operator>(const Comedy& rhs) const
    {
        if (getTitle() > rhs.getTitle()) 
        {
            return true;
        } else if (getTitle() == rhs.getTitle() && getYear() > rhs.getYear()) 
        {
            return true;
        } else 
        {
            return false;
        }
    }

	bool Comedy::operator<(const Comedy& rhs) const
    {
        if (getTitle() > rhs.getTitle()) 
        {
            return false;
        } else if (getTitle() == rhs.getTitle() && getYear() > rhs.getYear()) 
        {
            return false;
        } else 
        {
            return true;
        }
    }

    Comedy Comedy::operator+ (const Comedy& rhs) const
    {
        Comedy comedy; 
        comedy = *this;
        comedy.setStock(getStock() + rhs.getStock());
        return comedy;
    
    }

    Comedy& Comedy::operator+= (const Comedy& rhs) 
    {
        setStock(getStock() + rhs.getStock());
        return *this;
    }

    Comedy& Comedy::operator=(const Comedy& rhs) 
    {
        //string title = "title";
        setTitle(rhs.getTitle());
        setDirector(rhs.getDirector());
        setStock(rhs.getStock());
        setYear(rhs.getYear());
        setGenre(rhs.getGenre());

        return *this;
    }

	//stream overloads
	// display all the info 
	ostream& operator<< (ostream& stream, const Comedy& comedy) 
    {
        stream << comedy.getGenre() << ", " << comedy.getStock() << ", " <<comedy.getDirector() << ", " << comedy.getTitle() << ", " << comedy.getYear();

        return stream;
    }
