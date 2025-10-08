//
// Created by qos on 10/3/25.
//

#ifndef RECKLESSAIRFORCE_TARGET_CONTROL_H
#define RECKLESSAIRFORCE_TARGET_CONTROL_H

#include "raylib.h"

class TargetObject;
class TargetControl {
  public:

  void Update(TargetObject& enemy, float dT);

  void SetCoordinates(TargetObject& enemy);

  void BezierPath(TargetObject& enemy);

  static float XGenerator();


private:

  const float flight_time_{6.0f};

  Vector2 start_position_{};

  Vector2 end_position_{};

  Vector2 control_point_{};

  float t_{}; // Bezier's B(t), [0, 1]


};

#endif  // RECKLESSAIRFORCE_TARGET_CONTROL_H
