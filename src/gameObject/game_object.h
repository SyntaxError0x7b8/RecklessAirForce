//
// Created by SyntaxError0x7b8on 23/08/2025.
// Part of RAF game
//

#ifndef RAFLIB_GAME_OBJECT_H_
#define RAFLIB_GAME_OBJECT_H_


// #include "graphics_component.h"
#include <memory>

#include "../graphics/hero_graphics_component.h"
#include "../input/movement_handler.h"
#include "../input/hero_shoot.h"

class GameObject {
public:
  //GameObject(GraphicsComponent *, InputHandler *);

  explicit GameObject(float map_scale);

  ~GameObject();

  void Update(float);

  void Draw();

  [[nodiscard]] Vector2 GetScreenPosition() const { return screen_position_; }

  void SetScreenPosition(const Vector2 screen_position) {
    screen_position_ = screen_position;
  }

  [[nodiscard]] Vector2 GetVelocity() const { return velocity_; }

  void SetVelocity(const Vector2 velocity) { velocity_ = velocity; }

  [[nodiscard]] float GetReactionTime() const { return reaction_time_; }

  [[nodiscard]] float GetLastUpdateTime() const { return last_update_time_; }

  void ResetLastUpdateTime() { last_update_time_ = 0.0f; }

  void UpdateLastUpdateTime(const float dtime) { last_update_time_ += dtime; }

  Rectangle GetRectangle() const { return rect_;}

  void UpdateRectangle(float x, float y);

  void UpdateRectangle(Vector2 newPosition);

  [[nodiscard]] float GetSharedScale() const { return shared_scale_; }

  //Factory method to be implemented

private:
  float reaction_time_ {0.64f}; // will move faster after this time elapsed

  float last_update_time_ {};

  Vector2 screen_position_{};

  Vector2 velocity_{};

  Rectangle rect_{};

  // (abstract) create hero_graphics_component : graphics_component class
  GraphicsComponent *p_graphics_{nullptr};

  InputHandler *p_input_{nullptr};

  //HeroShoot *p_shoot_{nullptr};
  std::shared_ptr<HeroShoot> p_shoot_;

  float shared_scale_{};


};


#endif //RAFLIB_GAME_OBJECT_H_