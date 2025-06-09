// app1/app1.cpp
#include <iostream>
#include <string>
#include "./utils.hpp"
#include "./types.hpp"

using namespace std;

void addMatchCmd(const string& n1, int s1, const string& n2, int s2) {
    if (!isValidName(n1) || !isValidName(n2) ||
        !isValidScore(s1) || !isValidScore(s2) ||
        !exactlyOneIs21(s1, s2)) {
        cout << "Invalid match data.\n";
        return;
    }

    Match m(n1, s1, n2, s2);
    matches.push_back(m);
    saveMatchToFile(m);

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
        players[i1].addLoss();
        players[i2].addWin();
    }

    savePlayersToFile();
    cout << "Match added successfully!\n";
}

