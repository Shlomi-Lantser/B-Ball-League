#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Schedule.hpp"


int main(){
    League* league = new League();
    league->randomizeTeams();
    cout << "Hello , welcome to our league!" << endl;
    cout << "If you want to add a costumized team, type 'add' and then the name of the team , otherwise enter N" << endl;
    string input;
    cin >> input;
    while (input == "add"){
            string team_name;
            cout << "Enter the name of the team: " << endl;
            cin >> team_name;
            league->addTeam(new Team(team_name));
        cout << "If you want to add another costumized team, type 'add' and then the name of the team , otherwise enter N" << endl;
        cin >> input;
    }

    cout << "The league is stared!" << endl;
    cout << "The teams are:" << endl;
    for(int i = 0; i < league->getTeams().size(); i++){
        cout << league->getTeams()[i]->getName() << endl;
    }



    cout << "League is over!" << endl;

    cout << "Initializing schedule..." << endl;
    Schedule* schedule = new Schedule(league);
    schedule->startLeague();

    int option;
while(option != 8){
    cout << "____________MENU__________" << endl;
    cout << "1. Print the league" << endl;
    cout << "2. Print the top teams" << endl;
    cout << "3. Print the longest win streak" << endl;
    cout << "4. Print the longest lose streak" << endl;
    cout << "5. Print the points bigger than against" << endl;
    cout << "6. Print the against bigger than points" << endl;
    cout << "7. Print the average" << endl;
    cout << "8. Exit" << endl;
    cout << "Choose an option: ";

    cin >> option;
    
    switch(option){
        case 1:
            schedule->printLeague();
            break;
        case 2:
            schedule->printSchedule();
            break;
        case 3:
            schedule->longestWinStreak();
            break;
        case 4:
            schedule->longestLoseStreak();
            break;
        case 5:
            schedule->printPointsBiggerThanAgains();
            break;
        case 6:
            schedule->printAgainstBiggerThanPoints();
            break;
        case 7:
            schedule->average();
            break;
        case 8:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }
    
}


    return 0;
}
