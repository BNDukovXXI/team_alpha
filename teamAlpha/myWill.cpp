#include <raylib.h>
void myWill(Font font)
{
	BeginDrawing();
	ClearBackground(WHITE);
	DrawTextEx(font,"MyHeirs", {450, 200}, 60, 5, BLACK);
	DrawTextEx(font, "Heir's Assets", { 1050, 200 }, 60, 5, BLACK);
	DrawTextEx(font, "Add Heirs", { 430, 820 }, 60, 5, BLACK);
	DrawTextEx(font, "Add Assets", { 1070, 820 }, 60, 5, BLACK);
	DrawLineBezier({ 360, 800 }, { 760, 800 }, 5, BLACK);
	DrawLineBezier({ 860, 800 }, { 1530, 800 }, 5, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 300, 150, 1300, 800 }, 0.2, 0, 7, BLACK); 
	DrawRectangleRoundedLines(Rectangle{ 360, 270, 400, 630 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 380, 370, 360, 100 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 380, 490, 360, 100 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 380, 610, 360, 100 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 860, 270, 670, 630 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 880, 370, 630, 100 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 880, 490, 630, 100 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 880, 610, 630, 100 }, 0.2, 0, 7, BLACK);
	EndDrawing();
}