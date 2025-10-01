//
// Created by qos on 9/26/25.
//

#include <random>

#include "mobile_target.h"
#include "raymath.h" // raymath.h always has to be after raylib.h

MobileTarget::MobileTarget(const char* sprite,
  const float scale)
    : Target(sprite, scale) {
  SetCoordinates();
  direction_ = Vector2Normalize(Vector2Add(GetPosition(), dest_pos_));
}

void MobileTarget::MoveTarget() {
  const float dt = GetFrameTime();
  // move object according to a movement pattern
  TargetLinePath();
}


void MobileTarget::TargetLinePath(){
  // calculate next point in the path line
  // y =m*x + b
  // this path could be changed to other mathematical curves
  const Vector2 next_point = Vector2Add(
    GetPosition(),
    Vector2Scale(direction_, target_speed_)); // velocity
  SetPosition(next_point);
}
void MobileTarget::SetCoordinates() {
  // choose a random point on the other side of the screen
  constexpr int x_left = -100;
  const int x_right = GetScreenWidth() + 100;
  constexpr float y_top = -100.0f;
  const int y_bottom = GetScreenHeight() + 100;
  // generate a random x_coordinate for the destination point
  // initialise generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distribution(x_left, x_right);
  // get random numbers in range x_left --> x_right
  const int x_origin = distribution(gen);
  const int x_dest = distribution(gen);
  // set origin
  SetPosition({static_cast<float>(x_origin), y_top});
  // return vector2, cast int to float.
  dest_pos_ = {static_cast<float>(x_dest), static_cast<float>(y_bottom)};

}

