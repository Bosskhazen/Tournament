#include"Team.h"

using namespace std;

//----------------------CLASS INTERFACE-------------------------------------
// CONSTRUCTOR
Team::Team(string n) : name(n), points(0), wins(0), draws(0), losses(0), goals_for(0), goals_against(0) {}
// INTERFACE
bool Team::better(Team const& t){
    if(this->points > t.points) return true;
    else if (this->points < t.points) return false;

    if(this->getGoalDifference() > t.getGoalDifference()) return true;
    else if(this->getGoalDifference() < t.getGoalDifference()) return false;

    if(this->goals_for > t.goals_for) return true;
    else if(this->goals_for < t.goals_for) return false;

    return true;
}
bool Team::operator>(Team const& t){
    return this->better(t);
}
// DISPLAY
ostream& Team::displayTeam(ostream& out) const{
     out << name << " : " << points << " points, "
        << goals_for << " goals scored, "
        << goals_against << " goals conceded from "
        << wins << " wins, " << draws << " draws and "
        << losses << " losses\n";
return out;
}
// GETTER
string Team::getName() const {return name;}
int Team::getPoints() const {return points;}
int Team::getGoalDifference() const {return goals_for - goals_against;}
// SETTER
void Team::setWin(unsigned int const& f, unsigned const& a) {
    points += 3;
    wins ++;
    goals_for += f;
    goals_against += a;
}
void Team::setDraw(unsigned int const& f, unsigned const& a) {
    points += 1;
    draws ++;
    goals_for += f;
    goals_against += a;
}
void Team::setLoss(unsigned int const& f, unsigned const& a){
    losses ++;
    goals_for += f;
    goals_against += a;
}
