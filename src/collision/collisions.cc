//
// Created by qos on 9/16/25.
//

#include "collisions.h"

#include "../graphics/proton_graphics.h"
#include "../input/hero_shoot.h"
#include "../target/target.h"
bool Collisions::IsTargetHit(Target& target) {
  //
  std::vector<std::shared_ptr<ProtonGraphics>>* p_bullets = HeroShoot::GetBurst();
  for (const auto& bullet : *p_bullets) {
    if (CheckCollisionRecs(bullet->GetProtonBounds(),target.GetTargetBounds())) {
      bullet->SetHit(true);
      target.SetHit(true);
      // receive damage from bullet and reduce it from target
      //
      return true;
    }
  }

  return false;
}