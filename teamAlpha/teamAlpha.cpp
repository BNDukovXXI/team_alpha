#include <raylib.h>
#include <iostream>
#include "mainMenu.h"
#include "textures.h"
#include "wallet.h"
#include "login.h"
#include "signUp.h"
using namespace std;

int main()
{
    
    int balance = 10;
    int fontSize = 105;
    if (balance < 1000) fontSize = 115;
    else if (balance < 10000) fontSize = 110;
    else if (balance < 100000) fontSize = 105;
    else if (balance < 1000000) fontSize = 95;
    else if (balance < 10000000) fontSize = 90;
    else if (balance < 100000000) fontSize = 80;
    Rectangle loginBtnRec = { 1920.0f / 1.9f, 350, 390, 100 };
    Rectangle regBtnRec = { 1920.0f / 1.9f, 500, 390, 100 };
    Rectangle recBtnRec = { 1920.0f / 1.9f, 650, 390, 100 };
    Rectangle userRec = { 650, 475, 600, 85 };
    Rectangle passRec = { 650, 600, 600, 85 };
    Rectangle login_signupButtonRec = { 850, 775, 200, 85 };
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    int appState = 0;
    bool isClicked = false;
    InitWindow(screenWidth, screenHeight, "MyWill Platform");
    SetTargetFPS(60);
    LoadTextures();
    Font font1 = LoadFont("resources\\PetrovSans-Regular.ttf");
    while (!WindowShouldClose())
    {
        Rectangle mousePos = { GetMouseX(), GetMouseY(), 10,10 };
        int selectedBtn = 0;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) isClicked = true; else isClicked = false;
        if (appState == 0) {
            if (CheckCollisionRecs(loginBtnRec, mousePos)) selectedBtn = 1;
            if (CheckCollisionRecs(regBtnRec, mousePos)) selectedBtn = 2;
            if (CheckCollisionRecs(recBtnRec, mousePos)) selectedBtn = 3;
        }
        if (GetCharPressed() == 32)
        {
            MainMenu(buttonUnselected, buttonUnselected, buttonUnselected, logo, font1);
            appState = 0;
        }
        switch (appState)
        {
        case 0:

            switch (selectedBtn)
            {
            case 1:MainMenu(buttonSelected, buttonUnselected, buttonUnselected, logo, font1); SetMouseCursor(MOUSE_CURSOR_POINTING_HAND); if (isClicked) appState = 1; break;
            case 2:MainMenu(buttonUnselected, buttonSelected, buttonUnselected, logo, font1); SetMouseCursor(MOUSE_CURSOR_POINTING_HAND); if (isClicked) appState = 2; break;
            case 3: MainMenu(buttonUnselected, buttonUnselected, buttonSelected, logo, font1); SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);  if (isClicked) appState = 3;  break;
            default: MainMenu(buttonUnselected, buttonUnselected, buttonUnselected, logo, font1); SetMouseCursor(MOUSE_CURSOR_ARROW); break;
            } break;

        case 1:
            LoginMenu("User", balance, fontSize, font1);
            if (CheckCollisionRecs(userRec, mousePos)) isSelectedUser = true;
            else isSelectedUser = false;
            if (CheckCollisionRecs(passRec, mousePos)) isSelectedPass = true;
            else isSelectedPass = false;
            if (CheckCollisionRecs(login_signupButtonRec, mousePos)) isSelectedButton = true; else isSelectedButton = false;
            if (isSelectedPass || isSelectedUser || isSelectedButton) SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            else SetMouseCursor(MOUSE_CURSOR_ARROW); 
            if (isSelectedButton && isClicked) {
                appState = 3; textInputPass = ""; textInputUser = "";
            }
            break;
            
        case 2: 
            SignUpMenu("User", balance, fontSize, font1); SetMouseCursor(MOUSE_CURSOR_ARROW);
            if (CheckCollisionRecs(userRec, mousePos)) isSelectedUser = true;
            else isSelectedUser = false;
            if (CheckCollisionRecs(passRec, mousePos)) isSelectedPass = true;
            else isSelectedPass = false;
            if (CheckCollisionRecs(login_signupButtonRec, mousePos)) isSelectedButton = true; else isSelectedButton = false;
            if (isSelectedPass || isSelectedUser || isSelectedButton) SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            else SetMouseCursor(MOUSE_CURSOR_ARROW);
            if (isSelectedButton && isClicked) {
                appState = 0; textInputUser = ""; textInputPass = "";
            }
            break;
        case 3: WalletMenu("User", balance, fontSize, buttonUnselected2, font1); SetMouseCursor(MOUSE_CURSOR_ARROW); break;
        default: appState = 0;
        }
    }
    CloseWindow(); 
} 