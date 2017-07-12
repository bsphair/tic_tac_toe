#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <gameboard.hpp>
#include <string>



class GamePlay
{
    protected:
        std::string playerOne;
        std::string playerTwo;
        GameBoard board;

        int moveCounter;

        int *horizontalTracker;
        int *verticalTracker;




    public:
        GamePlay();
        virtual ~GamePlay();

        void initializeHorizontalTracker();
        void initializeVerticalTracker();

        void printHorizontalTracker();

        void setPlayerPieces();

        void playGame();

        bool userImputValidation(int);

        bool horrizontalScan(string);
        bool verticalScan(string);
        bool diagonalScan(string);

};

#endif // GAMEPLAY_H
