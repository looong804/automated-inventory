#ifndef CLASSIC_H
#define CLASSIC_H

#include "dvd.h"

class Classic : public Dvd
{
public:
	Classic();
	// passes in a command that contains all the needed data to create a Classic object
	Classic(Command command);
	~Classic();

	// return the month
	int getMonth() const;

	void setMonth(const int newMonth);

	bool getMajorActor(int const index, string &actor) const; //grabs a major actor from a certain index in the actor vector

	bool hasMajorActor(string actor) const;

	void addMajorActor(string actor); 

	int getNumberOfActors() const; //returns the number of major actors in this object (the nextActorIndex works for this)

	//comparison overloads - sorted by release date then major actor
	// a classic movie is equal if the director, title and data are the same
	bool operator==(const Classic& rhs) const;
	bool operator!=(const Classic& rhs) const;
	bool operator>(const Classic& rhs) const;
	bool operator<(const Classic& rhs) const;

	//stream overloads
	// display all the info 
	friend ostream& operator<< (ostream& stream, const Classic& classic);

	Classic operator+ (const Classic& rhs) const;
    Classic& operator+= (const Classic& rhs); 
	Classic& operator=(const Classic& rhs); 

private:
	// major actor's first name
	//string first = "";
	// major actor's last name
	//string last = "";
	// month of release for classics
	int month = 0;
	int nextActorIndex = 0; //the index to use when inserting a new actor

	vector<string> majorActors;

	//BSTree<Classic> bstree(); 
};
#endif // CLASSIC_H
