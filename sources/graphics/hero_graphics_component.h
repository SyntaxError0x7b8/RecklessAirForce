//
// Created by qos on 8/23/25.
//

#ifndef RECKLESSAIRFORCE_HERO_GRAPHICS_COMPONENT_H_
#define RECKLESSAIRFORCE_HERO_GRAPHICS_COMPONENT_H_

#include "graphics_component.h"


class HeroGraphicsComponent : public GraphicsComponent
{
public:
  explicit HeroGraphicsComponent(float scale);

  ~HeroGraphicsComponent() override;

  void Update(GameObject &) override;

  void Draw(GameObject &) override;

  void SetScale(const float scale) override { scale_ = scale; };

  float GetScale() override { return scale_; };

private:

  float images_in_texture_ {3.0f};

  float right_or_left_ {1.0f};

  float shadow_reduction_ {0.7f};

};


#endif //RECKLESSAIRFORCE_HERO_GRAPHICS_COMPONENT_H_