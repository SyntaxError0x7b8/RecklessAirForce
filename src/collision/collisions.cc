//
// Created by qos on 9/16/25.
//

#include "collisions.h"

#include "../graphics/proton_graphics.h"
#include "../input/hero_shoot.h"
#include "../target/target.h"




/**
 * @brief  checks collision between hero's proton-bullets and
 * test target. Function can be overloaded to accept enemies.
 * @param target
 * @return true if collision occurs
 */
bool Collisions::IsTargetHit(Target& target) {
  // get a pointer to all hero's proton-bullets
  std::vector<std::shared_ptr<ProtonGraphics>>* p_bullets = HeroShoot::GetBurst();
  // check collision with target for every proton-bullet
  for (const auto& bullet : *p_bullets) {
    if (CheckCollisionRecs(bullet->GetProtonBounds(),target.GetTargetBounds())) {
      // receive damage from bullet and reduce it from target
      target.TakeDamage(bullet->GetPower());
      bullet->SetHit(true);
      return true;
    }
  }
  return false;

}