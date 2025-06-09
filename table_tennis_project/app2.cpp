#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include "utils.hpp"
#include "types.hpp"

using namespace std;

// Declaration from main.cpp
extern HANDLE hConsole;
void setColor(int color);
void resetColor();

void showRankings() {
    sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
        return a.getWins() > b.getWins();
    });

    setColor(11);
    cout << "=== ";
    resetColor(); cout << "Player Rankings";
    setColor(11); cout << " ===\n";
    resetColor();

    for (size_t i = 0; i < players.size(); ++i) {
        setColor(13); cout << i + 1 << ". "; resetColor();
        setColor(14); cout << players[i] << "\n"; resetColor();
    }
}

void showPlayerInfo(const string& name) {
    int index = findPlayerIndex(name);
    if (index == -1) {
        setColor(12);
        cout << "Player not found.\n";
        resetColor();
        return;
    }

    setColor(13); cout << "Player: "; resetColor();
    setColor(14); cout << players[index] << "\n"; resetColor();

    setColor(11);
    cout << "Match History:\n";
    resetColor();

    for (const auto& m : matches) {
        if (m.getName1() == name || m.getName2() == name) {
            setColor(8); cout << " - "; resetColor();
            setColor(14); cout << m << "\n"; resetColor();
        }
    }
}

void showMatchHistory() {
    setColor(11);
    cout << "=== ";
    resetColor(); cout << "Match History";
    setColor(11); cout << " ===\n";
    resetColor();

    for (const auto& m : matches) {
        setColor(8); cout << " - "; resetColor();
        setColor(14); cout << m << "\n"; resetColor();
    }
}

void resetTournament() {
    players.clear();
    matches.clear();
    ofstream("matches.txt", ios::trunc).close();
    ofstream("players.txt", ios::trunc).close();

    setColor(10);
    cout << "Tournament reset successfully!\n";
    resetColor();
}
