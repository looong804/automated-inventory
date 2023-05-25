#ifndef DRAMA_H
#define DRAMA_H

#include "dvd.h"
#include "bstree.h"

class Drama : public DVD
{
public:
	Drama();
	// passes in a command that contains all the needed data to create a Drama object
	Drama(Command command);
	~Drama();

	//comparison overloads - sorted by director then title
	bool operator==(const Drama& rhs) const;
	bool operator!=(const Drama& rhs) const;
	bool operator>=(const Drama& rhs) const;
	bool operator<=(const Drama& rhs) const;
	bool operator>(const Drama& rhs) const;
	bool operator<(const Drama& rhs) const;

	//stream overloads
	// display all the info 
	friend ostream& operator<< (ostream& stream, const Drama& drama);

private:

};
#endif