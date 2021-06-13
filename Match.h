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
    std::ostream& displayResult(std::ostream& out) const;

private:
    Team& home_team;
    Team& away_team;
    std::array<unsigned int, 2> result;
};



#endif // MATCH_H_INCLUDED
