//
// Created by qos on 9/26/25.
//

#ifndef RECKLESSAIRFORCE_MOBILE_TARGET_H
#define RECKLESSAIRFORCE_MOBILE_TARGET_H
#include "target.h"

class MobileTarget final : public Target {
  public:
  MobileTarget(const char* sprite, Vector2 pos, float scale);

  ~MobileTarget() = default;

  void MoveTarget();

private:
  Vector2 next_pos_{};
  float target_speed_{6.0f}; // pixels per second


};

#endif  // RECKLESSAIRFORCE_MOBILE_TARGET_H
