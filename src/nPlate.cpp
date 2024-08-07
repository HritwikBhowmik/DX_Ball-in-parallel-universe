
#include "nPlate.h"

nPlate::nPlate() {
    height = 7;
    width = 70;
    x = GetScreenWidth() / 2 - width / 2;
    y = GetScreenHeight() - 20;

}

void nPlate::Draw() {
    DrawRectangle(x, y, width, height, BLACK);
}

void nPlate::Update() {
    if (IsKeyDown(KEY_LEFT)) x -= 7;
    if (IsKeyDown(KEY_RIGHT)) x += 7;
    if (x <= 0) x = 0;
    if (x + width >= GetScreenWidth()) x = GetScreenWidth() - width;
}
