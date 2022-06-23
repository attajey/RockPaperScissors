#pragma once

void winnerCheck(string& computerRandomChoice, string& playerChoice, int& playerWins, int& computerWins, bool& playerWinFlag, bool& computerWinFlag);

void findOrCreateUser(fstream& userFile, int& playerWins, int& computerWins, string& userName);

void saveScore(std::fstream& userFile, std::string& userName, int playerWins, int computerWins);

void farewell(int playerWins, int computerWins);

void repeatGame(std::string& playerAnsForGameEnd, int playerWins, int computerWins, int& retflag);

void playerAnswer(int& playerChoiceIndex, std::string& playerChoice, std::string  gameOptions[3]);
