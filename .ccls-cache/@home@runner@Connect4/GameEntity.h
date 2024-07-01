#ifndef GAMEENTITY_H
#define GAMEENTITY_H

class GameEntity {
protected:
  int x, y;
  bool isVisible;

public:
  GameEntity(int x, int y) : x(x), y(y), isVisible(true) {}
  virtual void render() const = 0;
  virtual ~GameEntity() = default;
};

#endif