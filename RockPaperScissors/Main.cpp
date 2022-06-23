#include <iostream> // input output operations
#include <fstream> // file operations
#include <stdlib.h>  // srand, rand
#include <time.h>       /* time */

using namespace std;

int main()
{
	fstream userFile;
	string userName;
	int playerWins = 0;
	int computerWins = 0;
	int playerChoiceIndex = 0;
	string playerChoice;
	string gameOptions[] = { "Rock", "Paper", "Scissors" };
	srand(time(NULL));
	bool endGame = false;
	bool playerWinFlag = false;

	cout << "GREETINGS! WLC TO R-P-S Game" << endl;
	cout << "Please Enter Your Username : ";
	cin >> userName;
	//userFile << userName; // write in file 

	// 1. Search through files to find userName.txt
	userFile.open(userName + ".txt", ios::in);
	if (userFile)
	{
		if (userFile.is_open())
		{
			// if exists, read 2 numbers : player wins AND computer wins
			userFile >> playerWins;
			userFile >> computerWins;
			userFile.close();	
		}
		else
		{
			cerr << "Unable to open File ! " << endl;
		}
	}

	while (!endGame)
	{
		// 3. Computer randomly pick R-P-S
		string computerRandomChoice = gameOptions[rand() % 3];

		// 4. Ask user to choose 1=R - 2=P - 3=S
		cout << "Please Choose One of the Following : 1=Rock  2=Paper  3=Scissors" << endl;
		cin >> playerChoiceIndex;
		playerChoice = gameOptions[playerChoiceIndex - 1];

		// 5. See who won
		if (computerRandomChoice == "Rock")
		{
			if (playerChoice == "Rock")
			{
				//Draw
				continue;

			}
			else if (playerChoice == "Paper")
			{
				// Player Wins
				playerWins++;
				playerWinFlag = true;
			}
			else if (playerChoice == "Scissors")
			{
				// Computer Wins
				computerWins++;
				playerWinFlag = false;
			}

		}
		else if (computerRandomChoice == "Paper")
		{
			if (playerChoice == "Rock")
			{
				// Computer Wins
				computerWins++;
				playerWinFlag = false;
			}
			else if (playerChoice == "Paper")
			{
				// Draw
				continue;
			}
			else if (playerChoice == "Scissors")
			{
				// Player Wins
				playerWins++;
				playerWinFlag = true;
			}
		}
		else if (computerRandomChoice == "Scissors")
		{
			if (playerChoice == "Rock")
			{
				// Player Wins
				playerWins++;
				playerWinFlag = true;
			}
			else if (playerChoice == "Paper")
			{
				// Computer Wins
				computerWins++;
				playerWinFlag = false;

			}
			else if (playerChoice == "Scissors")
			{
				// Draw
				continue;
			}
		}

		// 6. Display the game result to player
		if (playerWinFlag)
		{
			cout << "YOU HAVE WON !!! YEAYYYY" << endl;
		}
		else
		{
			cout << "L   LOOSER   L" << endl;
		}

		// 7. Keep track of "wins by the player" and "wins by the computer" 
		userFile.open(userName + ".txt", ios::out);
		userFile << playerWins << " " << computerWins;

		// 8. Ask player if want to play again : Y - N 
		cout << "Do you want to play again ? (0=Y / 1=N)" << endl;
		cin >> endGame;

		// if N : continue to step 9
		if (endGame)
		{
			// 9. save in userName.txt
			userFile.close();
			// 10. Privide confirmation msg to player
			cout << "Your Score was saved successfully. See ya soon ! " << endl;
			// 11. End the game
			break;
		}
	} // if Y : Go to step 3
	return 0;
}