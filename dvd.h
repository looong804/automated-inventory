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
	Dvd operator+ (const Dvd& rhs) const;
	Dvd operator+= (const Dvd& rhs);

private:
	string title = "";
	string director = "";
	int stock = 0;
	int year = 0;
	char genre = 'D';
};
#endif //DVD_H
