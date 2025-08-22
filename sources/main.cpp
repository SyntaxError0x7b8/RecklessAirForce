#include "raylib.h"
#include "raymath.h"

#include "map.h"



int main() {
    constexpr int WINDOWWIDTH = 768;
    constexpr int WINDOWHEIGHT = 1024;
    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Reckless Air Force");

    // Map
    auto map = Map();




    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        /*
         * GAME VARIABLES
         */
        const float dT= GetFrameTime(); // frames per second




        /*
         * GAME UPDATE
         */
        map.moveMap(dT);




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