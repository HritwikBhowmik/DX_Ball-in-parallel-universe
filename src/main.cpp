#include "ball.h"
#include "nPlate.h"
#include "sound.h"
#include <raylib.h>
#include <unistd.h>

int main() {

    int score = 0, des1 = 0, des2 = 0, des3 = 0, des4 = 0;
    int screenWidth = 501, screenHeight = 501;
    Color white = {255, 255, 255, 255};
    InitWindow(screenWidth, screenHeight, "DX Ball");
    SetTargetFPS(60);

    // row 1
    float x1[8] = {0,0,0,0,0,0,0,0};
    float y1[8] = {0,0,0,0,0,0,0,0};
    float width1[8] = {62,62,62,62,62,62,62,62};
    float height1[8] = {25,25,25,25,25,25,25,25};
    // row 2
    float x2[8] = {0,0,0,0,0,0,0,0};
    float y2[8] = {26,26,26,26,26,26,26,26};
    float width2[8] = {62,62,62,62,62,62,62,62};
    float height2[8] = {25,25,25,25,25,25,25,25};
    // row 3
    float x3[8] = {0,0,0,0,0,0,0,0};
    float y3[8] = {52,52,52,52,52,52,52,52};
    float width3[8] = {62,62,62,62,62,62,62,62};
    float height3[8] = {25,25,25,25,25,25,25,25};
    // row 4
    float x4[8] = {0,0,0,0,0,0,0,0};
    float y4[8] = {78,78,78,78,78,78,78,78};
    float width4[8] = {62,62,62,62,62,62,62,62};
    float height4[8] = {25,25,25,25,25,25,25,25};

    nPlate plate = nPlate();
    Ball ball = Ball();
    Sounds sounds = Sounds();

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(white);

        ball.Update();
        plate.Update(); 
        plate.Draw(); 

        // for nPlate
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{plate.x, plate.y, plate.width, plate.height})){
            ball.speedY *= -1;
            PlaySound(sounds.plateCollideSound);
        } 

        for (int i = 0; i < 8; i++){
            DrawRectangle(x1[i] + 63* i, y1[i], width1[i], height1[i], BLACK);
            DrawRectangle(x2[i] + 63* i, y2[i], width2[i], height2[i], BLACK);
            DrawRectangle(x3[i] + 63* i, y3[i], width3[i], height3[i], BLACK);
            DrawRectangle(x4[i] + 63* i, y4[i], width4[i], height4[i], BLACK);
        }

        // for brick
        for (int i = 0; i < 8; i++){
            if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x1[i] +63*i, y1[i], width1[i], height1[i]})){
                ball.speedY *= -1;
                x1[i] = 0;
                y1[i] = 0;
                width1[i] = 0;
                height1[i] = 0;
                PlaySound(sounds.brickCollideSound);
                des1++;
                score++;
            }
            if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x2[i] +63*i, y2[i], width2[i], height2[i]})){
                ball.speedY *= -1;
                x2[i] = 0;
                y2[i] = 0;
                width2[i] = 0;
                height2[i] = 0;
                PlaySound(sounds.brickCollideSound);
                des2++;
                score++;
            }
            if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x3[i] +63*i, y3[i], width3[i], height3[i]})){
                ball.speedY *= -1;
                x3[i] = 0;
                y3[i] = 0;
                width3[i] = 0;
                height3[i] = 0;
                PlaySound(sounds.brickCollideSound);
                des3++;
                score++;
            }
            if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x4[i] +63*i, y4[i], width4[i], height4[i]})){
                ball.speedY *= -1;
                x4[i] = 0;
                y4[i] = 0;
                width4[i] = 0;
                height4[i] = 0;
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

        for (int i = 0; i < 8; i++) {
            if (des1 == 8 && des2 == 8 && des3 == 8 && des4 == 8) {
                sleep(3);
                return 1;
            }
        }

        ball.Draw();
        EndDrawing();
    }

    return 0;
}