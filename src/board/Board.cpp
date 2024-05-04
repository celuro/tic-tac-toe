/******************************************************************************
* @file Board.cpp
* @brief Implements the constructor and member functions related to the Board
* class
*
* Purpose: This file implements the behaviour related to the board for the 
* game. It handles player input, clearing the board, displaying the board
* and checking win conditions.
*
* @author mimikyumom.
* @bug No known bugs
******************************************************************************/
#include "../include/board/Board.h"

Board::Board()
{
  defaultBoardCells();
}

void Board::defaultBoardCells()
{
  // We need to clear previous player positions or get ready for a new game
  BoardCell cell = BoardCell::Empty;
  char empty = static_cast<char>(cell); // I need to collect the value of the empty variable
  for (int i = INITIALIZE; i < MAX_BOARD_SIZE; i++) {
    for (int j = INITIALIZE; j < MAX_BOARD_SIZE; j++) {
      board[i][j] = empty;
    }
  }
}

char Board::playerInput(int playerID)
{
  int row = INITIALIZE;
  int column = INITIALIZE;

  std::cout << "Please enter your position starting with the row: ";
  std::cin >> row;
  std::cout << "Please enter the column: ";
  std::cin >> column;
  // You can not put an X or an O that's not on the board
  if ((row < MIN_ROW || row > MAX_ROW) || 
      (column < MIN_COLUMN || row > MAX_COLUMN)) 
  {
    std::cerr << "ERROR: Given position on board is invalid.\n";
    return EMPTY_SYMBOL;
  }
  // You can't put an X or an O that's already on the board
  else if ((board[row][column] == PLAYER_ONE_SYMBOL) ||
           (board[row][column] == PLAYER_TWO_SYMBOL)) 
  {
    std::cerr << "ERROR: Position on the board is taken.\n";
    return EMPTY_SYMBOL;
  }
  else {
    if (playerID == PLAYER_ONE) {
      PlayerSymbol playerOne = PlayerSymbol::X;
      char X = static_cast<char>(playerOne);
      board[row][column] = X;
      return PLAYER_ONE_SYMBOL;
    }
    else if(playerID == PLAYER_TWO){
      PlayerSymbol playerTwo = PlayerSymbol::O;
      char O = static_cast<char>(playerTwo);
      board[row][column] = O;
      return PLAYER_TWO_SYMBOL;
    }
    else {
      return '.';
    }
  }
}

void Board::displayBoard() const
{
  for (int i = INITIALIZE; i < MAX_BOARD_SIZE; i++) {
    std::cout << "-------\n";
    std::cout << '|';
    for (int j = INITIALIZE; j < MAX_BOARD_SIZE; j++) {
      std::cout << board[i][j] << '|';
    }
    std::cout << '\n';
  }
  std::cout << "-------\n";
}

bool Board::didPlayerWin(std::string name) const
{
  // Player wins if their symbol covers 3 spaces vertically, horizontally or diagonally
  PlayerSymbol playerOne = PlayerSymbol::X;
  char X = static_cast<char>(playerOne);
  PlayerSymbol playerTwo = PlayerSymbol::O;
  char O = static_cast<char>(playerTwo);

  bool playerOneWin = checkPossibleWins(X);
  bool playerTwoWin = checkPossibleWins(O);

  if (playerOneWin == true) {
    std::cout << name << " Won!\n";
    return playerOneWin;
  }
  else if (playerTwoWin == true) {
    std::cout << name << " Won!\n";
    return playerTwoWin;
  }
  else {
    bool tie = checkPossibleTie();
    if (tie == true) {
      std::cout << "Tie!\n";
    }
      return false;
    }
}

bool Board::checkPossibleWins(char symbol) const
{
  /****************************************************************************
  * Player wins if their symbol covers 3 spaces vertically, horizontally or diagonally
  * Represenation of the board:
  * A1 A2 A3
  * B1 B2 B3
  * C1 C2 C2
  */

  // If a player fills A1-C1 or A2-C2 or A3-B3, they have won vertically
  if (((board[ROW_ONE][COLUMN_ONE] == symbol) &&
       (board[ROW_TWO][COLUMN_ONE] == symbol) &&
       (board[ROW_THREE][COLUMN_ONE] == symbol)) ||

      ((board[ROW_ONE][COLUMN_TWO] == symbol) &&
       (board[ROW_TWO][COLUMN_TWO] == symbol) &&
       (board[ROW_THREE][COLUMN_TWO] == symbol)) ||

      ((board[ROW_ONE][COLUMN_THREE] == symbol) &&
       (board[ROW_TWO][COLUMN_THREE] == symbol) &&
       (board[ROW_THREE][COLUMN_THREE] == symbol)))
  {
    return true;
  }
  // If a player fills A1-A3 or B1-B3 pr C1-C3, they have won horizonatally
  else if (((board[ROW_ONE][COLUMN_ONE] == symbol) &&
            (board[ROW_ONE][COLUMN_TWO] == symbol) &&
            (board[ROW_ONE][COLUMN_THREE] == symbol)) ||

           ((board[ROW_TWO][COLUMN_ONE] == symbol) &&
            (board[ROW_TWO][COLUMN_TWO] == symbol) &&
            (board[ROW_TWO][COLUMN_THREE] == symbol)) ||

           ((board[ROW_THREE][COLUMN_ONE] == symbol) &&
            (board[ROW_THREE][COLUMN_TWO] == symbol) &&
            (board[ROW_THREE][COLUMN_THREE] == symbol)))
  {
    return true;
  }
  // If a player fills A1, B1, C2 or A3, B2, C1, they have won diagonally
  else if (((board[ROW_ONE][COLUMN_ONE] == symbol) &&
            (board[ROW_TWO][COLUMN_TWO] == symbol) &&
            (board[ROW_THREE][COLUMN_THREE] == symbol)) ||

           ((board[ROW_ONE][COLUMN_THREE] == symbol) &&
            (board[ROW_TWO][COLUMN_TWO] == symbol) &&
            (board[ROW_THREE][COLUMN_ONE] == symbol)))
  {
    return true;
  }
  else {
    return false;
  }
}

bool Board::checkPossibleTie() const
{
  bool didPlayerOneWin = checkPossibleWins(PLAYER_ONE_SYMBOL);
  bool didPlayerTwoWin = checkPossibleWins(PLAYER_TWO_SYMBOL);

  // If each position on the board is filled that means it's a tie
  int sum = INITIALIZE;

  for (int i = INITIALIZE; i < MAX_BOARD_SIZE; i++) {
    for (int j = INITIALIZE; j < MAX_BOARD_SIZE; j++) {
      if (board[i][j] == PLAYER_ONE_SYMBOL || board[i][j] == PLAYER_TWO_SYMBOL){
        sum += INCREMENT;
      }
    }
  }

  if (!didPlayerOneWin && !didPlayerTwoWin && sum == MAX_BOARD_SPACES) {
    return true;
  }
  else {
    return false;
  }
}
