//
// Created by qos on 8/23/25.
//

#include "hero_graphics_component.h"
#include "game_object.h"

#include "raymath.h"

HeroGraphicsComponent::HeroGraphicsComponent(const float scale) {
  scale_ = scale;
  texture_ = LoadTexture("../assets/heroAircraft/Blue_Plane_Sprite_3x64px.png");
  shadow_ = LoadTexture("../assets/heroAircraft/Shadow_Plane_Sprite_3x64px.png");
  shadow_offset_ = {
    (static_cast<float>(texture_.width) / images_in_texture_) * scale_,
    static_cast<float>(texture_.height) * scale_
  };
}

HeroGraphicsComponent::~HeroGraphicsComponent() {
  UnloadTexture(shadow_);
  UnloadTexture(texture_);
}

void HeroGraphicsComponent::Update(GameObject& hero) {
  frame_ = static_cast<int>(Vector2Length(hero.GetVelocity()));
  shadow_position_ = Vector2Add(hero.GetScreenPosition(), shadow_offset_);

}


void HeroGraphicsComponent::Draw(GameObject& hero) {
  const Rectangle source_aircraft {
    static_cast<float>(frame_),
    0.0f,
    static_cast<float>(texture_.width) / images_in_texture_,
    static_cast<float>(texture_.height)
};
  const Rectangle dest_aircraft {
    hero.GetScreenPosition().x,
    hero.GetScreenPosition().y,
    (static_cast<float>(texture_.width) / images_in_texture_) * right_or_left_, // will need to change orientation for left movement
    static_cast<float>(texture_.height)
};
  const Rectangle source_shadow {
    static_cast<float>(frame_),
    0.0f,
    (static_cast<float>(shadow_.width) / images_in_texture_) * right_or_left_,
    static_cast<float>(shadow_.height)
};
  const Rectangle dest_shadow {
    shadow_position_.x,
    shadow_position_.y,
    (static_cast<float>(shadow_.width) / images_in_texture_) * shadow_reduction_, // will need to change orientation for left movement
    static_cast<float>(shadow_.height) * shadow_reduction_
};
  DrawTexturePro(shadow_, source_shadow, dest_shadow, {}, scale_, WHITE);
  DrawTexturePro(texture_, source_aircraft, dest_aircraft, {}, scale_, WHITE);
}

