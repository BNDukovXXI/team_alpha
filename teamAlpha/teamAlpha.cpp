#include <raylib.h>
#include <iostream>
using namespace std;

int main()
{
    
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "MyWill Platform");
    SetTargetFPS(60);              
    
    while (!WindowShouldClose())    
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Welcome To MyWill", 600, 200, 80, BLACK);
        EndDrawing();
       
    }
    
    CloseWindow();
    return 0;
}