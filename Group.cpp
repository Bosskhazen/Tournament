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
    char leg;
    do{
        cout << "Please enter if there will be home/away games (y/n) : ";
        cin >> leg;
    } while ((leg != 'y') and (leg != 'n'));
    if(leg == 'y'){
        away_matches = true;
    } else {
        away_matches = false;
    }
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
        //table[i](teamName);
    }
}
void Group::settingSchedule() {
    int nbLeg = table.size()-1; //The number of legs in any competition is the number of Teams -1
    //if(away_matches) {nbLeg *= 2;} // The number of legs is multiplated by 2 in case of home/Away matches (LOGIC)
    for(int i(0); i < nbLeg; ++i){
        calendar.push_back(vector<Match>());
    }


}
void Group::playingMatches() {
    /*cout << "1st leg : \n";
    calendar.push_back(Match(table[0], table[1]));
    calendar.push_back(Match(table[2], table[3]));
    cout << "2nd leg : \n";
    calendar.push_back(Match(table[0], table[2]));
    calendar.push_back(Match(table[1], table[3]));
    cout << "3rd leg : \n";
    calendar.push_back(Match(table[0], table[3]));
    calendar.push_back(Match(table[1], table[2]));*/
}
void Group::swapTeams(size_t i, size_t j) {
    table.push_back(table[i]);
    table[i] = table[j];
    table[j] = table.back();
    table.pop_back();
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
