//
// Created by qos on 9/26/25.
//

#ifndef RECKLESSAIRFORCE_MOBILE_TARGET_H
#define RECKLESSAIRFORCE_MOBILE_TARGET_H
#include "target.h"

class MobileTarget final : public Target {
  public:
  MobileTarget(const char* sprite, const char* shadow, float scale);

  ~MobileTarget() = default;

  void MoveTarget();

  void TargetLinePath();

  void SetCoordinates();

  void Draw();

private:
  Vector2 next_pos_{};

  float target_speed_{6.0f}; // pixels per second

  Vector2 dest_pos_{};

  Vector2 direction_{};


};

#endif  // RECKLESSAIRFORCE_MOBILE_TARGET_H
