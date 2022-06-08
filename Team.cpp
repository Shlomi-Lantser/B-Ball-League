#include "Team.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>


using namespace std;

Team::Team(const string &name)
{
    if (name.length() == 0)
    {
        runtime_error("Team name cannot be empty");
        exit(1);
    }
    this->name = name;
    this->talent = rand();
    this->totalScore = 0;
    this->againstScore = 0;
    this->totalWins = 0;
    this->totalLosses = 0;
    this->winStreak = 0;
    this->loseStreak = 0;
    this->longestLoseStreak = 0;
    this->longestWinStreak = 0;

}


const string Team::getName()
{
    return this->name;
}

string Team::getFlag()
{
    return this->flag;
}

const double Team::getTalent()
{
    return this->talent;
}

