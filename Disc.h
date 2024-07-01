#ifndef DISC_H
#define DISC_H

// parent header file
#include "GameEntity.h"

// class definition 
class Disc : public GameEntity {
private:
  // char variable for the symbol
  char symbol;

public:
  // constructor
  Disc(int x, int y, char symbol);

  // function to render
  void render() const override;

  // getter for the symbol
  char getSymbol() const;
};

#endif