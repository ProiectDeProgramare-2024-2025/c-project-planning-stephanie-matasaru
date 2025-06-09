#include <iostream>
#include <string>
#include <windows.h>
#include "utils.hpp"

using namespace std;

HANDLE hConsole;

void setColor(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void resetColor() {
    SetConsoleTextAttribute(hConsole, 7);
}

void showMenu() {
    system("cls");
    setColor(11);
    cout << "====== Table Tennis Tournament ======\n"; resetColor();

    setColor(13); cout << "1"; resetColor(); cout << " - Add Match\n";
    setColor(13); cout << "2"; resetColor(); cout << " - Show Rankings\n";
    setColor(13); cout << "3"; resetColor(); cout << " - Show Player Info\n";
    setColor(13); cout << "4"; resetColor(); cout << " - Show Match History\n";
    setColor(13); cout << "5"; resetColor(); cout << " - Reset Tournament\n";
    setColor(13); cout << "0"; resetColor(); cout << " - Exit\n";

    setColor(11);
    cout << "=====================================\n"; resetColor();
}

int main(int argc, char* argv[])
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    loadFromFiles();

    if (argc < 2) {
        // Fallback to interactive menu
        int option;
        do {
            showMenu();
            cout << "Enter option: ";
            cin >> option;
            cin.ignore();
            system("cls");

            switch (option) {
                case 1: {
                    string name1, name2; int score1, score2;
                    cout << "Enter Player 1 name and score: "; cin >> name1 >> score1;
                    cout << "Enter Player 2 name and score: "; cin >> name2 >> score2;
                    addMatchCmd(name1, score1, name2, score2);
                    break;
                }
                case 2: showRankings(); break;
                case 3: {
                    string name;
                    cout << "Enter player name: "; cin >> name;
                    showPlayerInfo(name);
                    break;
                }
                case 4: showMatchHistory(); break;
                case 5: resetTournament(); break;
                case 0:
                    setColor(10); cout << "Exiting...\n"; resetColor(); break;
                default:
                    setColor(12); cout << "Invalid option.\n"; resetColor();
            }

            if (option != 0) {
                cout << "\nPress Enter to continue...";
                cin.ignore(); cin.get();
            }

        } while (option != 0);

        return 0;
    }

    string cmd = argv[1];

    if (cmd == "add_match" && argc == 6) {
        string p1 = argv[2];
        int s1 = stoi(argv[3]);
        string p2 = argv[4];
        int s2 = stoi(argv[5]);
        addMatchCmd(p1, s1, p2, s2);

    } else if (cmd == "match_history") {
        showMatchHistory();

    } else if (cmd == "list_players") {
        printVector(players);

    } else if (cmd == "show_rankings") {
        showRankings();

    } else if (cmd == "show_player" && argc == 3) {
        showPlayerInfo(argv[2]);

    } else if (cmd == "reset") {
        resetTournament();

    } else {
        setColor(12); cout << "Invalid command or parameters.\n"; resetColor();
    }

    return 0;
}
