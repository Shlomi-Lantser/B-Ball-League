#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "League.hpp"

League::League()
{
    this->teams = vector<Team *>();
    this->teams_database = {
        "Lakers",
        "Miami Heat",
        "Cleveland Cavaliers",
        "Golden State Warriors",
        "Los Angeles Lakers",
        "Chicago Bulls",
        "Boston Celtics",
        "Toronto Raptors",
        "Houston Rockets",
        "Indiana Pacers",
        "Detroit Pistons",
        "Philadelphia 76ers",
        "Dallas Mavericks",
        "Memphis Grizzlies",
        "Milwaukee Bucks",
        "New York Knicks",
        "Washington Wizards",
        "Atlanta Hawks",
        "Charlotte Hornets",
        "Brooklyn Nets",
        "Orlando Magic",
        "Oklahoma City Thunder",
        "Portland Trail Blazers",
        "Sacramento Kings",
        "Utah Jazz",
        "New Orleans Pelicans",
        "Minnesota Timberwolves",
        "Denver Nuggets",
        "Phoenix Suns",
        "San Antonio Spurs",
        "Golden State Warriors",
        "Los Angeles Clippers",
        "Los Angeles Lakers",
        "Phoenix Suns",
        "Portland Trail Blazers",
        "Sacramento Kings",
        "Utah Jazz",
        "Washington Wizards",
        "Atlanta Hawks",
        "Brooklyn Nets"

    };
}

void League::addTeam(Team *team)
{
    if (this->isTeamInLeague(team->getName()))
    {
        runtime_error("Team already in league");
    }
    else if (this->teams.size() >= 20)
    {
        runtime_error("League is full");
    }
    else
    {
        this->teams.push_back(team);
    }
}

void League::randomizeTeams()
{
    int i = 0;
    while (i != 20 - this->teams.size())
    {
        int random_index = rand() % this->teams_database.size();
        string random_team = this->teams_database[random_index];

        if (!this->isTeamInLeague(random_team))
        {
            Team *team = new Team(random_team);
            this->teams.push_back(team);
            this->teams_database.erase(this->teams_database.begin() + random_index);
        }
        else
        {
            this->teams_database.erase(this->teams_database.begin() + random_index);
        }
    }
}

// Team("Lakers)")


vector<Team *> League::getTeams()
{
    return this->teams;
}

bool League::isTeamInLeague(const string &team_name)
{
    for (Team *team : this->teams)
    {
        if (team->getName() == team_name)
        {
            return true;
        }
    }
    return false;
}
