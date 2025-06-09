// shared/utils.cpp
#include "utils.hpp"
#include <fstream>

std::vector<Player> players;
std::vector<Match> matches;

int findPlayerIndex(const std::string& name) {
    for (int i = 0; i < players.size(); ++i)
        if (players[i].getName() == name)
            return i;
    return -1;
}

bool isValidName(const std::string& name) {
    for (char c : name) if (!isalpha(c)) return false;
    return true;
}

bool isValidScore(int score) {
    return score >= 1 && score <= 21;
}

bool exactlyOneIs21(int s1, int s2) {
    return (s1 == 21 && s2 < 21) || (s2 == 21 && s1 < 21);
}

void saveMatchToFile(const Match& m) {
    std::ofstream file("matches.txt", std::ios::app);
    if (file) {
        file << m.getName1() << " " << m.getScore1() << " "
             << m.getName2() << " " << m.getScore2() << "\n";
    }
}

void savePlayersToFile() {
    std::ofstream file("players.txt");
    if (file) {
        file << players.size() << "\n";
        for (const Player& p : players)
            file << p.getName() << " " << p.getWins() << " " << p.getLosses() << "\n";
    }
}

void loadFromFiles() {
    players.clear();
    matches.clear();

    std::ifstream mfile("matches.txt");
    std::string n1, n2;
    int s1, s2;

    while (mfile >> n1 >> s1 >> n2 >> s2) {
        Match m(n1, s1, n2, s2);
        matches.push_back(m);

        int i1 = findPlayerIndex(n1);
        int i2 = findPlayerIndex(n2);

        if (i1 == -1) {
            players.emplace_back(n1);
            i1 = players.size() - 1;
        }
        if (i2 == -1) {
            players.emplace_back(n2);
            i2 = players.size() - 1;
        }

        if (s1 == 21) {
            players[i1].addWin();
            players[i2].addLoss();
        } else {
            players[i2].addWin();
            players[i1].addLoss();
        }
    }
}
