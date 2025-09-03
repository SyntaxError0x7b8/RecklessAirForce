//
// Created by qos on 9/2/25.
//

#ifndef RECKLESSAIRFORCE_HERO_SHOOT_H
#define RECKLESSAIRFORCE_HERO_SHOOT_H
#include <memory>
#include <vector>

#include "../graphics/proton_graphics.h"

class GameObject;
class ProtonGraphics;

class HeroShoot {
  public:
  explicit HeroShoot();

  ~HeroShoot() = default;

  void Update(GameObject &);

  void Draw();

  std::shared_ptr<ProtonGraphics> Shoot();

  private:
    std::shared_ptr<GameObject> sp_hero_ {};

  static std::vector<std::shared_ptr<ProtonGraphics>> burst_;

  static const char * bullet_file;;

};

#endif  // RECKLESSAIRFORCE_HERO_SHOOT_H
