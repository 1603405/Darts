#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//global variables
int roll = 0;
double games = 0.00;

class Player
{
public:
	//attributes
	string name;
	long double winPercent = 0.00;
	int noOfWins = 0;
	int bullHitRate = 0;
	int tenBullAve = 0;
	int bullHits = 0;
	int totalDartsThrown = 0;
	int roundsPlayed = 0;

	//functions
	void reset();
	bool round();
	int calculateTenBullAve();
	long double calculateWinPercent();

};

void Player::reset()
{
	bullHits = 0;
	roundsPlayed = 0;
}

bool Player::round()
{
	for (int i = 0; i < 3; i++)				//3 darts will be thrown by each player
	{
		if (bullHits != 10)					//Enters if bullHits not achieved
		{
			if (i == 0)						//Will add 1 round if 10 bulls not hit per round
			{
				roundsPlayed++;
			}

			totalDartsThrown++;

			int roll = rand() % 100 + 0;	//Randonly generate number between 0 and 100
			if (roll < bullHitRate)			//If roll < successRate then hit
			{
				bullHits++;
			}

			return false;
		}
		else
		{
			return true;
		}
	}
}

int Player::calculateTenBullAve()
{
	//Each round will only end when 10 bulls have been hit by each player
	//The total sum of darts thrown will divided by the number of total games 
	//will give you the how many throws each player took on ave to hit 10 bulls
	tenBullAve = totalDartsThrown / games;
	return tenBullAve;
}

long double Player::calculateWinPercent()
{
	winPercent = (noOfWins / games) * 100;
	return winPercent;
}
