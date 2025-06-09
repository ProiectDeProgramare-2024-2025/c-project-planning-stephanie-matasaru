// shared/types.hpp
#ifndef TYPES_HPP
#define TYPES_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

// Template utility for printing vectors
// (Demonstrates template usage)
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const T& item : vec)
        std::cout << item << std::endl;
}

class Player {
private:
    std::string name;
    int wins;
    int losses;

public:
    Player(std::string n) : name(n), wins(0), losses(0) {}
    Player(std::string n, int w, int l) : name(n), wins(w), losses(l) {}

    std::string getName() const { return name; }
    int getWins() const { return wins; }
    int getLosses() const { return losses; }

    void addWin() { wins++; }
    void addLoss() { losses++; }

    friend std::ostream& operator<<(std::ostream& os, const Player& p) {
        os << p.name << " - Wins: " << p.wins << ", Losses: " << p.losses;
        return os;
    }
};

class Match {
private:
    std::string name1, name2;
    int score1, score2;

public:
    Match(std::string n1, int s1, std::string n2, int s2)
        : name1(n1), name2(n2), score1(s1), score2(s2) {}

    std::string getName1() const { return name1; }
    std::string getName2() const { return name2; }
    int getScore1() const { return score1; }
    int getScore2() const { return score2; }

    friend std::ostream& operator<<(std::ostream& os, const Match& m) {
        os << m.name1 << " " << m.score1 << " - "
           << m.score2 << " " << m.name2;
        return os;
    }
};

#endif
