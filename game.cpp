//
// Created by ivar0 on 4/23/2020.
//

#include "game.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//another failed attempt at initializing the game board, using a constructor
/*game::game(){
    _sq[][3] = {' '};
}*/

//displays board
void game::board(char sq[_rows][_cols]) const{
    for (int i = 0; i < _rows; i++){
        cout << "-----------------------------" << endl << '|';
        for (int j = 0; j < _cols; j++){
            cout << " " << sq[i][j] << " |";
        }
        cout << endl;
    }
    cout << "-----------------------------" << endl;
    cout << "  1   2   3   4   5   6   7  " << endl;
}

//checks if column selection is valid
bool game::checkMove(int col, char (&sq)[_rows][_cols]) const {
    bool move = false;
    //checks that column is 1-7
    if (col < 0 || col > 6){
        return false;
    }

    //checks that column is not already full
    for (int i = _rows - 1; i >= 0 ; i--){
        if (sq[i][col] == ' ') {
            move = true;
            break;
        }
    }
    return move;
}

//modifies board according to player input
void game::playerTurn(int col, char (&sq)[_rows][_cols]) {
    int row;

    //places marker on the lowest empty space of the chosen column
    for (int i = _rows - 1; i >= 0 ; i--){
        if (sq[i][col] == ' ') {
            row = i;
            break;
        }
    }
        sq[row][col] = 'X';
}

//modifies board according to random generator
void game::computerTurn(char (&sq)[_rows][_cols]) {
    //seed rand generator
    srand(time(0));
    //throw away first value
    rand();
    while (true) {
        //random column
        int col = rand() % _cols;
        //check that column is valid play
        if(checkMove(col, sq)){
            int row;
            //place marker in lowest available spot
            for (int i = _rows - 1; i >= 0 ; i--){
                if (sq[i][col] == ' ') {
                    row = i;
                    break;
                }
            }
            sq[row][col] = 'O';
            break;
        }
    }
}

//checks if there is a winning condition for a given character
bool game::checkWin(char mark, char sq[_rows][_cols]) const{

    //Horizontal win
    //Iterates through each element in the array, and checks the subsequent elements in the same row for the given character
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols - 3; j++) {
            if (sq[i][j] == mark && sq[i][j + 1] == mark && sq[i][j + 2] == mark && sq[i][j + 3] == mark) {
                cout << "Horizontal win, row " << i + 1 << endl;
                return true;
            }
        }
    }

    //Vertical win
    //same as horizontal, but checking the column of a certain element instead of the row
    for (int i = 0; i < _rows - 3; i++) {
        for (int j = 0; j < _cols; j++) {
            if (sq[i][j] == mark && sq[i + 1][j] == mark && sq[i + 2][j] == mark && sq[i + 3][j] == mark) {
                cout << "Vertical win, col " << j + 1 << endl;
                return true;
            }
        }
    }

    //Diagonal win
    //Same as first two, but increase both row and column
    for (int i = 0; i < _rows - 3; i++) {
        for (int j = 0; j < _cols - 3; j++) {
            if (sq[i][j] == mark && sq[i + 1][j + 1] == mark && sq[i + 2][j + 2] == mark && sq[i + 3][j + 3] == mark) {
                cout << "Diagonal win" << endl;
                return true;
            }
        }
    }

    //Antidiagonal win
    //same as diagonal, but increase row while decreasing column
    for (int i = 0; i < _rows - 3; i++) {
        for (int j = _cols - 4; j < _cols; j++) {
            if (sq[i][j] == mark && sq[i + 1][j - 1] == mark && sq[i + 2][j - 2] == mark && sq[i + 3][j - 3] == mark) {
                cout << "Antidiagonal win" << endl;
                return true;
            }
        }
    }

    return false;
}

//checks if all spots on the board are filled, if so ends game
bool game::checkFull(char sq[_rows][_cols]) const{
    for (int i = 0; i < _rows; i++){
        for (int j = 0; j < _cols; j++){
            if (sq[i][j] == ' ')
                return false;
        }
    }
    return true;
}

//creates a file with the final gameboard and the winner
void game::printResults(char sq[_rows][_cols], string winner) const {
    ofstream out("results.txt");

    for (int i = 0; i < _rows; i++){
        out << "-----------------------------" << endl << '|';
        for (int j = 0; j < _cols; j++){
            out << " " << sq[i][j] << " |";
        }
        out << endl;
    }
    out << "-----------------------------" << endl;
    out << "  1   2   3   4   5   6   7  " << endl;
    out << winner << " victory!";
}