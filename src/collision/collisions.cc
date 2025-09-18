//
// Created by qos on 9/16/25.
//

#include "collisions.h"

#include "../graphics/proton_graphics.h"
#include "../input/hero_shoot.h"
#include "../target/target.h"
bool Collisions::IsTargetHit(Target& target) {
  //
  bool scored{};
  std::vector<std::shared_ptr<ProtonGraphics>>* p_bullets = HeroShoot::GetBurst();
  for (auto bullet : *p_bullets) {
    scored = CheckCollisionRecs(bullet->GetProtonBounds(),target.GetTargetBounds());
    if (scored) {
      bullet->SetHit(scored);
      target.SetHit(scored);
      // receive damage from bullet and reduce it from target
      //
    }
  }

  p_bullets = nullptr;
  delete p_bullets;
  return scored;
}