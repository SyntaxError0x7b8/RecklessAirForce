//
// Created by SyntaxError0x7b8on 23/08/2025.
// Part of RAF game
//

#ifndef RECKLESSAIRFORCE_GRAPHICS_COMPONENT_H_
#define RECKLESSAIRFORCE_GRAPHICS_COMPONENT_H_

//#include "game_object.h" // creates circular dependency
#include "raylib.h"

class GameObject; // to avoid circular dependency. Use only ref or ptr to GameObject

// interface for any agent graphics (heros or enemies)
class GraphicsComponent {
public:

  GraphicsComponent() = default;

  virtual ~GraphicsComponent() = default;

  virtual void Update(GameObject&) = 0;

  virtual void Draw(GameObject&) = 0;

  virtual void SetScale(const float scale) { scale_ = scale; };

  virtual float GetScale() { return scale_; };

protected:
  float images_in_texture_{};

  int frame_{}; // will depend on velocity

  float scale_{1.0f};

  Texture texture_{};

  Texture shadow_{};

  Vector2 shadow_offset_{};

  Vector2 shadow_position_{};


};


#endif //RECKLESSAIRFORCE_GRAPHICS_COMPONENT_H_