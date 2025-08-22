#include "raylib.h"


#include "main.h"
#include "map.h"
#include "hero.h"



int main() {

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);

    // Map
    auto map = Map();

    // create hero
    auto hero = Hero(map.getScale());




    SetTargetFPS(FPS);
    while (!WindowShouldClose()) {
        /*
         * GAME VARIABLES
         */
        const float dT= GetFrameTime(); // frames per second




        /*
         * GAME UPDATE
         */
        map.scrollMap(dT);




        /*
         * GAME DRAWING
         */
        BeginDrawing();
        ClearBackground(WHITE);
        // draw the map background
        DrawTextureEx(map.getTexture(), map.getMapPosition(), 0.0f, map.getScale(), WHITE);

        // draw the hero
        hero.drawHero();




        EndDrawing();
    }





    return 0;
}