#include "ScoreManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

ScoreManager::ScoreManager() {}

ScoreManager::~ScoreManager() { writeScoresToFile("PlayerScores.txt"); }

void ScoreManager::writeScoresToFile(const string &filename) {
  ofstream file(filename);
  for (const auto &pair : scores) {
    file << pair.first << " " << pair.second.wins << " " << pair.second.losses
         << " " << pair.second.draws << "\n";
  }
}

void ScoreManager::readScoresFromFile(const string &filename) {
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    istringstream iss(line);
    string name;
    int wins, losses, draws;
    if (iss >> name >> wins >> losses >> draws) {
      scores[name] = Score(wins, losses, draws);
    }
  }
}

void ScoreManager::updateScore(const string &playerName, bool win, bool draw) {
  Score &playerScore = scores[playerName];

  if (win) {
    playerScore.wins++;
    cout << " - Win incremented";
  } else if (draw) {
    playerScore.draws++;
    cout << " - Draw incremented";
  } else {
    playerScore.losses++;
    cout << " - Loss incremented";
  }
  cout << endl;
}

Score ScoreManager::getScore(const string &playerName) const {
  auto it = scores.find(playerName);
  if (it != scores.end()) {
    return it->second;
  }
  return Score();
}

void ScoreManager::updatePlayerName(const string &oldName,
                                    const string &newName) {
  if (scores.find(oldName) != scores.end()) {
    scores[newName] = scores[oldName];
    scores.erase(oldName);
  } else {
    scores[newName] = Score();
  }
  writeScoresToFile("PlayerScores.txt");
}

void ScoreManager::resetScores(const string &player1Name,
                               const string &player2Name) {
  scores.clear(); 

  scores[player1Name] = Score(0, 0, 0);
  scores[player2Name] = Score(0, 0, 0);

  writeScoresToFile("PlayerScores.txt");
}