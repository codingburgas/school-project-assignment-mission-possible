#include "rules.h"
#include "menu.h"

void rules()
{
    // Add storyButton and controlsButton
    const Rectangle storyButton = { (GetScreenWidth() / 2) - 130, (GetScreenHeight() / 2) - 120, 310, 100 };
    const Rectangle controlsButton = { (GetScreenWidth() / 2) - 130, (GetScreenHeight() / 2) + 15, 310, 100 };
    SetExitKey(KEY_ESCAPE);
    while (!WindowShouldClose())
    {
        // Get mouse position
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();

        // Clear the background
        ClearBackground({ 0, 1, 41, 255 });
        // Check if mouse is over the button
        bool isMouseOverStoryButton = CheckCollisionPointRec(mousePosition, storyButton);
        // Add colors for if mouse is over the button
        DrawRectangleRec(storyButton, (isMouseOverStoryButton ? SKYBLUE : BLUE));
        DrawText("How to play", GetScreenWidth() / 2 - 117, GetScreenHeight() / 2 - 97, 50, WHITE);

        // Get sent to story() after clicking the story button
        if (isMouseOverStoryButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            howToPlay();
        }

        // Check if mouse is over the button
        bool isMouseOverControls = CheckCollisionPointRec(mousePosition, controlsButton);
        // Add colors for if mouse is over the button
        DrawRectangleRec(controlsButton, (isMouseOverControls ? GREEN : LIME));
        DrawText("Controls", GetScreenWidth() / 2 - 83, (GetScreenHeight() / 2) - (-40), 50, WHITE);

        // Get sent to controls() after clicking the controls button
        if (isMouseOverControls && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            controls();
        }
        EndDrawing();

    }
}

void howToPlay() {
    SetExitKey(KEY_ESCAPE);

    while (!WindowShouldClose())
    {
        // Get mouse position
        Vector2 mousePosition = GetMousePosition();
        // Start drawing, draw textures, and clear background
        BeginDrawing();
        ClearBackground({ 0, 1, 41, 255 });
        DrawText("press ESC to go back", 75, 915, 20, RAYWHITE);
        DrawRectangleLines(GetScreenWidth() / 4 - 100, GetScreenHeight() / 4 - 100, GetScreenWidth() / 2 + 250, GetScreenHeight() / 2 + 150, { 0, 91, 241, 255 });

        // Draw text for story
        DrawText("Hi, welcome to our game! In it you're a student", GetScreenWidth() / 4 + 40, GetScreenHeight() / 4 + 50, 40, WHITE);
        DrawText("who has a normal school day. When you start,", GetScreenWidth() / 4 + 40, GetScreenHeight() / 4 + 100, 40, WHITE);
        DrawText("you're in the school hall where you can choose", GetScreenWidth() / 4 + 40, GetScreenHeight() / 4 + 150, 40, WHITE);
        DrawText("the subject you want to study. Then you read", GetScreenWidth() / 4 + 40, GetScreenHeight() / 4 + 200, 40, WHITE);
        DrawText("the student books and finally get tested via", GetScreenWidth() / 4 + 40, GetScreenHeight() / 4 + 250, 40, WHITE);
        DrawText("exams. We wish you the best of luck!", GetScreenWidth() / 4 + 125, GetScreenHeight() / 4 + 300, 40, WHITE);

        // Stop drawing
        EndDrawing();

    }
}

void controls() {
    SetExitKey(KEY_ESCAPE);
    while (!WindowShouldClose())
    {
        // Get mouse position, start drawing, and clear background
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        ClearBackground({ 0, 1, 41, 255 });

        // Draw text for controls
        DrawText("press ESC to go back", 75, 915, 20, RAYWHITE);
        DrawRectangleLines(530, 100, 800, 800, { 0, 91, 241, 255 });
        DrawText("W - move forward", 680, 155, 50, WHITE);
        DrawText("A - move to the left", 680, 265, 50, WHITE);
        DrawText("S - move backwards", 680, 375, 50, WHITE);
        DrawText("D - move to the right", 680, 485, 50, WHITE);
        DrawText("F - show menus ", 680, 595, 50, WHITE);
        DrawText("B - close menus ", 680, 705, 50, WHITE);
        DrawText("M - open the map ", 680, 805, 50, WHITE);

        // Stop drawing
        EndDrawing();

    }
}