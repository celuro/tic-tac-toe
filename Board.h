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

#include <iostream>

class Board
{
private:
  enum class PlayerSymbol : char {X = 'X', O = 'O'};
  enum class BoardCell : char {X = 'X', O = 'O', Empty = '.' };
  char board[3][3];
public:
  Board();
  void defaultBoardCells();
  char playerInput(int playerID);
  void displayBoard();
  bool didPlayerWin();
  bool checkPossibleWins(char symbol) const;
};
#endif BOARD_H
