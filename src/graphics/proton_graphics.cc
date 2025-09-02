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

}

bool ProtonGraphics::IsVisible(const Rectangle rectangle, const bool fired) {
  const bool inside = ((rectangle.x >= -proton_texture_.width) &&
      (rectangle.x < GetScreenWidth()) &&
      (rectangle.y >= -proton_texture_.height) &&
      (rectangle.y < GetScreenHeight()));
  return (inside && fired);
}




