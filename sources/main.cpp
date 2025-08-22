#include "raylib.h"
#include "raymath.h"

#include "map.h"



int main() {
    constexpr int windowWidth = 640;
    constexpr int windowHeight = 768;
    InitWindow(windowWidth, windowHeight, "Reckless Air Force");

    // Map
    auto map = Map(0.667f, windowWidth, windowHeight);




    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        /*
         * GAME VARIABLES
         */
        const float dT= GetFrameTime(); // frames per second




        /*
         * GAME UPDATE
         */




        /*
         * GAME DRAWING
         */
        BeginDrawing();
        ClearBackground(WHITE);
        // draw the map background
        DrawTextureEx(map.getTexture(), map.getMapPosition(), 0.0f, map.getScale(), WHITE);
        //DrawTextureEx(texture, {}, 0.0f, 1.0f, WHITE);




        EndDrawing();
    }





    return 0;
}