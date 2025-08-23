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
    explicit GameObject(GraphicsComponent *graphics);

    ~GameObject() = default;

    void Update();

    //Factory method:
    GameObject *CreateHero();

private:
    // (abstract) create hero_graphics_component : graphics_component class
    GraphicsComponent* graphics_;


};


#endif //RECKLESSAIRFORCE_GAME_OBJECT_H