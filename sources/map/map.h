//
// Created by SyntaxError0x7b8on 22/08/2025.
// Part of RAF game
//

#ifndef RECKLESSAIRFORCE_MAP_H
#define RECKLESSAIRFORCE_MAP_H

#include "raylib.h"

class Map {
public:

    Map();

    ~Map();

    [[nodiscard]] Texture2D getTexture() const { return texture;}

    [[nodiscard]] Vector2 getMapPosition() const { return mapPosition; };

    [[nodiscard]] float getScale() const { return mapScale; };

    void moveMap(float);

private:

    const Texture2D texture{LoadTexture("../assets/ground/RAF_Desert.png")};

    float mapScale {1.0f};

    Vector2 mapPosition {};

    const float speed {10.0f}; // pixels per second
};


#endif //RECKLESSAIRFORCE_MAP_H