#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <GameBoard.hpp>
#include <string>



class GamePlay
{
    protected:
        std::string playerOne;
        std::string playerTwo;
        GameBoard board;

        int moveCounter;


    public:
        GamePlay();
        virtual ~GamePlay();

        void setPlayerPieces();

        void playGame();

        bool userImputValidation(int);



};

#endif // GAMEPLAY_H
