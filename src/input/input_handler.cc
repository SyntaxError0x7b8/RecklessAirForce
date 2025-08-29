//
// Created by qos on 8/28/25.
//

#include "input_handler.h"

void InputHandler::Update(GameObject& hero) {
  return;
}
bool InputHandler::InsideScreen(Rectangle rect) {
  return (
    rect.x >= 0 &&
    rect.x + rect.width <= GetScreenWidth() &&
    rect.y >= 0 &&
    rect.y + rect.height <= GetScreenHeight()
    );
}

