//
// Created by qos on 10/2/25.
// Refactoring from inheritance to composition.
//

#ifndef RECKLESSAIRFORCE_TARGET_OBJECT_H
#define RECKLESSAIRFORCE_TARGET_OBJECT_H
#include "raylib.h"
#include "target_control.h"
#include "../graphics/target_graphics.h"


class TargetObject {
  public:
  TargetObject(const char* sprite,
    const char* shadow,
    int num_images,
    float map_scale);

  ~TargetObject();

  void Update(float dT);

  void Draw();

  void SetPosition(const float x, const float y) { position_ = {x, y};}

  void SetPosition(const Vector2 pos) { position_ = pos; }

  [[nodiscard]] Vector2 GetPosition() const { return position_; }

  void SetFrame(const int frame) { frame_ = frame; }

  [[nodiscard]] int GetFrame() const { return frame_; }


private:
  Texture enemy_texture_{};

  Texture enemy_shadow_texture_{};

  int frame_{};

  Vector2 position_{};

  Vector2 shadow_pos_{};


  int images_in_sprite_{3};

  float map_scale_{};

  bool set_endpoints_{false};

  // physics component to control movement
  TargetControl* p_control_{nullptr};

  // graphic component to control rendering
  TargetGraphics* p_graphics_{nullptr};

  // array to proton similar to hero's. However, change movement direction.
};

#endif  // RECKLESSAIRFORCE_TARGET_OBJECT_H
