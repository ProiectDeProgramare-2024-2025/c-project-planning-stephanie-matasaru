// shared/utils.hpp
#ifndef UTILS_HPP
#define UTILS_HPP

#include "types.hpp"

extern std::vector<Player> players;
extern std::vector<Match> matches;

int findPlayerIndex(const std::string& name);
bool isValidName(const std::string& name);
bool isValidScore(int score);
bool exactlyOneIs21(int s1, int s2);
void saveMatchToFile(const Match& m);
void savePlayersToFile();
void loadFromFiles();
void addMatchCmd(const std::string& n1, int s1, const std::string& n2, int s2);
void showRankings();
void showPlayerInfo(const std::string&);
void showMatchHistory();
void resetTournament();


#endif
