//
// Created by qos on 9/21/25.
//

#ifndef RECKLESSAIRFORCE_EXPLOSION_H
#define RECKLESSAIRFORCE_EXPLOSION_H


class Explosion {
  public:
  Explosion();

  Explosion(const char* file_expl, int num_frames);

  ~Explosion();




private:
  void ResetTime() { accumulated_time_ = 0.f; }

  int max_frames {9};

  const char *texture_file_{"../assets/other/explosion.png"};

  float explosion_frame_rate_ {100.0f}; // milliseconds

  float accumulated_time_ {};

  int frame_ {};
};

#endif  // RECKLESSAIRFORCE_EXPLOSION_H
