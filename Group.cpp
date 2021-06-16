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
        away_matches = false;
    /*}*/
}
void Group::fillingGroup() {
    size_t nbTeam = 0;
    do{
        cout << "Please enter the number of teams competing (an even number) : ";
        cin >> nbTeam;
    } while(nbTeam%2 != 0);
    cout << "Please enter the competing teams : ";
    string teamName;
    for(size_t i(0); i < nbTeam; ++i){
        cin >> teamName;
        table.push_back(Team(teamName));
    }
}

void Group::settingSchedule() {
    int nbLeg = table.size()-1; //The number of legs in any competition is the number of Teams -1
    /*if(away_matches) { // The number of legs in a group/league is multiplicated by 2 in case of home/Away matches (LOGIC)
        nbLeg *= 2;
    }*/
    for(int i(0); i < nbLeg; ++i){
        calendar.push_back(vector<Match>()); // Creation of the group/league legs. Each leg is a vector of Matchs
    }
    vector<Team> copieTable (table);
    for(int i(0); i < nbLeg; ++i){ // To go through all legs
        for (int j(0); j < (copieTable.size()/2)-1; ++j){ //To add matchs for every legs
            calendar[i].push_back(Match(copieTable[j], copieTable[copieTable.size()-1-j])); //Add match between the first and the last in the table then the second and the penultimate, etc.....
        }
        shiftingTable(copieTable);// A Function to shift positions in the copy table to prepare for the next leg programmation
    }
}
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
        out << i+1 << ". " << table[i].getName() << "\t"
            << table[i].getPoints() << "pts\t";
        if(table[i].getGoalDifference() < 0){
            out << table[i].getGoalDifference() << "\n";
        } else {
            out << "+" << table[i].getGoalDifference() << "\n";
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
