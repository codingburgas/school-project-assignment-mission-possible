#include "games.h"

void pong()
{
    int screenHeight = 975;
    int screenWidth = 1920;
    Paddle paddle1(20, 975 / 2 - 40, 20.0f, 100.0f, BLUE, 10);
    Paddle paddle2(screenWidth - 40, screenHeight / 2 - 40, 20.0f, 100.0f, RED, 10);
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

        if (paddle2.rect.y != ball.position.y)
        {
            if (paddle2.rect.y > ball.position.y)
            {
                paddle2.rect.y -= 6;
            }
            if (paddle2.rect.y < ball.position.y)
            {
                paddle2.rect.y += 6;
            }
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

void golf()
{

    SetTargetFPS(60);

    // Create golf ball
    GolfBall ball = GolfBall({ 1920 / 2, 975 / 2 }, RED);

    // Create holes
    Hole hole1 = Hole({ 200, 200 }, BLUE);
    Hole hole2 = Hole({ 600, 100 }, GREEN);

    // Aim direction
    Vector2 aimDirection = { 0, 0 };

    // Power variables
    float power = 0.0f;
    const float maxPower = 20.0f;
    const float powerIncrement = 0.2f;

    // Score
    int points = 0;

    // Main game loop
    while (!WindowShouldClose()) {
        // Update

        ball.updatePosition();

        // Input handling
        if (!ball.isMoving) {
            // Aim direction based on mouse position
            aimDirection = { GetMouseX() - ball.position.x, GetMouseY() - ball.position.y };

            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                // Increase power if it's not already at maximum
                if (power < maxPower) {
                    power += powerIncrement;
                }
            }

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                // Calculate direction and force
                float magnitude = sqrt(aimDirection.x * aimDirection.x + aimDirection.y * aimDirection.y);
                aimDirection.x /= magnitude;
                aimDirection.y /= magnitude;
                Vector2 force = { aimDirection.x * power, aimDirection.y * power };

                // Apply force to the ball
                ball.applyForce(force);
                ball.launch(); // Launch the ball
                // Reset power
                power = 0.0f;
            }
        }

        // Check for ball-hole collisions
        if (ball.isMoving) {
            if (hole1.checkCollision(ball.position) || hole2.checkCollision(ball.position)) {
                points++;
                ball.resetPosition();
                // Randomize hole positions after scoring
                hole1.setPosition({ static_cast<float>(GetRandomValue(50, 975 - 50)), static_cast<float>(GetRandomValue(50, 1920 - 50)) });
                hole2.setPosition({ static_cast<float>(GetRandomValue(50, 975 - 50)), static_cast<float>(GetRandomValue(50, 1920 - 50)) });

                // Debug: Print message when collision occurs
                printf("Ball collided with hole!\n");
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(WHITE);

        // Draw aim line
        DrawLine(ball.position.x, ball.position.y, ball.position.x + aimDirection.x * 50, ball.position.y + aimDirection.y * 50, BLACK);

        // Draw holes
        hole1.draw();
        hole2.draw();

        // Draw points
        string pointsStr = "Points: " + to_string(points);
        DrawText(pointsStr.c_str(), 10, 10, 20, BLACK);

        ball.draw();

        EndDrawing();
        if (IsKeyPressed(KEY_B))
        {
            break;
            break;
        }
    }
}

void snake()
{
    const int screenWidth = 1920;
    const int screenHeight = 975;

    // Player variables
    Rectangle player = { screenWidth / 2 - 20, screenHeight / 2 - 20, 40, 40 };
    Vector2 playerSpeed = { 0, 0 };
    const float playerSpeedValue = 5.0f;
    std::vector<Rectangle> snakeSegments; // Vector to store snake segments
    snakeSegments.push_back(player); // Add initial segment

    // Target variables
    Rectangle target = { GetRandomValue(0, screenWidth - 50), GetRandomValue(0, screenHeight - 50), 50, 50 };
    Color targetColor = GREEN;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        if (IsKeyDown(KEY_RIGHT)) playerSpeed = { playerSpeedValue, 0 };
        else if (IsKeyDown(KEY_LEFT)) playerSpeed = { -playerSpeedValue, 0 };
        else if (IsKeyDown(KEY_DOWN)) playerSpeed = { 0, playerSpeedValue };
        else if (IsKeyDown(KEY_UP)) playerSpeed = { 0, -playerSpeedValue };

        // Move the snake head
        player.x += playerSpeed.x;
        player.y += playerSpeed.y;

        // Move the snake body
        for (size_t i = snakeSegments.size() - 1; i > 0; --i)
        {
            snakeSegments[i] = snakeSegments[i - 1];
        }
        snakeSegments[0] = player;

        // Collision detection
        if (CheckCollisionRecs(player, target))
        {
            // Increase snake size
            snakeSegments.push_back(player);

            // Generate new target position and color
            target.x = GetRandomValue(0, screenWidth - 50);
            target.y = GetRandomValue(0, screenHeight - 50);
            targetColor = BROWN;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw snake
        for (const auto& segment : snakeSegments)
        {
            DrawRectangleRec(segment, BLUE);
        }
        if (IsKeyPressed(KEY_B))
        {
            break;
            break;
        }
        // Draw target
        DrawRectangleRec(target, targetColor);

        EndDrawing();
    }

}

void selectGame()
{
    Rectangle choices[3] = {
        {300,425,200,200},
        {900,425,200,200},
        {1500,425,200,200},
    };
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangleRec(choices[0], RED);
        DrawRectangleRec(choices[1], RED);
        DrawRectangleRec(choices[2], RED);
        if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), choices[0]))
        {
            pong();
        }
        if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), choices[1]))
        {
            golf();
        }
        if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), choices[2]))
        {
            snake();
        }
        EndDrawing();
        if (IsKeyPressed(KEY_B))
        {
            break;
            break;
        }
    }
}