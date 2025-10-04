//
// Created by qos on 10/3/25.
//

#ifndef RECKLESSAIRFORCE_TARGET_CONTROL_H
#define RECKLESSAIRFORCE_TARGET_CONTROL_H

#include "raylib.h"

class TargetObject;
class TargetControl {
  public:

  void Update(TargetObject& enemy);

  void SetCoordinates(TargetObject& enemy);

  Vector2 TargetLinearPath();

private:

  const float speed_{6.0f};

  Vector2 direction_{0,1};
};

#endif  // RECKLESSAIRFORCE_TARGET_CONTROL_H
