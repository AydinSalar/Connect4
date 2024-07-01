// header file
#include "GameBoard.h"
#include <iostream>

using namespace std;

// default constructor for the GameBoard class
GameBoard::GameBoard(int rows, int columns)
    : rows(rows), columns(columns),
      board(rows, vector<char>(columns, EMPTY_SLOT)) {}

// function to display the game board
void GameBoard::displayBoard() const {
  cout << endl;
  for (const auto &row : board) {
    for (char cell : row) {
      cout << "| " << (cell == EMPTY_SLOT ? ' ' : cell) << " ";
    }
    cout << "|\n";
  }

  for (int i = 1; i <= columns; ++i) {
    cout << "  " << i << " ";
  }
  cout << endl;
}

// function to update the board
bool GameBoard::updateBoard(int column, char disc) {
  if (!isColumnValid(column) || isColumnFull(column)) {
    return false;
  }

  for (int row = rows - 1; row >= 0; --row) {
    if (board[row][column - 1] == EMPTY_SLOT) {
      board[row][column - 1] = disc;
      return true;
    }
  }

  return false;
}

// function to check for the win
bool GameBoard::checkWin() const {
  
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < columns - 3; ++col) {
      if (board[row][col] != EMPTY_SLOT &&
          board[row][col] == board[row][col + 1] &&
          board[row][col] == board[row][col + 2] &&
          board[row][col] == board[row][col + 3]) {
        return true;
      }
    }
  }

  for (int col = 0; col < columns; ++col) {
    for (int row = 0; row < rows - 3; ++row) {
      if (board[row][col] != EMPTY_SLOT &&
          board[row][col] == board[row + 1][col] &&
          board[row][col] == board[row + 2][col] &&
          board[row][col] == board[row + 3][col]) {
        return true;
      }
    }
  }

  for (int row = 0; row < rows - 3; ++row) {
    for (int col = 0; col < columns - 3; ++col) {
      if (board[row][col] != EMPTY_SLOT &&
          board[row][col] == board[row + 1][col + 1] &&
          board[row][col] == board[row + 2][col + 2] &&
          board[row][col] == board[row + 3][col + 3]) {
        return true;
      }
    }
  }

  for (int row = 3; row < rows; ++row) {
    for (int col = 0; col < columns - 3; ++col) {
      if (board[row][col] != EMPTY_SLOT &&
          board[row][col] == board[row - 1][col + 1] &&
          board[row][col] == board[row - 2][col + 2] &&
          board[row][col] == board[row - 3][col + 3]) {
        return true;
      }
    }
  }

  return false;
} // ..end checkWin()

// function to check for draw
bool GameBoard::checkDraw() const {
  for (const auto &row : board) {
    for (char cell : row) {
      if (cell == EMPTY_SLOT) {
        return false;
      }
    }
  }
  return true;
}

// function to check if a column is valid
bool GameBoard::isColumnValid(int column) const {
  return column >= 1 && column <= columns;
}

// function to check if a column is full
bool GameBoard::isColumnFull(int column) const {
  return board[0][column - 1] != EMPTY_SLOT;
}

// function to reset the board
void GameBoard::resetBoard() {
  for (auto &row : board) {
    fill(row.begin(), row.end(), EMPTY_SLOT);
  }
}