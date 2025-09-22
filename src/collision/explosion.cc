//
// Created by qos on 9/21/25.
//

#include "explosion.h"


Explosion::Explosion() {
   blast_texture_ = LoadTexture(texture_file_);
 }

Explosion::Explosion(const char* file_expl, const int num_frames) {
   texture_file_ = file_expl;
   max_frames_ = num_frames;
   blast_texture_ = LoadTexture(texture_file_);
 }

 Explosion::~Explosion() {
   UnloadTexture(blast_texture_);
 }



 void Explosion::DrawBlast() {

 }

bool Explosion::UpdateBlast() {
  if (frame_ > max_frames_) {
    frame_ = 0;
    return false;
  }
  const float dt = GetFrameTime();
  if (accumulated_time_ >= explosion_frame_rate_) {
    frame_++;
    accumulated_time_ = 0.f;
    return true;
  }
  accumulated_time_ += dt;
  return true;

 }




