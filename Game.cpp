#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <algorithm>
#include <cmath>

// initilize generator for normal distribution
std::default_random_engine generator;

Game::Game(Team *home, Team *away)
{
    this->home = home;
    this->away = away;
    this->homeScore = normal_distribution<>(75,20)(generator);
    this->homeScore = this->homeScore < 55 ? 55 : this->homeScore;
    this->homeScore = this->homeScore > 100 ? 100 : this->homeScore;
    this->awayScore = normal_distribution<>(75,20)(generator);
    this->awayScore = this->awayScore < 50 ? 50 : this->awayScore;
    this->awayScore = this->awayScore > 100 ? 100 : this->awayScore;
    this->home->totalScore += this->homeScore;
    this->away->totalScore += this->awayScore;
    this->home->againstScore += this->awayScore;
    this->away->againstScore += this->homeScore;

    if (this->homeScore > this->awayScore)
    {
        this->winner = this->home;
        this->loser = this->away;
        this->game_ending();
    }
    else if (this->homeScore < this->awayScore)
    {
        this->winner = this->away;
        this->loser = this->home;
        this->game_ending();
    }
    else
    {
        if (this->home->totalScore - this->home->againstScore > this->away->totalScore - this->away->againstScore)
        {
            this->winner = this->home;
            this->loser = this->away;
            this->game_ending();
        }
        else if (this->home->totalScore - this->home->againstScore < this->away->totalScore - this->away->againstScore)
        {
            this->winner = this->away;
            this->loser = this->home;
            this->game_ending();
        }
        else
        { 
            if (this->home->totalWins - this->home->totalLosses > this->away->totalWins - this->away->totalLosses){
                this->winner = this->home;
                this->loser = this->away;
                this->game_ending();
            }else if (this->home->totalWins - this->home->totalLosses < this->away->totalWins - this->away->totalLosses){
                this->winner = this->away;
                this->loser = this->home;
                this->game_ending();
            }else {
                this->winner = this->home;
                this->loser = this->away;
                this->game_ending();
            }
        }
    }
}

const Team *Game::getHome()
{
    return this->home;
}

const Team *Game::getAway()
{
    return this->away;
}

const Team *Game::getWinner()
{
    return this->winner;
}

const Team *Game::getLoser()
{
    return this->loser;
}

void Game::game_ending()
{
    this->winner->winStreak++;
    this->winner->totalWins++;
    this->loser->loseStreak++;
    this->loser->totalLosses++;
    if (this->winner->winStreak > this->winner->longestWinStreak)
    {
        this->winner->longestWinStreak = this->winner->winStreak;
    }
    if (this->loser->loseStreak > this->loser->longestLoseStreak)
    {
        this->loser->longestLoseStreak = this->loser->loseStreak;
    }
    this->loser->winStreak = 0;
    this->winner->loseStreak = 0;
}
