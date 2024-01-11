
#include <raylib.h>
using namespace std;

void MainMenu(Texture2D loginButton, Texture2D regButton, Texture2D recoverButton, Texture2D pLogo)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawText("Welcome To MyWill", 500, 100, 100, BLACK);
	DrawTexture(loginButton, 1920.0f / 1.9f, 350, WHITE);
	DrawText("Log In", 1920.0f / 1.75f, 380, 70, BLACK);
	DrawTexture(regButton, 1920.0f / 1.9f, 500, WHITE);
	DrawText("Sign Up", 1920.0f / 1.78f, 530, 70, BLACK);
	DrawTexture(recoverButton, 1920.0f / 1.9f, 650, WHITE);
	DrawText("Recover Assets", 1920.0f / 1.87f, 690, 45, BLACK);
	DrawTexture(pLogo, 400, 300, WHITE);
	DrawText("The platform where you can manage your assets and create your digital will fast and easy", 250, 1000, 30, BLACK);
	EndDrawing();
}
