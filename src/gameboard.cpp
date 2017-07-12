#include <iostream>
#include "gameboard.hpp"

using std::string;


GameBoard::GameBoard()
{
    boardHeight = 3;
    boardWidth = 3;

    int totalSpacesFilled;

    board = new string*[boardHeight];
    for(int x = 0; x < boardHeight; x++){
        board[x] = new string[boardWidth];
    }
}

GameBoard::~GameBoard()
{
    //dtor
}

int GameBoard::getBoardHeigth(){
    return boardHeight;
}

int GameBoard::getBoardWidth(){
    return boardWidth;
}


bool GameBoard::searchBoard(string playerPiece, int height, int width){

    /*for(int height = 0; height < boardHeight; height++) {
        for(int width = 0; width < boardWidth; width++){
                if(board[height][width] == playerPiece){
                    return true;
                }
        }
    }
    return false;*/
    if(board[height][width] == playerPiece){
        return true;
    }
    return false;

}

void GameBoard::initializeGameBoard(){

    for(int height = 0; height < boardHeight; height++) {
        for(int width = 0; width < boardWidth; width++){
            board[height][width] = '-';
        }
    }
}


void GameBoard::printBoard(){

    for(int height = 0; height < boardHeight; height++) {
        for(int width = 0; width < boardWidth; width++){
                std::cout << board[height][width];
                if(width < boardWidth - 1){
                    std::cout << " | ";
                }
        }
        if(height < boardHeight - 1){
            std::cout << "\n----------" << std::endl;
        }
    }
    std::cout<<std::endl;
}


void GameBoard::instructions(){

    int tempArray[3][3] = {{1, 2, 3}, {4, 5, 6}, { 7, 8, 9}};

    std::cout << "Game Board Layout\n" << std::endl;

    for(int height = 0; height < 3; height++) {
        for(int width = 0; width < 3; width++){
                std::cout << tempArray[height][width];
                if(width < 2){
                    std::cout << " | ";
                }
        }
        if(height < 2){
            std::cout << "\n----------" << std::endl;
        }
    }

    std::cout << "\n\nTo make your move, enter the number" << std::endl;
    std::cout << "it represents on the board." << std::endl;

}


bool GameBoard::updateBoard(int usersMove, string playerPiece){

    int counter = 0;
    int fullBoard = 0;

        for(int height = 0; height < 3; height++){
            for(int width = 0; width < 3; width++){
                counter++;
                if(usersMove == counter){
                    if(board[height][width] == "X" || board[height][width] == "O"){
                        return false;
                    }
                    else{
                        board[height][width] = playerPiece;
                    }
                }
            }
        }
        return true;
}


bool GameBoard::isBoardFull(int counter){

    /*int boardPieceCount = 0;
    int counter = 0;

    for(int height = 0; height < 3; height++){
        for(int width = 0; width < 3; width++){
            counter++;
            if(board[height][width] == "X" || board[height][width] == "O"){
                boardPieceCount++;
            }
        }
    }

    if(boardPieceCount == 9){
        return true;
    }
    else{
        return false;
    }*/
    totalSpacesFilled = boardHeight * boardWidth;

    if(counter == totalSpacesFilled){
        return true;
    }
    else{
        return false;
    }

}

string GameBoard::getBoardPiece(int height, int width){

    return board[height][width];
}







