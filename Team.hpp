#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#pragma once

using namespace std;

class Team
{
    private:
        string name;
        double talent;
        string flag;

    public:
        Team(const string &name);
        const string getName();
        const double getTalent();
        string getFlag();
        void setTalent(const double &talent);
        void setFlag(const string &flag);
        int totalScore;
        int againstScore;
        int totalWins;
        int totalLosses;
        int winStreak;
        int loseStreak;
        int longestWinStreak;
        int longestLoseStreak;
};