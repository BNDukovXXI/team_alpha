#include <raylib.h>
#include <string>
using namespace std;
Rectangle balanceRec { 100, 350, 800, 500 };
Rectangle assetRec{ 1000, 200, 800, 800 };
void drawProgram(const char* user, float currentBalance, int fontSize)
{
	BeginDrawing();

	ClearBackground(LIGHTGRAY);
	DrawRectangle(0, 0, 1920, 120, DARKBLUE);
	DrawText(TextFormat("Hello, %s", user), 100, 200, 100, BLACK);
	DrawRectangleRounded(balanceRec, 0.2, 0, WHITE); //balance rectangle
	DrawRectangleRoundedLines(balanceRec, 0.2, 0, 5, BLACK); // balance rectangle lines
	DrawText("MyWill Balance", 120, 400, 80, BLACK);
	DrawText(TextFormat("%.2f EUR",currentBalance), 120, 560, fontSize, BLACK);
	DrawRectangleRounded(assetRec, 0.2, 0, WHITE); // asset rectangle
	DrawRectangleRoundedLines(assetRec, 0.2, 0, 5, BLACK); // asset rectangle line
	DrawRectangleRounded(Rectangle{1080, 215, 250, 70}, 0.2, 0, WHITE); // asset button
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