#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "League.hpp"



class Schedule{
    private:
        League* league;

    public:
        int cycles;
        Schedule(League* league);
        vector<Team*> topTeams(int n);
        void longestWinStreak();
        void longestLoseStreak();
        vector<Team*> pointsBiggerThanAgains();
        void printSchedule();
        void startLeague();
        void printLeague();
        void printPointsBiggerThanAgains();
        void average();
        vector <Team*> againstBiggerThanPoints();
        void printAgainstBiggerThanPoints();
};
        
    