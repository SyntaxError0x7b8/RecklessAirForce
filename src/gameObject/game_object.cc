/**
 * @brief A container class meant to generate active entities.
 * @date 2025/08/24
 * @author Jorge TM (SyntaxError0x7b8)
 * @param pgraphics {a pointer to GraphicsComponent interface derived object}
 *
 */

#include "game_object.h"

/**
 * @brief Initialise object's position to bottom center of the screen.
 * It assumes a 64px sprite. Screen offset left to personal preference.
 * @param pgraphics {pointer to GraphicsComponent derived object}
 */
GameObject::GameObject(GraphicsComponent *pgraphics, InputHandler *pinput) :
    p_graphics_(pgraphics),
    p_input_(pinput) {
  const auto kwin_w = static_cast<float>(GetScreenWidth());
  const auto kwin_h = static_cast<float>(GetScreenHeight());
  screen_position_ = {
    (kwin_w - 32.0f) / 2.0f,
    kwin_h - (256.0f * p_graphics_->GetScale())
  };
  // screen & collision rectangle
  rect_ = {screen_position_.x,
    screen_position_.y,
    p_graphics_->GetTextureDimensions().x,
    p_graphics_->GetTextureDimensions().y
  };

}

GameObject::~GameObject() {
  delete p_graphics_;
  delete p_input_;
}

void GameObject::Update(const float kdeltaTime) {

  p_input_->Update(*this, kdeltaTime);
  p_graphics_->Update(*this);

}

void GameObject::Draw() {
  p_graphics_->Draw(*this);
}
void GameObject::UpdateRectangle(const float x, const float y) {
  rect_.x = x;
  rect_.y = y;
}
void GameObject::UpdateRectangle(const Vector2 newPosition) {
  rect_.x = newPosition.x;
  rect_.y = newPosition.y;
}
