#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include "engine/Engine.h"

Vector2f SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to avoid boids too close
  Vector2f separatingForce = Vector2f::zero();
      // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
      float desiredDistance = desiredMinimalDistance;
      if (!neighborhood.empty()) {
          // todo: find and apply force only on the closest mates
          int closeFlockmates = 0;

          for(auto i : neighborhood)
          {
             Vector2f diff = boid->getPosition() - i->getPosition();
             float distance = diff.getMagnitude();
             if (distance < desiredDistance)
             {
                closeFlockmates++;
                Vector2f hat = diff.normalized();
                Vector2f force = hat/(distance/desiredDistance);
                separatingForce += force;
             }
          }

          if(closeFlockmates > 0)
          {
             separatingForce /= closeFlockmates;
          }
      }

  return separatingForce.normalized();
}

bool SeparationRule::drawImguiRuleExtra() {
  ImGui::SetCurrentContext(world->engine->window->imGuiContext);
  bool valusHasChanged = false;

  if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
    valusHasChanged = true;
  }

  return valusHasChanged;
}
