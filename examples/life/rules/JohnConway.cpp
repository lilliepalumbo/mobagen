#include "JohnConway.h"

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world) {
    for (int x = 0; x < world.SideSize(); x++) {
      for (int y = 0; y < world.SideSize(); y++) {
        int neighborCount = CountNeighbors(world, Point2D(x, y));
        if (world.Get(Point2D(x, y)))
        {
          (neighborCount > 1 && neighborCount < 4) ? true : world.SetNext(Point2D(x, y), false);
        }
      }
    }
}

int JohnConway::CountNeighbors(World& world, Point2D point) {
    int neighborCount = 0;

    world.Get(point.Up()) ? neighborCount++ : NULL;
    world.Get(point.Left()) ? neighborCount++ : NULL;
    world.Get(point.Down()) ? neighborCount++ : NULL;
    world.Get(point.Right()) ? neighborCount++ : NULL;

    world.Get(point.Up() + Point2D(1, 0)) ? neighborCount++ : NULL; // Upper Right
    world.Get(point.Down() + Point2D(1, 0)) ? neighborCount++ : NULL; // Lower Right
    world.Get(point.Up() - Point2D(1, 0)) ? neighborCount++ : NULL; // Upper Left
    world.Get(point.Down() - Point2D(1, 0)) ? neighborCount++ : NULL; // Lower Left

    return neighborCount;
}
