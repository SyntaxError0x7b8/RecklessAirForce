//
// Created by qos on 8/22/25.
//

#include "hero.h"
#include "raymath.h"

Hero::Hero(const float mapScale) {
    const float winW = static_cast<float>(GetScreenWidth());
    const float winH = static_cast<float>(GetScreenHeight());
    aircraftScale = mapScale; // get from map
    texture = LoadTexture("../assets/heroAircraft/Blue_Plane_Sprite_3x64px.png");
    shadow = LoadTexture("../assets/heroAircraft/Shadow_Plane_Sprite_3x64px.png");
    aircraftPosition = {(winW - static_cast<float>(texture.width) / imagesInTexture) / 2.0f, winH - 256.0f * aircraftScale};
    shadowPosition = Vector2Add(aircraftPosition, shadowOffset);

}

Hero::~Hero() {
    UnloadTexture(texture);
    UnloadTexture(shadow);
}


void Hero::drawHero() const {
    Rectangle sourceAircraft {
        static_cast<float>(frame),
        0.0f,
        static_cast<float>(texture.width) / imagesInTexture,
        static_cast<float>(texture.height)
    };
    Rectangle destAircraft {
        aircraftPosition.x,
        aircraftPosition.y,
        static_cast<float>(texture.width) / imagesInTexture, // will need to change orientation for left movement
        static_cast<float>(texture.height)
    };
    Rectangle sourceAShadow {
        static_cast<float>(frame),
        0.0f,
        static_cast<float>(shadow.width) / imagesInTexture,
        static_cast<float>(shadow.height)
    };
    Rectangle destShadow {
        shadowPosition.x,
        shadowPosition.y,
        (static_cast<float>(shadow.width) / imagesInTexture) / shadowReduction, // will need to change orientation for left movement
        static_cast<float>(shadow.height) / shadowReduction
    };
    DrawTexturePro(shadow, sourceAShadow, destShadow, {}, aircraftScale, WHITE);
    DrawTexturePro(texture, sourceAircraft, destAircraft, {}, aircraftScale, WHITE);

}
