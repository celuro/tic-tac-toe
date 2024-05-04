#include "Board.h"

int main(void) {
  Board gameBoard;
  std::cout << "Weclome to Tic-Tac-Toe!\n";
  std::cout << "=======================\n";
  std::cout << "Starting...\n";
  gameBoard.displayBoard();

  // These are player ID's so that the game knows who they are
  int playerOne = 1;
  int playerTwo = 2;

  bool gameFinished = gameBoard.didPlayerWin();
  int turn = 1;

  while (gameFinished == false) {
    std::cout << "Turn " << turn << '\n';
    // This Stimulates turn based gameplay
    std::cout << "Player One Input: ";
    gameBoard.playerInput(1);
    gameBoard.displayBoard();
    gameFinished = gameBoard.didPlayerWin();
    if (gameFinished) {
      break;
    }
    
    std::cout << "Player Two Input: ";
    gameBoard.playerInput(2);
    gameBoard.displayBoard();
    gameFinished = gameBoard.didPlayerWin();
    if (gameFinished) {
      break;
    }

    //Needs to update the game loop to represent the turn
    turn += 1;
  }
}
