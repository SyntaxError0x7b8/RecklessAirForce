/**
 * @brief A container class meant to generate active entities.
 * @date 2025/08/24
 * @author Jorge TM (SyntaxError0x7b8)
 * @param pgraphics {a pointer to GraphicsComponent interface derived object}
 *
 */

#include "game_object.h"

/**
 * @brief Creates a game object. The type of object depends on the components
 * passed as arguments.
 * @param pgraphics {pointer to GraphicsComponent derived object}
 * @param pinput {handle user input for player controlled objects}
 * @param sp_hero_shoot {std::shared_ptr<HeroShoot> bullets fired}
 */
GameObject::GameObject(GraphicsComponent *pgraphics,
  InputHandler *pinput,
  std::shared_ptr<HeroShoot> hs) :
    p_graphics_(pgraphics),
    p_input_(pinput){
  sp_shoot_.swap(hs);
  const auto kwin_w = static_cast<float>(GetScreenWidth());
  const auto kwin_h = static_cast<float>(GetScreenHeight());
  shared_scale_ = p_graphics_->GetScale();
  screen_position_ = {
    (kwin_w - 32.0f) / 2.0f,
    kwin_h - (256.0f * shared_scale_)
  };

  // screen & collision rectangle
  rect_ = {screen_position_.x,
    screen_position_.y,
    p_graphics_->GetTextureDimensions().x,
    p_graphics_->GetTextureDimensions().y
  };

}
/**
 * @brief destroys the game object. The type of game object depends on the
 * components used for its initialisation. It deletes pointers to components.
 *
 */
GameObject::~GameObject() {
  delete p_graphics_;
  delete p_input_; // if enemy, need to delete?
}

/**
 * @brief This method calls its components member of the same name.
 * It will call the component->update() method of each component.
 * @param kdeltaTime {float}
 */
void GameObject::Update(const float kdeltaTime) {

  p_input_->Update(*this, kdeltaTime);
  p_graphics_->Update(*this);
  sp_shoot_->Update(*this);

}

/**
 * @brief Once updated, it draws the object on the screen.
 */
void GameObject::Draw() {
  p_graphics_->Draw(*this);
  sp_shoot_->Draw();
}

/**
 * @brief Updates the position of the rectangle necessary for drawing and
 * collision.
 * @param x {float, object's x position}
 * @param y {float, object's y position}
 */
void GameObject::UpdateRectangle(const float x, const float y) {
  rect_.x = x;
  rect_.y = y;
}

/**
 * @brief Updates the position of the rectangle necessary for drawing and collision.
 * @param newPosition {Vector2, object's position (x, y)}
 */
void GameObject::UpdateRectangle(const Vector2 newPosition) {
  rect_.x = newPosition.x;
  rect_.y = newPosition.y;
}
