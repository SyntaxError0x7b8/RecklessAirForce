//
// Created by SyntaxError0x7b8on 22/08/2025.
// Part of RAF game
//

#include "map.h"

Map::Map() {
    const int win_w = GetScreenWidth();
    const int win_h = GetScreenHeight();
    map_scale_ = static_cast<float>(win_w) / static_cast<float>(texture_.width);
    const auto map_start_y = (static_cast<float>(texture_.height) * map_scale_) - static_cast<float>(win_h);
    map_position_ = {0.0f, -map_start_y};
}


Map::~Map() {
    UnloadTexture(texture_);
}

void Map::ScrollMap(const float deltaTime) {
    if (map_position_.y < 0.0f) {
        map_position_.y += deltaTime * speed_;
    }
    else {
        return; // send game over message
    }
}
