//
// Created by qos on 8/23/25.
//

#include "hero_graphics_component.h"
#include "../gameObject/game_object.h"

#include "raymath.h"

/**
 * @brief Load textures for aircraft and its shadow. scale should match map's
 * scale for better results. It also initialises the aircraft's jet exhaust
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
  jet_offset_ = {
    (((static_cast<float>(texture_.width) / images_in_texture_) * scale_) /
      2.0f) -5.0f, // -5.0f trial and error to aircraft's shape
    static_cast<float>(texture_.height) * scale_
  };
}

/**
 * @brief unload the textures used for aircraft, shadow and exhaust.
 */
HeroGraphicsComponent::~HeroGraphicsComponent() {
  UnloadTexture(shadow_);
  UnloadTexture(texture_);
  UnloadTexture(jet_texture_);
}

/**
 * @brief updates frame to be used and direction of movement.
 * @param hero {GameObject, required for position and velocity}
 */
void HeroGraphicsComponent::Update(GameObject& hero) {
  right_or_left_= (hero.GetVelocity().x < 0.0f) ? -1.0f : 1.0f;
  // update airplane / shadow frame
  // first frame for standstill
  if (hero.GetVelocity().x == 0.0f) {
    frame_ = 0;
    jet_offset_.x = (((static_cast<float>(texture_.width) / images_in_texture_)
      * scale_) / 2.0f) -5.0f;
  }
  else { // moving sideways
    if (hero.GetLastUpdateTime() < hero.GetReactionTime()) {
      frame_ = 1; // started moving so next frame
      const float adjust_pos = (right_or_left_ < 0.0f) ? -7.0f : 0.0f;
      jet_offset_.x = (((static_cast<float>(texture_.width) / images_in_texture_)
        * scale_) / 2.0f) + adjust_pos;
    }
    else {
      frame_ = 2; // moving for longer, last frame
      const float adjust_pos = (right_or_left_ < 0.0f) ? -10.0f : +5.0f;
      jet_offset_.x = (((static_cast<float>(texture_.width) / images_in_texture_)
        * scale_) / 2.0f) + adjust_pos;
    }
  }
  if (last_frame_update_ >= frame_update_rate_) {
    jet_frame_ = (jet_frame_++) % jet_images;
    last_frame_update_ = 0.0f;
  }
  else {
    last_frame_update_ += GetFrameTime();
  }

  // draw shado right-below aircraft
  shadow_position_ = Vector2Add(hero.GetScreenPosition(), shadow_offset_);
  // below center aircraft
  jet_position_ = Vector2Add(hero.GetScreenPosition(), jet_offset_);


}

/**
 * @brief from texture image to screen position. It selects in a rectangle the
 * correct frame in order to render it on the screen (visible or not).
 * @param hero {GameObject}
 */
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
  Rectangle source_jet {
    static_cast<float>(jet_texture_.width) * jet_frame_,
    static_cast<float>(jet_texture_.height),
    (static_cast<float>(jet_texture_.width) / jet_images),
    static_cast<float>(jet_texture_.height)
    };
  Rectangle dest_jet {
  jet_position_.x,
  jet_position_.y,
  ((static_cast<float>(jet_texture_.width) / jet_images) / 2.0f) * jet_size_,
  static_cast<float>(jet_texture_.height) * jet_size_
  };


  DrawTexturePro(shadow_, source_shadow, dest_shadow, {}, 0.0f, WHITE); // draw shadow first so aircraft is on top - if needed.
  DrawTexturePro(jet_texture_, source_jet, dest_jet, {}, 0.0, WHITE);
  DrawTexturePro(texture_, source_aircraft, dest_aircraft, {}, 0.0f, WHITE);
}


