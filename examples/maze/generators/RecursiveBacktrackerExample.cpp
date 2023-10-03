#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>
bool RecursiveBacktrackerExample::Step(World* w) {
  stack.push_back(randomStartPoint(w));
  while(!stack.empty())
  {
    visited[stack.front().x][stack.front().y] = true;
    std::vector<Point2D> visiting = getVisitables(w,stack.front());
    if(visiting.empty())
    {
      stack.pop_back();
    }
    else if (visiting.size() == 1)
    {
      BreakWall(w ,stack.front(), visiting[0]);

    }
    else
    {

    }
  }

  return true;
}



void RecursiveBacktrackerExample::Clear(World* world) {
  visited.clear();
  stack.clear();
  auto sideOver2 = world->GetSize() / 2;

  for (int i = -sideOver2; i <= sideOver2; i++) {
    for (int j = -sideOver2; j <= sideOver2; j++) {
      visited[i][j] = false;
    }
  }
}
Point2D RecursiveBacktrackerExample::randomStartPoint(World* world) {
  auto sideOver2 = world->GetSize() / 2;

  // todo: change this if you want
  for (int y = -sideOver2; y <= sideOver2; y++)
    for (int x = -sideOver2; x <= sideOver2; x++)
      if (!visited[y][x]) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> RecursiveBacktrackerExample::getVisitables(World* w, const Point2D& p) {
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;

  return visitables;
}

void RecursiveBacktrackerExample::BreakWall(World* w, Point2D stackTop, Point2D visiting) {

}
