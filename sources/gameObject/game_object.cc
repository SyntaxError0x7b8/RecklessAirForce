//
// Created by SyntaxError0x7b8on 23/08/2025.
// Part of RAF game
//

#include "game_object.h"

GameObject::GameObject(GraphicsComponent *pgraphics) : p_graphics_(pgraphics) {
  const auto kwin_w = static_cast<float>(GetScreenWidth());
  const auto kwin_h = static_cast<float>(GetScreenHeight());
  screen_position_ = {
    (kwin_w - 32.0f) / 2.0f,
    kwin_h - (256.0f * p_graphics_->GetScale())
  };

}

GameObject::~GameObject() {
  delete p_graphics_;
}

void GameObject::Update(const float kdeltaTime) {
  // deltaTime will be necessary later
  p_graphics_->Update(*this);
}

void GameObject::Draw() {
  p_graphics_->Draw(*this);
}
