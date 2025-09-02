//
// Created by qos on 9/2/25.
//

#ifndef RECKLESSAIRFORCE_PROTON_GRAPHICS_H
#define RECKLESSAIRFORCE_PROTON_GRAPHICS_H

#include "graphics_component.h"

class ProtonGraphics : public GraphicsComponent {
  public:
  ProtonGraphics(const char* texture, float scale, float power, Vector2 pos);

  ~ProtonGraphics() override;

  void Update(GameObject&) override;

  void Draw(GameObject&) override;

  bool IsVisible(Rectangle, bool) override;

  private:
  Texture proton_texture_{};

  Vector2 proton_position_{};

  float proton_speed_{-5.0f};

  Rectangle proton_bounds_{};

  float power_ {};

  float scale_{};

  bool fired_{};

  bool hit_{};


};

#endif  // RECKLESSAIRFORCE_PROTON_GRAPHICS_H
