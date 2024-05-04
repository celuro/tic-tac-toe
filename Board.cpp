#include "Board.h"


Board::Board()
{
  defaultBoardCells();
}

void Board::defaultBoardCells()
{
  // We need to clear previous player positions or get ready for a new game
  BoardCell cell = BoardCell::Empty;
  char empty = static_cast<char>(cell); // I need to collect the value of the empty variable
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = empty;
    }
  }
}

char Board::playerInput(int playerID)
{
  int row = 0;
  int column = 0;

  std::cout << "Please enter your position starting with the row: ";
  std::cin >> row;
  std::cout << "Please enter the column: ";
  std::cin >> column;
  // You can not put an X or O that's not on the board
  if ((row < 0 || row > 2) || (column < 0 || row > 2)) {
    std::cerr << "ERROR: Given position on board is invalid, must be inside the 3x3 matrix.\n";
    return '.';
  }
  else if ((board[row][column] == 'X') || (board[row][column] == 'O')) {
    std::cerr << "ERROR: Position on the board is taken.\n";
    return '.';
  }
  else {
    if (playerID == 1) {
      PlayerSymbol playerOne = PlayerSymbol::X;
      char X = static_cast<char>(playerOne);
      board[row][column] = X;
      return 'X';
    }
    else {
      PlayerSymbol playerTwo = PlayerSymbol::O;
      char O = static_cast<char>(playerTwo);
      board[row][column] = O;
      return 'O';
    }
  }
}

void Board::displayBoard()
{
  for (int i = 0; i < 3; i++) {
    std::cout << "-------\n";
    std::cout << '|';
    for (int j = 0; j < 3; j++) {
      std::cout << board[i][j] << '|';
    }
    std::cout << '\n';
  }
  std::cout << "-------\n";
}

bool Board::didPlayerWin()
{
  // Player wins if their symbol covers 3 spaces vertically, horizontally or diagonally
  PlayerSymbol playerOne = PlayerSymbol::X;
  char X = static_cast<char>(playerOne);
  PlayerSymbol playerTwo = PlayerSymbol::O;
  char O = static_cast<char>(playerTwo);

  bool playerOneWin = checkPossibleWins(X);
  bool playerTwoWin = checkPossibleWins(O);
  if (playerOneWin == true) {
    std::cout << "Player One Won!\n";
    return playerOneWin;
  }
  else if (playerTwoWin == true) {
    std::cout << "Player Two Won!\n";
    return playerTwoWin;
  }
  else {
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
  if (((board[0][0] == symbol) && (board[1][0] == symbol) && (board[2][0] == symbol)) ||
      ((board[0][1] == symbol) && (board[1][1] == symbol) && (board[2][1] == symbol)) ||
      ((board[0][2] == symbol) && (board[1][2] == symbol) && (board[2][2] == symbol)))
  {
    return true;
  }
  // If a player fills A1-A3 or B1-B3 pr C1-C3, they have won horizonatally
  else if (((board[0][0] == symbol) && (board[0][1] == symbol) && (board[0][2] == symbol)) ||
           ((board[1][0] == symbol) && (board[1][1] == symbol) && (board[1][2] == symbol)) ||
           ((board[2][0] == symbol) && (board[2][1] == symbol) && (board[2][2] == symbol)))
  {
    return true;
  }
  // If a player fills A1, B1, C2 or A3, B2, C1, they have won diagonally
  else if (((board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] == symbol)) ||
           ((board[0][2] == symbol) && (board[1][1] == symbol) && (board[2][0] == symbol)))
  {
    return true;
  }
  else {
    return false;
  }
}
