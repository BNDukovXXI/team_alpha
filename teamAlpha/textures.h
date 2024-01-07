#pragma once
#include <raylib.h>

Texture2D buttonSelected;
Texture2D buttonUnselected;
Texture2D logo;


void LoadTextures()
{
	Image btnUnselected = LoadImage("resources\\buttonUnselected.png");
	Image btnSelected = LoadImage("resources\\buttonSelected.png");
	Image Logo = LoadImage("resources\\projectLogo.png");
	ImageResize(&btnUnselected, 400, 120);
	ImageResize(&btnSelected, 400, 120);
	logo = LoadTextureFromImage(Logo);
	buttonSelected = LoadTextureFromImage(btnSelected);
	buttonUnselected = LoadTextureFromImage(btnUnselected);
}