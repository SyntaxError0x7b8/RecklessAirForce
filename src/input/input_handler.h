//
// Created by qos on 8/28/25.
//

#ifndef RECKLESSAIRFORCE_INPUT_HANDLER_H
#define RECKLESSAIRFORCE_INPUT_HANDLER_H

//#include "../gameObject/game_object.h"
#include "raylib.h"
class GameObject; // to avoid circular dependency. Use only ref or ptr to GameObject

class InputHandler {
  public:
  InputHandler() = default;

  ~InputHandler() = default;

  void Update(GameObject &hero);

  bool InsideScreen(Rectangle rect);

  private:
  GameObject *pplayer_object_ {nullptr};

  Vector2 last_position_ {};

  Vector2 velocity_ {};
};

#endif  // RECKLESSAIRFORCE_INPUT_HANDLER_H
