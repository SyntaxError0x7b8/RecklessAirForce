//
// Created by qos on 9/2/25.
//
//#include <memory>
#include "hero_shoot.h"

#include "../gameObject/game_object.h"
#include "../graphics/proton_graphics.h"
#include "raymath.h"

std::vector<std::shared_ptr<ProtonGraphics>> HeroShoot::burst_;
//const char *HeroShoot::bullet_file_ = "../assets/heroAircraft/Proton_Large.png";


void HeroShoot::Update(const GameObject &hero) {
  // create bullet
  if (IsKeyPressed(KEY_SPACE)) {
    Shoot(hero);
  }
  // remove bullets that have hit something or out of the screen
  if (!burst_.empty()) {
    for (auto it = burst_.begin(); it != burst_.end(); ++it) {
      if (*it == nullptr) {
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
}

void HeroShoot::Draw() {
  if (!burst_.empty()) {
    for (const auto& s_ptr : burst_) {
      s_ptr->Draw();
    }
  }
}

void HeroShoot::Shoot(const GameObject &hero) {
  bullet_pos_ = {
    hero.GetRectangle().width / 2,
    0.0f
  };
  bullet_pos_ = Vector2Add(bullet_pos_, hero.GetScreenPosition());

  // creates a new bullet and adds it to vector
  const auto sp_bullet = std::make_shared<ProtonGraphics>(
    hero.GetSharedScale(),
    15.0f,
    bullet_pos_);
  burst_.push_back(sp_bullet);

}



