#include "Agent.h"
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include "World.h"
using namespace std;
std::vector<Point2D> Agent::generatePath(World* w){
  unordered_map<Point2D, Point2D> cameFrom; // to build the flowfield and build the path
  queue<Point2D> frontier; // to store next ones to visit
  unordered_set<Point2D> frontierSet; // OPTIMIZATION to check faster if a point is in the queue
  unordered_map<Point2D, bool> visited; // use .at() to get data, if the element dont exist [] will give you wrong results

  // bootstrap state
  auto catPos = w->getCat();
  frontier.push(catPos);
  frontierSet.insert(catPos);
  Point2D borderExit = Point2D::INFINITE; // if at the end of the loop we dont find a border, we have to return random points

  while (!frontier.empty()){
    // get the current from frontier
    auto current = frontier.front();

    if(w->catWinsOnSpace(current))
    {
      // quit early
    }

    // remove the current from frontierset
    frontierSet.erase(current);
    // mark current as visited
    visited[current] = true;
    // getVisitableNeightbors(world, current) returns a vector of neighbors that are not visited, not cat, not block, not in the queue
    auto neightbors = getVisitableNeighbors(w, current);
    // iterate over the neighs:
      // for every neighbor set the cameFrom
      // enqueue the neighbors to frontier and frontierset
    for(auto neighbor : neightbors)
    {
      cameFrom.at(neighbor) = current;
      frontier.push(neighbor);
      frontierSet.emplace(neighbor);


    }
  }

  // if the border is not infinity, build the path from border to the cat using the camefrom map
  // if there isnt a reachable border, just return empty vector
  // if your vector is filled from the border to the cat, the first element is the catcher move, and the last element is the cat move
}

std::vector<Point2D> Agent::getVisitableNeighbors(World* w, const Point2D &current) {
  std::vector<Point2D> neighbors;
  Point2D NE = w->NE(current), NW = w->NW(current), W = w->W(current), SW = w->SW(current), SE = w->SE(current), E = w->E(current);

  if (NE != w->getCat() && w->isValidPosition(NE) && !w->getContent(NE))
  {
    neighbors.push_back(NE);
  }
  if (NW != w->getCat() && w->isValidPosition(NW) && !w->getContent(NW))
  {
    neighbors.push_back(NW);
  }
  if (W != w->getCat() && w->isValidPosition(W) && !w->getContent(W))
  {
    neighbors.push_back(W);
  }
  if (SW != w->getCat() && w->isValidPosition(SW) && !w->getContent(SW))
  {
    neighbors.push_back(SW);
  }
  if (SE != w->getCat() && w->isValidPosition(SE) && !w->getContent(SE))
  {
    neighbors.push_back(SE);
  }
  if (E != w->getCat() && w->isValidPosition(E) && !w->getContent(E))
  {
    neighbors.push_back(E);
  }

  return neighbors;
}
