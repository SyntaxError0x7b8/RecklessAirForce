//
// Created by qos on 9/6/25.
//

#include "target.h"

/**
 * @brief It creates a practice target for code implementation and debugging.
 * @param scale to reflect map's scale
 */
Target::Target(const float scale) {
   scale_ = scale;
   target_texture_ = LoadTexture("../assets/other/target.png");
   position_ = {static_cast<float>(GetScreenWidth()) / 2.0f, 200.0f};
   position_bounds_ = {
     position_.x,
     position_.y,
     static_cast<float>(target_texture_.width) * scale_,
     static_cast<float>(target_texture_.height) * scale_
   };
 }

 Target::~Target() {
   UnloadTexture(target_texture_);
 }


 void Target::Update() {
   if (energy_ <= 0.0) {
     // allow to restore target
     // place here guard for explosion
     RestoreTarget();
   }
 }

 /**
  * @brief It renders practice target on the screen if its energy is positive.
  */
void Target::Draw() const {
   const Rectangle source_rect {
     0.0f, 0.0f,
     static_cast<float>(target_texture_.width),
     static_cast<float>(target_texture_.height)};

   if (energy_ >= 0.0) {
     DrawTexturePro(target_texture_, source_rect,position_bounds_, {}, 0.0f, WHITE);
     DrawRectangleLinesEx(position_bounds_, 2.0f, RED);
   }
 }

/**
 * @brief Allows a fresh new target re-using the same Target object.
 */
void Target::RestoreTarget() {
   if (IsKeyPressed(KEY_T)) {
     energy_ = ENERGY;
     //hit_ = false;
   }
 }
float Target::TakeDamage(const float damage) {
  if (energy_ > 0.0) {
    energy_ -= damage;
    return energy_;
  }
  return 0.0f;
}
