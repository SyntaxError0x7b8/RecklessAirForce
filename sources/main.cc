#include "raylib.h"


#include "main.h"

#include "game_object.h"
#include "map.h"




int main() {

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);

    // Map
    auto map = Map();

    // create hero (todo: create factory class once complex enough)
    auto hero = GameObject(new HeroGraphicsComponent(map.GetScale()));




    SetTargetFPS(FPS);
    while (!WindowShouldClose()) {
        /*
         * GAME VARIABLES
         */
        const float kdT= GetFrameTime(); // frames per second




        /*
         * GAME UPDATE
         */
        map.ScrollMap(kdT);
        hero.Update(kdT);




        /*
         * GAME DRAWING
         */
        BeginDrawing();
        ClearBackground(WHITE);
        // draw the map background
        DrawTextureEx(map.GetTexture(), map.GetMapPosition(), 0.0f, map.GetScale(), WHITE);

        // draw the hero
        hero.Draw(); // fix shadow as it shows in {0,0} and not scaled down




        EndDrawing();
    }





    return 0;
}