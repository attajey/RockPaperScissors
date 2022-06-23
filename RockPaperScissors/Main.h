#pragma once
using namespace std;
void winnerCheck(string& computerRandomChoice, string& playerChoice, int& playerWins, int& computerWins, bool& playerWinFlag, bool& computerWinFlag);

void findOrCreateUser(fstream& userFile, int& playerWins, int& computerWins, string& userName);

void saveScore(fstream& userFile, string& userName, int playerWins, int computerWins);

void farewell(int playerWins, int computerWins);

void repeatGame(string& playerAnsForGameEnd, int playerWins, int computerWins, int& retflag);

void playerAnswer(int& playerChoiceIndex, string& playerChoice, string  gameOptions[3]);
