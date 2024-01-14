#include <raylib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int heirCounter, heirAssetCounter; int shownHeirs = 3;
bool isSelectedAddHeir, isSelectedAddHeirAsset;
vector <string> heirs = { "My Heir #1", "My Heir #2", "My Heir #3", "My Heir #4", "My Heir #5", "My Heir #6"};
vector <string> heirAssets = { "My Heir's Asset #1", "My Heir's Asset #2", "My Heir's Asset #3", "My Heir's Asset #4", "My Heir's Asset #5", "My Heir's Asset #6" };
void myWill(Font font, Rectangle mousePos, Texture2D triangle)
{
	Color c1 = WHITE, c2 = WHITE;
	Rectangle heirBtn = { 380, 750, 360, 100 }, assetsBtn = { 880, 750, 630, 100 }, heirArrowUp = { 520, 250, 80, 50 }, heirArrowDown{ 520, 670 , 80, 50 }, assetArrowUp{ 1170, 250 , 80, 50 }, assetArrowDown{ 1170, 670 , 80, 50 };
	if (CheckCollisionRecs(mousePos, heirBtn))
	{
		c1 = LIGHTGRAY;
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		
	}
	else if (CheckCollisionRecs(mousePos, assetsBtn))
	{
		c2 = LIGHTGRAY;
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		
	}
	else if (!CheckCollisionRecs(mousePos, heirArrowUp) && !CheckCollisionRecs(mousePos, heirArrowDown) && !CheckCollisionRecs(mousePos, assetArrowUp) && !CheckCollisionRecs(mousePos, assetArrowDown))
	{
		SetMouseCursor(MOUSE_CURSOR_ARROW);

	}
	else
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
	}
	if (CheckCollisionRecs(mousePos, assetsBtn)) isSelectedAddHeirAsset = true; else isSelectedAddHeirAsset = false;
	if (CheckCollisionRecs(mousePos, heirBtn)) isSelectedAddHeir = true; else isSelectedAddHeir = false;
	if (CheckCollisionRecs(mousePos, heirArrowUp) && heirCounter != 0 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		heirCounter--;
	if (CheckCollisionRecs(mousePos, heirArrowDown) && heirCounter < (heirs.size() - 2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		heirCounter++;
	if (CheckCollisionRecs(mousePos, assetArrowUp) && heirAssetCounter != 0 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		heirAssetCounter--;
	if (CheckCollisionRecs(mousePos, assetArrowDown) && heirAssetCounter < (heirAssets.size() - 2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		heirAssetCounter++;
	
	BeginDrawing();
	ClearBackground(WHITE);
	DrawLineBezier({ 360, 800 }, { 760, 800 }, 5, BLACK);
	DrawLineBezier({ 860, 800 }, { 1530, 800 }, 5, BLACK);
	DrawRectangleRounded(Rectangle{ 300, 150, 1300, 800 }, 0.2, 0, WHITE);
	DrawRectangleRounded(Rectangle{ 360, 270, 400, 630 }, 0.2, 0, WHITE);
	DrawRectangleRounded(Rectangle{ 380, 340, 360, 100 }, 0.2, 0, WHITE);
	DrawRectangleRounded(Rectangle{ 380, 460, 360, 100 }, 0.2, 0, WHITE);
	DrawRectangleRounded(Rectangle{ 880, 580, 630, 100 }, 0.2, 0, c1);
	DrawRectangleRounded(heirBtn, 0.2, 0, c1);
	DrawRectangleRounded(Rectangle{ 860, 270, 670, 630 }, 0.2, 0, WHITE);
	DrawRectangleRounded(Rectangle{ 880, 340, 630, 100 }, 0.2, 0, WHITE);
	DrawRectangleRounded(Rectangle{ 880, 460, 630, 100 }, 0.2, 0, WHITE);
	DrawRectangleRounded(Rectangle{ 380, 580, 360, 100 }, 0.2, 0, WHITE);
	DrawRectangleRounded(assetsBtn, 0.2, 0, c2);
	DrawTriangle({ 560, 270 }, { 520,320 }, { 600,320 }, DARKBLUE);
	DrawTexture(triangle, 520, 690, RAYWHITE);
	DrawTriangle({ 1210, 270 }, { 1170,320 }, { 1250,320 }, DARKBLUE);
	DrawTexture(triangle, 1170, 690, RAYWHITE);
	DrawRectangleRoundedLines(Rectangle{ 300, 150, 1300, 800 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 360, 270, 400, 630 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 380, 340, 360, 100 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 380, 460, 360, 100 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 380, 580, 360, 100 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 380, 750, 360, 100 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 860, 270, 670, 630 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 880, 340, 630, 100 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 880, 460, 630, 100 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 880, 580, 630, 100 }, 0.2, 0, 7, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 880, 750, 630, 100 }, 0.2, 0, 7, BLACK);
	DrawTextEx(font, heirs[heirCounter].c_str(), {440, 370}, 50, 5, BLACK);
	DrawTextEx(font, heirs[heirCounter + 1].c_str(), { 440, 490 }, 50, 5, BLACK);
	DrawTextEx(font, heirs[heirCounter + 2].c_str(), { 440, 610 }, 50, 5, BLACK);
	DrawTextEx(font, heirAssets[heirAssetCounter].c_str(), { 885, 370 }, 50, 5, BLACK);
	DrawTextEx(font, heirAssets[heirAssetCounter + 1].c_str(), { 885, 490 }, 50, 5, BLACK);
	DrawTextEx(font, heirAssets[heirAssetCounter + 2].c_str(), { 885, 610 }, 50, 5, BLACK);
	DrawTextEx(font, "MyHeirs", { 450, 200 }, 60, 5, BLACK);
	DrawTextEx(font, "Heir's Assets", { 1050, 200 }, 60, 5, BLACK);
	DrawTextEx(font, "Add Heirs", { 430, 780 }, 60, 5, BLACK);
	DrawTextEx(font, "Add Assets", { 1070, 780 }, 60, 5, BLACK);
	EndDrawing();
}
void addHeir()
{
	string temp;
	cout << "Enter New Heir: " << endl;
	getline(std::cin, temp);
	heirs.push_back(temp);
}
void addHeirAsset()
{
	string temp;
	cout << "Enter New Heir Asset: " << endl;
	getline(std::cin, temp);
	heirAssets.push_back(temp);
}