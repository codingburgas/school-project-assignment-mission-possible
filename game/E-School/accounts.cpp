#include "accounts.h"
#include "menu.h"
#include "accessData.h"
#include "validation.h"

void signup()
{

    char username[51] = "";
    char password[51] = "";
    char repeatPassword[51] = "";

    int usernameLetterCount = 0;
    int passwordLetterCount = 0;
    int repeatPasswordLetterCount = 0;

    const Rectangle usernameBox = { GetScreenWidth() / 2 - 435, GetScreenHeight() / 2 - 130, 900, 65 };
    const Rectangle passwordBox = { GetScreenWidth() / 2 - 435, GetScreenHeight() / 2, 900, 65 };
    const Rectangle repeatPasswordBox = { GetScreenWidth() / 2 - 435, GetScreenHeight() / 2 + 130, 900, 65 };

    Rectangle inputBoxes[] = { usernameBox, passwordBox, repeatPasswordBox };

    bool mouseOnInputBox[3] = { false };

    const Rectangle signupButton = { GetScreenWidth() / 2 - 115, GetScreenHeight() / 2 + 350, 270, 90 };

    DataAccess account;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();

        // Input box hover check
        for (int i = 0; i < 3; ++i) {
            mouseOnInputBox[i] = CheckCollisionPointRec(mousePosition, inputBoxes[i]);
        }

        bool anyInputBoxHovered = false;
        for (int i = 0; i < 3; ++i) {
            if (mouseOnInputBox[i]) {
                anyInputBoxHovered = true;
                break;
            }
        }

        SetMouseCursor(anyInputBoxHovered ? MOUSE_CURSOR_IBEAM : MOUSE_CURSOR_DEFAULT);

        // Input handling
        for (int i = 0; i < 3; ++i) {
            if (mouseOnInputBox[i]) {
                int key = GetCharPressed();
                while (key > 0) {
                    if ((key >= 32) && (key <= 125)) {
                        switch (i) {
                        case 0: // username box
                            if (usernameLetterCount < 50) {
                                username[usernameLetterCount++] = (char)key;
                                username[usernameLetterCount] = '\0';
                            }
                            break;
                        case 1: // password box
                            if (passwordLetterCount < 50) {
                                password[passwordLetterCount++] = (char)key;
                                password[passwordLetterCount] = '\0';
                            }
                            break;
                        case 2: // repeat password box
                            if (repeatPasswordLetterCount < 50) {
                                repeatPassword[repeatPasswordLetterCount++] = (char)key;
                                repeatPassword[repeatPasswordLetterCount] = '\0';
                            }
                            break;
                        }
                    }

                    key = GetCharPressed();
                }

                if (IsKeyPressed(KEY_BACKSPACE))
                {
                    switch (i) {
                    case 0: // username box
                        if (usernameLetterCount > 0) {
                            usernameLetterCount--;
                            username[usernameLetterCount] = '\0';
                        }
                        break;
                    case 1: // password box
                        if (passwordLetterCount > 0) {
                            passwordLetterCount--;
                            password[passwordLetterCount] = '\0';
                        }
                        break;
                    case 2: // repeat password box
                        if (repeatPasswordLetterCount > 0) {
                            repeatPasswordLetterCount--;
                            repeatPassword[repeatPasswordLetterCount] = '\0';
                        }
                        break;
                    }
                }
            }
        }
        Validate validator;
        bool showMismatchError = false; // Flag for mismatched passwords
        bool showRequirementError = false; // Flag for requirement errors
        // Sign up button click check
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePosition, signupButton)) {
            if (strcmp(password, repeatPassword) != 0) {
                // Clear password fields if passwords don't match
                password[0] = '\0';
                repeatPassword[0] = '\0';
                passwordLetterCount = 0;
                repeatPasswordLetterCount = 0;
                showMismatchError = true; // Set mismatch error flag
                showRequirementError = false; // Ensure requirement error is not shown
            }
            else {
                // Check password requirements if passwords match
                if (validator.containsUppercase(password) && validator.containsLowercase(password) &&
                    validator.containsDigit(password) && validator.containsSpecial(password)) {
                    account.addAccount(username, password);
                    menu();
                }
                else {
                    // Password does not meet requirements, handle accordingly
                    password[0] = '\0';
                    repeatPassword[0] = '\0';
                    passwordLetterCount = 0;
                    repeatPasswordLetterCount = 0;

                }
            }
        }


        // Drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("You don't have an account? Sign up from here!", GetScreenWidth() / 2 - 475, GetScreenHeight() / 2 - 400, 40, BLACK);
        DrawText("!Note: the password must contain at least one uppercase, lowercase, number and symbol", GetScreenWidth() / 2 - 650, GetScreenHeight() / 2 - 250, 30, GREEN);
        DrawText("Username:", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 - 175, 40, BLACK);
        DrawText("Password:", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 - 42, 40, BLACK);
        DrawText("Repeat Password:", GetScreenWidth() / 2 - 165, GetScreenHeight() / 2 + 87, 40, BLACK);

        for (int i = 0; i < 4; ++i) {
            DrawRectangleLines(inputBoxes[i].x, inputBoxes[i].y, inputBoxes[i].width, inputBoxes[i].height, (mouseOnInputBox[i] ? RED : BLACK));
        }

        DrawText(username, usernameBox.x + 5, usernameBox.y + 8, 40, BLACK);
        DrawText(TextFormat("%.*s", passwordLetterCount, "*************************************"), passwordBox.x + 5, passwordBox.y + 8, 40, BLACK);
        DrawText(TextFormat("%.*s", repeatPasswordLetterCount, "*************************************"), repeatPasswordBox.x + 5, repeatPasswordBox.y + 8, 40, BLACK);

        DrawRectangleRec(signupButton, (CheckCollisionPointRec(mousePosition, signupButton) ? GREEN : LIME));
        DrawText("Sign up", GetScreenWidth() / 2 - 55, GetScreenHeight() / 2 + 370, 50, WHITE);



        EndDrawing();
    }
}

