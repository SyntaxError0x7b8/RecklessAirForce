//
// Created by qos on 9/2/25.
//
//#include <memory>
#include "hero_shoot.h"

#include "../gameObject/game_object.h"
#include "../graphics/proton_graphics.h"
#include "raymath.h"

/**
 * @brief static variables used by all bullets shot.
 * @var burst_ {std::vector<std::shared_ptr<ProtonGraphics>> , contains all
 * bullets}
 */
std::vector<std::shared_ptr<ProtonGraphics>> HeroShoot::burst_;

/**
 * @brief Factory method that creates a bullet when SPACEBAR was pressed once.
 * This method creates a bullet by calling member method Shoot. It removes
 * bullets that are no longer on the screen or have hit a target. This saves
 * memory.
 * @param hero {GameObject reference}
 */
void HeroShoot::Update(const GameObject &hero) {
  // create bullet
  if (IsKeyPressed(KEY_SPACE)) {
    Shoot(hero);
  }
  // remove bullets that have hit something or out of the screen
  if (!burst_.empty()) {
      CleanupHeroShoots();
      // update those visible and not hit, nullify the rest
      for (const auto& s_ptr : burst_) {
        if (s_ptr &&
          s_ptr->IsVisible(s_ptr->GetProtonBounds()) &&
          !(s_ptr->IsHit())) {
            s_ptr->Update();
        }
       }
  }
}

/**
 * @brief render bullets stored in vector burst_ on the screen
 */
void HeroShoot::Draw() {
  if (!burst_.empty()) {
    for (const auto& s_ptr : burst_) {
      if (s_ptr && !(s_ptr->IsHit())) {s_ptr->Draw();}
    }
  }
}

/**
 * @brief creates a bullet by calling ProtonGraphics constructor.
 * @param hero {GameObject, needed to get the initial position of the bullet}
 */
void HeroShoot::Shoot(const GameObject &hero) {
  bullet_pos_ = {
    hero.GetRectangle().width / 2,
    0.0f
  };
  bullet_pos_ = Vector2Add(bullet_pos_, hero.GetScreenPosition());

  // creates a new bullet and adds it to vector
  const auto sp_bullet = std::make_shared<ProtonGraphics>(
    hero.GetSharedScale(),
    15.0f,
    bullet_pos_);
  burst_.push_back(sp_bullet);

}

void HeroShoot::CleanupHeroShoots() {
  if (!burst_.empty()) {
    // move this code to a Clean()func and call it again at the end
    for (auto it = burst_.begin(); it != burst_.end(); ++it) {
      if (*it == nullptr ||
        (*it)->IsHit() ||
        !((*it)->IsVisible((*it)->GetProtonBounds()))) {
        // only eliminates the pointer and not the object pointed to,
        // but it is a nullptr, so no object to remove (and smart pointer)
        it = burst_.erase(it);
      }
    } // closed for loop
  }
}



