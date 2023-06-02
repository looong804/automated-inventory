#ifndef DRAMA_CPP
#define DRAMA_CPP

#include "drama.h"



	Drama::Drama() 
    {
        setGenre('D');
    }
	// passes in a command that contains all the needed data to create a Drama object
	Drama::Drama(Commands command) 
    {
        //setTitle("title");
        setTitle(command.getVector(3));
        setDirector(command.getVector(2)); 
        setStock(stoi(command.getVector(1)));
        setYear(stoi(command.getVector(4)));
        setGenre('D');
    }

	//comparison overloads - sorted by director then title
	bool Drama::operator==(const Drama& rhs) const 
    {
        if (getTitle() == rhs.getTitle(), getDirector() == rhs.getDirector(), getStock() == rhs.getStock(), getYear() == rhs.getYear(), getGenre() == rhs.getGenre()) 
        {
            return true;
        } else 
        {
            return false;
        }
    }

	bool Drama::operator!=(const Drama& rhs) const 
    {
        return !(*this == rhs);
    }

	bool Drama::operator>(const Drama& rhs) const
    {
        //director then Title
        if (getDirector() > rhs.getDirector()) 
        {
            return true;
        } else 
        {
            return false;
        }
    }

	bool Drama::operator<(const Drama& rhs) const 
    {
        if (!(*this > rhs) && *this != rhs) 
        {
            return true;
        } else 
        {
            return false;
        }
    }

    Drama Drama::operator+ (const Drama& rhs) const
    {
        Drama drama; 
        drama = *this;
        drama.setStock(getStock() + rhs.getStock());
        return drama;
    
    }

    Drama& Drama::operator+= (const Drama& rhs) 
    {
        setStock(getStock() + rhs.getStock());
        return *this;
    }

    Drama& Drama::operator=(const Drama& rhs) 
    {
        //string title = "title";
        setTitle(rhs.getTitle());
        setDirector(rhs.getDirector());
        setStock(rhs.getStock());
        setYear(rhs.getYear());
        setGenre(rhs.getGenre());

        return *this;
        /*
        setTitle(command.getVector(3));
        setDirector(command.getVector(2)); 
        setStock(command.getVector(1));
        setYear(command.getVector(4));
        setGenre('D');
        
        */
    }

	//stream overloads
	// display all the info 
	ostream& operator<< (ostream& stream, const Drama& drama) 
    {
        stream << drama.getGenre() << ", " << drama.getStock() << ", " << drama.getDirector() << ", " << drama.getTitle() << ", " << drama.getYear();
    
        return stream;
    }


#endif
