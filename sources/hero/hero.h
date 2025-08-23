//
// Created by SyntaxError0x7b8on 22/08/2025.
// Part of RAF game
//
#ifndef RECKLESSAIRFORCE_HERO_H
#define RECKLESSAIRFORCE_HERO_H

#include "raylib.h"


class Hero {
public:

    explicit Hero(float);

    ~Hero();

    void drawHero() const;


private:



    const float imagesInTexture = 3.0f;

    int frame {};

    float aircraftScale {1.0f};

    const float shadowReduction {1.5f};

    Texture2D texture {};

    Texture2D shadow {};

    Vector2 aircraftPosition {};

    Vector2 shadowPosition {};

    Vector2 shadowOffset {64.0f * aircraftScale, 64.0f * aircraftScale};

};


#endif //RECKLESSAIRFORCE_HERO_H