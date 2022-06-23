#include <iostream>  // input output operations
#include <fstream>   // file operations
#include <cstdlib>   // srand, rand
#include <time.h>    // time
#include <stdio.h>   // to access terminal colors
#include <windows.h> // to access terminal colors

#include "Main.h"
#include "UnableToOpenFileException.h"
#include "InvalidInputException.h"

using namespace std;

void greeting()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	cout << "              ******** GREETINGS ******** " << "\n\n ******** WELCOME TO Rock Paper Scissors Game ******** " << endl << endl;
	cout << " >>> COMP217 Midterm Exam - Centennial College - Atta Jirofty - 301151759 <<<" << endl << endl;
}

void findOrCreateUser(fstream& userFile, int& playerWins, int& computerWins, string& userName)
{
	cout << "Please Enter Your Username : ";
	cin >> userName;
	cout << endl << endl;
	userFile.open(userName + ".txt", fstream::in);

	if (userFile)
	{
		if (userFile.is_open())
		{
			// if exists, read 2 numbers : player wins AND computer wins
			userFile >> playerWins;
			userFile >> computerWins;
			cout << "Your Current Score is : " << playerWins << endl;
			cout << "Computer's Score is : " << computerWins << endl << endl;
			userFile.close();
		}
		else
		{
			throw UnableToOpenFileException();
			//cerr << "Unable to open File ! " << endl;
		}
	}
}

void playerAnswer(int& playerChoiceIndex, string& playerChoice, string  gameOptions[3])
{
	cout << "\n\nPlease Choose One of the Following :" << "\nEnter 1 for 'Rock' \nEnter 2 for 'Paper' \nEnter 3 for 'Scissors'" << endl;
	cin >> playerChoiceIndex;
	if (playerChoiceIndex <= 3 && playerChoiceIndex >= 1)
	{
		playerChoice = gameOptions[playerChoiceIndex - 1];
	}
	else
	{
		cin.clear();
		throw InvalidInputException();
	}
}

void winnerCheck(string& computerRandomChoice, string& playerChoice, int& playerWins, int& computerWins, bool& playerWinFlag, bool& computerWinFlag)
{
	if (computerRandomChoice == "Rock")
	{

		if (playerChoice == "Rock")
		{
			//Draw
			cout << "DRAW ! Try Again...\n\n" << endl;
		}

		else if (playerChoice == "Paper")
		{
			// Player Wins
			playerWins++;
			playerWinFlag = true;
			computerWinFlag = false;
		}

		else if (playerChoice == "Scissors")
		{
			// Computer Wins
			computerWins++;
			playerWinFlag = false;
			computerWinFlag = true;
		}

	}

	else if (computerRandomChoice == "Paper")
	{

		if (playerChoice == "Rock")
		{
			// Computer Wins
			computerWins++;
			playerWinFlag = false;
			computerWinFlag = true;
		}

		else if (playerChoice == "Paper")
		{
			// Draw
			cout << "DRAW ! Try Again...\n\n" << endl;
		}

		else if (playerChoice == "Scissors")
		{
			// Player Wins
			playerWins++;
			playerWinFlag = true;
			computerWinFlag = false;
		}

	}

	else if (computerRandomChoice == "Scissors")
	{

		if (playerChoice == "Rock")
		{
			// Player Wins
			playerWins++;
			playerWinFlag = true;
			computerWinFlag = false;
		}

		else if (playerChoice == "Paper")
		{
			// Computer Wins
			computerWins++;
			playerWinFlag = false;
			computerWinFlag = true;
		}

		else if (playerChoice == "Scissors")
		{
			// Draw
			cout << "DRAW ! Try Again...\n\n" << endl;
		}

	}

	// setting flags for displaying final results
	if (playerWinFlag)
	{
		cout << "\n\n$$$$$ YOU HAVE WON $$$$$ \nWe shall be victorious in despite of difficulties... \n\n" << endl;
	}
	else if (computerWinFlag)
	{
		cout << "\n\n>>>>>>>>>>   LOOSER   <<<<<<<<<< \nThis fight is not over...\n\n" << endl;
	}
}

void saveScore(std::fstream& userFile, std::string& userName, int playerWins, int computerWins)
{
	userFile.open(userName + ".txt", fstream::out | fstream::trunc);
	userFile << playerWins << " " << computerWins;
	userFile.close();
}

void farewell(int playerWins, int computerWins)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	cout << "\nYour Final Score is : " << playerWins << endl;
	cout << "Computer's Final Score is : " << computerWins << endl << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	cout << "User Data Successfully Saved. \nFarewell Muchacho ! \n\n" << endl;
}


int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // to access terminal colors 

	bool endGame = false;
	bool playerWinFlag = false;
	bool computerWinFlag = false;

	int playerWins = 0;
	int computerWins = 0;
	int playerChoiceIndex = 0;

	string userName;
	string playerChoice;
	string playerAnsForGameEnd;
	string gameOptions[] = { "Rock", "Paper", "Scissors" };

	fstream userFile;

	srand(time(NULL));

	greeting();

	// 1. Search through files to find userName.txt
	try
	{
		findOrCreateUser(userFile, playerWins, computerWins, userName);

	}
	catch (const UnableToOpenFileException& ex)
	{
		cerr << "Exception Occurred: " << ex.what() << endl << endl;
		return -1;
	}

	while (!endGame)
	{
		// 3. Computer randomly pick R-P-S
		string computerRandomChoice = gameOptions[rand() % 3];

		// 4. Ask user to choose 1=R - 2=P - 3=S
		try
		{
			playerAnswer(playerChoiceIndex, playerChoice, gameOptions);

		}
		catch (const InvalidInputException& ia)
		{
			cerr << "Exception Occurred: " << ia.what() << endl << endl;
		}

		// 5. See who won  ----  6. Display the game result to player
		winnerCheck(computerRandomChoice, playerChoice, playerWins, computerWins, playerWinFlag, computerWinFlag);

		// 7. Keep track of scores 
		saveScore(userFile, userName, playerWins, computerWins);

		// 8. Ask player if want to play again : Y - N 
		cout << "Do you want to play again ? (Y/N)" << endl;
		cin >> playerAnsForGameEnd;
		if (playerAnsForGameEnd == "N" || playerAnsForGameEnd == "n")
		{
			//endGame = true;
			farewell(playerWins, computerWins);
			break;
		}
		else if (playerAnsForGameEnd == "Y" || playerAnsForGameEnd == "y")
		{
			//endGame = false;
			continue;
		}

		// if N : continue to step 9
		/* if (endGame)
		{
			// 9. save in userName.txt
			// 10. Privide confirmation msg to player
			farewell(playerWins, computerWins);
			// 11. End the game
			break;
		}*/
	} // if Y : Go to step 3

	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
	return 0;
}