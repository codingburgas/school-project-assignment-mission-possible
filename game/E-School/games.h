#pragma once

#include "pch.h"

float Vector2Distance(Vector2 v1, Vector2 v2);

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



    void Reset() {
        position = { static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) / 2 };
    }
    void OutOfBounds(int& pointsBot, int& pointsPlayer) {
        if (position.x - radius <= 0) {
            pointsBot++; // Increment bot's points
            Reset();
        }
        else if (position.x + radius >= GetScreenWidth()) {
            pointsPlayer++; // Increment player's points
            Reset();
        }
    }
    void Draw() {
        DrawCircleV(position, radius, color);
    }
};

class GolfBall {
public:
    Vector2 position;
    Vector2 velocity;
    bool isMoving;
    Color color;

    // Constructor
    GolfBall(Vector2 startPos, Color ballColor) : position(startPos), color(ballColor) {
        velocity = { 0, 0 };
        isMoving = false;

    }

    // Function to apply force to the ball
    void applyForce(Vector2 force) {
        velocity.x += force.x;
        velocity.y += force.y;
    }

    // Function to update the ball's position
    void updatePosition() {
        if (isMoving) {
            position.x += velocity.x;
            position.y += velocity.y;
            velocity.y += 0.2f;
            checkWallCollision();
        }
        // Update launch time if the ball is launched

    }

    // Function to check wall collisions
    void checkWallCollision() {
        // Left and right walls
        if (position.x <= 0 || position.x >= 1920) {
            velocity.x *= -0.8; // Bounce back with some loss of energy
            resetPosition(); // Reset the ball's position
        }

        // Top and bottom walls
        if (position.y <= 0 || position.y >= 975) {
            velocity.y *= -0.8; // Bounce back with some loss of energy
            resetPosition(); // Reset the ball's position
        }
    }
    // Function to draw the ball
    void draw() {
        DrawCircleV(position, 30, color);
    }

    // Function to reset ball position
    void resetPosition() {
        position = { 1920 / 2, 975 / 2 };
        velocity = { 0, 0 };
        isMoving = false;
    }

    // Function to launch the ball
    void launch() {
        isMoving = true;

    }
    // Function to check if the ball should reset

};

// Define a class for the holes
class Hole {
public:
    Vector2 position;
    Color color;

    // Constructor
    Hole(Vector2 pos, Color holeColor) : color(holeColor) {
        setPosition(pos);
    }

    // Function to set hole position
    void setPosition(Vector2 pos) {
        position = pos;
    }

    // Function to check if the ball hits the hole
    bool checkCollision(Vector2 ballPos) {
        float distance = Vector2Distance(ballPos, position);
        return distance < 30; // Radius of the hole and the ball
    }

    // Function to draw the hole
    void draw() {
        DrawCircleV(position, 30, color);
    }
};

void selectGame();

void pong();

void golf();

void snake();