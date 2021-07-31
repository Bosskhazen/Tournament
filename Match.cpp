#include"Match.h"

using namespace std;

//----------------------CLASS INTERFACE-------------------------------------
// CONSTRUCTOR
Match::Match(Team& a, Team& b) : home_team(a), away_team(b), result({0,0}) {}
// INTERFACE
void Match::playing() {
    // Reading match results
    cout << home_team.getName() << " - " << away_team.getName() << "\n"
        <<"Match result : ";
    for(size_t i(0); i < result.size(); ++i){
        cin >> result[i];
    }
    //Saving results
    if (result[0] == result[1]){ // In case of a draw
        home_team.setDraw(result[0], result[1]);
        away_team.setDraw(result[1], result[0]);
    } else { // In case of a victory/loss
        if (result[0] > result[1]){ //Victory of the home team
            home_team.setWin(result[0], result[1]);
            away_team.setLoss(result[1], result[0]);
        } else {                    //Victory of the away team
            home_team.setLoss(result[0], result[1]);
            away_team.setWin(result[1], result[0]);
        }
    }
}
// DISPLAY
ostream& Match::displayResult(ostream& out) const{
    out << home_team.getName() << " " << result[0]
        << " - " << result[1] << " " << away_team.getName()
        << "\n";
    return out;
}
void Match::displayResult() const{
    cout << home_team.getName() << " " << result[0]
    << " - " << result[1] << " " << away_team.getName()
    << "\n";

}
/*Match& Match::operator=(Match const& m){
    home_team = m.home_team;
    away_team = m.away_team;
    result[0] = m.result[0];
    result[1] = m.result[1];
}*/


