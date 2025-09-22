//
// Created by qos on 9/16/25.
//



#ifndef RECKLESSAIRFORCE_COLLISIONS_H
#define RECKLESSAIRFORCE_COLLISIONS_H

#include <memory>

//#include "explosion.h"

//class Explosion;
class Target;
class GameObject;
class ProtonGraphics;

class Collisions {
  private:



public:

  static bool IsHeroHit(const GameObject& hero) {return false;}

  static bool IsTargetHit(Target& target);





};


#endif  // RECKLESSAIRFORCE_COLLISIONS_H
