//
// Created by SyntaxError0x7b8on 23/08/2025.
// Part of RAF game
//

#ifndef RAFLIB_GAME_OBJECT_H_
#define RAFLIB_GAME_OBJECT_H_


//#include "graphics_component.h"
#include "../graphics/hero_graphics_component.h"

class GameObject {
public:
  explicit GameObject(GraphicsComponent *);

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
  GraphicsComponent *p_graphics_{nullptr};


};


#endif //RAFLIB_GAME_OBJECT_H_