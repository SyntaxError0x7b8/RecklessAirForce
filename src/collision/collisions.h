//
// Created by qos on 9/16/25.
//



#ifndef RECKLESSAIRFORCE_COLLISIONS_H
#define RECKLESSAIRFORCE_COLLISIONS_H

#include <memory>
#include <vector>

#include "raylib.h"

class Target;
class GameObject;
class ProtonGraphics;

class Collisions {
  private:
  int num_hits_{};


public:
  bool IsHeroHit(const GameObject& hero) {return false;}

  bool IsTargetHit(const Target& target,
    std::vector<std::shared_ptr<ProtonGraphics>>& burst);

  //bool IsEnemyHit(const Enemy& enemy){return false;}


};


#endif  // RECKLESSAIRFORCE_COLLISIONS_H
