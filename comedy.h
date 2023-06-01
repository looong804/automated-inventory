#ifndef COMEDY_H
#define COMEDY_H

#include "dvd.h"
#include "bstree.h"

class Comedy : public Dvd
{
public:
	Comedy();
	// passes in a command that contains all the needed data to create a Comedy object
	Comedy(Command command); //build the item with the data from the comand object. 
	~Comedy();
	
	//comparison overloads - sorted by title then year
	bool operator==(const Comedy& rhs) const;
	bool operator!=(const Comedy& rhs) const;
	bool operator>(const Comedy& rhs) const;
	bool operator<(const Comedy& rhs) const;


	Comedy operator+ (const Comedy& rhs) const;
	Comedy& operator+= (const Comedy& rhs);
	

	//stream overloads
	// display all the info 
	friend ostream& operator<< (ostream& stream, const Comedy& comedy);

private:
};
#endif // COMEDY_H
