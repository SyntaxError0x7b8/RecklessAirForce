//
// Created by qos on 10/2/25.
// Refactoring from inheritance to composition.
//

#ifndef RECKLESSAIRFORCE_TARGET_OBJECT_H
#define RECKLESSAIRFORCE_TARGET_OBJECT_H

#include  <memory>
#include "raylib.h"
#include "target_control.h"
#include "../graphics/target_graphics.h"

#define DEFAULT_ENERGY 20.0f

class Explosion;
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

  float energy_ {DEFAULT_ENERGY};

  bool burning_ {};

  // physics component to control movement
  TargetControl* p_control_{nullptr};

  // graphic component to control rendering
  TargetGraphics* p_graphics_{nullptr};

  // array to proton similar to hero's. However, change movement direction.
protected:

  std::shared_ptr<Explosion> target_blast_ = nullptr;

  Vector2 explosion_offset_ {-24.0f, -12.0f};

  float scale_adjustment_ {1.75f};
};

#endif  // RECKLESSAIRFORCE_TARGET_OBJECT_H
