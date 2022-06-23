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

// 1. Greet the player
void greeting()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	cout << "              ******** GREETINGS ******** " << "\n\n ******** WELCOME TO Rock Paper Scissors Game ******** " << endl << endl;
	cout << " >>> COMP217 Midterm Exam - Centennial College - Atta Jirofty - 301151759 <<<" << endl << endl;
}

// 2. Ask for username and read the scores from file ( create user if does not exits )
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
			// if user exists, read 2 numbers : playerWins AND computerWins
			userFile >> playerWins;
			userFile >> computerWins;
			userFile.close();
		}
		else
		{
			throw UnableToOpenFileException();
		}
	}
}

// 3. Ask player to choose an option and check the user input
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

void userInfo(std::string& userName, int playerWins, int computerWins)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);

	cout << "How you doin' " << userName << " ?" << "\n\n";
	cout << "Your Current Score is : " << playerWins << endl;
	cout << "Computer's Score is : " << computerWins << endl << endl;
}

// 4. Determine the winner
void winnerCheck(string& computerRandomChoice, string& playerChoice, int& playerWins, int& computerWins, bool& playerWinFlag, bool& computerWinFlag)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (computerRandomChoice == "Rock")
	{

		if (playerChoice == "Rock")
		{
			//Draw
			cout << "DRAW ! Try Again...\n\n" << endl;
			playerWinFlag = false;
			computerWinFlag = false;
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
			playerWinFlag = false;
			computerWinFlag = false;
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
			playerWinFlag = false;
			computerWinFlag = false;
		}

	}

	// setting flags for displaying final results
	if (playerWinFlag)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE || BACKGROUND_RED);
		cout << "\n\n$$$$$ YOU HAVE WON $$$$$ \nWe shall be victorious in despite of difficulties... \n" << endl;

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "SCORES ===> Player:" << playerWins << "  Computer:" << computerWins << " <=== SCORES\n\n" << endl;
	}
	else if (computerWinFlag)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE || BACKGROUND_RED);
		cout << "\n\n>>>>>>>>>>   LOOSER   <<<<<<<<<< \nThis fight is not over...\n" << endl;

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "SCORES ===> Player:" << playerWins << "  Computer:" << computerWins << " <=== SCORES\n\n" << endl;
	}
	else
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE || BACKGROUND_RED);
		cout << "\n\nOh well, a draw ! \n" << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "SCORES ===> Player:" << playerWins << "  Computer:" << computerWins << " <=== SCORES\n\n" << endl;
	}
}

// 5. Save the new scores for player in userName.txt file
void saveScore(std::fstream& userFile, std::string& userName, int playerWins, int computerWins)
{
	userFile.open(userName + ".txt", fstream::out | fstream::trunc);
	userFile << playerWins << " " << computerWins;
	userFile.close();
}

// 6. Ask player if want to play again
void repeatGame(std::string& playerAnsForGameEnd, int playerWins, int computerWins, int& retflag)
{
	retflag = 1;

	cout << "Do you want to play again ? (Y/N)" << endl;
	cin >> playerAnsForGameEnd;

	if (playerAnsForGameEnd == "N" || playerAnsForGameEnd == "n")
	{
		farewell(playerWins, computerWins);
		{ retflag = 2; return; };
	}
	else if (playerAnsForGameEnd == "Y" || playerAnsForGameEnd == "y")
	{
		{ retflag = 3; return; };
	}
	else
	{
		cin.clear();
		throw InvalidInputException();
	}
}

// 7. Show confirmation message
void farewell(int playerWins, int computerWins)
{
	system("CLS");
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

	try
	{
		findOrCreateUser(userFile, playerWins, computerWins, userName);
	}
	catch (const UnableToOpenFileException& ex)
	{
		cerr << "Exception Occurred: " << ex.what() << endl << endl;
	}

	while (true)
	{
		system("CLS");
		userInfo(userName, playerWins, computerWins);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

		// Computer randomly pick Rock-Paper-Scissors
		string computerRandomChoice = gameOptions[rand() % 3];

		try
		{
			playerAnswer(playerChoiceIndex, playerChoice, gameOptions);
		}
		catch (const InvalidInputException& ia)
		{
			cerr << "Exception Occurred: " << ia.what() << endl << endl;
		}

		winnerCheck(computerRandomChoice, playerChoice, playerWins, computerWins, playerWinFlag, computerWinFlag);

		saveScore(userFile, userName, playerWins, computerWins);

		try
		{
			int retflag;
			repeatGame(playerAnsForGameEnd, playerWins, computerWins, retflag);
			if (retflag == 2) break;
			if (retflag == 3) continue;
		}
		catch (const InvalidInputException& ia)
		{
			cerr << "Exception Occurred: " << ia.what() << endl << endl;
		}
	}

	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
	return 0;
}

