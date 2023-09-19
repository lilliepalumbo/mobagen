//
// Created by atolstenko on 2/9/2023.
//

#include "HexagonGameOfLife.h"
void HexagonGameOfLife::Step(World& world) {
  for (int x = 0; x < world.SideSize(); x++) {
    for (int y = 0; y < world.SideSize(); y++) {
      int neighborCount = CountNeighbors(world, Point2D(x, y));
      if (world.Get(Point2D(x, y)))
      {
        if (neighborCount < 2 || neighborCount > 3)
        {
          world.SetNext(Point2D(x, y), false);
        }
      }
      else
      {
        if (neighborCount == 3)
        {
          world.SetNext(Point2D(x, y), true);
        }

      }
    }
  }
}
int HexagonGameOfLife::CountNeighbors(World& world, Point2D point) {
  int neighborCount = 0;

  world.Get(point.Left()) ? neighborCount++ : NULL;
  world.Get(point.Right()) ? neighborCount++ : NULL;
  world.Get(point.Up()) ? neighborCount++ : NULL;
  world.Get(point.Down()) ? neighborCount++ : NULL;

  if(point.y % 2 == 1)
  {
    world.Get(point + Point2D(1, 1)) ? neighborCount++ : NULL;
    world.Get(point + Point2D(1, -1)) ? neighborCount++ : NULL;
  }
  else
  {
    world.Get(point + Point2D(-1, -1)) ? neighborCount++ : NULL;
    world.Get(point + Point2D(-1, 1)) ? neighborCount++ : NULL;
  }

  return neighborCount;
}
