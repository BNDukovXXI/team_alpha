#include <iostream>
#include <raylib.h>
#include "login.h"
using namespace std;
int letterCountUser1 = 0, letterCountPass1 = 0;
void SignUpMenu(const char* user, float currentBalance, int fontSize,Font font)
{
	Color c, c1, c2;
	if (isSelectedUser) c = LIGHTGRAY; else c = RAYWHITE;
	if (isSelectedPass) c1 = LIGHTGRAY; else c1 = RAYWHITE;
	if (isSelectedButton) c2 = LIGHTGRAY; else c2 = RAYWHITE;
	int key = GetKeyPressed();
	if (key > 0 && key < 250 && letterCountUser1 < 25 && isSelectedUser)
	{
		textInputUser += (char)key;
		letterCountUser1++;
	}
	if (key > 0 && key < 250 && letterCountPass1 < 25 && isSelectedPass)
	{
		textInputPass += (char)key;
		letterCountPass1++;
	}
	if (IsKeyPressed(KEY_BACKSPACE) && textInputUser.length() > 0 && isSelectedUser) textInputUser.pop_back();
	if (IsKeyPressed(KEY_BACKSPACE) && textInputPass.length() > 0 && isSelectedPass) textInputPass.pop_back();
	const char* userText = textInputUser.c_str();
	const char* passwordText = textInputPass.c_str();
	BeginDrawing();
	ClearBackground(WHITE);
	DrawRectangleRounded(Rectangle{ 600, 200, 700, 700 }, 0.2, 0, RAYWHITE); // container rec
	DrawRectangleRounded(Rectangle{ 650, 475, 600, 85 }, 0.2, 0, c); // user rec
	DrawRectangleRounded(Rectangle{ 650, 600, 600, 85 }, 0.2, 0, c1); // password rec
	DrawRectangleRounded(Rectangle{ 850, 775, 200, 85 }, 0.2, 0, c2); // Sign Up button rec

    DrawRectangleRoundedLines(Rectangle{ 600, 200, 700, 700 }, 0.2, 0, 7, BLACK); // Container Lines
	DrawRectangleRoundedLines(Rectangle{ 650, 475, 600, 85 }, 0.2, 0, 5, BLACK); // Username Rec Lines
	DrawRectangleRoundedLines(Rectangle{ 650, 600, 600, 85 }, 0.2, 0, 5, BLACK); // Password Rec Lines
    DrawRectangleRoundedLines(Rectangle{ 850, 775, 200, 85 }, 0.2, 0, 5, BLACK); // Sign up button Lines
	DrawTextEx(font, "Create A New Account", Vector2{ 670, 300 }, 60, 5, BLACK);
	if (!isSelectedUser && textInputUser.length() == 0) DrawTextEx(font, "Username", Vector2{ 860, 500 }, 40, 5, DARKGRAY);
	if (!isSelectedPass && textInputPass.length() == 0) DrawTextEx(font, "Password", Vector2{ 860, 625 }, 40, 5, DARKGRAY);
	DrawTextEx(font, "Sign Up", Vector2{ 880, 800 }, 40, 5, DARKGRAY);
	DrawTextEx(font, userText, Vector2{ 670, 500 }, 40, 0, BLACK);
	DrawTextEx(font, passwordText, Vector2{ 670, 625 }, 40, 0, BLACK);
	EndDrawing();
}