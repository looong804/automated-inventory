#ifndef DVD_H
#define DVD_H

#include "command.h"

class DVD : public Item
{
public:
	// not needed
	DVD();
	// not needed
	~DVD();

	// return the director of the movie
	string getDirector() const;
	// return the title of the DVD
	string getTitle() const;
	// return the genre
	char getGenre() const;
	// return the year
	int getYear() const;
	// return the stock of the DVD
	int getStock() const;
	// set the stock
	void SetStock(int amount);
	// up the stock by one
	void upStock();
	// down the stock by one
	void downStock();

	// addition overloads
	int operator+ (const int& rhs) const;
	int operator+= (const int& rhs);

	//stream overloads -- should this just be in the genre class or 
	// should we just create another for the classics where you alos put in a genre parameter
	// output the title 
	friend ostream& operator<< (ostream& stream, DVD& dvd);

private:
	string title = "";
	string director = "";
	int stock = 0;
	int year = 0;
	char genre = 'D';
};
#endif //DVD_H
