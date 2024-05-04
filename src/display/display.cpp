/******************************************************************************
* @file display.cpp
* @brief Implements behaviour responsible for showing key events of the game
*
* Purpose: This file indicates to the user when the game loads, game starts and
* when the game is over.
*
* @author mimikyumom.
* @bug No known bugs
******************************************************************************/

#include "../../include/display/display.h"

void displayTitle() {
  std::cout << R"( .-') _                           .-') _      ('-.                      .-') _                   ('-.   
(  OO) )                         (  OO) )    ( OO ).-.                 (  OO) )                _(  OO)  
/     '._ ,-.-')   .-----.       /     '._   / . --. /   .-----.       /     '._  .-'),-----. (,------. 
|'--...__)|  |OO) '  .--./       |'--...__)  | \-.  \   '  .--./       |'--...__)( OO'  .-.  ' |  .---' 
'--.  .--'|  |  \ |  |('-.       '--.  .--'.-'-'  |  |  |  |('-.       '--.  .--'/   |  | |  | |  |     
   |  |   |  |(_//_) |OO  )         |  |    \| |_.'  | /_) |OO  )         |  |   \_) |  |\|  |(|  '--.  
   |  |  ,|  |_.'||  |`-'|          |  |     |  .-.  | ||  |`-'|          |  |     \ |  | |  | |  .--'  
   |  | (_|  |  (_'  '--'\          |  |     |  | |  |(_'  '--'\          |  |      `'  '-'  ' |  `---. 
   `--'   `--'     `-----'          `--'     `--' `--'   `-----'          `--'        `-----'  `------')";
  std::cout << "\n\n";
}

void startingConfirmation()
{
  std::cout << R"(  .-')    .-') _      ('-.     _  .-')   .-') _               .-') _             
 ( OO ). (  OO) )    ( OO ).-.( \( -O ) (  OO) )             ( OO ) )            
(_)---\_)/     '._   / . --. / ,------. /     '._ ,-.-') ,--./ ,--,'  ,----.     
/    _ | |'--...__)  | \-.  \  |   /`. '|'--...__)|  |OO)|   \ |  |\ '  .-./-')  
\  :` `. '--.  .--'.-'-'  |  | |  /  | |'--.  .--'|  |  \|    \|  | )|  |_( O- ) 
 '..`''.)   |  |    \| |_.'  | |  |_.' |   |  |   |  |(_/|  .     |/ |  | .--, \ 
.-._)   \   |  |     |  .-.  | |  .  '.'   |  |  ,|  |_.'|  |\    | (|  | '. (_/ 
\       /   |  |     |  | |  | |  |\  \    |  | (_|  |   |  | \   |  |  '--'  |  
 `-----'    `--'     `--' `--' `--' '--'   `--'   `--'   `--'  `--'   `------' )";
  std::cout << "\n\n";
}

void gameOver()
{
  std::cout << R"(               ('-.     _   .-')       ('-.                           (`-.      ('-.  _  .-')   
              ( OO ).-.( '.( OO )_   _(  OO)                        _(OO  )_  _(  OO)( \( -O )  
  ,----.      / . --. / ,--.   ,--.)(,------.       .-'),-----. ,--(_/   ,. \(,------.,------.  
 '  .-./-')   | \-.  \  |   `.'   |  |  .---'      ( OO'  .-.  '\   \   /(__/ |  .---'|   /`. ' 
 |  |_( O- ).-'-'  |  | |         |  |  |          /   |  | |  | \   \ /   /  |  |    |  /  | | 
 |  | .--, \ \| |_.'  | |  |'.'|  | (|  '--.       \_) |  |\|  |  \   '   /, (|  '--. |  |_.' | 
(|  | '. (_/  |  .-.  | |  |   |  |  |  .--'         \ |  | |  |   \     /__) |  .--' |  .  '.' 
 |  '--'  |   |  | |  | |  |   |  |  |  `---.         `'  '-'  '    \   /     |  `---.|  |\  \  
  `------'    `--' `--' `--'   `--'  `------'           `-----'      `-'      `------'`--' '--')";
}