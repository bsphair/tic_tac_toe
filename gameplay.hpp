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


    public:
        GamePlay();
        virtual ~GamePlay();

        void initializeHorizontalTracker();
        void printHorizontalTracker();

        void setPlayerPieces();

        void playGame();

        bool userImputValidation(int);

        bool horrizontalScan(string);

};

#endif // GAMEPLAY_H
