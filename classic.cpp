
#ifndef CLASSIC_CPP
#define CLASSIC_CPP

#include "classic.h"
#include <vector>
#include <sstream>


/*----------------------------------------------------------
Classic(): default constructor, sets the genre to 'C'
but nothing else is filled out.

params: none
*/

	Classic::Classic() 
    {
        setGenre('C');
    }

	// passes in a command that contains all the needed data to create a Classic object

/*----------------------------------------------------------
Classic(Command command): given the command object it pulls
out all the needed data and inserts into the Classic object.

params: Command command
*/
	Classic::Classic(Commands command) 
    {
        setTitle(command.getVector(3));
        setDirector(command.getVector(2)); 
        setStock(stoi(command.getVector(1)));
        //setYear(command.getVector(4));
        setGenre('C');

        vector<string> actorAndDate = command.spaceParser(command.getVector(4));
        //vector<string> actorAndDate = command.spaceSplitter(4);
        string temp = actorAndDate[0] + " " + actorAndDate[1]; 
        addMajorActor(temp); 
        int month = (stoi(actorAndDate[2]));
        setMonth(month);
        int year = stoi(actorAndDate[3]);
        setYear(year);
    }

Classic::Classic(int month, int year, string firstName, string lastName) 
{
    setMonth(month);
    setYear(year);
    string actor = firstName + " " + lastName;
    addMajorActor(actor);
}


Classic::~Classic() 
{

}
    /*void spaceSplitter(vector<string> &splitString, string stringToSplit) 
    {
        istringstream string {stringToSplit};
        string temp;
        int i = 0;
        while (getline( string, temp, ' ')) {
            splitString[i] << temp << std::endl;
            i++;
        }
    }*/



/*----------------------------------------------------------
setMonth(const int newMonth):

sets the month to the given integer as long as that number
is betweeen 1 and 12, else the month will be defaulted to 
12 and an error message will be printed. 

params: const int newMonth;

returns: none

*/
    void Classic::setMonth(const int newMonth) 
    {
	if (newMonth > 12 || newMonth < 1) 
	{
		month = 12;
		cout << "Month given was not between 1 and 12, the month has been defaulted to 12" << endl;
	} else {
        	month = newMonth;
	}
    }

/*----------------------------------------------------------
int getMonth(): 
returns the month of the classic object

params: none

returns: int month
*/
	int Classic::getMonth() const 
    {
        return month;
    }

    /*
        getMajorActor(int const index) const


        if the index is valid, the actor will be returned (first and last name in one string),
        otherwise "" will be returned
    
    */
    bool Classic::getMajorActor(int const index, string &actor) const
    {
        if (index < nextActorIndex) 
        {
            actor = majorActors[index]; //I don't think this makes a copy?
            return true;
        } else 
        {
            return false;
        }
    }


/*----------------------------------------------------------
int getNumberOfActors() const:
returns the number of actors that the classic objects has
(this is also the index of the next open spot in the vector
that holds the major actors)

params: none

returns: int numOfActors
*/
    int Classic::getNumberOfActors() const
    {
        return nextActorIndex;
    }

/*----------------------------------------------------------
addMajorActor(string actor): 

adds a major actor to the classic object. String must be
first name and last naem with a space between
"firstName LastName"

params: string actor

returns: none
*/
    void Classic::addMajorActor(string actor) 
    {   
        //majorActors[nextActorIndex] = actor;
        majorActors.push_back(actor);
        nextActorIndex++;
    }

    bool Classic::hasMajorActor(string actor) const
    {
        int numOfActors = getNumberOfActors();
        for (int i = 0; i < numOfActors; i++) 
        {
            if (majorActors[i] == actor) 
            {
                return true;
            } 
        }

        return false;
    }

	//comparison overloads - sorted by release date then major actor
	// a classic movie is equal if the director, title and date are the same

/*----------------------------------------------------------
operator==(const Classic& rhs) const:

checks if two classic obejcts are equal. This is a comparison
of the director, the title, and the month and year date.
Does not consider the major actors, as there might
be two lines for the same classic movie but featuring a
different major actor.

returns true if equal, returns false if not equal

params: const Classic& rhs

returns: bool
*/
	bool Classic::operator==(const Classic& rhs) const 
    {
        if(getDirector() == rhs.getDirector() && getTitle() == rhs.getTitle() && getYear() == rhs.getYear() && getMonth() == rhs.getMonth()) 
        {
            return true; 
        } else 
        {
            return false;
        }
    }


