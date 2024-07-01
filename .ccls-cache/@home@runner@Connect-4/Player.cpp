#include "Player.h"
#include <iostream>
#include <limits>

using namespace std;

// player name and symbol
Player::Player(const string& name, char discSymbol) : name(name), discSymbol(discSymbol) {}

// get player name
string Player::getName() const {
  return name;
}

// get player symbol
char Player::getDiscSymbol() const {
  return discSymbol;
}

// get player move
void Player::makeMove(GameBoard& board){
  int column;
  bool validMove = false;

  do {
    cout << name << ", enter the column number (1-7) to drop your disc: ";
    cin >> column;

    if(cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter a number between 1 and 7." << endl;
      continue;
    }

    if (board.isColumnValid(column) && !board.isColumnFull(column)){
      validMove = true;
    } else {
      cout << "Invalid move. Try again." << endl;
    }
    
  } while (!validMove); // ..end do-while loop

  board.updateBoard(column, discSymbol);
}// ..end makeMove()