#pragma once
extern bool isClickedExit;
extern bool isSelectedExitBtn, isSelectedManageBtn, isSelectedWalletBtn, isSelectedAddBtn, isSelectedLiabBtn, isSelectedAssetBtn, isSelectedAddCash, isSelectedTriangleTop, isSelectedTriangleBottom;
Rectangle exitBtn = { 1600, 30, 280,80 }, manageBtn = { 350, 30, 280,80 }, walletBtn = { 20, 30, 280,80 }, addBtn = { 1250, 910, 280,80 }, liabBtn = { 1450, 210, 280,80 }, assetBtn = { 1050, 210, 280,80 }, addCash = { 350, 750, 280, 80 };
Rectangle topTriangleBtn = { 1335,320,122,55 }, botTriangleBtn = { 1335,820,122,55 };
extern int assetCounter;
extern bool isClickedAssets, isClickedLiabilities, isUpdatedAssets, isUpdatedLiabilities;
void WalletMenu(float currentBalance, int fontSize, Font font, Texture2D triangle);
void addAsset();
