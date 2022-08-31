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

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Ray2D ray = (Ray2D){ 0 };
    Ray2DCollision collisioncircle = { 0 };
    Ray2DCollision collisionLine = { 0 };
    Vector2 pos = { screenWidth * 0.5, screenHeight * 0.5 };
    ray.direction = (Vector2){ 1, 0 };
    ray.position = pos;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_W)) pos.y -= 5;
        if (IsKeyDown(KEY_S)) pos.y += 5;
        if (IsKeyDown(KEY_A)) pos.x -= 5;
        if (IsKeyDown(KEY_D)) pos.x += 5;

        ray.position = pos;

        ray.direction = Vector2Normalize(Vector2Subtract(GetMousePosition(), ray.position));
        //ray.direction = Vector2Normalize((Vector2) { 1, 0 });
        //collisioncircle = GetRay2DCollisionCircle(ray, (Vector2) { 50, 50 }, 50);
        collisionLine = GetRay2DCollisionLineSegment(ray, (Vector2) { screenWidth * 0.5 + 100, 0 }, (Vector2) { screenWidth * 0.5, screenHeight });

        BeginDrawing();

        ClearBackground(RAYWHITE);
        /*if (collisioncircle.hit) {
            DrawLineV(ray.position, collisioncircle.point, BLUE);
            DrawLineV(collisioncircle.point, Vector2Add(collisioncircle.point, Vector2Scale(collisioncircle.normal, 50)), BLUE);
        }*/

        if (collisionLine.hit) {
            DrawLineV(ray.position, collisionLine.point, BLUE);
            //DrawLineV(collisioncircle.point, Vector2Add(collisioncircle.point, Vector2Scale(collisioncircle.normal, 50)), BLUE);
        }

        //DrawCircleLines(50, 50, 50, RED);
        DrawLineV((Vector2) { screenWidth * 0.5 + 100, 0 }, (Vector2) { screenWidth * 0.5, screenHeight }, RED);
        DrawCircleV(pos, 5, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}