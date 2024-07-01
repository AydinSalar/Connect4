// header file
#include "Game.h"

// iostream library
#include <iostream>

using namespace std;

// default constructor to initial the game
Game::Game(const string &player1Name, const string &player2Name,
           ScoreManager &scoreMgr)
    : player1(player1Name, 'X'), player2(player2Name, 'O'), board(6, 7),
      currentPlayer(&player1), scoreManager(scoreMgr) {}

// function to start the game
void Game::startGame() { playGame(); }

// function that runs the game
void Game::playGame() {
  
  // beginning of the do-while loop
  do {
    // reset the board
    board.resetBoard();
    bool gameEnded = false;

    // while loop to play the game until it ends
    while (!gameEnded) {

      // display the board
      board.displayBoard();

      // get the column from the current player
      currentPlayer->makeMove(board);

      // checks if someone has won
      if (board.checkWin()) {
        board.displayBoard();
        cout << endl << currentPlayer->getName() << " wins!" << endl;
        scoreManager.updateScore(currentPlayer->getName(), true, false);

        Player *losingPlayer =
            (currentPlayer == &player1) ? &player2 : &player1;
        scoreManager.updateScore(losingPlayer->getName(), false, false);

        gameEnded = true;
      } else if (board.checkDraw()) { // checks for draw
        board.displayBoard();
        cout << "\nIt's a draw!" << endl;
        scoreManager.updateScore(player1.getName(), false, true);
        scoreManager.updateScore(player2.getName(), false, true);
        gameEnded = true;
      } else {
        switchPlayer();
      }
    } // ..end while loop

    // ask the user if they want to play again
    char choice;
    cout << "\nDo you want to play again? (y/n): ";
    cin >> choice;
    if (tolower(choice) == 'n') {
      break;
    }
  } while (true); // ..end do-while loop

  // end the game
  endGame();
}// ..end playGame()

// funcion to switch the player
void Game::switchPlayer() {
  if (currentPlayer == &player1) {
    currentPlayer = &player2;
  } else {
    currentPlayer = &player1;
  }
}

// function to get player's input
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
}// ..end playTrun()

// function to check the game's state
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
} // ..end checkGameState()

// function to end the game
void Game::endGame() {
  cout << "\nGame Over! Final Scores:" << endl;
  displayPlayerScore(player1.getName());
  displayPlayerScore(player2.getName());
  cout << "\nThank you for playing Connect 4!" << endl;
}

// funciton to display the player's score
void Game::displayPlayerScore(const string &playerName) {
  Score score = scoreManager.getScore(playerName);
  cout << playerName << ": " << score.wins << " Wins, " << score.losses
       << " Losses, " << score.draws << " Draws" << endl;
}
