#include"Group.h"

using namespace std;
//----------------------CLASS INTERFACE-------------------------------------
// CONSTRUCTOR
Group::Group()  {
    this->settingGroup();
    this->fillingGroup();
}
// INTERFACE
void Group::settingGroup(){
    /*char leg;
    do{
        cout << "Please enter if there will be home/away games (y/n) : ";
        cin >> leg;
    } while ((leg != 'y') and (leg != 'n'));
    if(leg == 'y'){
        away_matches = true;
    } else {*/
        away_matches = true;
    /*}*/
}
void Group::fillingGroup() {
    size_t nbTeam = 0;
    cout << "Please enter the number of teams per group : ";
    cin >> nbTeam;
    cout << "Please enter the competing teams : ";
    string teamName;
    for(size_t i(0); i < nbTeam; ++i){
        cin >> teamName;
        table.push_back(Team(teamName));
    }
    if(table.size()%2 != 0){ //Adding a dummy team for groups with an odd number of teams
        table.push_back(Team("dummy"));
    }

}

void Group::settingSchedule() {
    int nbLeg = table.size()-1; //The number of legs in any competition is the number of Teams -1
    /*if(away_matches) { // The number of legs in a group/league is multiplied by 2 in case of home/Away matches (LOGIC)
        nbLeg *= 2;
    }*/
    for(int i(0); i < nbLeg; ++i){
        calendar.push_back(vector<Match>()); // Creation of the group/league legs. Each leg is a vector of Matches
    }
    vector<Team> copieTable(table);
    size_t teamH; //to store the home team position in the original table
    size_t teamA; //to store the away team position in the original table

    //-----------------ADDING HOME GAMES---------------------------------
    for(int i(0); i < nbLeg; ++i){ // To go through all legs
        for (size_t j(0); j < (copieTable.size()/2); ++j){ //To add matches for every legs
            for(size_t k(0); k < table.size(); ++k){ //This loop is for collecting the team index from the original table and not from the shifting copieTable
                if(copieTable[j].getName() == table[k].getName()){
                    teamH = k;
                }
                if(copieTable[copieTable.size()-1-j].getName() == table[k].getName()){
                    teamA = k;
                }
            }
            if((table[teamH].getName() != "dummy") and (table[teamA].getName() != "dummy")){ //too avoid adding matches with a dummy team in group with an odd number of teams
                calendar[i].push_back(Match(table[teamH], table[teamA])); //Add match between the first and the last in the table then the second and the penultimate, etc.....
            }
        }
        shiftingTable(copieTable);// A Function to shift positions in the copy table to prepare for the next leg programming
    }

    //---------------ADDING AWAY GAMES---------------------------------
    if(away_matches) { // The number of legs in a group/league is multiplied by 2 in case of home/Away matches (LOGIC)
            for(int i(0); i < nbLeg; ++i){
            calendar.push_back(vector<Match>()); // Preparing the calendar for away games
        }

        for(size_t i(nbLeg); i < nbLeg*2; ++i){ // To go through all away legs
            for(size_t j(0); j < (copieTable.size()/2); ++j){ //To add matches for every legs
                for(size_t k(0); k < table.size(); ++k) {
                    if(copieTable[j].getName() == table[k].getName()){
                        teamA = k;
                    }
                    if(copieTable[copieTable.size()-1-j].getName() == table[k].getName()){
                        teamH = k;
                    }
                }
                if((table[teamH].getName() != "dummy") and (table[teamA].getName() != "dummy")){
                    calendar[i].push_back(Match(table[teamH], table[teamA]));
                }

            }
            shiftingTable(copieTable);
        }

    }
    //invertingAwayGames();//Inverting away games
}

/*void Group::invertingAwayGames(){
    size_t teamH;
    size_t teamA;
    for(size_t i = calendar.size()/2; i < calendar.size(); ++i){
        for(size_t j = 0; j < calendar[i].size(); ++j){
            for(size_t k = 0; k < table.size(); ++ k){ //This loop is for collecting the team index from the original table
                if(calendar[i][j].home_team.getName() == table[k].getName()){
                    teamA = k;
                }
                if(calendar[i][j].away_team.getName() == table[k].getName()){
                    teamH = k;
                }
            }
            calendar[i][j] = Match(table[teamH], table[teamA]); // Creating the new match with inverted teams
        }
    }
}*/

void Group::playingMatches() {
    for(size_t i(0); i < calendar.size(); ++i){
        // This block is for announcing each leg
        cout << i+1;
        if((i+1) == 1){ cout << "st leg : \n"; }
        else if((i+1) == 2){ cout << "nd leg : \n";}
        else if((i+1) == 3){ cout << "rd leg : \n";}
        else{cout << "th leg : \n";}
        //End of the announcing block
        for(size_t j(0); j < calendar[i].size(); ++j){
            calendar[i][j].playing();
        }
    }

}

void Group::rankingTeams() {
    for(size_t i(0); i < table.size()-1; ++i){
        for(size_t j(table.size()-1); j > i; --j){
            if(table[j] > (table[j-1])){
                this->swapTeams(j, j-1);
            }
        }
    }

}
// DISPLAY
ostream& Group::displayGroup(ostream& out) const{
    for(size_t i(0); i < table.size(); ++i){
        if(table[i].getName() != "dummy"){
            out << i+1 << ". " << table[i].getName() << "\t"
                << table[i].getPoints() << "pts\t";
            if(table[i].getGoalDifference() < 0){
                out << table[i].getGoalDifference() << "\n";
            } else {
                out << "+" << table[i].getGoalDifference() << "\n";
            }
        }
    }
    return out;
}
void Group::displaySchedule() const{
    for(size_t i(0); i < calendar.size(); ++i){
        cout << "leg " << i+1 << " : \n";
        for(size_t j(0); j < calendar[i].size(); ++j){
            cout << calendar[i][j].home_team.getName()
                << " - "
                << calendar[i][j].away_team.getName() << "\n";
        }
    }
}

// PRIVATE METHODS
void Group::shiftingTable(vector<Team>& t){
    t.push_back(t.back());
    for(size_t i(t.size()-2); i >= 2; --i){
        t[i] = t[i-1];
    }
    t[1] = t.back();
    t.pop_back();
}
void Group::swapTeams(size_t i, size_t j) {
    table.push_back(table[i]);
    table[i] = table[j];
    table[j] = table.back();
    table.pop_back();
}
