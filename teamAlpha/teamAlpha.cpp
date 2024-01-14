#include <raylib.h>
#include <iostream>
#include <string>
#include "mainMenu.h"
#include "textures.h"
#include "wallet.h"
#include "login.h"
#include "signUp.h"
#include "recoverAssets.h"
#include "myWill.h"
using namespace std;

int main()
{

    float balance = 0;
    int fontSize = 105;
    int counter = 3;
   
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
            case 3:MainMenu(buttonUnselected, buttonUnselected, buttonSelected, logo, font1); SetMouseCursor(MOUSE_CURSOR_POINTING_HAND); if (isClicked) appState = 3;  break;
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
                if (isLoginValid())
                {
                    cout << "Login Successful" << endl;
                    appState = 4;
                }
                else cout << "Not successful" << endl;
                textInputPass = ""; textInputUser = "";
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
                createAccount();
                appState = 0; textInputUser = ""; textInputPass = "";
            }
            break;
        case 3: recoverAssetsMenu("User", balance, fontSize, font1); SetMouseCursor(MOUSE_CURSOR_ARROW);
            if (CheckCollisionRecs(userRec, mousePos)) isSelectedUser = true;
            else isSelectedUser = false;
            if (CheckCollisionRecs(passRec, mousePos)) isSelectedPass = true;
            else isSelectedPass = false;
            if (CheckCollisionRecs(login_signupButtonRec, mousePos)) isSelectedButton = true; else isSelectedButton = false;
            if (isSelectedPass || isSelectedUser || isSelectedButton) SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            else SetMouseCursor(MOUSE_CURSOR_ARROW);
            if (isSelectedButton && isClicked) {
                if (isLoginValid())
                {
                    cout << "Login Successful" << endl;
                    appState = 5;
                }
                else cout << "Not successful" << endl;
                textInputPass = ""; textInputUser = "";

            }
            break;
        case 4:
            WalletMenu(balance, fontSize, font1, triangle);
            if (CheckCollisionRecs(exitBtn, mousePos)) isSelectedExitBtn = true; else isSelectedExitBtn = false;
            if (CheckCollisionRecs(manageBtn, mousePos)) isSelectedManageBtn = true; else isSelectedManageBtn = false;
            if (CheckCollisionRecs(walletBtn, mousePos)) isSelectedWalletBtn = true; else isSelectedWalletBtn = false;
            if (CheckCollisionRecs(addBtn, mousePos)) isSelectedAddBtn = true; else isSelectedAddBtn = false;
            if (CheckCollisionRecs(liabBtn, mousePos)) isSelectedLiabBtn = true; else isSelectedLiabBtn = false;
            if (CheckCollisionRecs(assetBtn, mousePos)) isSelectedAssetBtn = true; else isSelectedAssetBtn = false;
            if (CheckCollisionRecs(addCash, mousePos)) isSelectedAddCash = true; else isSelectedAddCash = false;
            if (isSelectedExitBtn || isSelectedManageBtn || isSelectedWalletBtn || isSelectedAddBtn || isSelectedLiabBtn || isSelectedAssetBtn || isSelectedAddCash || isSelectedTriangleTop || isSelectedTriangleBottom) SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            else SetMouseCursor(MOUSE_CURSOR_ARROW);
            if (isSelectedExitBtn && isClicked) goto close;
            if (CheckCollisionRecs(topTriangleBtn, mousePos)) isSelectedTriangleTop = true; else isSelectedTriangleTop = false;
            if (CheckCollisionRecs(botTriangleBtn, mousePos)) isSelectedTriangleBottom = true; else isSelectedTriangleBottom = false;
            if (isSelectedTriangleTop && isClicked && assetCounter != 0) assetCounter--;
            if (isSelectedTriangleBottom && isClicked && assetCounter < counter) assetCounter++;
            if (isSelectedManageBtn && isClicked) appState = 5; 
            if (isSelectedAddBtn && isClicked)
            {
                addAsset();
                counter++;
            }
            if (isSelectedWalletBtn && isClicked)
            {
                appState = 0;
                balance = 0;
            }
            if (isSelectedAddCash && isClicked)
            {
                float sum;
                cout << "Enter sum to add in wallet: " << endl;
                cin >> sum;
                balance += sum;
            }
            break;
        case 5:
            myWill(font1, mousePos, triangle);
            break;
        default: appState = 0;
        }

    }
close:
    CloseWindow();
}