#include <raylib.h>
#include <string>
using namespace std;
Rectangle balanceRec { 100, 350, 800, 500 };
Rectangle assetRec{ 1000, 200, 800, 800 };

void WalletMenu(const char* user, float currentBalance, int fontSize, Texture2D button, Font font)
{
	BeginDrawing();

	ClearBackground(LIGHTGRAY);
	DrawRectangle(0, 0, 1920, 120, DARKBLUE);
	DrawTextEx(font, TextFormat("Hello, %s", user), Vector2{ 150, 200 }, 100, 10, BLACK);
	DrawRectangleRounded(balanceRec, 0.2, 0, WHITE); //balance rectangle
	DrawRectangleRoundedLines(balanceRec, 0.2, 0, 5, BLACK); // balance rectangle lines
	DrawTextEx(font, "MyWill Balance", Vector2{ 270, 400 }, 80, 1, BLACK);
	DrawTextEx(font, TextFormat("%.2f EUR", currentBalance), Vector2{ 120,560 }, fontSize, 10, BLACK);
	DrawRectangleRounded(assetRec, 0.2, 0, WHITE); // asset rectangle
	DrawRectangleRoundedLines(assetRec, 0.2, 0, 5, BLACK); // asset rectangle line
	DrawTexture(button, 1050, 210, RAYWHITE);
	DrawTexture(button, 1450, 210, RAYWHITE);
	DrawTexture(button, 1050, 915, RAYWHITE);
	DrawTexture(button, 20, 30, RAYWHITE);
	DrawTexture(button, 350, 30, RAYWHITE);
	DrawTexture(button, 1600, 30, RAYWHITE);
	DrawTextEx(font, "Wallet", Vector2{ 80, 40 }, 60, 1, BLACK);
	DrawTextEx(font, "Manage Will", Vector2{ 370, 45 }, 50, 1, BLACK);
	DrawTextEx(font, "Exit", Vector2{ 1700, 40 }, 60, 1, BLACK);
	DrawTextEx(font, "Assets", Vector2{ 1115, 220 }, 60, 1, BLACK);
	DrawTextEx(font, "Liabilities", Vector2{ 1490, 220 }, 60, 1, BLACK);
	DrawTextEx(font, "Add New", Vector2{ 1090, 925}, 60, 1, BLACK);
	DrawTextEx(font, "Currently Available", Vector2{ 120, 680 }, 40, 5, DARKGRAY);
	DrawLineBezier(Vector2{ 1000, 300 }, Vector2{ 1800, 300 }, 5, BLACK); // split line top
	DrawLineBezier(Vector2{ 1000,900 }, Vector2{ 1800,900 }, 5, BLACK); // split line bottom
	DrawLineBezier(Vector2{ 100,500 }, Vector2{ 900,500 }, 5, BLACK);
	DrawLineBezier(Vector2{ 0,120 }, Vector2{ 1920,120 }, 7, BLACK);

	EndDrawing();
}	