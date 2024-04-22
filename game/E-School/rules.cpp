#include "rules.h"
#include "menu.h"

void rules() {
    // Load textures for buttons
    Texture2D skeleton = LoadTexture("Textures/skeleton.png");
    Texture2D molecual = LoadTexture("Textures/molecual.png");
    Texture2D calculator = LoadTexture("Textures/calculator.png");
    Texture2D bus = LoadTexture("Textures/bus.png");

    // Define rectangles for buttons
    const Rectangle storyButton = { (GetScreenWidth() / 3) - 80, (GetScreenHeight() / 2) - 120, 310, 100 };
    const Rectangle controlsButton = { (GetScreenWidth() / 2) - 40, (GetScreenHeight() / 3) + 42, 310, 100 };

    SetExitKey(KEY_ESCAPE); // Set ESC key to exit

    // Main loop for rules screen
    while (!WindowShouldClose()) {
        Vector2 mousePosition = GetMousePosition(); // Get mouse position

        BeginDrawing(); // Begin drawing

        ClearBackground(GRAY); // Clear the background

        // Draw textures and buttons
        DrawTexture(skeleton, 20, 120, WHITE);
        DrawTexture(molecual, 1500, 120, WHITE);
        DrawTexture(calculator, 1500, 820, WHITE);
        DrawTexture(bus, 20, 820, WHITE);

        bool isMouseOverStoryButton = CheckCollisionPointRec(mousePosition, storyButton);
        DrawRectangleRec(storyButton, (isMouseOverStoryButton ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("How to play", GetScreenWidth() / 3 - 72, GetScreenHeight() / 2 - 90, 50, WHITE);

        bool isMouseOverControls = CheckCollisionPointRec(mousePosition, controlsButton);
        DrawRectangleRec(controlsButton, (isMouseOverControls ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Controls", GetScreenWidth() / 2 + 8, (GetScreenHeight() / 3) - (-68), 50, WHITE);

        // Check for button clicks and navigate accordingly
        if (isMouseOverStoryButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            howToPlay();
        }
        if (isMouseOverControls && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            controls();
        }

        EndDrawing(); // End drawing
    }
}

void howToPlay() {
    SetExitKey(KEY_ESCAPE); // Set ESC key to exit

    // Main loop for how to play screen
    while (!WindowShouldClose()) {
        Vector2 mousePosition = GetMousePosition(); // Get mouse position

        BeginDrawing(); // Begin drawing
        ClearBackground(GRAY); // Clear the background

        // Draw text for story
        DrawText("press ESC to go back", 75, 915, 20, RAYWHITE);
        DrawRectangleLines(GetScreenWidth() / 4 - 100, GetScreenHeight() / 4 - 100, GetScreenWidth() / 2 + 250, GetScreenHeight() / 2 + 150, { 255, 109, 194, 255 });
        DrawText("Hi, welcome to our game! In it you're a student", GetScreenWidth() / 4 + 40, GetScreenHeight() / 4 + 50, 40, WHITE);
        DrawText("who has a normal school day. When you start,", GetScreenWidth() / 4 + 40, GetScreenHeight() / 4 + 100, 40, WHITE);
        DrawText("you're in the school hall where you can choose", GetScreenWidth() / 4 + 40, GetScreenHeight() / 4 + 150, 40, WHITE);
        DrawText("the subject you want to study. Then you read", GetScreenWidth() / 4 + 40, GetScreenHeight() / 4 + 200, 40, WHITE);
        DrawText("the student books and finally get tested via", GetScreenWidth() / 4 + 40, GetScreenHeight() / 4 + 250, 40, WHITE);
        DrawText("exams. We wish you the best of luck!", GetScreenWidth() / 4 + 125, GetScreenHeight() / 4 + 300, 40, WHITE);

        EndDrawing(); // End drawing
    }
}

void controls() {
    SetExitKey(KEY_ESCAPE); // Set ESC key to exit

    // Main loop for controls screen
    while (!WindowShouldClose()) {
        Vector2 mousePosition = GetMousePosition(); // Get mouse position

        BeginDrawing(); // Begin drawing
        ClearBackground(GRAY); // Clear the background

        // Draw text for controls
        DrawText("press ESC to go back", 75, 915, 20, RAYWHITE);
        DrawRectangleLines(530, 100, 800, 800, { 255, 109, 194, 255 });
        DrawText("W - move forward", 680, 155, 50, WHITE);
        DrawText("A - move to the left", 680, 265, 50, WHITE);
        DrawText("S - move backwards", 680, 375, 50, WHITE);
        DrawText("D - move to the right", 680, 485, 50, WHITE);
        DrawText("F - show menus ", 680, 595, 50, WHITE);
        DrawText("B - close menus ", 680, 705, 50, WHITE);
        DrawText("M - open the map ", 680, 805, 50, WHITE);

        EndDrawing(); // End drawing
    }
}