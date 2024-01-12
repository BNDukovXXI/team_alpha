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
void drawProgram2(const char* user, float currentBalance, int fontSize)
{
	BeginDrawing();

	ClearBackground(LIGHTGRAY);
	DrawRectangle(0, 0, 1920, 120, DARKBLUE);
	DrawText(TextFormat("Hello, %s", user), 100, 200, 100, BLACK);
	DrawRectangleRounded(balanceRec, 0.2, 0, WHITE); //balance rectangle
	DrawRectangleRoundedLines(balanceRec, 0.2, 0, 5, BLACK); // balance rectangle lines
	DrawText("MyWill Balance", 120, 400, 80, BLACK);
	DrawText(TextFormat("%.2f EUR", currentBalance), 120, 560, fontSize, BLACK);
	DrawRectangleRounded(assetRec, 0.2, 0, WHITE); // asset rectangle
	DrawRectangleRoundedLines(assetRec, 0.2, 0, 5, BLACK); // asset rectangle line
	DrawRectangleRounded(Rectangle{ 1080, 215, 250, 70 }, 0.2, 0, WHITE); // asset button
	DrawRectangleRoundedLines(Rectangle{ 1080, 215, 250, 70 }, 0.2, 0, 5, BLACK); // asset button lines
	DrawRectangleRounded(Rectangle{ 1450, 215, 250, 70 }, 0.2, 0, WHITE); // liabilities button
	DrawRectangleRoundedLines(Rectangle{ 1450, 215, 250, 70 }, 0.2, 0, 5, BLACK); // liabilities lines
	DrawText("Currently Available", 120, 720, 40, DARKGRAY);
	DrawLineBezier(Vector2{ 1000, 300 }, Vector2{ 1800, 300 }, 5, BLACK); // split line top
	DrawLineBezier(Vector2{ 1000,900 }, Vector2{ 1800,900 }, 5, BLACK); // split line bottom
	DrawRectangleRounded(Rectangle{ 1080, 915, 250, 70 }, 0.2, 0, WHITE); // add button
	DrawRectangleRoundedLines(Rectangle{ 1080, 915, 250, 70 }, 0.2, 0, 5, BLACK); // add button lines
	DrawRectangleRounded(Rectangle{ 1450, 915, 250, 70 }, 0.2, 0, WHITE); // list button
	DrawRectangleRoundedLines(Rectangle{ 1450, 915, 250, 70 }, 0.2, 0, 5, BLACK); // list button lines

	EndDrawing();
}	