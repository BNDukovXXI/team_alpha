#include <raylib.h>
#include <string>
using namespace std;
Rectangle balanceRec { 100, 350, 800, 500 };
Rectangle assetRec{ 1000, 200, 800, 800 };
bool isSelectedExitBtn, isSelectedManageBtn, isSelectedWalletBtn, isSelectedAddBtn, isSelectedLiabBtn, isSelectedAssetBtn, isSelectedAddCash, isSelectedTriangleTop, isSelectedTriangleBottom;
int assetCounter;
void WalletMenu(const char* user, float currentBalance, int fontSize, Font font, Texture2D triangle)
{
	Color c1, c2, c3, c4, c5, c6, c7;
	if (isSelectedWalletBtn) c1 = LIGHTGRAY; else c1 = RAYWHITE;
	if (isSelectedManageBtn) c2 = LIGHTGRAY; else c2 = RAYWHITE;
	if (isSelectedExitBtn) c3 = LIGHTGRAY; else c3 = RAYWHITE;
	if (isSelectedAddCash) c4 = LIGHTGRAY; else c4 = RAYWHITE;
	if (isSelectedAssetBtn) c5 = LIGHTGRAY; else c5 = RAYWHITE;
	if (isSelectedLiabBtn) c6 = LIGHTGRAY; else c6 = RAYWHITE;
	if (isSelectedAddBtn) c7 = LIGHTGRAY; else c7 = RAYWHITE;

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
	DrawRectangleRounded({ 1050, 210, 280,80 }, 0.2, 0, c5);
	DrawRectangleRoundedLines({ 1050, 210, 280,80 }, 0.2, 0,5, BLACK);
	DrawRectangleRounded({ 1450, 210, 280,80 }, 0.2, 0, c6);
	DrawRectangleRoundedLines({ 1450, 210, 280,80 }, 0.2, 0, 5, BLACK);
	DrawRectangleRounded({ 1250, 915, 280,80 }, 0.2, 0, c7);
	DrawRectangleRoundedLines({ 1250, 910, 280,80 }, 0.2, 0, 5, BLACK);
	DrawRectangleRounded({20, 30, 280,80 }, 0.2, 0, c1);
	DrawRectangleRoundedLines({ 20, 30, 280,80 }, 0.2, 0, 5, BLACK);
	DrawRectangleRounded({ 350, 30, 280,80 }, 0.2, 0, c2);
	DrawRectangleRoundedLines({ 350, 30, 280,80 }, 0.2, 0, 5, BLACK);
	DrawRectangleRounded({ 1600, 30, 280,80 }, 0.2, 0, c3);
	DrawRectangleRoundedLines({ 1600, 30, 280,80 }, 0.2, 0, 5, BLACK);
	DrawRectangleRounded({ 350, 760, 280,80 }, 0.2, 0, c4);
	DrawRectangleRoundedLines({ 350, 760, 280,80 }, 0.2, 0, 5, BLACK);
	DrawTextEx(font, "Wallet", Vector2{ 80, 40 }, 60, 1, BLACK);
	DrawTextEx(font, "Manage Will", Vector2{ 370, 45 }, 50, 1, BLACK);
	DrawTextEx(font, "Exit", Vector2{ 1700, 40 }, 60, 1, BLACK);
	DrawTextEx(font, "Assets", Vector2{ 1115, 220 }, 60, 1, BLACK);
	DrawTextEx(font, "Liabilities", Vector2{ 1490, 220 }, 60, 1, BLACK);
	DrawTextEx(font, "Add New", Vector2{ 1290, 925}, 60, 1, BLACK);
	DrawTextEx(font, "Currently Available", Vector2{ 120, 680 }, 40, 5, DARKGRAY);
	DrawTextEx(font, "Add Cash", { 380,775 }, 50, 5, BLACK);
	DrawLineBezier(Vector2{ 1000, 300 }, Vector2{ 1800, 300 }, 5, BLACK); // split line top
	DrawLineBezier(Vector2{ 1000,900 }, Vector2{ 1800,900 }, 5, BLACK); // split line bottom
	DrawLineBezier(Vector2{ 100,500 }, Vector2{ 900,500 }, 5, BLACK);
	DrawLineBezier(Vector2{ 0,120 }, Vector2{ 1920,120 }, 7, BLACK);

	EndDrawing();
}	