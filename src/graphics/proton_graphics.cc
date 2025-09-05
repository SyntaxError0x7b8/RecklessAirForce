//
// Created by qos on 9/2/25.
//

#include "proton_graphics.h"



ProtonGraphics::ProtonGraphics(const float scale,
                               const float power, const Vector2 pos) :
    proton_position_(pos),
    power_(power),
    scale_(scale) {
  proton_texture_ = LoadTexture(proton_texture_file_);
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

void ProtonGraphics::Update() {
  // function called only if visible and not hit
  if (last_update_time_ >= update_rate_) {
    proton_position_.y += proton_speed_;
    proton_bounds_.y += proton_speed_;
    last_update_time_ = 0.0f;
  }
  else {
    last_update_time_ += GetFrameTime();
  }


  // trying the use of smart pointers to avoid memory leaks
}
void ProtonGraphics::Draw() {
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

bool ProtonGraphics::IsVisible(const Rectangle rectangle) {
  const bool inside = ((rectangle.x >= -proton_texture_.width) &&
      (rectangle.x < GetScreenWidth()) &&
      (rectangle.y >= -proton_texture_.height) &&
      (rectangle.y < GetScreenHeight()));
  return inside;
}

bool ProtonGraphics::SetHit() {
  if (!hit_) { hit_ = true; }
  return hit_;
}




