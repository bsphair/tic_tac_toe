#include <iostream>

#include <gameboard.hpp>
#include <gameplay.hpp>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>



int main(){


    srand((int)(std::time(NULL)));

    //GameBoard board;
    GamePlay game;

    //board.initializeGameBoard();
   // board.printBoard();
   // board.instructions();

    game.setPlayerPieces();
    game.playGame();

    //game.makeMove();
    //board.updateBoard(2, "x");

    //board.printBoard();



    /*
        1. GamePlay has a GameBoard
        2. GameBoard CAN be private so main can't touch gameboard directly
        3. Initialization functions for gameboard can be a part of gameplay
        4. tell gameplay how to update its board but don't touch its board directly

     */




    return 0;
}






