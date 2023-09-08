#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f cohesionForce;

  // todo: add your code here to make a force towards the center of mass
  // hint: iterate over the neighborhood

  // find center of mass
  if (neighborhood.size() == 0)
  {
    Vector2f centerOfMass(0, 0);
    for (int i = 0; i < neighborhood.size(); i++)
    {
      centerOfMass += neighborhood[i]->transform.position;
    };
    centerOfMass /= neighborhood.size() - 1;

    cohesionForce = centerOfMass - boid->transform.position;
  }

  return cohesionForce;
}