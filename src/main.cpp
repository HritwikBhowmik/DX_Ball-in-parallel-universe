#include "ball.h"
#include "nPlate.h"
#include "sounds.h"
#include <raylib.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main() {
    int score = 0, des1 = 0, des2 = 0, des3 = 0, des4 = 0;
    // row 1
    float x11[8] = {0,0,0,0,0,0,0,0};
    float y11[8] = {0,0,0,0,0,0,0,0};
    float width11[8] = {62,62,62,62,62,62,62,62};
    float height11[8] = {25,25,25,25,25,25,25,25};
    // row 2
    float x12[8] = {0,0,0,0,0,0,0,0};
    float y12[8] = {26,26,26,26,26,26,26,26};
    float width12[8] = {62,62,62,62,62,62,62,62};
    float height12[8] = {25,25,25,25,25,25,25,25};
    // row 3
    float x13[8] = {0,0,0,0,0,0,0,0};
    float y13[8] = {52,52,52,52,52,52,52,52};
    float width13[8] = {62,62,62,62,62,62,62,62};
    float height13[8] = {25,25,25,25,25,25,25,25};
    // row 4
    float x14[8] = {0,0,0,0,0,0,0,0};
    float y14[8] = {78,78,78,78,78,78,78,78};
    float width14[8] = {62,62,62,62,62,62,62,62};
    float height14[8] = {25,25,25,25,25,25,25,25};
    // row 1
    float x21[4] = {125,125,125,125};
    float y21[4] = {0,0,0,0};
    float width21[4] = {62,62,62,62};
    float height21[4] = {25,25,25,25};
    // row 2
    float x22[8] = {0,0,0,0,0,0,0,0};
    float y22[8] = {26,26,26,26,26,26,26,26};
    float width22[8] = {62,62,62,62,62,62,62,62};
    float height22[8] = {25,25,25,25,25,25,25,25};
    // row 3
    float x23[4] = {125,125,125,125};
    float y23[4] = {52,52,52,52};
    float width23[8] = {62,62,62,62};
    float height23[8] = {25,25,25,25};
    // row 4
    float x24[8] = {0,0,0,0,0,0,0,0};
    float y24[8] = {78,78,78,78,78,78,78,78};
    float width24[8] = {62,62,62,62,62,62,62,62};
    float height24[8] = {25,25,25,25,25,25,25,25};

    int screenWidth = 501, screenHeight = 501, chLevel = 0;
    Color white = {255, 255, 255, 255};
    InitWindow(screenWidth, screenHeight, "DX Ball");
    SetTargetFPS(60);

    nPlate plate = nPlate();
    Ball ball = Ball();
    Sounds sounds = Sounds();

    cout << "Select level from [1-5]" << endl;
    cout << "Enter level: ";
    cin >> chLevel;

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(white);

        ball.Update();
        plate.Update(); 
        plate.Draw(); 

        // nPlate interact with ball
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{plate.x, plate.y, plate.width, plate.height})){
            ball.speedY *= -1;
            PlaySound(sounds.plateCollideSound);
        }

        // for level 01
        if (chLevel == 1) {
            // build bricks
            for (int i = 0; i < 8; i++){
                DrawRectangle(x11[i] + 63* i, y11[i], width11[i], height11[i], BLACK);
                DrawRectangle(x12[i] + 63* i, y12[i], width12[i], height12[i], BLACK);
                DrawRectangle(x13[i] + 63* i, y13[i], width13[i], height13[i], BLACK);
                DrawRectangle(x14[i] + 63* i, y14[i], width14[i], height14[i], BLACK);
            }

            // destroy bricks
            for (int i = 0; i < 8; i++){
                if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x11[i] +63*i, y11[i], width11[i], height11[i]})){
                    ball.speedY *= -1;
                    x11[i] = 0;
                    y11[i] = 0;
                    width11[i] = 0;
                    height11[i] = 0;
                    PlaySound(sounds.brickCollideSound);
                    des1++;
                    score++;
                }
                if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x12[i] +63*i, y12[i], width12[i], height12[i]})){
                    ball.speedY *= -1;
                    x12[i] = 0;
                    y12[i] = 0;
                    width12[i] = 0;
                    height12[i] = 0;
                    PlaySound(sounds.brickCollideSound);
                    des2++;
                    score++;
                }
                if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x13[i] +63*i, y13[i], width13[i], height13[i]})){
                    ball.speedY *= -1;
                    x13[i] = 0;
                    y13[i] = 0;
                    width13[i] = 0;
                    height13[i] = 0;
                    PlaySound(sounds.brickCollideSound);
                    des3++;
                    score++;
                }
                if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x14[i] +63*i, y14[i], width14[i], height14[i]})){
                    ball.speedY *= -1;
                    x14[i] = 0;
                    y14[i] = 0;
                    width14[i] = 0;
                    height14[i] = 0;
                    PlaySound(sounds.brickCollideSound);
                    des4++;
                    score++;
                } 
            }
            DrawText(TextFormat("%i", score), GetScreenWidth()/2, GetScreenHeight()/2, 20, BLACK);
            if (ball.y + ball.radius >= GetScreenHeight()) {
                DrawText(TextFormat("GAME OVER!!"), GetScreenWidth()/2 - 40, GetScreenHeight()/2 - 60, 10, BLACK);
                sleep(3);
                return 1;
            }

            if (des1 == 8 && des2 == 8 && des3 == 8 && des4 == 8) return 0;
        }

        // for level 02
        if (chLevel == 2) {
            for (int i = 0; i < 8; i++){
                if (i < 4){
                    DrawRectangle(x21[i] + 63* i, y21[i], width21[i], height21[i], BLACK);
                    DrawRectangle(x23[i] + 63* i, y23[i], width23[i], height23[i], BLACK);
                }
                DrawRectangle(x22[i] + 63* i, y22[i], width22[i], height22[i], BLACK);
                DrawRectangle(x24[i] + 63* i, y24[i], width24[i], height24[i], BLACK);
            }

            // destroy bricks
            for (int i = 0; i < 8; i++){
                if (i < 4) {
                    if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x21[i] +63*i, y21[i], width21[i], height21[i]})){
                        ball.speedY *= -1;
                        x21[i] = 0;
                        y21[i] = 0;
                        width21[i] = 0;
                        height21[i] = 0;
                        PlaySound(sounds.brickCollideSound);
                        des1++;
                        score++;
                    }
                    if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x23[i] +63*i, y23[i], width23[i], height23[i]})){
                        ball.speedY *= -1;
                        x23[i] = 0;
                        y23[i] = 0;
                        width23[i] = 0;
                        height23[i] = 0;
                        PlaySound(sounds.brickCollideSound);
                        des3++;
                        score++;
                    }
                }
                
                if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x22[i] +63*i, y22[i], width22[i], height22[i]})){
                    ball.speedY *= -1;
                    x22[i] = 0;
                    y22[i] = 0;
                    width22[i] = 0;
                    height22[i] = 0;
                    PlaySound(sounds.brickCollideSound);
                    des2++;
                    score++;
                }
                if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x24[i] +63*i, y24[i], width24[i], height24[i]})){
                    ball.speedY *= -1;
                    x24[i] = 0;
                    y24[i] = 0;
                    width24[i] = 0;
                    height24[i] = 0;
                    PlaySound(sounds.brickCollideSound);
                    des4++;
                    score++;
                } 
            }
            DrawText(TextFormat("%i", score), GetScreenWidth()/2, GetScreenHeight()/2, 20, BLACK);
            if (ball.y + ball.radius >= GetScreenHeight()) {
                DrawText(TextFormat("GAME OVER!!"), GetScreenWidth()/2 - 40, GetScreenHeight()/2 - 60, 10, BLACK);
                sleep(3);
                return 1;
            }

            if (des1 == 4 && des2 == 8 && des3 == 4 && des4 == 8) return 0;

        }
        
        ball.Draw();
        EndDrawing();
    }

    //return 0;
}