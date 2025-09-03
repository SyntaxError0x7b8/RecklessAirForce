//
// Created by qos on 9/2/25.
//

#ifndef RECKLESSAIRFORCE_HERO_SHOOT_H
#define RECKLESSAIRFORCE_HERO_SHOOT_H
#include <vector>
#include "../graphics/proton_graphics.h"

class GameObject;
class ProtonGraphics;

class HeroShoot {
  public:
  explicit HeroShoot(const GameObject&);

  ~HeroShoot();

  void Update(ProtonGraphics& bullet);

  inline void Draw(ProtonGraphics& bullet) { bullet.Draw(); }

  private:
  std::vector<ProtonGraphics*> burst {};

};

#endif  // RECKLESSAIRFORCE_HERO_SHOOT_H
