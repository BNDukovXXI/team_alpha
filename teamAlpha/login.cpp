#include <iostream>
#include <raylib.h>
#include <string>
#include <fstream>
#include <ostream>
using namespace std;
bool isSelectedUser, isSelectedPass, isSelectedButton;
string textInputUser = "";
string textInputPass = "";
int letterCountUser = 0, letterCountPass = 0;
string loggedUsername;
void LoginMenu(const char* user, float currentBalance, int fontSize, Font font)
{
	Color c, c1, c2;
	if (isSelectedUser) c = LIGHTGRAY; else c = RAYWHITE;
	if (isSelectedPass) c1 = LIGHTGRAY; else c1 = RAYWHITE;
	if (isSelectedButton) c2 = LIGHTGRAY; else c2 = RAYWHITE;
	int key = GetKeyPressed();
	if (key > 0 && key < 250 && letterCountUser < 25 && isSelectedUser)
	{
		textInputUser += (char)key;
		letterCountUser++;
	}
	if (key > 0 && key < 250 && letterCountPass < 25 && isSelectedPass)
	{
		textInputPass += (char)key;
		letterCountPass++;
	}
	if (IsKeyPressed(KEY_BACKSPACE) && textInputUser.length() > 0 && isSelectedUser) textInputUser.pop_back();
	if (IsKeyPressed(KEY_BACKSPACE) && textInputPass.length() > 0 && isSelectedPass) textInputPass.pop_back();
	const char* userText = textInputUser.c_str();
	const char* passwordText = textInputPass.c_str();


	BeginDrawing();
	ClearBackground(WHITE);
	DrawRectangleRounded(Rectangle{ 600, 200, 700, 700 }, 0.2, 0, RAYWHITE); // Container Rec
	DrawRectangleRounded(Rectangle{ 650, 475, 600, 85 }, 0.2, 0, c); // User Rec
	DrawRectangleRounded(Rectangle{ 650, 600, 600, 85 }, 0.2, 0, c1); // Password Rec
	DrawRectangleRounded(Rectangle{ 850, 775, 200, 85 }, 0.2, 0, c2); // Login button Rec

	DrawRectangleRoundedLines(Rectangle{ 600, 200, 700, 700 }, 0.2, 0, 7, BLACK); // Container Lines
	DrawRectangleRoundedLines(Rectangle{ 650, 475, 600, 85 }, 0.2, 0, 5, BLACK); // Username Rec Lines
	DrawRectangleRoundedLines(Rectangle{ 650, 600, 600, 85 }, 0.2, 0, 5, BLACK); // Password Rec Lines
	DrawRectangleRoundedLines(Rectangle{ 850, 775, 200, 85 }, 0.2, 0, 5, BLACK); // Log In button Lines

	DrawTextEx(font, "Log Into An Existing Account", Vector2{ 640, 300 }, 50, 5, BLACK);
	if (!isSelectedUser && textInputUser.length() == 0) DrawTextEx(font, "Username", Vector2{ 860, 500 }, 40, 5, DARKGRAY);
	DrawTextEx(font, userText, Vector2{ 670, 500 }, 40, 0, BLACK);
	if (!isSelectedPass && textInputPass.length() == 0) DrawTextEx(font, "Password", Vector2{ 860, 625 }, 40, 5, DARKGRAY);
	DrawTextEx(font, passwordText, Vector2{ 670, 625 }, 40, 0, BLACK);
	DrawTextEx(font, "Login", Vector2{ 902, 800 }, 40, 5, DARKGRAY);
	EndDrawing();

}

bool isLoginValid()
{
	ifstream usernameFile("data\\Usernames.txt");
	ifstream passwordFile("data\\Passwords.txt");
	string line;
	int userLineNum = 0;
	int passLineNum = 0;

	if (!usernameFile.is_open())
	{
		cerr << "Error Opening Username File When Logging In" << endl;
		return false;
	}
	if (!passwordFile.is_open())
	{
		cerr << "Error Opening Password File When Logging In" << endl;
		return false;
	}
	while (getline(usernameFile, line))
	{
		if (!line.empty() && line == textInputUser)
		{
			usernameFile.close();
		}
		else userLineNum++;
	}

	while (getline(passwordFile, line))
	{
		if (!line.empty() && line == textInputPass)
		{
			passwordFile.close();
		}
		else passLineNum++;
	}
	if (userLineNum == passLineNum && passLineNum != 0 && userLineNum != 0)
	{
		loggedUsername = textInputUser;
		return true;
	}
	return false;
}