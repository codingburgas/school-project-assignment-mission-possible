#include "games.h"

class Paddle {
public:
    Rectangle rect;
    Color color;
    int speed;

    Paddle(float x, float y, float width, float height, Color color, int speed)
        : rect({ x, y, width, height }), color(color), speed(speed) {}

    void MoveUp() {
        rect.y -= speed;
    }

    void MoveDown() {
        rect.y += speed;
    }

    void Draw() {
        DrawRectangleRec(rect, color);
    }
};

class Ball {
public:
    Vector2 position;
    Vector2 speed;
    int radius;
    Color color;

    Ball(float x, float y, int radius, Vector2 speed, Color color)
        : position({ static_cast<float>(x), static_cast<float>(y) }), radius(radius), speed(speed), color(color) {
    }

    void Move() {
        position.x += speed.x;
        position.y += speed.y;

        if ((position.y + radius) >= GetScreenHeight() || (position.y - radius) <= 0) {
            speed.y = -speed.y;
        }
    }

    void CheckCollision(Paddle& paddle) {
        if (CheckCollisionCircleRec(position, radius, paddle.rect)) {
            speed.x = -speed.x;
        }
    }

    bool OutOfBounds() {
        return (position.x - radius <= 0 || position.x + radius >= GetScreenWidth());
    }

    void Reset() {
        position = { static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) / 2 };
    }

    void Draw() {
        DrawCircleV(position, radius, color);
    }
};

void pong()
{
    int screenHeight = 975;
    int screenWidth = 1920;
    Paddle paddle1(20, 975 / 2 - 40, 20.0f, 80.0f, BLUE, 10);
    Paddle paddle2(screenWidth - 40, screenHeight / 2 - 40, 20.0f, 80.0f, RED, 10);
    Ball ball(screenWidth / 2, screenHeight / 2, 15, { 10, 10 }, GREEN);
        while (true) {
        SetTargetFPS(60);

       
            if (IsKeyPressed(KEY_B))
            {
                break;
                break;
            }
            BeginDrawing();
            ClearBackground(RAYWHITE);

            if (IsKeyDown(KEY_W) && paddle1.rect.y > 0) {
                paddle1.MoveUp();
            }
            if (IsKeyDown(KEY_S) && (paddle1.rect.y + paddle1.rect.height) < screenHeight) {
                paddle1.MoveDown();
            }

            if (IsKeyDown(KEY_UP) && paddle2.rect.y > 0) {
                paddle2.MoveUp();
            }
            if (IsKeyDown(KEY_DOWN) && (paddle2.rect.y + paddle2.rect.height) < screenHeight) {
                paddle2.MoveDown();
            }

            ball.Move();
            ball.CheckCollision(paddle1);
            ball.CheckCollision(paddle2);


            if (ball.OutOfBounds()) {
                ball.Reset();
            }

            paddle1.Draw();
            paddle2.Draw();
            ball.Draw();

            EndDrawing();
        }
    
}