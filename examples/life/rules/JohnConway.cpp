#include "JohnConway.h"

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world) {
    for (int x = 0; x < world.SideSize(); x++) {
        for (int y = 0; y < world.SideSize(); y++) {
            int neighborCount = CountNeighbors(world, {x,y});
            bool isAlive = world.Get({x,y});
            world.SetNext({x,y}, isAlive);

            if (isAlive)
            {
                if(neighborCount < 2 || neighborCount > 3)
                {
                  world.SetNext({x,y}, false);
                }
            }
            else
            {
                if(neighborCount == 3)
                {
                  world.SetNext({x,y}, true);
                }
            }

        }
    }
}

int JohnConway::CountNeighbors(World& world, Point2D point) {
    return
        world.Get(point.Up()) +
        world.Get(point.Left()) +
        world.Get(point.Down()) +
        world.Get(point.Right()) +
        world.Get(point.Up().Left()) +
        world.Get(point.Down().Left()) +
        world.Get(point.Up().Right()) +
        world.Get(point.Down().Right());
}
