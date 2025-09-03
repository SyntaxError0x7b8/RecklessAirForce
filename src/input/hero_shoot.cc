//
// Created by qos on 9/2/25.
//

#include "hero_shoot.h"

#include "../gameObject/game_object.h"

HeroShoot::HeroShoot(const GameObject& hero) {
  const Vector2 hero_pos = hero.GetScreenPosition();
  const auto bullet_texture = "../assets/heroAircraft/Proton_Large.png";
  const float scale = hero.GetSharedScale();
  auto *pbullet = new ProtonGraphics(bullet_texture,
    scale,
    15.0f,
    hero_pos);
  burst.push_back(pbullet);

 }
HeroShoot::~HeroShoot() {
  for (auto ptr : burst) {
    delete ptr;
  }
  burst.clear();

}


