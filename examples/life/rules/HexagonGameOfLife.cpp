#include "HexagonGameOfLife.h"
#include <iostream>
void HexagonGameOfLife::Step(World& world) {
  for (int x = 0; x < world.SideSize(); x++) {
    for (int y = 0; y < world.SideSize(); y++) {
      int neighborCount = CountNeighbors(world, {x, y});
      bool isAlive = world.Get({x, y});
      world.SetNext({x,y}, isAlive);
      if (isAlive)
      {
        if (neighborCount < 2 || neighborCount > 3)
        {
          world.SetNext({x,y}, false);
        }
      }
      else
      {
        if (neighborCount == 3)
        {
          world.SetNext({x,y}, true);
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
