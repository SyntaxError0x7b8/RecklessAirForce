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

  private:
  Rectangle position_bounds_{};

  Vector2 position_{};

  Texture target_texture_{};


};

#endif  // RECKLESSAIRFORCE_TARGET_H
