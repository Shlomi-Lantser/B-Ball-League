#include "Schedule.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

Schedule::Schedule(League *league)
{
    if (league == NULL)
    {
        throw runtime_error("League cannot be NULL");
    }
    else if (league->getTeams().size() < 2)
    {
        throw runtime_error("League must have at least 2 teams");
    }
    else if (league->getTeams().size() > 20)
    {
        throw runtime_error("League cannot have more than 20 teams");
    }

    this->league = league;
    this->cycles = 0;
}

void Schedule::startLeague()
{
    for (int i = 0; i < this->league->getTeams().size(); i++)
    {
        for (int j = i; j < this->league->getTeams().size(); j++)
        {
            if (i != j)
            {
                Game *game = new Game(this->league->getTeams()[i], this->league->getTeams()[j]);
                Game *game2 = new Game(this->league->getTeams()[j], this->league->getTeams()[i]);
            }
        }
    }
}

bool sortTeams(Team *a, Team *b)
{
    float a_points = float(a->totalWins) / float(a->totalLosses);
    float b_points = float(b->totalWins) / float(b->totalLosses);
    if (a_points > b_points)
        return true;
    else
    {
        if(a_points == b_points){
        return (a->totalScore - a->againstScore) > (b->totalScore - b->againstScore);
        }
        return false;
    }
}

void Schedule::longestWinStreak()
{
    vector<Team *> teams = this->league->getTeams();
    sort(teams.begin(), teams.end(), [](Team *a, Team *b)
         { return a->longestWinStreak > b->longestWinStreak; });
    cout << "The longest win streak is " + teams[0]->getName() + " with " + to_string(teams[0]->longestWinStreak) + " wins in a row." << endl << endl;
}

void Schedule::longestLoseStreak()
{
    vector<Team *> teams = this->league->getTeams();
    sort(teams.begin(), teams.end(), [](Team *a, Team *b)
         { return a->longestLoseStreak > b->longestLoseStreak; });
    cout << "The longest lose streak is " + teams[0]->getName() + " with " + to_string(teams[0]->longestLoseStreak) + " losses in a row." << endl << endl;
}

vector<Team *> Schedule::pointsBiggerThanAgains()
{
    vector<Team *> teams = this->league->getTeams();
    vector<Team *> result;
    for (Team *team : teams)
    {
        if (team->totalScore > team->againstScore)
        {
            result.push_back(team);
        }
    }
    return result;
}

void Schedule::printSchedule()
{
    cout << "Loading schedule..." << endl;

    cout << "Choose number of the top teams you want to see: ";
    int n;
    cin >> n;

    if (n >= 20){
        runtime_error("There is only 20 teams on the league !");
    }

    cout << "Top teams: " << endl;

    vector<Team *> top_teams = this->league->getTeams();
    sort(top_teams.begin(), top_teams.end(), sortTeams);
    // print in table format with iomanip
    cout << setw(25) << "Team" << setw(10) << "Wins" << setw(10) << "Loses" << setw(10) << "Points" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(25) << top_teams[i]->getName() << setw(10) << top_teams[i]->totalWins << setw(10) << top_teams[i]->totalLosses << setw(10) << top_teams[i]->totalScore << endl;
    }
    cout << "___________________________________________________________________________________________________________"<< endl;
}


void Schedule::printLeague()
{
    cout << "League table :" << endl;
    vector<Team *> teams = this->league->getTeams();
    sort(teams.begin(), teams.end(), sortTeams);
    // print in table format with iomanip
    cout << setw(25) << "Team" << setw(10) << "Wins" << setw(10) << "Loses" << setw(10) << "Points" << endl;
    for (Team *team : teams)
    {
        cout << setw(25) << team->getName() << setw(10) << team->totalWins << setw(10) << team->totalLosses << setw(10) << team->totalScore << endl;
    }
    cout << "___________________________________________________________________________________________________________" << endl;
}

void Schedule::printPointsBiggerThanAgains()
{
    vector<Team *> teams = this->pointsBiggerThanAgains();
    sort(teams.begin(), teams.end(), sortTeams);
    cout << "The teams that have more points than they get , there is " << teams.size() << " teams on that category :"<< endl;
    // print in table format with iomanip
    cout << setw(25) << "Team" << setw(10) << "Wins" << setw(10) << "Loses" << setw(10) << "Points" << setw(15) << "Against score" << endl;
    for (Team *team : teams)
    {
        cout << setw(25) << team->getName() << setw(10) << team->totalWins << setw(10) << team->totalLosses << setw(10) << team->totalScore << setw(10) << team->againstScore << endl;
    }
    cout << "___________________________________________________________________________________________________________" << endl;
}

void Schedule::average(){
    vector<Team*> teams = this->league->getTeams();
    int average_against_score = 0;
    int average_wins = 0;
    int average_losses = 0;
    int average_points = 0;
    int average_win_streak = 0;
    int average_lose_streak = 0;
    for(Team* team : teams){
        average_against_score += team->againstScore;
        average_wins += team->totalWins;
        average_losses += team->totalLosses;
        average_points += team->totalScore;
        average_win_streak += team->longestWinStreak;
        average_lose_streak += team->longestLoseStreak;
    }
    average_against_score /= teams.size();
    average_wins /= teams.size();
    average_losses /= teams.size();
    average_points /= teams.size();
    average_win_streak /= teams.size();
    average_lose_streak /= teams.size();

    //print in table format with iomanip
    cout << setw(10) << "Average score" << setw(20) << "Average wins" << setw(20) << "Average losses" << setw(20) << "Average points" << setw(20) << "Average win streak" << setw(20) << "Average lose streak" << endl;
    cout << setw(10) << average_points << setw(20) << average_wins << setw(20) << average_losses << setw(20) << average_points << setw(20) << average_win_streak << setw(20) << average_lose_streak << endl;

}

vector<Team*> Schedule::againstBiggerThanPoints(){
    vector<Team*> teams = this->league->getTeams();
    vector<Team*> result;
    for(Team* team : teams){
        if(team->againstScore > team->totalScore){
            result.push_back(team);
        }
    }
    return result;
}

void Schedule::printAgainstBiggerThanPoints(){
    vector<Team*> teams = this->againstBiggerThanPoints();
    sort(teams.begin(), teams.end(), sortTeams);
    cout << "The teams that have more against score than they get , there is " << teams.size() << " teams on that category :"<< endl;
    // print in table format with iomanip
    cout << setw(25) << "Team" << setw(10) << "Wins" << setw(10) << "Loses" << setw(10) << "Points" << setw(15) << "Against score" << endl;
    for (Team *team : teams)
    {
        cout << setw(25) << team->getName() << setw(10) << team->totalWins << setw(10) << team->totalLosses << setw(10) << team->totalScore << setw(10) << team->againstScore << endl;
    }
    cout << "___________________________________________________________________________________________________________" << endl;
}