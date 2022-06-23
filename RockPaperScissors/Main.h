#pragma once

void winnerCheck(std::string& computerRandomChoice, std::string& playerChoice, int& playerWins, bool& playerWinFlag, int& computerWins);

void findOrCreateUser(std::fstream& userFile, int& playerWins, int& computerWins);
