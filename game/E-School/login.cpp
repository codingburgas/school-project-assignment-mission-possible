#include "login.h"
#include "menu.h"

void login()
{
    bool isAnswerTrue = false;

    char username[50] = "\0";
    char password[50] = "\0";
    int usernameLetterCount = 0;
    int passwordLetterCount = 0;

    const Rectangle usernameBox = { GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 235, 650, 65 };
    const Rectangle passwordBox = { GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 35, 650, 65 };

    bool mouseOnUsername = false;
    bool mouseOnPassword = false;

    int framesCounter = 0;
    const Rectangle loginButton = { GetScreenWidth() / 2 - 110, GetScreenHeight() / 2 + 350, 270, 90 };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, usernameBox)) mouseOnUsername = true;
        else mouseOnUsername = false;

        if (CheckCollisionPointRec(mousePosition, passwordBox)) mouseOnPassword = true;
        else mouseOnPassword = false;

        if (mouseOnUsername || mouseOnPassword) SetMouseCursor(MOUSE_CURSOR_IBEAM);
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnUsername)
        {
            int key = GetCharPressed();
            while (key > 0)
            {
                if ((key >= 32) && (key <= 125) && (usernameLetterCount < 50))
                {
                    username[usernameLetterCount] = (char)key;
                    username[usernameLetterCount + 1] = '\0';
                    usernameLetterCount++;
                }

                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                usernameLetterCount--;
                if (usernameLetterCount < 0) usernameLetterCount = 0;
                username[usernameLetterCount] = '\0';
            }
        }

        if (mouseOnPassword)
        {
            int key = GetCharPressed();
            while (key > 0)
            {
                if ((key >= 32) && (key <= 125) && (passwordLetterCount < 50))
                {
                    password[passwordLetterCount] = (char)key;
                    password[passwordLetterCount + 1] = '\0';
                    passwordLetterCount++;
                }

                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                passwordLetterCount--;
                if (passwordLetterCount < 0) passwordLetterCount = 0;
                password[passwordLetterCount] = '\0';
            }
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePosition, loginButton))
        {
            menu();
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Welcome back! Log into your account!", GetScreenWidth() / 2 - 325, GetScreenHeight() / 2 - 400, 40, BLACK);

        DrawRectangleLines((int)usernameBox.x, (int)usernameBox.y, (int)usernameBox.width, (int)usernameBox.height, (mouseOnUsername ? DARKGRAY : BLACK));
        DrawText(username, (int)usernameBox.x + 5, (int)usernameBox.y + 8, 40, BLACK);

        DrawRectangleLines((int)passwordBox.x, (int)passwordBox.y, (int)passwordBox.width, (int)passwordBox.height, (mouseOnPassword ? DARKGRAY : BLACK));
        DrawText(password, (int)passwordBox.x + 5, (int)passwordBox.y + 8, 40, BLACK);

        bool isMouseOverButtonLogin = CheckCollisionPointRec(mousePosition, loginButton);
        DrawRectangleRec(loginButton, (isMouseOverButtonLogin ? GREEN : LIME));
        DrawText("Login", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 370, 50, WHITE);
        DrawText("Username:", GetScreenWidth() / 2 - 75, GetScreenHeight() / 2 - 278, 40, BLACK);
        DrawText("Password:", GetScreenWidth() / 2 - 75, GetScreenHeight() / 2 - 78, 40, BLACK);


        EndDrawing();
    }
}

void startingScreen()
{
    const int screenWidth = 1920;
    const int screenHeight = 975;
    InitWindow(screenWidth, screenHeight, "Mission: Possible");

    const Rectangle loginButton = { screenWidth / 2 - 450, screenHeight / 2 - 50, 270, 90 };
    const Rectangle registerButton = { screenWidth / 2 + 220, screenHeight / 2 - 50, 270, 90 };

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        Vector2 mousePosition = GetMousePosition();

        DrawText("Welcome to our game! Let's get into it", screenWidth / 2 - 365, screenHeight / 2 - 400, 40, BLACK);

        bool isMouseOverButtonLogin = CheckCollisionPointRec(mousePosition, loginButton);
        DrawRectangleRec(loginButton, (isMouseOverButtonLogin ? GREEN : LIME));
        DrawText("Login", screenWidth / 2 - 385, screenHeight / 2 - 30, 50, WHITE);

        if (isMouseOverButtonLogin && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            login();
        }

        bool isMouseOverButtonRegister = CheckCollisionPointRec(mousePosition, registerButton);
        DrawRectangleRec(registerButton, (isMouseOverButtonRegister ? GREEN : LIME));
        DrawText("Register", screenWidth / 2 + 250, screenHeight / 2 - 30, 50, WHITE);

        EndDrawing();
    }
}
