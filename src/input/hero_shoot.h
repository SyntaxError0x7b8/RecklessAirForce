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
  HeroShoot();

  ~HeroShoot() = default;

  void Update(GameObject &);

  void Draw();

  void Shoot(GameObject &);

  private:

  static std::vector<std::shared_ptr<ProtonGraphics>> burst_;

  const char * bullet_file_;

  Vector2 bullet_pos_{};

};

#endif  // RECKLESSAIRFORCE_HERO_SHOOT_H
