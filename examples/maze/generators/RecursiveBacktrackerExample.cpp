#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>

bool RecursiveBacktrackerExample::Step(World* w) {

  auto rnd = randomStartPoint(w);

  // stop cond
  if(stack.empty() && rnd == Point2D(INT_MAX, INT_MAX)){
    return false;
  }

  // start
  if(stack.empty())
  {
    stack.push_back(rnd);
    return true;
  }

  auto back = stack.back();
  visited[back.x][back.y] = true;
  std::vector<Point2D> visiting = getVisitables(w, back);

  w->SetNodeColor(back, Color::Blue);

  if (visiting.empty()) {
    stack.pop_back();
    w->SetNodeColor(back, Color::Black);
  } else if (visiting.size() == 1) {
    BreakWall(w, back, visiting[0]);
    stack.push_back(visiting[0]);
    w->SetNodeColor(visiting[0], Color::Purple);
  } else {
    int rand = Random().Range(0, visiting.size() - 1);
    BreakWall(w, back, visiting[rand]);
    stack.push_back(visiting[rand]);
    w->SetNodeColor(visiting[rand], Color::Purple);
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

  // north
  auto UP = p.Up();
  if(UP.y>-sideOver2 && !visited[UP.y][UP.x])
    visitables.push_back(UP);
  auto RIGHT = p.Right();
  if(RIGHT.x>-sideOver2 && !visited[RIGHT.y][RIGHT.x])
    visitables.push_back(RIGHT);
  auto DOWN = p.Down();
  if(DOWN.y>-sideOver2 && !visited[DOWN.y][DOWN.x])
    visitables.push_back(DOWN);
  auto LEFT = p.Left();
  if(LEFT.x>-sideOver2 && !visited[LEFT.y][LEFT.x])
    visitables.push_back(LEFT);

  //if (!visited[p.Up().y][p.Up().x] && abs(p.Up().y) <= sideOver2) visitables.push_back(p.Up());
  //if (!visited[p.Right().y][p.Right().x] && abs(p.Right().x) <= sideOver2) visitables.push_back(p.Right());
  //if (!visited[p.Down().y][p.Down().x] && abs(p.Down().y) <= sideOver2) visitables.push_back(p.Down());
  //if (!visited[p.Left().y][p.Left().x] && abs(p.Left().x) <= sideOver2) visitables.push_back(p.Left());

  return visitables;
}

void RecursiveBacktrackerExample::BreakWall(World* w, Point2D stackTop, Point2D visiting) {
  if(visiting == stackTop.Up()) {
    w->SetNorth(stackTop, false);
    return;
  }
  else if(visiting == stackTop.Right()) {
    w->SetEast(stackTop, false);
    return;
  }
  else if(visiting == stackTop.Down()) {
    w->SetSouth(stackTop, false);
    return;
  }
  else if(visiting == stackTop.Left()) {
    w->SetWest(stackTop, false);
    return;
  }
}
