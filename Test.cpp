#include "doctest.h"
#include "Schedule.hpp"



TEST_CASE("Team"){
    Team* team = new Team("Team1");
    CHECK(team->getName() == "Team1");
    CHECK_THROWS(Team(""));
}

TEST_CASE("League"){
    League* league = new League();
    CHECK(league->getTeams().size() == 0);
    CHECK_THROWS(league->addTeam(nullptr));
    for (int i = 0; i < 20; i++){
        CHECK_NOTHROW(league->addTeam(new Team("Team" + to_string(i))));
    }
    CHECK_THROWS(league->addTeam(new Team("Team20")));
    CHECK(league->getTeams().size() == 20);
    CHECK_THROWS(league->randomizeTeams());
    League *league2 = new League();
    CHECK_NOTHROW(league2->randomizeTeams());
    CHECK(league2->getTeams().size() == 20);
}

TEST_CASE("Game"){
    League* league = new League();
    league->randomizeTeams();
    for (uint i=0; i < 20; i++){
        for (uint j=i; j < 20; j++){
            if (i != j){
                CHECK_NOTHROW(new Game(league->getTeams()[i], league->getTeams()[j]));
            }
        }
    }
}

TEST_CASE("Schedule"){
    League* league = new League();
    CHECK_THROWS(new Schedule(league));
    league->addTeam(new Team("Team1"));
    CHECK_THROWS(new Schedule(league));
    league->addTeam(new Team("Team2"));
    CHECK_NOTHROW(new Schedule(league));

    League *league2 = new League();
    league2->randomizeTeams();
    CHECK_NOTHROW(new Schedule(league2));
    Schedule *schedule = new Schedule(league2);
    CHECK(league2->getTeams().size() == 20);
    CHECK_NOTHROW(schedule->printLeague());
    CHECK_NOTHROW(schedule->printSchedule());
    CHECK_NOTHROW(schedule->printPointsBiggerThanAgains());
    
}

