#include <raylib.h>
#include <string>
using namespace std;
Rectangle balanceRec { 100, 350, 800, 500 };
Rectangle assetRec{ 1000, 200, 800, 800 };
void drawProgram(const char* user, float currentBalance, int fontSize)
{
	BeginDrawing();

	ClearBackground(WHITE);
	DrawRectangleRounded(Rectangle{ 600, 200, 700, 700 }, 0.2, 0, RAYWHITE); // add button
	DrawRectangleRounded(Rectangle{ 850, 775, 200, 85 }, 0.2, 0, RAYWHITE); // add button
	DrawRectangleRounded(Rectangle{ 650, 575, 600, 85 }, 0.2, 0, RAYWHITE); // add button
	DrawRectangleRounded(Rectangle{ 650, 475, 600, 85 }, 0.2, 0, RAYWHITE); // add button

	DrawRectangleRoundedLines(Rectangle{ 600, 200, 700, 700 }, 0.2, 0, 7, BLACK); // list button lines
	DrawRectangleRoundedLines(Rectangle{ 850, 775, 200, 85 }, 0.2, 0, 5, BLACK); // list button lines
	DrawRectangleRoundedLines(Rectangle{ 650, 575, 600, 85 }, 0.2, 0, 5, BLACK); // list button lines
	DrawRectangleRoundedLines(Rectangle{ 650, 475, 600, 85 }, 0.2, 0, 5, BLACK); // list button lines

	DrawText("Login", 900, 800, 40, DARKGRAY);
	DrawText("Password", 850, 600, 40, DARKGRAY);
	DrawText("Email", 900, 500, 40, DARKGRAY);

	EndDrawing();

}
void drawProgram1(const char* user, float currentBalance, int fontSize)
{
	BeginDrawing();

	ClearBackground(WHITE);
	DrawRectangleRounded(Rectangle{ 600, 200, 700, 700 }, 0.2, 0, RAYWHITE); // add button
	DrawRectangleRounded(Rectangle{ 850, 775, 200, 85 }, 0.2, 0, RAYWHITE); // add button
	DrawRectangleRounded(Rectangle{ 650, 575, 600, 85 }, 0.2, 0, RAYWHITE); // add button
	DrawRectangleRounded(Rectangle{ 650, 475, 600, 85 }, 0.2, 0, RAYWHITE); // add button

	DrawRectangleRoundedLines(Rectangle{ 600, 200, 700, 700 }, 0.2, 0, 7, BLACK); // list button lines
	DrawRectangleRoundedLines(Rectangle{ 850, 775, 200, 85 }, 0.2, 0, 5, BLACK); // list button lines
	DrawRectangleRoundedLines(Rectangle{ 650, 575, 600, 85 }, 0.2, 0, 5, BLACK); // list button lines
	DrawRectangleRoundedLines(Rectangle{ 650, 475, 600, 85 }, 0.2, 0, 5, BLACK); // list button lines

	DrawText("Sign Up", 875, 800, 40, DARKGRAY);
	DrawText("Password", 850, 600, 40, DARKGRAY);
	DrawText("Email", 900, 500, 40, DARKGRAY);

	EndDrawing();
}
void drawProgram2(const char* user, float currentBalance, int fontSize, Texture2D button, Font font)
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
	DrawTexture(button, 1450, 915, RAYWHITE);
	DrawTexture(button, 20, 30, RAYWHITE);
	DrawTexture(button, 350, 30, RAYWHITE);
	DrawTextEx(font, "Currently Available", Vector2{ 120, 680 }, 40, 5, DARKGRAY);
	DrawLineBezier(Vector2{ 1000, 300 }, Vector2{ 1800, 300 }, 5, BLACK); // split line top
	DrawLineBezier(Vector2{ 1000,900 }, Vector2{ 1800,900 }, 5, BLACK); // split line bottom
	DrawLineBezier(Vector2{ 100,500 }, Vector2{ 900,500 }, 5, BLACK);

	EndDrawing();
}	