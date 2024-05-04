/******************************************************************************
* @file gameState.h
* @brief Defines logic related to handling the win condition for the game
* and the name of the players
*
* Purpose: This file defiied the behaviour needed to manage the game loop
* of the program.
* 
*
* @author mimikyumom.
* @bug No known bugs
******************************************************************************/

#ifndef GAME_STATE_H
#define GAME_STATE_H

#define FIRST_TURN 1
#define PLAYER_ONE 1
#define PLAYER_TWO 2

#include <string>
#include <iostream>
#include "../../include/board/Board.h"
#include "../../include/player/Player.h"

std::string playerNameInput(std::string player);
bool manageInput(Player& player, Board& gameBoard);
#endif
#include <Board.h>
