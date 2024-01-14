#include <raylib.h>
using namespace std;

void MainMenu(Texture2D loginButton, Texture2D regButton, Texture2D recoverButton, Texture2D pLogo, Font font)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTextEx(font, "Welcome To MyWill", Vector2{ 570, 100 }, 80, 10, BLACK);
    DrawTexture(loginButton, 1920.0f / 1.9f, 350, WHITE);
    DrawTextEx(font, "Log In", Vector2{ 1920.0f / 1.71f, 380 }, 60, 10, BLACK);
    DrawTexture(regButton, 1920.0f / 1.9f, 500, WHITE);
    DrawTextEx(font, "Sign Up", Vector2{ 1920.0f / 1.75f, 530 }, 60, 10, BLACK);
    DrawTexture(recoverButton, 1920.0f / 1.9f, 650, WHITE);
    DrawTextEx(font, "Recover Assets", Vector2{ 1920.0f / 1.87f, 690 }, 45, 10, BLACK);
    DrawTexture(pLogo, 400, 300, WHITE);
    DrawTextEx(font, "The platform where you can manage your assets and create your digital will fast and easy", Vector2{ 200, 1000 }, 30, 7, BLACK);
    EndDrawing();
}