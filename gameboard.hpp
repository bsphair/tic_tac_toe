#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <string>

using std::string;

class GameBoard
{

    private:
        int boardHeight;
        int boardWidth;

        string **board;

        int totalSpacesFilled;

    public:
        GameBoard();
        virtual ~GameBoard();

        int getBoardHeigth();
        int getBoardWidth();

        bool searchBoard(string, int, int);

        string getBoardPiece(int, int);

        void initializeGameBoard();

        void printBoard();

        void instructions();

        bool updateBoard(int, string);

        bool isBoardFull(int);







};

#endif // GAMEBOARD_H
