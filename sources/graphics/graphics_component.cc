//
// Created by SyntaxError0x7b8on 22/08/2025.
// Part of RAF game
//

#include "graphics_component.h"

GraphicsComponent::GraphicsComponent(const char* sprite,
    const int num_img,
    const float scale) {
  const auto win_w = static_cast<float>(GetScreenWidth());
  const auto win_h = static_cast<float>(GetScreenHeight());
  texture_ = LoadTexture(sprite);
  images_in_texture_ = static_cast<float>(num_img);
  screen_position_ = {
    (win_w - (static_cast<float>(texture_.width) / images_in_texture_)) / 2.0f,
    win_h - (256.0f * scale)
  };
}

GraphicsComponent::~GraphicsComponent() {
  UnloadTexture(texture_);
}