void login() {
    bool isAnswerTrue = false;

    char username[50] = "\0";
    char password[50] = "\0";
    int usernameLetterCount = 0;
    int passwordLetterCount = 0;

    const Rectangle usernameBox = { GetScreenWidth() / 2 - 430, GetScreenHeight() / 2 - 235, 900, 65 };
    const Rectangle passwordBox = { GetScreenWidth() / 2 - 430, GetScreenHeight() / 2 - 35, 900, 65 };

    bool mouseOnUsername = false;
    bool mouseOnPassword = false;

    const Rectangle loginButton = { GetScreenWidth() / 2 - 120, GetScreenHeight() / 2 + 350, 270, 90 };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        Vector2 mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, usernameBox)) mouseOnUsername = true;
        else mouseOnUsername = false;

        if (CheckCollisionPointRec(mousePosition, passwordBox)) mouseOnPassword = true;
        else mouseOnPassword = false;

        if (mouseOnUsername || mouseOnPassword) SetMouseCursor(MOUSE_CURSOR_IBEAM);
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnUsername) {
            int key = GetCharPressed();
            while (key > 0) {
                if ((key >= 32) && (key <= 125) && (usernameLetterCount < 50)) {
                    username[usernameLetterCount] = (char)key;
                    username[usernameLetterCount + 1] = '\0';
                    usernameLetterCount++;
                }

                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                usernameLetterCount--;
                if (usernameLetterCount < 0) usernameLetterCount = 0;
                username[usernameLetterCount] = '\0';
            }
        }

        if (mouseOnPassword) {
            int key = GetCharPressed();
            while (key > 0) {
                if ((key >= 32) && (key <= 125) && (passwordLetterCount < 50)) {
                    password[passwordLetterCount] = (char)key;
                    password[passwordLetterCount + 1] = '\0';
                    passwordLetterCount++;
                }

                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                passwordLetterCount--;
                if (passwordLetterCount < 0) passwordLetterCount = 0;
                password[passwordLetterCount] = '\0';
            }
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePosition, loginButton) || IsKeyPressed(KEY_ENTER)) {
            Validate validator;
            if (validator.doesAccountExist(username) && validator.isPasswordCorrect(username, password)) {
                menu();
            }
            else
            {
                password[0] = '\0';
                username[0] = '\0';
                passwordLetterCount = 0;
                usernameLetterCount = 0;
            }

        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Welcome back! Log into your account!", GetScreenWidth() / 2 - 325, GetScreenHeight() / 2 - 400, 40, BLACK);

        DrawRectangleLines(usernameBox.x, usernameBox.y, usernameBox.width, usernameBox.height, (mouseOnUsername ? RED : BLACK));
        DrawText(username, usernameBox.x + 5, usernameBox.y + 8, 40, BLACK);

        DrawRectangleLines(passwordBox.x, passwordBox.y, passwordBox.width, passwordBox.height, (mouseOnPassword ? RED : BLACK));
        DrawText(TextFormat("%.*s", passwordLetterCount, "**********"), passwordBox.x + 5, passwordBox.y + 8, 40, BLACK);

        bool isMouseOverButtonLogin = CheckCollisionPointRec(mousePosition, loginButton);
        DrawRectangleRec(loginButton, (isMouseOverButtonLogin ? GREEN : LIME));
        DrawText("Login", GetScreenWidth() / 2 - 55, GetScreenHeight() / 2 + 370, 50, WHITE);
        DrawText("Username:", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 - 278, 40, BLACK);
        DrawText("Password:", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 - 78, 40, BLACK);

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

        bool isMouseOverButtonSignup = CheckCollisionPointRec(mousePosition, registerButton);
        DrawRectangleRec(registerButton, (isMouseOverButtonSignup ? GREEN : LIME));
        DrawText("Sign up", screenWidth / 2 + 260, screenHeight / 2 - 30, 50, WHITE);
        if (isMouseOverButtonSignup && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            signup();
        }
        EndDrawing();
    }
}

