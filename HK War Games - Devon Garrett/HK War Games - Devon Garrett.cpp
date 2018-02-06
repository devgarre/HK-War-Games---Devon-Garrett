// HK War Games - Devon Garrett.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

//prevents unnecesary repetition of code
using namespace std;

int main()
{
	cout << "Enemy is finding a new position..." << endl;
	//generates a number between 1 and 64 for enemy position
	srand(time(0));
	int topLimit = 64;
	int bottomLimit = 1;
	int binaryTopLimit = 64;
	int binaryBottomLimit = 1;
	int enemyBase = rand() % topLimit + bottomLimit;
	cout << "The enemy base is hidden in Sector #" << enemyBase << " of the 8x8 grid." << endl << endl;

	cout << "Initializing HK-Ariel Drone Protocol..." << endl;
	//initializes all variables for the drone search program
	int binaryNumberOfGuesses = 0;
	bool binaryTargetFound = false;
	int linearNumberOfGuesses = 0;
	bool linearTargetFound = false;
	int randomNumberOfGuesses = 0;
	bool randomTargetFound = false;
	int humanNumberOfGuesses = 0;
	bool humanTargetFound = false;
	bool allTargetFound = false;

	//loop to repeatedly search until enemy is found
	while (allTargetFound == false)
	{
		//loops the binary search protocol
		while (binaryTargetFound == false)
		{
			int binaryCurrentGuess = ((topLimit - bottomLimit) / 2) + bottomLimit;
			binaryNumberOfGuesses++; //increases binary guess count
			cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=" << endl;
			cout << "HK-Aerial Binary Drone currently searching Sector #" << binaryCurrentGuess << endl;

			//determines if the current guess was higher or lower than the actual location and adjusts search based on this
			if (enemyBase > binaryCurrentGuess)
			{
				binaryBottomLimit = binaryCurrentGuess + 1;
				cout << "The scan of Sector #" << binaryCurrentGuess << " provided information that showed the base to be in a higher sector." << endl;
				cout << "HK-Aerial Drone is now searching in Sectors #" << binaryBottomLimit << " - #" << binaryTopLimit << endl;
			}
			else if (enemyBase < binaryCurrentGuess)
			{
				binaryTopLimit = binaryCurrentGuess - 1;
				cout << "The scan of Sector #" << binaryCurrentGuess << " provided information that showed the base to be in a lower sector." << endl;
				cout << "HK-Aerial Drone is now searching in Sectors #" << binaryBottomLimit << " - #" << binaryTopLimit << endl;
			}
			else if (enemyBase = binaryCurrentGuess)
			{
				cout << "Target has been found by the Binary Drone in Sector #" << binaryCurrentGuess << endl;
				cout << "It took the HK-Aerial Drone " << binaryNumberOfGuesses << " sector scan(s) in order to find the targets." << endl << endl;
				binaryTargetFound = true;
			}
			else
			{
				cout << "Binary Drone has malfunctioned!" << endl;
				cout << "A request has been sent to maintnece." << endl << endl;
				binaryTargetFound = true;
			}
		}

		//loops the linear search protocol
		while (linearTargetFound == false) 
		{
			int linearCurrentGuess = bottomLimit;
			linearNumberOfGuesses++; //increases linear guess count
			cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=" << endl;
			cout << "HK-Aerial Linear Drone currently searching Sector #" << linearCurrentGuess << endl;

			//determines if current linear guess is correct
			if (enemyBase == linearCurrentGuess) 
			{
				cout << "Target has been found by the Linear Drone in Sector #" << linearCurrentGuess << endl;
				cout << "It took the HK-Aerial Drone " << linearNumberOfGuesses << " sector scan(s) in order to find the targets." << endl << endl;
				linearTargetFound = true;
			}

			else
			{
				cout << "Linear Drone has malfunctioned!" << endl;
				cout << "A request has been sent to maintnece." << endl << endl;
				linearTargetFound = true;
			}

			//loops the random search protocol
			while (randomTargetFound == false)
			{
				srand(time(0));
				int randomCurrentGuess = rand() % topLimit + bottomLimit;
				randomNumberOfGuesses++; //increases linear guess count
				cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=" << endl;
				cout << "HK-Aerial Random Drone currently searching Sector #" << randomCurrentGuess << endl;

				//determines if current linear guess is correct
				if (enemyBase == randomCurrentGuess)
				{
					cout << "Target has been found by the Random Drone in Sector #" << randomCurrentGuess << endl;
					cout << "It took the HK-Aerial Drone " << randomNumberOfGuesses << " sector scan(s) in order to find the targets." << endl << endl;
					randomTargetFound = true;
				}

				else
				{
					cout << "Random Drone has malfunctioned!" << endl;
					cout << "A request has been sent to maintnece." << endl << endl;
					randomTargetFound = true;
				}
			}

			//loops the random search protocol
			while (humanTargetFound == false)
			{
				int humanCurrentGuess;
				humanNumberOfGuesses++; //increases linear guess count
				cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=" << endl;
				cout << "HK-Aerial Human-Controlled Drone currently searching Sector #" << humanCurrentGuess << endl;

				//determines if current linear guess is correct
				if (enemyBase == humanCurrentGuess)
				{
					cout << "Target has been found by the Random Drone in Sector #" << humanCurrentGuess << endl;
					cout << "It took the HK-Aerial Drone " << humanNumberOfGuesses << " sector scan(s) in order to find the targets." << endl << endl;
					humanTargetFound = true;
				}

				else
				{
					cout << "Human-Controlled Drone has malfunctioned!" << endl;
					cout << "A request has been sent to maintnece." << endl << endl;
					humanTargetFound = true;
				}
			}
		}

		if (binaryTargetFound == true)
		{
			if (linearTargetFound == true)
			{
				if (randomTargetFound == true)
				{
					if (humanTargetFound == true)
					{
						allTargetFound = true;
					}
				}
			}
		}
	}
	system("pause");

	return 0;
}

