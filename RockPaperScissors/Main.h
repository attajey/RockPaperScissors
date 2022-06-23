#pragma once

void winnerCheck(std::string& computerRandomChoice, std::string& playerChoice, int& playerWins, bool& playerWinFlag, int& computerWins);

void findOrCreateUser(std::fstream& userFile, int& playerWins, int& computerWins);

void saveScore(std::fstream& userFile, std::string& userName, int playerWins, int computerWins);

void farewell(int playerWins, int computerWins);
