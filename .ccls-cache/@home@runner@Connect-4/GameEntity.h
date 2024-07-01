#ifndef GAMEENTITY_H
#define GAMEENTITY_H

// class definition 
class GameEntity {
protected:
  // protected variables
  int x, y;
  bool isVisible;

public:
  // constructor
  GameEntity(int x, int y) : x(x), y(y), isVisible(true) {}

  // virtual
  virtual void render() const = 0;
  virtual ~GameEntity() = default;
};

#endif