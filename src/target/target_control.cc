//
// Created by qos on 10/3/25.
//

#include <random>
#include "target_control.h"
#include "target_object.h"
#include "raymath.h"

// random coordinate generator, static
static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> distribution(-100, (GetScreenWidth() + 100));

void TargetControl::Update(TargetObject& enemy, const float dT) {
  // Follow Bezier's path
  if (t_ >= 1.0f) {
    // reset object
    SetCoordinates(enemy);
  }
  else {
   (t_ + dT) / flight_time_;
  }



}

void TargetControl::SetCoordinates(TargetObject& enemy) { // only called when created or reset
  // start time
  t_ = 0.0f;

  constexpr float y_top = -100.0f;
  const float y_control = (static_cast<float>(GetScreenHeight()) / 2.0f);
  const int y_bottom = GetScreenHeight() + 100;

  const float x_origin = TargetControl::XGenerator();
  const float x_control = TargetControl::XGenerator();
  const float x_dest = TargetControl::XGenerator();
  // set origin
  enemy.SetPosition(static_cast<float>(x_origin), y_top);
  // set control point
  control_point_ = {static_cast<float>(x_control), y_control};
  // sed end_position, cast int to float.
  end_position_ = {static_cast<float>(x_dest), static_cast<float>(y_bottom)};

}

Vector2 TargetControl::BezierPath(TargetObject& enemy) {
  // calculate next point in the path line
  // B(t) = (1-t)**2P_0 + 2(1-t)tP_1 + t**2P_2 // cuadratic Bezier
  // no need for linear bezier if control point falls inside line between P0 & P1



  return {0.0f, 0.0f};
}

float TargetControl::XGenerator() {
  return static_cast<float>(distribution(gen));
}
