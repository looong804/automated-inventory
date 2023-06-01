
#ifndef CLASSIC_CPP
#define CLASSIC_CPP

#include "classic.h"
#include <vector>
#include <sstream>


	Classic::Classic() 
    {
        setGenre('C');
    }

	// passes in a command that contains all the needed data to create a Classic object
	Classic::Classic(Command command) 
    {
        setTitle(command.getVector(3));
        setDirector(command.getVector(2)); 
        setStock(stoi(command.getVector(1)));
        //setYear(command.getVector(4));
        setGenre('D');

        vector<string> actorAndDate = command.spaceParser(command.getVector(4));
        //vector<string> actorAndDate = command.spaceSplitter(4);
        string temp = actorAndDate[0] + " " + actorAndDate[1]; 
        addMajorActor(temp); 
        int month = (stoi(actorAndDate[3]));
        setMonth(month);
        int year = stoi(actorAndDate[4]);
        setYear(year);

        


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

    void Classic::setMonth(int const newMonth) 
    {
        month = newMonth;
    }


	// return the month
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

    int Classic::getNumberOfActors() const
    {
        return nextActorIndex;
    }

    void Classic::addMajorActor(string actor) 
    {   
        majorActors[nextActorIndex] = actor;
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

	bool Classic::operator!=(const Classic& rhs) const 
    {
        return !(*this == rhs);
    }

    //sorted by release date and major actor, the first major actor added
	bool Classic::operator>(const Classic& rhs) const 
    {
        string actor1;
        string actor2;
        getMajorActor(0, actor1);
        rhs.getMajorActor(0, actor2);


        if (getYear() > rhs.getYear()) 
        {
            return true;
        } else if (getMonth() > rhs.getYear()) 
        {
            return true;
        } else if (actor1 > actor2) 
        {
            return true;
        } else  
        {
            return false;
        }
    }

	bool Classic::operator<(const Classic& rhs) const 
    {
        if (*this != rhs && !(*this > rhs))  
        {
            return true;
        } else 
        {
            return false;
        }
    }

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

    Classic& Classic::operator+= (const Classic& rhs) 
    {
        Classic classic = *this + rhs; 
        *this = classic; 
        return *this;
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
            addMajorActor(actor);
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
