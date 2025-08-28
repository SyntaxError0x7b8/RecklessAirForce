//
// Created by SyntaxError0x7b8on 22/08/2025.
// Part of RAF game
//

#ifndef RAFLIB_MAP_H_
#define RAFLIB_MAP_H_

#include "raylib.h"

class Map {
public:

    Map();

    ~Map();

    [[nodiscard]] Texture2D GetTexture() const { return texture_;}

    [[nodiscard]] Vector2 GetMapPosition() const { return map_position_; };

    [[nodiscard]] float GetScale() const { return map_scale_; };

    void ScrollMap(float);

private:

    const Texture2D texture_{LoadTexture("../assets/ground/RAF_Desert.png")};

    float map_scale_ {1.0f};

    Vector2 map_position_ {};

    const float speed_ {10.0f}; // pixels per second
};


#endif //RAFLIB_MAP_H_