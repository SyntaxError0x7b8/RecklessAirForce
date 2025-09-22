//
// Created by qos on 9/16/25.
//

#include "collisions.h"

#include "../graphics/proton_graphics.h"
#include "../input/hero_shoot.h"
#include "../target/target.h"

 Collisions::Collisions() {
   fire_ = new Explosion;
 }

 Collisions::~Collisions() {
   delete fire_;
 }





/**
 * @brief  checks collision between hero's proton-bullets and
 * test target. Function can be overloaded to accept enemies.
 * @param target
 * @return true if collision occurs
 */
bool Collisions::IsTargetHit(Target& target) {
  //
  std::vector<std::shared_ptr<ProtonGraphics>>* p_bullets = HeroShoot::GetBurst();
  for (const auto& bullet : *p_bullets) {
    if (target.IsBurning()) { // if target burning, execute burning
      // call explosion burning function
    }
    else {
          if (CheckCollisionRecs(bullet->GetProtonBounds(),target.GetTargetBounds())) {
      // receive damage from bullet and reduce it from target
      target.TakeDamage(bullet->GetPower());
      bullet->SetHit(true);
      //set target to burning
      target.SetBurning(true);
      return true;
    }
    }

  }

  return false;
}