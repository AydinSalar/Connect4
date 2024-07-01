#ifndef DISC_H
#define DISC_H

#include "GameEntity.h"

class Disc : public GameEntity{
private:
  char symbol;

public:
  Disc(int x, int y, char symbol);
  void render() const override;
  char getSymbol() const;
};

#endif