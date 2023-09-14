#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2f AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to match the heading of neighbors = Average velocity
  Vector2f averageVelocity = Vector2f::zero();

  // todo: add your code here to align each boid in a neighborhood
  // hint: iterate over the neighborhood
  averageVelocity += boid->getVelocity();
  int boidCount = 1;
  for (auto i : neighborhood)
  {
     averageVelocity += i->getVelocity();
     boidCount++;
  }
  averageVelocity /= boidCount;

  return Vector2f::normalized(averageVelocity);
}