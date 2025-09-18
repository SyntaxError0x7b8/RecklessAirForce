//
// Created by qos on 9/2/25.
//

#ifndef RECKLESSAIRFORCE_HERO_SHOOT_H
#define RECKLESSAIRFORCE_HERO_SHOOT_H
#include <memory>
#include <vector>

#include "../graphics/hero_graphics_component.h"

class GameObject;
class ProtonGraphics;

class HeroShoot {
  public:
  HeroShoot() = default;

  ~HeroShoot() =default;

  void Update(const GameObject &);

  static void Draw();

  void Shoot(const GameObject &);

  static std::vector<std::shared_ptr<ProtonGraphics>> burst_;

  private:



  //static const char * bullet_file_;

  Vector2 bullet_pos_{};

};

#endif  // RECKLESSAIRFORCE_HERO_SHOOT_H
