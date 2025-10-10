//
// Created by qos on 10/8/25.
//

#include "target_graphics.h"

#include "../target/target_object.h"

TargetGraphics::TargetGraphics(const char* sprite,
    const char* shadow,
    const int num_images,
    const float map_scale) {
  sprite_texture_ = LoadTexture(sprite);
  shadow_texture_ = LoadTexture(shadow);
  num_images_ = num_images;
  map_scale_ = map_scale;
  shadow_offset_ = {
    (static_cast<float>(shadow_texture_.width) /
        static_cast<float>(num_images_)) * map_scale_,
    static_cast<float>(shadow_texture_.height) * map_scale_
  };

}

 TargetGraphics::~TargetGraphics() {
  UnloadTexture(sprite_texture_);
  UnloadTexture(shadow_texture_);
}
 void TargetGraphics::Draw(TargetObject& enemy) {
  int frame_x = enemy.GetFrame();
  const Vector2 pos = enemy.GetPosition();
  // source rectangle (image)
  Rectangle target_source_rect{
  static_cast<float>(frame_x),
  0.0f,
  static_cast<float>(sprite_texture_.width / num_images_),
  static_cast<float>(sprite_texture_.height)
  };
  Rectangle shadow_source_rect{
    static_cast<float>(frame_x),
    0.0f,
    static_cast<float>(shadow_texture_.width / num_images_),
    static_cast<float>(shadow_texture_.height)
    };
  // destination rectangle (screen)
  Rectangle target_dest_rect {
  pos.x,
  pos.y,
  static_cast<float>(sprite_texture_.width / num_images_) * map_scale_,
  static_cast<float>(sprite_texture_.height) * map_scale_
  };
  Rectangle shadow_dest_rect {
    pos.x + shadow_offset_.x,
    pos.y + shadow_offset_.y,
    static_cast<float>(shadow_texture_.width / num_images_) * map_scale_,
    static_cast<float>(shadow_texture_.height) * map_scale_
    };

  //Draw enemy's object and its shadow
  DrawTexturePro(sprite_texture_,
    target_source_rect,
    shadow_source_rect,
    {},0.0f, WHITE);
  DrawTexturePro(shadow_texture_,
    shadow_source_rect,
    shadow_dest_rect,
    {}, 0.0f, WHITE);
}


