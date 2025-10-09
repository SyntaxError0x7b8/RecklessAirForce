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
  const int frame_x = enemy.GetFrame();
  const Vector2 pos = enemy.GetPosition();
  // source rectangle (image)

  // destination rectangle (screen)

  //Draw enemy's object and its shadow
}


