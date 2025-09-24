//
// Created by qos on 9/21/25.
//

#ifndef RECKLESSAIRFORCE_EXPLOSION_H
#define RECKLESSAIRFORCE_EXPLOSION_H

#include "raylib.h"

class Target;
class Explosion {
  public:
  Explosion();

  //call for other explosion visuals
  Explosion(const char* file_expl, int num_frames);

  ~Explosion();

  bool UpdateBlast();

  void DrawBlast(float x, float y, float scale) const;


private:

  int max_frames_{9};

  const char *texture_file_{"../assets/other/explosion.png"};

  Texture blast_texture_{};

  float explosion_frame_rate_ {0.15f}; // milliseconds

  float accumulated_time_ {};

  int frame_{};
};


#endif  // RECKLESSAIRFORCE_EXPLOSION_H
