//
// Created by qos on 9/21/25.
//

#include "explosion.h"

#include <iostream>

#include "../target/target.h"

Explosion::Explosion() {
   blast_texture_ = LoadTexture(texture_file_);
 }

// constructor to allow other sprites to be loaded
Explosion::Explosion(const char* file_expl, const int num_frames) {
   texture_file_ = file_expl;
   max_frames_ = num_frames;
   blast_texture_ = LoadTexture(texture_file_);
 }

 Explosion::~Explosion() {
   UnloadTexture(blast_texture_);
 }

 /**
  * @brief renders explosion once after calling object is destroyed.
  * The explosion must only be drawn once immediately after object's energy
  * reduces to 0.0 or lower.
  * @param x float, x-coordinate on the screen
  * @param y float, y-coordinate on the screen
  * @param scale float, resize to map's scale or another desired size
  */
void Explosion::DrawBlast(const float x, const float y, const float scale) const {
  // ensure function gets called only when necessary to avoid repeated blasts
  const int frame_width = (blast_texture_.width / max_frames_);

  const Rectangle blast_source_rect {
  static_cast<float>(frame_ * frame_width),
  0.0f,
    static_cast<float>(frame_width),
    static_cast<float>(blast_texture_.height)
  };
  const Rectangle blast_destination_rect {
  x,
  y,
  static_cast<float>(frame_width) * scale,
  static_cast<float>(blast_texture_.height) * scale// 2.0f trial error factor to check best size
  };
  DrawTexturePro(blast_texture_, blast_source_rect,
    blast_destination_rect,
    {},
    0.0f,
    WHITE);
 }

 /**
 * @brief increases the frame after a period of time, and it uses the frame_
 * to control when an explosion should be drawn.
 * @return bool, true frame_ >= 0 and < max_frames_
 */
bool Explosion::UpdateBlast() {
  if (frame_ >= max_frames_) {
    frame_ = 0;
    return false;
  }
  const float dt = GetFrameTime();
  if (accumulated_time_ >= explosion_frame_rate_) {
    frame_++;
    accumulated_time_ = 0.f;
  }
  else {
    accumulated_time_ += dt;
  }
  return true;
 }




