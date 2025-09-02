//
// Created by qos on 9/2/25.
//

#include "proton_graphics.h"
ProtonGraphics::ProtonGraphics(const char* texture, const float scale,
                               const float power, const Vector2 pos) :
    proton_texture_(LoadTexture(texture)),
    proton_position_(pos),
    power_(power),
    scale_(scale) {
  proton_bounds_ = {
    proton_position_.x,
    proton_position_.y,
    static_cast<float>(proton_texture_.width) - 3.0f,
    static_cast<float>(proton_texture_.height) - 3.0f
  };
  fired_ = true;

}
ProtonGraphics::~ProtonGraphics() {
  UnloadTexture(proton_texture_);
}

void ProtonGraphics::Update(GameObject&) {
  if (IsVisible(proton_bounds_, fired_) && !hit_) {
    proton_position_.y += proton_speed_;
  }
  // outside screen or hit will destroy object: handled in another class
}
void ProtonGraphics::Draw(GameObject&) {
  //source
  Rectangle proton_source {
    0.0f,
      0.0f,
      static_cast<float>(proton_texture_.width),
      static_cast<float>(proton_texture_.height)
    };
  // dest on screen
  Rectangle proton_dest {
    proton_position_.x,
    proton_position_.y,
    static_cast<float>(proton_bounds_.width),
    static_cast<float>(proton_bounds_.height)
    };
  //draw it
  DrawTexturePro(proton_texture_,proton_source, proton_dest, {},0.0f, WHITE);
}

bool ProtonGraphics::IsVisible(const Rectangle rectangle, const bool fired) {
  const bool inside = ((rectangle.x >= -proton_texture_.width) &&
      (rectangle.x < GetScreenWidth()) &&
      (rectangle.y >= -proton_texture_.height) &&
      (rectangle.y < GetScreenHeight()));
  return (inside && fired);
}




