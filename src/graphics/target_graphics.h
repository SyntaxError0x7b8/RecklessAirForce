//
// Created by qos on 10/8/25.
//

#ifndef RECKLESSAIRFORCE_TARGET_GRAPHICS_H
#define RECKLESSAIRFORCE_TARGET_GRAPHICS_H

#include "raylib.h"

class TargetObject;
class TargetGraphics {
public:
  TargetGraphics(const char* sprite,
    const char* shadow,
    int num_images,
    float map_scale);

  ~TargetGraphics();

  void Draw(TargetObject& enemy);

private:
  Texture sprite_texture_{};

  Texture shadow_texture_{};

  int num_images_{};

  float map_scale_{};
};

#endif  // RECKLESSAIRFORCE_TARGET_GRAPHICS_H
