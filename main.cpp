#include <iostream>
#include <fstream>
#include <zconf.h>
#include "game.h"
using namespace std;

int main() {
    //create game object
    game c4;
    int c;
    string winner;

    //Loops until user enters valid column
    while(true) {
        c4.board(c4._sq);
        cout << "Input move: ";
        while (true) {
            cin >> c;
            c--;
            if (c4.checkMove(c, c4._sq)) {
                c4.playerTurn(c, c4._sq);
                break;
            } else {
                cout << "Invalid move" << endl;
            }
        }

        //display updated board
        c4.board(c4._sq);

        //check if player's move was a winning move
        if (c4.checkWin('X', c4._sq)) {
            cout << "Player wins";
            winner = "Player";
            break;
        }

        //Computers turn, with pause to make it seem like theres actually some kind of processing happening
        cout << "Computer's Turn..." << endl;
        sleep(1);
        c4.computerTurn(c4._sq);

        //Check if computer won somehow
        if (c4.checkWin('O', c4._sq)) {
            c4.board(c4._sq);
            cout << "Computer Wins";
            winner = "Computer";
            break;
        }

        //Check that theres still playable spaces on board
        if (c4.checkFull(c4._sq)){
            cout << "Draw" << endl;
            break;
        }
    }

    c4.printResults(c4._sq, winner);

    return 0;
}
