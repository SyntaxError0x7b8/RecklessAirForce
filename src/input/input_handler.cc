//
// Created by qos on 8/28/25.
//

#include "input_handler.h"
#include "raymath.h"

#include "../gameObject/game_object.h"

void InputHandler::Update(GameObject& hero, const float deltaTime) {
  // a key redefinition function to be implemented on the next iteration

  // start without movement
  Vector2 velocity_update{};
  Vector2 acceleration{};

  if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) &&
      (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))) {
    //change of movement when both left and right at the same time
    hero.ResetLastUpdateTime();
  }
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    if (hero.GetLastUpdateTime() >= hero.GetReactionTime()) {
      // move faster to the left
      velocity_update = Vector2Add(velocity_update, {-2.0f, 0.0f});
      acceleration.x = 2.0f;
    }
    else {
      // button has been pressed for less than reaction time
      velocity_update = Vector2Add(velocity_update, {-1.0f, 0.0f});
      acceleration.x = 1.0f;
    }
  }
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    if (hero.GetLastUpdateTime() >= hero.GetReactionTime()) {
      // move faster to the right
      velocity_update = Vector2Add(velocity_update, {2.0f, 0.0f});
      acceleration.x = 2.0f;

    }
    else {
      // button has been pressed for less than reaction time
      velocity_update = Vector2Add(velocity_update, {1.0f, 0.0f});
      acceleration.x = 1.0f;
    }
  }
  if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    velocity_update = Vector2Add(velocity_update, {0.0f, -1.0f});
    acceleration.y = 1.0f;
    }
  if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    velocity_update = Vector2Add(velocity_update, {0.0f, 1.0f});
    acceleration.y = 1.0f;
  }
  // normalise velocity_update but scale x component by acceleration
  //if (velocity_update.x < 0.0f) { acceleration.x *= -1.0f; } //needed?
  velocity_update = Vector2Normalize(velocity_update);
  velocity_update = Vector2Scale(velocity_update, velocity_scale_);
  velocity_update.x *= acceleration.x;

  // update hero's position
  hero.SetVelocity(velocity_update);
  const Vector2 old_position = hero.GetScreenPosition(); // ready to undo
  const Vector2 new_position = Vector2Add(hero.GetScreenPosition(), velocity_update);
  hero.SetScreenPosition(new_position);
  //if new position outside screen then undo
  hero.UpdateRectangle(hero.GetScreenPosition());
  if (!InsideScreen(hero.GetRectangle())) {
    hero.SetScreenPosition(old_position);
    hero.UpdateRectangle(old_position);
    acceleration = {};
    hero.SetVelocity({}); // stop aircraft in all directions (simpler solution)
  }
  // if not moving left or right, reset last update.
  if (!(IsKeyDown(KEY_LEFT ) ||
      IsKeyDown(KEY_RIGHT ) ||
      IsKeyDown(KEY_A) ||
      IsKeyDown(KEY_D))) {
    hero.ResetLastUpdateTime();
  }
  else {
    // add  time to last time update
    hero.UpdateLastUpdateTime(deltaTime);
  }

}

bool InputHandler::InsideScreen(const Rectangle rect) {
  return (
    rect.x >= 0 &&
    rect.x + rect.width <= GetScreenWidth() &&
    rect.y >= 0 &&
    rect.y + rect.height <= GetScreenHeight()
    );
}

