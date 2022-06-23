#pragma once

void winnerCheck(std::string& computerRandomChoice, std::string& playerChoice, int& playerWins, bool& playerWinFlag, int& computerWins);

void findOrCreateUser(std::fstream& userFile, int& playerWins, int& computerWins);

void saveScore(std::fstream& userFile, std::string& userName, int playerWins, int computerWins);

void farewell(int playerWins, int computerWins);

void repeatGame(std::string& playerAnsForGameEnd, int playerWins, int computerWins, int& retflag);

void playerAnswer(int& playerChoiceIndex, std::string& playerChoice, std::string  gameOptions[3]);
