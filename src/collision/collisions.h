//
// Created by qos on 9/16/25.
//



#ifndef RECKLESSAIRFORCE_COLLISIONS_H
#define RECKLESSAIRFORCE_COLLISIONS_H

#include <memory>

#include "explosion.h"

//class Explosion;
class Target;
class GameObject;
class ProtonGraphics;

class Collisions {
  private:
  int num_hits_{};

  std::shared_ptr<Explosion> fire_ = nullptr;


public:
  Collisions();

  ~Collisions() = default;

  bool IsHeroHit(const GameObject& hero) {return false;}

  bool IsTargetHit(Target& target);

  //bool IsEnemyHit(const Enemy& enemy){return false;}



};


#endif  // RECKLESSAIRFORCE_COLLISIONS_H
