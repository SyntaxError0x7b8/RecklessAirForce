//
// Created by SyntaxError0x7b8on 23/08/2025.
// Part of RAF game
//

#ifndef RECKLESSAIRFORCE_GRAPHICS_COMPONENT_H_
#define RECKLESSAIRFORCE_GRAPHICS_COMPONENT_H_

#include "raylib.h"

#include "game_object.h"

class GraphicsComponent {
public:
    GraphicsComponent(const char *sprite, int num_img, float scale);

    virtual ~GraphicsComponent();

    virtual void Draw() = 0;

    [[nodiscard]] virtual Vector2 GetScreenPosition() const {
      return screen_position_;
    };

protected:
  float images_in_texture_{};

  int frame_{};

  Texture texture_{};

  Vector2 screen_position_{};

};


#endif //RECKLESSAIRFORCE_GRAPHICS_COMPONENT_H_