//
// Created by SyntaxError0x7b8on 23/08/2025.
// Part of RAF game
//

#ifndef RECKLESSAIRFORCE_GAME_OBJECT_H
#define RECKLESSAIRFORCE_GAME_OBJECT_H

#include <memory>
#include "graphics_component.h"

class GameObject {
public:
    GameObject() = default;

    ~GameObject() = default;

    void Update();

    //Factory method:
    std::unique_ptr<GameObject> CreateHero();

private:
    std::unique_ptr<GraphicsComponent> graphics_;

};


#endif //RECKLESSAIRFORCE_GAME_OBJECT_H