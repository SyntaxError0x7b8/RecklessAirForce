//
// Created by qos on 9/6/25.
//

#ifndef RECKLESSAIRFORCE_TARGET_H
#define RECKLESSAIRFORCE_TARGET_H
#include <memory>

#include "../collision/explosion.h"
#include "raylib.h"

#define DEFAULT_ENERGY 20.0f

class Target {
public:
  explicit Target(float scale);

  Target(const char* sprite, const char* shadow, float scale);

  ~Target();

  void Update();

  void Draw() const;

  [[nodiscard]] Rectangle GetTargetBounds() const { return position_bounds_;}

  //bool SetHit(const bool hit) {hit_ = hit; return hit_;}

  void RestoreTarget(float energy = DEFAULT_ENERGY);

  float TakeDamage(float damage = 0.0f);

  [[nodiscard]] float GetEnergy() const { return energy_; }

  void SetEnergy(const float energy) { energy_ = energy;}

  [[nodiscard]] bool IsBurning() const { return burning_; }

  void SetBurning(const bool burn) { burning_ = burn; }

  [[nodiscard]] Vector2 GetPosition() const { return position_; };

  void SetPosition(const Vector2 pos) { position_ = pos; }

  void SetExplosionOffset(const Vector2 offset) { explosion_offset_ = offset; }

  void SetScaleAdjustment(const float scaleAdj) { scale_adjustment_ = scaleAdj; }

  [[nodiscard]] Vector2 GetTargetTextureDimensions() const { return {
    static_cast<float>(target_texture_.width),
    static_cast<float>(target_texture_.height)}; }

  [[nodiscard]] Vector2 GetShadowTextureDimensions() const { return {
    static_cast<float>(target_shadow_.width),
    static_cast<float>(target_shadow_.height)}; }

  Texture& GetTargetTexture() { return target_texture_; }

  private:



  Rectangle position_bounds_{};

  Vector2 position_{};

  Texture target_texture_{};

  Texture target_shadow_{};

  Vector2 shadow_offset_{12.0f, 12.0f};

  Vector2 shadow_position_{};

  float energy_ {DEFAULT_ENERGY};

  bool burning_ {};


protected:

  std::shared_ptr<Explosion> target_blast_ = nullptr;

  Vector2 explosion_offset_ {-24.0f, -12.0f};

  float scale_{};

  float scale_adjustment_ {1.75f};

};

#endif  // RECKLESSAIRFORCE_TARGET_H
