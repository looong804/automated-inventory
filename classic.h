#ifndef CLASSIC_H
#define CLASSIC_H

#include "dvd.h"
#include <vector>

class Classic : public DVD
{
public:
	Classic();
	// passes in a command that contains all the needed data to create a Classic object
	Classic(Command command);
	~Classic();

	// return the month
	int getMonth() const;

	//comparison overloads - sorted by release date then major actor
	// a classic movie is equal if the director, title and data are the same
	bool operator==(const Classic& rhs) const;
	bool operator!=(const Classic& rhs) const;
	bool operator>=(const Classic& rhs) const;
	bool operator<=(const Classic& rhs) const;
	bool operator>(const Classic& rhs) const;
	bool operator<(const Classic& rhs) const;

	//stream overloads
	// display all the info 
	friend ostream& operator<< (ostream& stream, const Classic& classic);

private:
	// major actor's first name
	//string first = "";
	// major actor's last name
	//string last = "";
	// month of release for classics
	int month = 0;

	vector<string> majorActors;

	//BSTree<Classic> bstree(); 
};
#endif //CLASSIC_H