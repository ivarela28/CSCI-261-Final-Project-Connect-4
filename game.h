//
// Created by ivar0 on 4/23/2020.
//

#ifndef FINALPROJECT_GAME_H
#define FINALPROJECT_GAME_H
#include <string>
using namespace std;



class game {
private:
    static const int _rows = 6, _cols = 7;
public:
    //I tried to initialize the game board array to be empty (filled with spaces) in a more sleek way than this but I kept getting errors.
    //char _sq[_rows][_cols] = {' '};
    char _sq[_rows][_cols] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '}
                            , {' ', ' ', ' ', ' ', ' ', ' ', ' '}
                            , {' ', ' ', ' ', ' ', ' ', ' ', ' '}
                            , {' ', ' ', ' ', ' ', ' ', ' ', ' '}
                            , {' ', ' ', ' ', ' ', ' ', ' ', ' '}
                            , {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    //game();
    void board(char sq[_rows][_cols]) const;
    bool checkMove(int col, char (&sq)[_rows][_cols]) const;
    void playerTurn(int col, char (&sq)[_rows][_cols]);
    void computerTurn(char (&sq)[_rows][_cols]);
    bool checkWin(char mark, char sq[_rows][_cols]) const;
    bool checkFull(char sq[_rows][_cols]) const;
    void printResults(char sq[_rows][_cols], string winner) const;
};


#endif //FINALPROJECT_GAME_H
