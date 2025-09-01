/**
 * @brief concrete class that implements GraphicsComponent.
 * This concrete class serves as a component for the game's hero.
 * It implements abstract class GraphicsComponent and requires the use of
 * pointers and references to a GameObject data type.
 * Communication with other components is through position and velocity data
 * members os such GameObject.
 *
 * @date 2025/08/24
 * @author Jorge TM (SyntaxError0x7b8)
 *
 */

#ifndef RAFLIB_HERO_GRAPHICS_COMPONENT_H_
#define RAFLIB_HERO_GRAPHICS_COMPONENT_H_

#include "graphics_component.h"


class HeroGraphicsComponent final : public GraphicsComponent {
public:
  explicit HeroGraphicsComponent(float scale);

  ~HeroGraphicsComponent() override;

  void Update(GameObject&) override; /**< Updates container's members */

  void Draw(GameObject&) override; /**< It renders object's sprite. */

  void SetScale(const float scale) override { scale_ = scale; };

  float GetScale() override { return scale_; };

  Vector2 GetTextureDimensions() override { return  texture_dimensions_; }

private:

  float images_in_texture_ {3.0f};

  float right_or_left_ {1.0f};

  float shadow_reduction_ {0.7f};

  Vector2 jet_position_{};

  Vector2 jet_offset_{};

  Texture jet_texture_{};

  int jet_frame_{};

  int jet_images_ {6};

  float jet_size_ {2.0f};


};


#endif //RAFLIB_HERO_GRAPHICS_COMPONENT_H_