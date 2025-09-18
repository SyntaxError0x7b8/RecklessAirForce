/**
 * A Top-Down aircraft shooting game. This is a 1943-style inspired game. Its
 * is not meant to be a commercial product, but a learning project. Its main
 * focus is on how to implement different software patterns. In particular the
 * preference of composition over inheritance. It will also serve the purpose
 * of practicing automatic documentation generation and automatic testing.
 */
#include "raflib.h"

#include <cassert>
#include <iostream>

#include "collision/collisions.h"
#include "gameObject/game_object.h"
#include "graphics/proton_graphics.h"
#include "map/map.h"
#include "raylib.h"
#include "target/target.h"

int raflib() {

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);

    // Map
    auto map = Map();

    // create hero (TODO_LATER: create factory class once complex enough)
    // you have to create one ProtonGraphics because it calls members before it exists???
    auto hero = GameObject(map.GetScale());

    // create a practicetarget for testing
    auto target = Target(map.GetScale());

    // try collision
    auto collider = Collisions();





    SetTargetFPS(FPS);
    while (!WindowShouldClose()) {
        //=========================================
        //GAME VARIABLES
        //=========================================
        const float kdT= GetFrameTime(); // frames per second




        //=========================================
        // GAME UPDATE
        //=========================================
        map.ScrollMap(kdT);
        hero.Update(kdT);
        target.Update();
        collider.IsTargetHit(target);




        //========================================
        // GAME DRAWING
        //========================================

        BeginDrawing();
        ClearBackground(WHITE);
        // draw the map background
        DrawTextureEx(map.GetTexture(), map.GetMapPosition(), 0.0f, map.GetScale(), WHITE);

        // draw the hero
        hero.Draw(); // fix shadow as it shows in {0,0} and not scaled down

        // draw target
        target.Draw();




        EndDrawing();
    }





    return 0;
}