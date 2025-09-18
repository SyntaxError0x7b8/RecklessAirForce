//
// Created by qos on 9/6/25.
//

#ifndef RECKLESSAIRFORCE_TARGET_H
#define RECKLESSAIRFORCE_TARGET_H
#include "raylib.h"

class Target {
public:
  explicit Target(float scale);

  ~Target();

  void Update();

  void Draw() const;

  [[nodiscard]] Rectangle GetTargetBounds() const { return position_bounds_;}

  bool SetHit(const bool hit) {hit_ = hit; return hit_;}

  private:
  Rectangle position_bounds_{};

  Vector2 position_{};

  Texture target_texture_{};

  double energy_ {100.0};

  bool hit_ {};

  float scale_{};


};

#endif  // RECKLESSAIRFORCE_TARGET_H