/*----------------------------------------------------------
operator!=(const Classic& rhs) const:

checks if two classic obejcts are not equal. This is a comparison
of the director, the title, and the month and year date.
Does not consider the major actors, as there might
be two lines for the same classic movie but featuring a
different major actor.

returns true if not equal, returns false if equal

params: const Classic& rhs

returns: bool
*/
	bool Classic::operator!=(const Classic& rhs) const 
    {
        return !(*this == rhs);
    }

    //sorted by release date and major actor, the first major actor added

/*----------------------------------------------------------
bool operator>(const Classic& rhs): 

compares two classic objects, returns true if the classic 
object on the left (the calling object) is greater than
the classic object on the right.

Comparison is based off the the release date, and the first major actor
listed. 

params: const Classic& rhs

returns: bool
*/
	bool Classic::operator>(const Classic& rhs) const 
    {
        string actor1;
        string actor2;
        getMajorActor(0, actor1);
        rhs.getMajorActor(0, actor2);


        if (getYear() > rhs.getYear()) 
        {
            return true;
        } else if (getYear() == rhs.getYear() && getMonth() > rhs.getYear()) 
        {
            return true;
        } else if (getYear() == rhs.getYear() && getMonth() == rhs.getYear() && actor1 > actor2) 
        {
            return true;
        } else  
        {
            return false;
        }
    }

/*----------------------------------------------------------
bool operator>(const Classic& rhs): 

compares two classic objects, returns true if the classic 
object on the left (the calling object) is less than
the classic object on the right.

Comparison is based off the the release date, and the first major actor
listed. 

params: const Classic& rhs

returns: bool
*/
	bool Classic::operator<(const Classic& rhs) const 
    {
        string actor1;
        string actor2;
        getMajorActor(0, actor1);
        rhs.getMajorActor(0, actor2);


        if (getYear() > rhs.getYear()) 
        {
            return false;
        } else if (getYear() == rhs.getYear() && getMonth() > rhs.getYear()) 
        {
            return false;
        } else if (getYear() == rhs.getYear() && getMonth() == rhs.getYear() && actor1 > actor2) 
        {
            return false;
        } else  
        {
            return false;
        }
    }

/*----------------------------------------------------------

*/
    Classic Classic::operator+ (const Classic& rhs) const 
    {
        Classic classic;
        classic = *this;

        classic.setStock(classic.getStock() + rhs.getStock());
        
        string actor;
        int numOfActors = rhs.getNumberOfActors();
        for (int i = 0; i < numOfActors; i++) 
        {
            rhs.getMajorActor(i, actor);

            if (classic.hasMajorActor(actor) == false) {
                classic.addMajorActor(actor);
            }
        }

        return classic;

    }

/*----------------------------------------------------------
Classic& operator+= (const Classic& rhs): 


*/
    Classic& Classic::operator+= (const Classic& rhs) 
    {
        setStock(getStock() + rhs.getStock());
        
        string actor;
        int numOfActors = rhs.getNumberOfActors();
        for (int i = 0; i < numOfActors; i++) 
        {
            rhs.getMajorActor(i, actor);

            if (hasMajorActor(actor) == false) {
                addMajorActor(actor);
            }
        }

        /*Classic classic = *this + rhs; 
        *this = classic; */
        return *this;//*/
    }

    Classic& Classic::operator=(const Classic& rhs) 
    {
        //string title = "title";
        setTitle(rhs.getTitle());
        setDirector(rhs.getDirector());
        setStock(rhs.getStock());
        setYear(rhs.getYear());
        setGenre(rhs.getGenre());

        string actor;
        int numOfActors = rhs.getNumberOfActors();
        for (int i = 0; i < numOfActors; i++) 
        {
            rhs.getMajorActor(i, actor);
            if (hasMajorActor(actor) == false) {
                addMajorActor(actor);
            }
        }

        return *this;
    }





	//stream overloads
	// display all the info 
	ostream& operator<< (ostream& stream, const Classic& classic) 
    {
        string actor;

        stream << classic.getGenre() << ", " << classic.getStock() << ", " << classic.getDirector() << ", " << classic.getTitle() << ", ";

        for (int i = 0; i < classic.getNumberOfActors(); i++) //prints all the actors
        {
            classic.getMajorActor(i, actor);
            stream << actor << ", ";
        }
        
        stream << classic.getMonth() << " " << classic.getYear();

        return stream;
    }

	// major actor's first name
	//string first = "";
	// major actor's last name
	//string last = "";
	// month of release for classics
	//int month = 0;

	//vector<string> majorActors;

	//BSTree<Classic> bstree(); 

#endif //CLASSIC_H



/*
std::istringstream iss { "Cpp|is|fun" };

  std::string s;
  while ( std::getline( iss, s, '|' ) )
    std::cout << s << std::endl;
*/
