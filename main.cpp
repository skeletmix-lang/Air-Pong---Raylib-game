#include "header.h"

bool fps60;


class Ball {
public:
    float x = 400;
    float y = 225;
    int radius = 10;
    int speedX = 4;
    int speedY = 3;
    int screenWidth = 800;
    int screenHeight = 450;

    void Update() {
        x += speedX;
        y += speedY;
        if (x <= radius || x >= screenWidth - radius) {
            speedX *= -1;
        }
        if (y <= radius || y >= screenHeight - radius) {
            speedY *= -1;    
            
            }
        }
    };

class Player1 {
public:
    float x = 10;
    float y = 200;
    int  Sigmawidth = 10;
    int SigmaRadius = 10;
    int SigmaWidth = 10;
    int SigmaHeight = 80;
    int  SigmaspeedY = 5;
    int  Sigmaradius = 10;
    int  SigmascreenWidth = 800;
    int  SigmascreenHeight = 450;

    void Update() {
        if (IsKeyDown(KEY_W)) y -= SigmaspeedY;
        if (IsKeyDown(KEY_S)) y += SigmaspeedY;
        if (y < 0) y = 0;
        if (y > SigmascreenHeight - SigmaHeight) y = SigmascreenHeight - SigmaHeight;

    }
};


class Player2 {
public:
    float x = 780;
    float y = 200;
    int width = 10;
    int Radius = 10;
    int Width = 10;
    int Height = 80;
    int speedY = 5;
    int radius = 10;
    int screenWidth = 800;
    int screenHeight = 450;

    void Update() {
        if (IsKeyDown(KEY_UP)) y -= speedY;
        if (IsKeyDown(KEY_DOWN)) y += speedY;
        if (y < 0) y = 0;
        if (y > screenHeight - Height) y = screenHeight - Height;

    }
};


int main() {
    int screenWidth = 800;
    int screenHeight = 450;

    Ball ball;
    Player1 player1;
    Player2 player2;
    raylib::Window window(screenWidth, screenHeight, "RayPong");

    window.SetTargetFPS(60); {
        fps60 = true;
    }
	
    while (!window.ShouldClose()) {
        window.BeginDrawing();
        {
            if (fps60 == true) {
                DrawFPS(10, 10);
            }

            ball.Update();
            player1.Update();
            player2.Update();

            if (ball.x > player1.x &&
                ball.x < player1.x + player1.SigmaWidth &&
                ball.y > player1.y &&
                ball.y < player1.y + player1.SigmaHeight)
            {
                ball.speedX *= -1;
            }
            if (ball.x > player2.x &&
                ball.x < player2.x + player2.Width &&
                ball.y > player2.y &&
                ball.y < player2.y + player2.Height)
            {
                ball.speedX *= -1;
            }
            window.ClearBackground(raylib::Color(200, 180, 230));
            DrawLine((float)(screenWidth / 2.0), 0.0f, (float)(screenWidth / 2.0), (float)screenHeight, BLACK);
            DrawCircle((int)ball.x, (int)ball.y, ball.radius, WHITE);
            DrawRectangle((int)player1.x, (int)player1.y, player1.SigmaWidth, player1.SigmaHeight, WHITE);
            DrawRectangle((int)player2.x, (int)player2.y, player2.Width, player2.Height, WHITE);
            
        }
        window.EndDrawing();
        
    }

    return 0;
}
