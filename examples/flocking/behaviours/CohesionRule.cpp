#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f cohesionForce;

  // todo: add your code here to make a force towards the center of mass
  // hint: iterate over the neighborhood

  // find center of mass
  if (neighborhood.size() > 0)
  {
    Vector2f centerOfMass(0, 0);
    for (auto i : neighborhood)
    {
      centerOfMass += i->getPosition();
    };
    centerOfMass /= neighborhood.size();

    cohesionForce = centerOfMass - boid->getPosition();
  }

  return cohesionForce.normalized();
}