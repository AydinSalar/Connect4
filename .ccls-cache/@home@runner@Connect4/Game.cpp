#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(const string &player1Name, const string &player2Name, ScoreManager& scoreMgr)
    : player1(player1Name, 'X'), player2(player2Name, 'O'), board(6, 7),
      currentPlayer(&player1), scoreManager(scoreMgr) {}

void Game::startGame() { playGame(); }

void Game::displayMenu() {
  cout << "\nWelcome to Connect 4!" << endl;
  cout << "1. Start Game" << endl;
  cout << "2. Exit" << endl;
  cout << "Choose an option: ";
}

void Game::playGame() {
  do {
    board.resetBoard();
    bool gameEnded = false;

    while (!gameEnded) {
      board.displayBoard();
      currentPlayer->makeMove(board);

      if (board.checkWin()) {
        board.displayBoard();
        cout << endl << currentPlayer->getName() << " wins!" << endl;
        scoreManager.updateScore(currentPlayer->getName(), true, false);

        Player* losingPlayer = (currentPlayer == &player1) ? &player2 : &player1;
        scoreManager.updateScore(losingPlayer->getName(), false, false);
        
        gameEnded = true;
      } else if (board.checkDraw()) {
        board.displayBoard();
        cout << "\nIt's a draw!" << endl;
        scoreManager.updateScore(player1.getName(), false, true);
        scoreManager.updateScore(player2.getName(), false, true);
        gameEnded = true;
      } else {
        switchPlayer();
      }
    }

    char choice;
    cout << "\nDo you want to play again? (y/n): ";
    cin >> choice;
    if (tolower(choice) == 'n') {
      break;
    }
  } while (true);

  endGame();
}

void Game::switchPlayer() {
  if (currentPlayer == &player1) {
    currentPlayer = &player2;
  } else {
    currentPlayer = &player1;
  }
}

void Game::playTurn() {
  board.displayBoard();
  cout << endl
       << currentPlayer->getName()
       << "'s turn. \nEnter the column number (1-7) to drop your disc: ";
  int column;
  cin >> column;

  while (!board.isColumnValid(column) || board.isColumnFull(column)) {
    cout << "Invalid column or column is full. Try another column: ";
    cin >> column;
  }

  board.updateBoard(column, currentPlayer->getDiscSymbol());
}

void Game::checkGameState() {
  if (board.checkWin()) {
    board.displayBoard();
    cout << currentPlayer->getName() << " wins!" << endl;
    scoreManager.updateScore(currentPlayer->getName(), true, false);
    endGame();
  } else if (board.checkDraw()) {
    board.displayBoard();
    cout << "It's a draw!" << endl;
    scoreManager.updateScore(player1.getName(), false, true);
    scoreManager.updateScore(player2.getName(), false, true);
    endGame();
  } else {
    switchPlayer();
  }
}

void Game::endGame() {
  cout << "\nGame Over! Final Scores:" << endl;
  displayPlayerScore(player1.getName());
  displayPlayerScore(player2.getName());
  cout << "\nThank you for playing Connect 4!" << endl;
}

void Game::displayPlayerScore(const string &playerName) {
  Score score = scoreManager.getScore(playerName);
  cout << playerName << ": " << score.wins << " Wins, " << score.losses
            << " Losses, " << score.draws << " Draws" << endl;
}
