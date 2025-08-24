//
// Created by SyntaxError0x7b8on 23/08/2025.
// Part of RAF game
//

#ifndef RECKLESSAIRFORCE_GAME_OBJECT_H
#define RECKLESSAIRFORCE_GAME_OBJECT_H

#include <memory>
#include "graphics_component.h"

class GameObject {
public:
  explicit GameObject(GraphicsComponent *graphics);

  ~GameObject();

  void Update(float);

  void Draw();

  [[nodiscard]] Vector2 GetScreenPosition() const { return screen_position_; }

  void SetScreenPosition(const Vector2 screen_position) {
    screen_position_ = screen_position;
  }

  [[nodiscard]] Vector2 GetVelocity() const { return velocity_; }

  void SetVelocity(const Vector2 velocity) { velocity_ = velocity; }

  //Factory method to be implemented

private:
  Vector2 screen_position_{};

  Vector2 velocity_{};

    // (abstract) create hero_graphics_component : graphics_component class
  GraphicsComponent* p_graphics_{nullptr};


};


#endif //RECKLESSAIRFORCE_GAME_OBJECT_H