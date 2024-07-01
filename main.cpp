#include "Game.h"
#include "ScoreManager.h"
#include <iostream>
#include <string>

// function to get the player's name
string getPlayerName(const string &prompt) {
  cout << prompt;
  string name;
  getline(cin, name);
  return name;
}

// main function
int main() {

  cout << "Welcome to Connect 4!\n";

  // getting the names
  string player1Name = getPlayerName("Player 1, please enter your name: ");
  string player2Name = getPlayerName("Player 2, please enter your name: ");

  // creating scores
  ScoreManager scoreManager;
  scoreManager.resetScores(player1Name, player2Name);

  // creating the game
  Game game(player1Name, player2Name, scoreManager);
  game.startGame();

  return 0;
}