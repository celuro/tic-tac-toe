/******************************************************************************
* @file Board.h
* @brief Manages the board state during the game
* 
* Purpose: This file repesents a single instance of the tic tac toe board
* needed to play this game. It handles player input, win condition and
* displaying the board.
* 
* @author mimikyumom.
* @bug No known bugs
******************************************************************************/

#ifndef BOARD_H
#define BOARD_H

#define MAX_BOARD_SIZE 3
#define INITIALIZE 0
#define MIN_ROW 0
#define MAX_ROW 2
#define MIN_COLUMN 0
#define MAX_COLUMN 2

#define PLAYER_ONE 1
#define PLAYER_TWO 2

#define ROW_ONE 0
#define ROW_TWO 1
#define ROW_THREE 2
#define COLUMN_ONE 0
#define COLUMN_TWO 1
#define COLUMN_THREE 2

#define PLAYER_ONE_SYMBOL 'X'
#define PLAYER_TWO_SYMBOL 'O'
#define EMPTY_SYMBOL '.'

#define INCREMENT 1
#define MAX_BOARD_SPACES 9

#include <iostream>

class Board
{
private:
  char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
  enum class PlayerSymbol : char 
    {X = PLAYER_ONE_SYMBOL, O = PLAYER_TWO_SYMBOL};
  enum class BoardCell : char 
    {X = PLAYER_ONE_SYMBOL, O = PLAYER_TWO_SYMBOL, Empty = EMPTY_SYMBOL };
public:
  Board();
  void defaultBoardCells();
  char playerInput(int playerID);
  void displayBoard() const;
  bool didPlayerWin(std::string name) const;
  bool checkPossibleWins(char symbol) const;
  bool checkPossibleTie() const;
};
#endif BOARD_H