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
    void swapTeams(size_t, size_t); // For ranking purpose. Swap teams in parameter in a group ranking
    void rankingTeams(); // Re-Rank the whole group.

    std::ostream& displayGroup(std::ostream&) const; // Display group ranking
private:
    std::vector<Team> table; // THIS IS the group of teams
    bool away_matches; // To know if there home and away matches or not
    std::vector<std::vector<Match>> calendar; // To store all past games and results. Will be changed to store all future games.
                                    // Will be like a calendar
};




#endif // COMPETITION_H_INCLUDED
