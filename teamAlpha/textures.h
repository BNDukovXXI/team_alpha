#pragma once
#include <raylib.h>

Texture2D buttonSelected;
Texture2D buttonUnselected;
Texture2D logo;
Texture2D buttonSelected2;
Texture2D buttonUnselected2;
Texture2D triangle;

void LoadTextures()
{
    Image btnUnselected = LoadImage("resources\\buttonUnselected.png");
    Image btnSelected = LoadImage("resources\\buttonSelected.png");
    Image Logo = LoadImage("resources\\projectLogo.png");
    Image btnUnselected2 = LoadImage("resources\\buttonUnselected.png");
    Image btnSelected2 = LoadImage("resources\\buttonSelected.png");
    Image tr = LoadImage("resources\\triangle.png");
    ImageResize(&btnUnselected, 400, 120);
    ImageResize(&btnSelected, 400, 120);
    ImageResize(&btnUnselected2, 280, 80);
    ImageResize(&btnSelected2, 215, 70);
    logo = LoadTextureFromImage(Logo);
    buttonSelected = LoadTextureFromImage(btnSelected);
    buttonUnselected = LoadTextureFromImage(btnUnselected);
    buttonSelected2 = LoadTextureFromImage(btnSelected2);
    buttonUnselected2 = LoadTextureFromImage(btnUnselected2);
    triangle = LoadTextureFromImage(tr);
}