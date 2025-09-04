//
// Created by qos on 9/2/25.
//
//#include <memory>
#include "hero_shoot.h"

#include "../gameObject/game_object.h"
#include "../graphics/proton_graphics.h"

std::vector<std::shared_ptr<ProtonGraphics>> HeroShoot::burst_;

// singleton to be implemented
HeroShoot::HeroShoot() {
  bullet_file_ = "../assets/heroAircraft/Proton_Large.png";

}



void HeroShoot::Update(GameObject &hero) {
  if (burst_.empty()) { return;}

  // create bullet
  if (IsKeyDown(KEY_SPACE)) {
    Shoot(hero);
  }
  // remove bullets that have hit something or out of the screen
  for (auto it = burst_.begin(); it != burst_.end(); ++it) {
    if (it->get() == nullptr) {
      it = burst_.erase(it);
    }
    // update those visible and not hit, nullify the rest
    for (auto s_ptr : burst_) {
      if (s_ptr->IsVisible(s_ptr->GetProtonBounds()) && !s_ptr->IsHit()) {
        s_ptr->Update();
      }
      else {
        // change to nullpointer so it gets removed
        s_ptr.reset();
      }
    }
  }
}

void HeroShoot::Draw() {
  if (!burst_.empty()) {
    for (auto s_ptr : burst_) {
      s_ptr->Draw();
    }
  }
}

void HeroShoot::Shoot(GameObject &hero) {
  // creates a new bullet and adds it to vector
  auto sp_bullet = std::make_shared<ProtonGraphics>(bullet_file_,
    hero.GetSharedScale(),
    15.0f,
    hero.GetScreenPosition());
  burst_.push_back(sp_bullet);

}



