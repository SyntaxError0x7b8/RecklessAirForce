//
// Created by qos on 10/2/25.
//

#include "target_object.h"

TargetObject::TargetObject(const char* sprite, const char* shadow,
                           const int num_images, const float map_scale) {
  /*enemy_texture_ = LoadTexture(sprite);
  enemy_shadow_texture_ = LoadTexture(shadow);
  images_in_sprite_ = num_images;
  map_scale_ = map_scale;*/
  p_control_ = new TargetControl();
  p_graphics_ = new TargetGraphics(sprite, shadow, num_images, map_scale);
  p_control_->SetCoordinates(*this);


}
TargetObject::~TargetObject() {
  UnloadTexture(enemy_texture_);
  UnloadTexture(enemy_shadow_texture_);
  delete p_control_;
  delete p_graphics_;
}
void TargetObject::Update(const float dT) { // dT = time per frame
  // move (i.e. update() TargetControl
  p_control_->Update(*this, dT);


  //if left screen or destroyed, set_positions false again
}


