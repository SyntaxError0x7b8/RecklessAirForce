//
// Created by qos on 10/2/25.
//

#ifndef RECKLESSAIRFORCE_TARGET_OBJECT_H
#define RECKLESSAIRFORCE_TARGET_OBJECT_H
#include "raylib.h"

class TargetObject {
  public:
  TargetObject(const char* sprite,
    const char* shadow,
    int num_images,
    float map_scale);

  ~TargetObject();


private:
  Texture enemy_texture_{};

  Texture enemy_shadow_texture_{};

  float frame_{};

  Vector2 position_{};

  Vector2 shadow_pos_{};
};

#endif  // RECKLESSAIRFORCE_TARGET_OBJECT_H
