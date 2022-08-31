/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0

*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "raymath.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    Ray2D ray = (Ray2D){0};
    Ray2DCollision collision = { 0 };
    Vector2 pos = { screenWidth * 0.5, screenHeight * 0.5 };
    ray.direction = (Vector2){ 1, 0 };
    ray.position = pos;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_W)) pos.y -= 5;
        if (IsKeyDown(KEY_S)) pos.y += 5;
        if (IsKeyDown(KEY_A)) pos.x -= 5;
        if (IsKeyDown(KEY_D)) pos.x += 5;

        ray.position = pos;

        ray.direction = Vector2Normalize(Vector2Subtract(GetMousePosition(), ray.position));
        collision = GetRay2DCollisionCircle(ray, (Vector2) { 50, 50 }, 50);

        BeginDrawing();

        ClearBackground(RAYWHITE);
        //DrawRay2D(ray, RED);
        if (collision.hit) {
            DrawLineV(ray.position, collision.point, BLUE);
        }
        DrawCircleLines(50, 50, 50, RED);
        DrawCircleV(pos, 5, RED);
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}