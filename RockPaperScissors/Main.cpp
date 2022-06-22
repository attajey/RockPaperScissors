#include <iostream> // input output operations
#include <fstream> // file operations
#include <stdlib.h>  // srand, rand
#include <time.h>       /* time */

using namespace std;

int main()
{
	fstream userFile;
	string userName;
	int playerWins;
	int computerWins;
	string gameOptions[] = { "Rock", "Paper", "Scissors" };
	srand(time(NULL));

	cout << "GREETINGS! WLC TO R-P-S Game" << endl;
	cout << "Please Enter Your Username : ";
	cin >> userName;
	//userFile << userName; // write in file 

	// 1. Search through files to find userName.txt
	userFile.open(userName + ".txt", ios::app);
	if (userFile)
	{
		if (userFile.is_open())
		{
			
		}
	// if exists, read 2 numbers : player wins AND computer wins
		userFile >> playerWins;
		userFile >> computerWins;

	}
	else
	{
	// if not exists, create one

	}


	// 3. Computer randomly pick R-P-S
	string computerRandomChoice = gameOptions[rand() % 3];
	cout << computerRandomChoice;
	


	// 4. Ask user to choose 1=R - 2=P - 3=S

	// 5. See who won

	// 6. Display the game result to player

	// 7. Keep track of "wins by the player" and "wins by the computer" 

	// 8. Ask player if want to play again : Y - N 
	// if Y : Go to step 3
	// if N : continue to step 9

	// 9. save in userName.txt

	// 10. Privide confirmation msg to player

	// 11. End the game

	return 0;
}