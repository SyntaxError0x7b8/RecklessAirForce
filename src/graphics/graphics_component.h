/**
 * @brief Abstract component class.
 * This class is an interface to be used as a component of GameObject.
 *
 * @date 2025/08/24
 * @author Jorge TM (SyntaxError0x7b8)
 *
 * Including "game-object.h" creates a circular dependency. Hence, the class is
 * declared and only pointers and reference of GameObject can be used.
 *
 */

#ifndef RAFLIB_GRAPHICS_COMPONENT_H_
#define RAFLIB_GRAPHICS_COMPONENT_H_


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

  virtual Vector2 GetTextureDimensions() { return texture_dimensions_; };

protected:
  float images_in_texture_{};

  int frame_{}; // will depend on velocity

  float scale_{1.0f};

  Texture texture_{};

  Texture shadow_{};

  Vector2 shadow_offset_{};

  Vector2 shadow_position_{};

  Vector2 texture_dimensions_{};


};


#endif //RAFLIB_GRAPHICS_COMPONENT_H_