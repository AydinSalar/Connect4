#include "Player.h"
#include <iostream>
#include <limits>

using namespace std;

Player::Player(const string& name, char discSymbol) : name(name), discSymbol(discSymbol) {}

string Player::getName() const {
  return name;
}

char Player::getDiscSymbol() const {
  return discSymbol;
}

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
    
  } while (!validMove);

  board.updateBoard(column, discSymbol);
}