//
// Created by qos on 8/23/25.
//

#include "hero_graphics_component.h"
#include "../gameObject/game_object.h"

#include "raymath.h"

/**
 * @brief Load textures for aircraft and its shadow. scale should match map's
 * scale for better results.
 *
 * @param scale {float}
 */
HeroGraphicsComponent::HeroGraphicsComponent(const float scale) {
  scale_ = scale;
  texture_ = LoadTexture("../assets/heroAircraft/Blue_Plane_Sprite_3x64px.png");
  shadow_ = LoadTexture("../assets/heroAircraft/Shadow_Plane_Sprite_3x64px.png");
  jet_texture_ = LoadTexture("../assets/heroAircraft/rear_jet.png");
  shadow_offset_ = {
    (static_cast<float>(texture_.width) / images_in_texture_) * scale_,
    static_cast<float>(texture_.height) * scale_
  };
  texture_dimensions_.x = ((static_cast<float>(texture_.width) /
    images_in_texture_) * scale_) + 10.0f; // padding
  texture_dimensions_.y = (static_cast<float>(texture_.height) * scale_) + 10.0f;
  jet_position_ = {
    ((static_cast<float>(texture_.width) / images_in_texture_) * scale_) / 2.0f,
    static_cast<float>(texture_.height) * scale_
  };
}

HeroGraphicsComponent::~HeroGraphicsComponent() {
  UnloadTexture(shadow_);
  UnloadTexture(texture_);
  UnloadTexture(jet_texture_);
}

void HeroGraphicsComponent::Update(GameObject& hero) {
  // update airplane / shadow frame
  // first frame for standstill
  if (hero.GetVelocity().x == 0.0f) {
    frame_ = 0;
  }
  else { // moving sideways
    if (hero.GetLastUpdateTime() < hero.GetReactionTime()) {
      frame_ = 1; // started moving so next frame
    }
    else {
      frame_ = 2; // moving for longer, last frame
    }
  }
  jet_frame_++; // burn at FPS speed

  shadow_position_ = Vector2Add(hero.GetScreenPosition(), shadow_offset_);
  jet_position_ = Vector2Add(hero.GetScreenPosition(), jet_offset_);

  right_or_left_= (hero.GetVelocity().x < 0.0f) ? -1.0f : 1.0f;


}


void HeroGraphicsComponent::Draw(GameObject& hero) {
  const float hero_width = (static_cast<float>(texture_.width) / images_in_texture_);
  const float shadow_width = (static_cast<float>(shadow_.width) / images_in_texture_);
  // Hero aircraft
  const Rectangle source_aircraft {
    static_cast<float>(frame_) * hero_width,
    0.0f,
    hero_width * right_or_left_,
    static_cast<float>(texture_.height)
};
  const Rectangle dest_aircraft {
    hero.GetScreenPosition().x,
    hero.GetScreenPosition().y,
    hero_width,
    static_cast<float>(texture_.height)
};
  // Hero aircraft's shadow
  const Rectangle source_shadow {
    static_cast<float>(frame_) * shadow_width,
    0.0f,
    shadow_width * right_or_left_,
    static_cast<float>(shadow_.height)
};
  const Rectangle dest_shadow {
    shadow_position_.x,
    shadow_position_.y,
    shadow_width * shadow_reduction_,
    static_cast<float>(shadow_.height) * shadow_reduction_
};
  // jet stream

  DrawTexturePro(shadow_, source_shadow, dest_shadow, {}, scale_, WHITE); // draw shadow first so aircraft is on top - if needed.
  DrawTexturePro(texture_, source_aircraft, dest_aircraft, {}, scale_, WHITE);
}


