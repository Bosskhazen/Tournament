#include <iostream>
#include"Team.h"
#include"Match.h"
#include"Group.h"

using namespace std;

//OPERATOR OVERLOAD
ostream& operator<<(ostream& out, Match const& m){
    return m.displayResult(out);
}
ostream& operator<<(ostream& out, Team const& t){
    return t.displayTeam(out);
}
ostream& operator<<(ostream& out, Group const& g){
    return g.displayGroup(out);
}


int main()
{
    Group champ;
    champ.settingSchedule();

    champ.displaySchedule();

    champ.playingMatches();
    champ.rankingTeams();
    cout << champ;


    return 0;
}
