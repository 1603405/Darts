#include "Player.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


//Average no.of throws per win =/= average number of throws to get to ten bulls
//Question asks: "How can we calculate the number of throws, on average, each player will take to hit 10 bulls?"
//Program will continue to run until both players have hit ten bulls and will calculate average number of darts needed for 10 bulls.
//Because of the rounds system the first person to 10 will win, whoever starts first will have a great advantage.

int main()
{
	srand(time(0));									//Sets time to 0

	Player one;
	Player two;

	cout << "\n				Welcome to Dave's 'ten-up' darts" << endl;
	cout << "	this game requires two players, the successful bull hits percentage of each player" << endl;
	cout << "		and the number of games to be played by both players" << endl << endl;

	cout << "Please enter the number of games: ";
	cin >> games;

	cout << "Please enter the name of the player going first: ";
	cin >> one.name;
	cout << "Please enter the percenage hit rate of the player going first: ";
	cin >> one.bullHitRate;

	cout << "Please enter the name of the player going second: ";
	cin >> two.name;
	cout << "Please enter the percenage hit rate of the player going second: ";
	cin >> two.bullHitRate;


	for (int i = 0; i < games; i++)
	{
		while (one.round() == false || two.round() == false)
		{
			one.round();
			two.round();
		}

		if (one.roundsPlayed <= two.roundsPlayed)	//adds a win to player who won
		{
			one.noOfWins++;
		}
		else
		{
			two.noOfWins++;
		}

		one.reset();
		two.reset();
	}

	//Average darts to hit 10 bulls
	cout << "\n";
	cout << one.name << " takes on average " << one.calculateTenBullAve() << " darts to hit ten bulls. \n";
	cout << two.name << " takes on average " << two.calculateTenBullAve() << " darts to hit ten bulls. \n \n";

	std::cout << one.name << " won " << one.noOfWins << " games. \n";
	std::cout << two.name << " won " << two.noOfWins << " games. \n \n";

	//percentage
	cout << one.name << " has won " << one.calculateWinPercent() << " percent of games \n";
	cout << two.name << " has won " << two.calculateWinPercent() << " percent of games \n";


}
