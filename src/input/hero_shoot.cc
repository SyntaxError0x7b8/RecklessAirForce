//
// Created by qos on 9/2/25.
//
//#include <memory>
#include "hero_shoot.h"

#include "../gameObject/game_object.h"


// singleton to be implemented
HeroShoot::HeroShoot() { // circular: std::shared_ptr<GameObject> hero
  //sp_hero_ = hero;
  //hero.reset();
  bullet_file = "../assets/heroAircraft/Proton_Large.png";
}



void HeroShoot::Update(GameObject &hero) {
  sp_hero_ = std::make_shared<GameObject>(hero);
  // create bullet
  if (IsKeyDown(KEY_SPACE)) {
    Shoot();
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
  for (auto s_ptr : burst_) {
    s_ptr->Draw();
  }
}

std::shared_ptr<ProtonGraphics> HeroShoot::Shoot() {
  // creates a new bullet and adds it to vector
  auto sp_bullet = std::make_shared<ProtonGraphics>(bullet_file,
    sp_hero_->GetSharedScale(),
    15.0f,
    sp_hero_->GetScreenPosition());
  burst_.push_back(sp_bullet);
  return sp_bullet;
}



