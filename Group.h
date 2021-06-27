#ifndef COMPETITION_H_INCLUDED
#define COMPETITION_H_INCLUDED

#include<vector>
#include<iostream>
#include"Team.h"
#include"Match.h"

class Group{
public:
    Group(); // Constructor

    void settingGroup(); // Asking the user if there are only one match or home/away games. WILL BE MOVED TO COMPETITION CLASS LATER
    void fillingGroup(); // Asking the user to fill the group with teams
    void settingSchedule(); // Filling the calendar with matches to be played
    void playingMatches();  // Playing group leg matches/WILL BE CHANGED WHEN FILLING CALENDAR IS FINISHED
    void rankingTeams(); // Re-Rank the whole group.

    std::ostream& displayGroup(std::ostream&) const; // Display group ranking
    void displaySchedule() const; //Display schedule
private:
    void shiftingTable(std::vector<Team>&); // To rearrange a table of teams in order to generate a calendar
    void swapTeams(size_t, size_t); // For ranking purpose. Swap teams in parameter in a group ranking
    void invertingAwayGames(); // inverting home and away teams


    std::vector<Team> table; // THIS IS the group of teams
    bool away_matches; // To know if there are home and away matches or not
    std::vector<std::vector<Match>> calendar; // store all future games like a calendar like a calendar

};


#endif // COMPETITION_H_INCLUDED
