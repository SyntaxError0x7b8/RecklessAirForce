//
// Created by SyntaxError0x7b8on 22/08/2025.
// Part of RAF game
//

#include "map.h"

Map::Map(const int winW, const int winH) {
    const auto mapStartY = (static_cast<float>(texture.height) * mapScale) - static_cast<float>(winH);
    mapPosition = {0.0f, -mapStartY};
}


Map::Map(const float scale, const int winW, const int winH) {
    mapScale = scale;
    const auto mapStartY = (static_cast<float>(texture.height) * mapScale) - static_cast<float>(winH);
    mapPosition = {0.0f, -mapStartY};
}

Map::~Map() {
    UnloadTexture(texture);
}