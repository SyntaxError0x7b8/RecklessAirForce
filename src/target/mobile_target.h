//
// Created by qos on 9/26/25.
//

#ifndef RECKLESSAIRFORCE_MOBILE_TARGET_H
#define RECKLESSAIRFORCE_MOBILE_TARGET_H
#include "target.h"

class MobileTarget final : public Target {
  public:
  MobileTarget(const char* sprite, Vector2 pos, const float scale);

  ~MobileTarget();
};

#endif  // RECKLESSAIRFORCE_MOBILE_TARGET_H
