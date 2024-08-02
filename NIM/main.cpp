//
//  main.cpp
//  NIM
//
//  Created by Anyu Gu on 7/15/24.
//

#include <iostream>

using namespace std;

void outputRules() {
    cout << "Welcome to NIM. Your objective is to be the one to reach 0 starting from 25." << endl << "You can move in steps of 1, 3, or 4 in a turn. You can play in single player mode against a computer following the same rules, or you can play against another player. Good luck!" << endl;
}
int modeSelection() {
    int input;
    cout << "Please enter the number of players: ";
    cin >> input;
    while (input < 1 || input > 2) {
        cout << "Invalid number of players. Please enter the number of players: ";
        cin >> input;
    }
    return input;
}
bool checkUserInput(int input, int pile) {
    bool isValid(true);
    if (input == 1 || input == 3 || input == 4) {
        if (pile - input >= 0) {
            isValid = true;
        }
        else {
            isValid = false;
        }
    }
    else {
        isValid = false;
    }
    return isValid;
}
bool checkRobotSelection (int pile, int move) {
    if (pile - move >= 0) {
        return true;
    }
    else {
        return false;
    }
}
void robotSelection(int & pile) {
    srand((int)time(0));
    int remainder = pile % 7;
    if (remainder == 1 && checkRobotSelection(pile, 1)) {
        pile -= 1;
        cout << "The computer has removed 1 stone" << endl;
    }
    else if ((remainder == 3 || remainder == 5) && checkRobotSelection(pile, 3)) {
        pile -= 3;
        cout << "The computer has removed 3 stone" << endl;
    }
    else if ((remainder == 4 || remainder == 6) && checkRobotSelection(pile, 4)) {
        pile -= 4;
        cout << "The computer has removed 4 stones" << endl;
    }
    else {
        int x = rand() % 10;
        if (x >= 0 && x <= 3 && checkRobotSelection(pile, 4)) {
            pile -= 4;
            cout << "The computer has removed 4 stones" << endl;
        }
        else if (x < 7 && checkRobotSelection(pile, 3)) {
            pile -= 3;
            cout << "The computer has removed 3 stones" << endl;
        }
        else {
            pile -= 1;
            cout << "The computer has removed 1 stone" << endl;
        }
    }
    cout << "Pile: " << pile << endl;
}
int main() {
    int pile = 25;
    int i = 1;
    int userInput, mode;
    bool gameEnd = false;
    outputRules();
    mode = modeSelection();
    if (mode == 1) {
        cout << "You have chosen singleplayer mode." << endl << endl;
    }
    else {
        cout << "You have chosen multiplayer mode." << endl << endl;
    }
    cout << "Pile: " << pile << endl;
    while (!gameEnd) {
        cout << "Turn " << i << endl;
        cout << "Please choose a number: ";
        cin >> userInput;
        while (!checkUserInput(userInput, pile)) {
            cout << "Your number is invalid. Please choose a new number: ";
            cin >> userInput;
        }
        pile -= userInput;
        cout << "Player 1 has removed " << userInput << " stone(s)" << endl;
        cout << "Pile: " << pile << endl;
        if (mode == 1) {
            if (pile != 0) {
                robotSelection(pile);
                i++;
                if (pile == 0) {
                    gameEnd = true;
                    cout << "Better luck next time : (" << endl;
                }
            }
            else {
                gameEnd = true;
                cout << "Congratulations! You Win!" << endl;
            }
        }
        else {
            if (pile != 0) {
                cout << "Please choose a number: ";
                cin >> userInput;
                while (!checkUserInput(userInput, pile)) {
                    cout << "Your number is invalid. Please choose a new number: ";
                    cin >> userInput;
                }
                cout << "Player 2 has removed " << userInput << " stone(s)" << endl;
                pile -= userInput;
                i++;
                cout << "Pile: " << pile << endl;
                if (pile == 0) {
                    gameEnd = true;
                    cout << "Player 2 wins! Congratulations!" << endl;
                }
            }
            else {
                gameEnd = true;
                cout << "Player 1 wins! Congratulations!" << endl;
            }
        }
    }
    return 0;
}
