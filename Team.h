#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include<string>
#include<iostream>


class Team{
public:
    //CONSTRUCTOR
    Team(std::string n);

    bool better(Team const&); // To compare two teams
    bool operator>(Team const&);    // To compare two teams using the > operator (it looks better)
    std::ostream& displayTeam(std::ostream&) const;

    //GETTERS
    std::string getName() const;
    int getPoints() const;
    int getGoalDifference() const;
    //SETTERS
    void setWin(unsigned int const& f, unsigned const& a);
    void setDraw(unsigned int const& f, unsigned const& a);
    void setLoss(unsigned int const& f, unsigned const& a);
private:
    std::string name;
    int points;
    unsigned int wins;
    unsigned int draws;
    unsigned int losses;
    unsigned int goals_for;
    unsigned int goals_against;
};

#endif // TEAM_H_INCLUDED
