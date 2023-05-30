#ifndef DVD_H
#define DVD_H

#include "command.h"
#include "item.h"

class Dvd : public Item
{
public:
	Dvd();
	// passes in a command object that contains all the needed data to create a DVD object
	Dvd(Command command);
	~Dvd();

	// /char getItemType() const; 
	
	// return the director of the movie
	string getDirector() const;

	void setDirector(string director);
	// return the genre
	char getGenre() const;

	void setGenre(const char genre); 

	// return the year
	int getYear() const;

	void setYear(int newYear);
	// return the stock of the DVD

        // addition overloads
    Dvd operator+ (const Dvd& rhs) const;
    Dvd& operator+= (const Dvd& rhs); 
	

	//stream overloads -- should this just be in the genre class or 
	// should we just create another for the classics where you alos put in a genre parameter
	// output the title 
	friend ostream& operator<< (ostream& stream, Dvd& dvd);

private:
	string director = "";
	int year = 0;
	char genre = 'D';
	
};
#endif
