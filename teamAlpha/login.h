#pragma once
extern bool isSelectedUser;
extern bool isSelectedPass;
extern bool isSelectedButton;
extern std::string textInputUser;
extern std::string textInputPass;

extern std::string loggedUsername;
void LoginMenu(const char* user, float currentBalance, int fontSize, Font font);
bool isLoginValid();