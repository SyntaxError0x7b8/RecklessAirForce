//
// Created by SyntaxError0x7b8on 22/08/2025.
// Part of RAF game
//

#include "map.h"

Map::Map() {
    const int winW = GetScreenWidth();
    const int winH = GetScreenHeight();
    mapScale = static_cast<float>(winW) / static_cast<float>(texture.width);
    const auto mapStartY = (static_cast<float>(texture.height) * mapScale) - static_cast<float>(winH);
    mapPosition = {0.0f, -mapStartY};
}


Map::~Map() {
    UnloadTexture(texture);
}

void Map::scrollMap(const float deltaTime) {
    if (mapPosition.y < 0.0f) {
        mapPosition.y += deltaTime * speed;
    }
    else {
        return; // send game over message
    }
}
