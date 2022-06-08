#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



class League{
    private:
        vector<Team*> teams;
        vector<string> teams_database;

    public:
        League();
        void randomizeTeams();
        void addTeam(Team* team);
        vector<Team*> getTeams();
        bool isTeamInLeague(const string &team_name);
};