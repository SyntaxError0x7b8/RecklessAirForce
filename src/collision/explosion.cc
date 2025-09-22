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
 bool Explosion::DrawBlast() {
   if (frame_ > 9) {
     frame_ = 0;
     return false;
   }
   else {
     // draw explosion frame and frame++
     //

     return true;
   }
 }



