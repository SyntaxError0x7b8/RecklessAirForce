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
   if (t_ > 1.0f) { t_ = 1.0f; } // Bezier curve requires t_ = [0, 1]
   // update position using Bezier's path function
   BezierPath(enemy);
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
  // set origin = start position
  start_position_ = {x_origin, y_top};
  enemy.SetPosition(x_origin, y_top);
  // set control point
  control_point_ = {static_cast<float>(x_control), y_control};
  // sed end_position, cast int to float.
  end_position_ = {static_cast<float>(x_dest), static_cast<float>(y_bottom)};

}

void TargetControl::BezierPath(TargetObject& enemy) {
  // calculate next point in the path line
  // B(t) = (1-t)**2P_0 + 2(1-t)tP_1 + t**2P_2 // quadratic Bezier
  // no need for linear bezier if control point falls inside line between P0 &
  // P1
  const float a = (1 - t_) * (1 - t_);
  const Vector2 term_start = Vector2Scale(start_position_, a);
  const float b = 2 * (1 - t_) * t_;
  const Vector2 term_control = Vector2Scale(control_point_, b);
  const float c = t_ * t_;
  const Vector2 term_end = Vector2Scale(end_position_, c);
  // Vector2Add only allows to add 2 vectors at a time
  const Vector2 _ = Vector2Add(term_start, term_control);
  // last vector sum will be set as the target's position
  enemy.SetPosition(Vector2Add(_, term_end));
}

float TargetControl::XGenerator() {
  return static_cast<float>(distribution(gen));
}
