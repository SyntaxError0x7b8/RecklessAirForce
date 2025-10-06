//
// Created by qos on 10/3/25.
//
#include <random>

#include "target_control.h"
#include "target_object.h"



void TargetControl::Update(TargetObject& enemy) {
  // chose a random path.
  // for now only straight line implemented

}

void TargetControl::SetCoordinates(TargetObject& enemy) {
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
  enemy.SetPosition(static_cast<float>(x_origin), y_top);
  // sed end_position, cast int to float.
  enemy.SetDestination(static_cast<float>(x_dest), static_cast<float>(y_bottom));

}

Vector2 TargetControl::TargetLinearPath() {
  // calculate next point in the path line
  // y =m*x + b
  // this path could be changed to other mathematical curves
  /*const Vector2 next_point = Vector2Add(
    GetPosition(),
    Vector2Scale(direction_, target_speed_)); // velocity
  SetPosition(next_point);*/
  Vector2 _ = {};
  return _;
}