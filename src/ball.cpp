
#include "ball.h"
#include <raylib.h>
#include <iostream>
using namespace std;

Ball::Ball()
{
    x = 501/2;
    y = 470;
    speedX = 5;
    speedY = 5;
    radius = 5;
}

void Ball::Update()
{
    x += speedX;
    y += speedY;

    if (x + radius >= GetScreenWidth() || x - radius <= 0)    
        speedX *= -1;
    
    if (y + radius >= GetScreenHeight() || y - radius <= 0)
        speedY *= -1;
    
    if (y + radius >= GetScreenHeight()) cout << "Game over!!" << endl;
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, BLACK);
}