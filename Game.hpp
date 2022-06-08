#include "Team.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



class Game
{
private:
    Team* winner;
    Team* loser;
    Team *home;
    Team *away;
    int homeScore;
    int awayScore;

public:
    Game(Team *home, Team *away);
    const Team *getWinner();
    const Team *getLoser();
    const Team *getHome();
    const Team *getAway();
    void game_ending();
};