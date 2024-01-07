#include <raylib.h>
#include <iostream>
#include "mainMenu.h"
#include "textures.h"
using namespace std;

int main()
{
    
    Rectangle loginBtnRec = { 1920.0f / 1.9f, 380, 400, 120 };
    Rectangle regBtnRec = { 1920.0f / 1.9f, 500, 400, 120 };
    Rectangle recBtnRec = { 1920.0f / 1.9f, 650, 400, 120 };
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "MyWill Platform");
    SetTargetFPS(60);              
    LoadTextures();
    while (!WindowShouldClose())    
    {
        
        Rectangle mousePos = { GetMouseX(), GetMouseY(), 10,10 };
        int selectedBtn = 0;
        if (CheckCollisionRecs(loginBtnRec, mousePos)) selectedBtn = 1;
        if (CheckCollisionRecs(regBtnRec, mousePos)) selectedBtn = 2;
        if (CheckCollisionRecs(recBtnRec, mousePos)) selectedBtn = 3;
        switch (selectedBtn)
        {
        case 1:MainMenu(buttonSelected, buttonUnselected, buttonUnselected, logo); SetMouseCursor(MOUSE_CURSOR_POINTING_HAND); break;
        case 2:MainMenu(buttonUnselected, buttonSelected, buttonUnselected, logo); SetMouseCursor(MOUSE_CURSOR_POINTING_HAND); break;
        case 3: MainMenu(buttonUnselected, buttonUnselected, buttonSelected, logo); SetMouseCursor(MOUSE_CURSOR_POINTING_HAND); break;
        default: MainMenu(buttonUnselected, buttonUnselected, buttonUnselected, logo); SetMouseCursor(MOUSE_CURSOR_ARROW); break;
        }
       
    }
    
    CloseWindow();
    return 0;
}