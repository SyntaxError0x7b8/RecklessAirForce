//
// Created by qos on 9/2/25.
//

#ifndef RECKLESSAIRFORCE_PROTON_GRAPHICS_H
#define RECKLESSAIRFORCE_PROTON_GRAPHICS_H

#include "raylib.h"

class ProtonGraphics {
  public:
  ProtonGraphics() = default;

  ProtonGraphics(const char* texture, float scale, float power, Vector2 pos);

  ~ProtonGraphics();

  void Update();

  void Draw();

  bool IsVisible(Rectangle);

  [[nodiscard]] bool IsHit() const { return hit_; }

  bool SetHit();

  [[nodiscard]] Rectangle GetProtonBounds() const { return proton_bounds_; }

  private:
  Texture proton_texture_{};

  Vector2 proton_position_{};

  float proton_speed_{-12.0f};

  const float update_rate_ {0.12f};

  float last_update_time_ {0.0};

  Rectangle proton_bounds_{};

  float power_ {};

  float scale_{};

  bool fired_{}; // needed?

  bool hit_{};


};

#endif  // RECKLESSAIRFORCE_PROTON_GRAPHICS_H
