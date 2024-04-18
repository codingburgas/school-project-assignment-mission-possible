#include "rules.h"


void howToPlay() {
    SetExitKey(KEY_APOSTROPHE);

    while (!WindowShouldClose())
    {
        // Get mouse position
        Vector2 mousePosition = GetMousePosition();
        // Start drawing, draw textures, and clear background
        BeginDrawing();
        ClearBackground({ 0, 1, 41, 255 });
        DrawText("press ESC to go back", 75, 915, 20, RAYWHITE);
        DrawRectangleLines(820, 60, 850, 850, { 0, 91, 241, 255 });

        // Draw text for story
        DrawText("Hi, welcome to our game! In", 880, 80, 50, WHITE);
        DrawText("it you're a student who has", 880, 140, 50, WHITE);
        DrawText("a normal school day.When you", 900, 200, 50, WHITE);
        DrawText("start, you are in the school", 900, 260, 50, WHITE);
        DrawText("hall where you can choose which ", 900, 320, 50, WHITE);
        DrawText("subject you want to study. Then", 880, 380, 50, WHITE);
        DrawText("you read student books and finally ", 880, 440, 50, WHITE);
        DrawText("you are being examined.Good luck!", 880, 500, 50, WHITE);
        /*DrawText("ones and complete my expedition. ", 835, 560, 50, WHITE);
        DrawText("However, I have a certain ", 880, 620, 50, WHITE);
        DrawText("amount of time before I run ", 880, 680, 50, WHITE);
        DrawText("out of oxygen, my clock is ", 880, 740, 50, WHITE);
        DrawText("already tickingso be as fast ", 880, 800, 50, WHITE);
        DrawText("as you can! ", 1080, 860, 50, WHITE);*/

        // Stop drawing
        EndDrawing();
    }
}
void controls() {
    SetExitKey(KEY_APOSTROPHE);
    while (!WindowShouldClose())
    {
        // Get mouse position, start drawing, and clear background
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        ClearBackground({ 0, 1, 41, 255 });

        // Draw text for controls
        DrawText("press ESC to go back", 75, 915, 20, RAYWHITE);
        DrawRectangleLines(530, 100, 800, 700, { 0, 91, 241, 255 });
        DrawText("W - move forward", 680, 155, 50, WHITE);
        DrawText("A - move to the left", 680, 265, 50, WHITE);
        DrawText("S - move backwards", 680, 375, 50, WHITE);
        DrawText("D - move to the right", 680, 485, 50, WHITE);
        DrawText("F - show menus ", 680, 595, 50, WHITE);
        DrawText("B - close menus ", 680, 705, 50, WHITE);

        // Stop drawing
        EndDrawing();
    }
}
void rules()
{
    // Add storyButton and controlsButton
    const Rectangle storyButton = { (GetScreenWidth() / 2) - 130, (GetScreenHeight() / 2) - 120, 310, 100 };
    const Rectangle controlsButton = { (GetScreenWidth() / 2) - 130, (GetScreenHeight() / 2) + 15, 310, 100 };
    SetExitKey(KEY_APOSTROPHE);
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