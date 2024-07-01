#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>

using namespace std;

// class definition 
class GameBoard {
private:
  // variables for the game board
  static const char EMPTY_SLOT = ' ';
  int rows;
  int columns;
  vector<vector<char>> board;

public:
  // constructor
  GameBoard(int rows, int columns);

  // functions regarding the game board
  void displayBoard() const;
  bool updateBoard(int column, char disc);
  bool checkWin() const;
  bool checkDraw() const;
  bool isColumnFull(int column) const;
  void resetBoard();
  bool isColumnValid(int column) const;
};

#endif