//
// Created by qos on 9/6/25.
//

#include "target.h"


 Target::Target(float scale) {
   target_texture_ = LoadTexture("../assets/other/target.png");
   position_ = {static_cast<float>(GetScreenWidth()) / 2.0f, 300.0f};
   position_bounds_ = {
     position_.x,
     position_.y,
     static_cast<float>(target_texture_.width),
     static_cast<float>(target_texture_.height)
   };
 }
 Target::~Target() {
   UnloadTexture(target_texture_);
 }
 void Target::Update() {
   return;
 }

void Target::Draw() const {
   return;
 }
