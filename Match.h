#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED

#include<array>
#include<iostream>
#include"Team.h"

class Match{
public:
    //CONSTRUCTOR
    Match(Team& a, Team& b);

    void playing(); // Reading and saving match results
    std::ostream& displayResult(std::ostream& out) const; //For overloading <<operator
    void          displayResult() const;                  //To display directly with the method
    //Match& operator=(std::Match const& m);

    Team& home_team; // PUT IN PUBLIC TO ALLOW DISPLAYING SCHEDULE IN Group.cpp. IT IS A BAD SOLUTION
    Team& away_team;

private:

    std::array<unsigned int, 2> result;
};



#endif // MATCH_H_INCLUDED
