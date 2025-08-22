#include "raylib.h"
#include "raymath.h"



int main() {
    constexpr int windowWidth = 1024;
    constexpr int windowHeight = 768;
    InitWindow(windowWidth, windowHeight, "Reckless Air Force");



    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        /*
         * GAME VARIABLES
         */




        /*
         * GAME UPDATE
         */




        /*
         * GAME DRAWING
         */
        BeginDrawing();
        ClearBackground(WHITE);




        EndDrawing();
    }





    return 0;
}