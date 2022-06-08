# B-Ball-League
## implementation in C++

# Description
In this project i built a random / input by user basketball league , in this league there is 20 teams that playes one against each other once as a home teams and once as a away team.
Every team has it owns talent level between 0 to 1 that increase or decrease their chances to get points in the game.
every team has it's own unique name ,
the goal of building this league is to build a easy to use schedule that shows us the statistic of the league season.

Classes on this project :
                  
* **Team** - This class represents team with a unique name and talent that given by random.

* **Game** - Implementation of the game , the game has 2 teams , the teams get random points and the one got more points from the other wins , in order in case of a "draw" 
we will check who has the bigger points vs against point difference and this team will win , if their difference is equal we will check the difference between total wins and total lose , if this also equal we will give the win for the home team !
                  
* **League** - The league class represents the league , the league contains dataBase of teams name to randomize team in case of the user puts less than 20 teams
and the final teams data-structor that store all the information about the league.

* **Schedule** - The schedule contains functions that prints all the information about the league season :
1. Top teams - the user enter number of the top teams he would like to see
2. League - Prints all the league details in table pattern , the table sorted by the most wins or most big difference between points and against points.
3. Most win streak - returns the team that win the most times in a row
4. Most lose streak - returns the team that lose the most time in a row
5. Average - returns table with all needed average details.

* **Test** - Test about all the classes and checking for throws and ecxeptions , implemented by using `dockest.h`
                 
## Running guide:

* Clone this ripository
* Open the directory and open it in terminal
* Use the command `make all` to create all the needed files and the executable ones.
* Use the command `./main` to run the main function 
* Use the command `./test` to run the Tests.
* Use the command `make clean` to clean all the executable files.
