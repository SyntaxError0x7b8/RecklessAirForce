#include "raylib.h"


#include "main.h"
#include "map.h"
#include "hero.h"



int main() {

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);

    // Map
    auto map = Map();

    // create hero
    auto hero = Hero(map.GetScale());




    SetTargetFPS(FPS);
    while (!WindowShouldClose()) {
        /*
         * GAME VARIABLES
         */
        const float dT= GetFrameTime(); // frames per second




        /*
         * GAME UPDATE
         */
        map.ScrollMap(dT);




        /*
         * GAME DRAWING
         */
        BeginDrawing();
        ClearBackground(WHITE);
        // draw the map background
        DrawTextureEx(map.GetTexture(), map.GetMapPosition(), 0.0f, map.GetScale(), WHITE);

        // draw the hero
        hero.drawHero();




        EndDrawing();
    }





    return 0;
}