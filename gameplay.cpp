#include "gameplay.hpp"


#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <iomanip>


GamePlay::GamePlay()
{
    moveCounter = 0;

    horizontalTracker = new int(board.getBoardWidth());

    //ctor
}

/*
* Description:
* Input:
* Output:
*/
GamePlay::~GamePlay()
{
    //dtor
}

/*
* Description: initializes elements in the horizontalTracker
*              array to zero
* Input:
* Output:
*/
void GamePlay::initializeHorizontalTracker(){
    for(int width = 0; width < board.getBoardWidth(); width++){
        horizontalTracker[width] = 0;
    }
}

void GamePlay::setPlayerPieces(){

    int userChoice;
    bool endLoop = false;
    std::cout << "Pick your piece:" << std::endl;
    std::cout << "1.) X" << std::endl;
    std::cout << "2.) O" << std::endl;

    while(!endLoop){
        std::cin >> userChoice;

        switch(userChoice){

            case 1: {
                  playerOne = 'X';
                  playerTwo = 'O';
                  endLoop = true;
                  break;
            }

            case 2: {
                    playerOne = 'O';
                    playerTwo = 'X';
                    endLoop = true;
                    break;
            }

            default: {
                std::cout << "Invalid entry. Please re-enter." << std::endl;
                break;
            }
        }
    }
}

void GamePlay::playGame(){

    int userMove;
    int takeTurns = 2;
    int playerTwoRandomNumber;

    bool endGame = false;
    bool testUserInput;
    bool boardIsFull = false;
    bool checkPlayerWon = false;

    initializeHorizontalTracker();


    while(!endGame){

        bool successfulMovePlayerOne = false;
        bool successfulMovePlayerTwo = false;

        //check if board is full
        boardIsFull = board.isBoardFull(moveCounter);

        if(boardIsFull == true){
            break;
        }

        if(takeTurns % 2 == 0){
            while(!successfulMovePlayerOne){
                //playerOne enters move
                std::cout << "Enter the tile in which you wish to move: ";
                std::cin >> userMove;

                //input validation; check for input of integers 1 - 9
                testUserInput = userImputValidation(userMove);

                if(testUserInput == false){
                    std::cout << "Invalid entry. Please re-enter." << std::endl;
                }
                else if(testUserInput == true){
                    //make move; if tile is already taken, move is not successful
                    successfulMovePlayerOne = board.updateBoard(userMove, playerOne);
                }

                if(successfulMovePlayerOne == false){
                    std::cout << "That space is already taken. Pick another space." << std::endl;
                }

                //clear buffer stream
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                checkPlayerWon = horrizontalScan(playerOne);
                if(checkPlayerWon == true){
                        std::cout << "Player one wins game!" << std::endl;
                }
            }

            moveCounter++; //account for board filling up
            takeTurns++; //next players turn
        }

        else{

            while(!successfulMovePlayerTwo){
                playerTwoRandomNumber = (rand() % 9 + 1);
                successfulMovePlayerTwo = board.updateBoard(playerTwoRandomNumber, playerTwo);
            }

            moveCounter++;
            takeTurns++;
        }

        board.printBoard();
    }

    printHorizontalTracker();
}


bool GamePlay::userImputValidation(int userChoice){

    switch(userChoice){

        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:{
            return true;
            break;
        }

        default:{
            return false;
            break;
        }
    }
}


bool GamePlay::horrizontalScan(string playerPiece){

    int inARow = 0;

    initializeHorizontalTracker();

    for(int height = 0; height < board.getBoardHeigth(); height++)
    {

        for(int width = 0; width < board.getBoardWidth(); width++)
        {

                if(board.getBoardPiece(height, width) == playerPiece)
                {
                    horizontalTracker[height]++;
                }
        }
        if(horizontalTracker[height] == 3)
        {
            return true;
        }
    }
    return false;
}



void GamePlay::printHorizontalTracker(){

    for(int x = 0; x < board.getBoardWidth(); x++){
        std::cout << horizontalTracker[x] << " ";
    }
}



            /*
            if(board.searchBoard(playerPiece, height, width) == true){
                inARow++;
            }
            std::cout << "inARow: " << inARow << std::endl;

            if(inARow == 3){
                std::cout << "WINS!!!!" << std::endl;
                break;
            }*/
