#include "accounts.h"
#include "menu.h"
#include "accessData.h"
#include "validation.h"

void signup()
{

    char username[25] = "";
    char password[25] = "";
    char repeatPassword[25] = "";

    int usernameLetterCount = 0;
    int passwordLetterCount = 0;
    int repeatPasswordLetterCount = 0;

    const Rectangle usernameBox = { GetScreenWidth() / 2 + 275, GetScreenHeight() / 2 - 100 , 550, 65 };
    const Rectangle passwordBox = { GetScreenWidth() / 2 + 275, GetScreenHeight() / 2 + 50, 550, 65 };
    const Rectangle repeatPasswordBox = { GetScreenWidth() / 2 + 275, GetScreenHeight() / 2 + 200, 550, 65 };

    Rectangle inputBoxes[] = { usernameBox, passwordBox, repeatPasswordBox };

    bool mouseOnInputBox[3] = { false };

    const Rectangle signupButton = { GetScreenWidth() / 2 + 415, GetScreenHeight() / 2 + 325, 270, 90 };

    DataAccess account;

    SetTargetFPS(60);

    Texture2D background = LoadTexture("../images/startingScreen.png");
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
                    strcpy_s(currentUser, username);
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
        DrawTexture(background, 0, 0, WHITE);
        DrawText("Sign up from here!", GetScreenWidth() / 2 + 330, GetScreenHeight() / 2 - 315, 50, BLACK);
        DrawText("!Note: the password must contain at least one\n   uppercase, lowercase, number and symbol", GetScreenWidth() / 2 + 190, GetScreenHeight() / 2 - 250, 30, PINK);
        DrawText("Username:", GetScreenWidth() / 2 + 425, GetScreenHeight() / 2 - 150, 50, BLACK);
        DrawText("Password:", GetScreenWidth() / 2 + 425, GetScreenHeight() / 2, 50, BLACK);
        DrawText("Repeat Password:", GetScreenWidth() / 2 + 325, GetScreenHeight() / 2 + 145, 50, BLACK);

        for (int i = 0; i < 4; ++i) {
            DrawRectangleLines(inputBoxes[i].x, inputBoxes[i].y, inputBoxes[i].width, inputBoxes[i].height, (mouseOnInputBox[i] ? PINK : BLACK));
        }

        DrawText(username, usernameBox.x + 5, usernameBox.y + 8, 40, BLACK);
        DrawText(TextFormat("%.*s", passwordLetterCount, "******************************************"), passwordBox.x + 5, passwordBox.y + 8, 40, BLACK);
        DrawText(TextFormat("%.*s", repeatPasswordLetterCount, "******************************************"), repeatPasswordBox.x + 5, repeatPasswordBox.y + 8, 40, BLACK);

        DrawRectangleRec(signupButton, (CheckCollisionPointRec(mousePosition, signupButton) ? Color{ 250,122,255,255 } : PINK));
        DrawText("Sign up", GetScreenWidth() / 2 + 453, GetScreenHeight() / 2 + 345, 50, WHITE);



        EndDrawing();
    }
}

void login() {
    bool isAnswerTrue = false;

    char username[25] = "\0";
    char password[25] = "\0";
    int usernameLetterCount = 0;
    int passwordLetterCount = 0;

    const Rectangle usernameBox = { GetScreenWidth() / 2 + 275, GetScreenHeight() / 2 - 100 , 550, 65 };
    const Rectangle passwordBox = { GetScreenWidth() / 2 + 275, GetScreenHeight() / 2 + 150, 550, 65 };

    bool mouseOnUsername = false;
    bool mouseOnPassword = false;

    const Rectangle loginButton = { GetScreenWidth() / 2 + 410, GetScreenHeight() / 2 + 300, 270, 90 };

    Texture2D background = LoadTexture("../images/startingScreen.png");
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
                if ((key >= 32) && (key <= 125) && (usernameLetterCount < 25)) {
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
                if ((key >= 32) && (key <= 125) && (passwordLetterCount < 25)) {
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
                strcpy_s(currentUser, username);
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
        DrawTexture(background, 0, 0, WHITE);
        DrawText("Welcome back! Log in!", GetScreenWidth() / 2 + 285, GetScreenHeight() / 2 - 275, 50, BLACK);

        DrawRectangleLines(usernameBox.x, usernameBox.y, usernameBox.width, usernameBox.height, (mouseOnUsername ? PINK : BLACK));
        DrawText(username, usernameBox.x + 5, usernameBox.y + 8, 40, BLACK);

        DrawRectangleLines(passwordBox.x, passwordBox.y, passwordBox.width, passwordBox.height, (mouseOnPassword ? PINK : BLACK));
        DrawText(TextFormat("%.*s", passwordLetterCount, "**************************"), passwordBox.x + 5, passwordBox.y + 8, 40, BLACK);

        bool isMouseOverButtonLogin = CheckCollisionPointRec(mousePosition, loginButton);
        DrawRectangleRec(loginButton, (isMouseOverButtonLogin ? Color{ 250,122,255,255 } : PINK));
        DrawText("Login", GetScreenWidth() / 2 + 475, GetScreenHeight() / 2 + 325, 50, WHITE);
        DrawText("Username:", GetScreenWidth() / 2 + 415, GetScreenHeight() / 2 - 155, 50, BLACK);
        DrawText("Password:", GetScreenWidth() / 2 + 415, GetScreenHeight() / 2 + 85, 50, BLACK);

        EndDrawing();

    }

}

void startingScreen()
{
    const int screenWidth = 1920;
    const int screenHeight = 975;
    InitWindow(screenWidth, screenHeight, "Mission: Possible");

    Vector2 loginButtonPosition = { 1400, 400 };
    Vector2 signUpButtonPosition = { 1400, 600 };
    Vector2 exitButtonPosition = { 1400, 800 };

    const Rectangle loginButton = { loginButtonPosition.x, loginButtonPosition.y, 300, 100 };
    const Rectangle signUpButton = { signUpButtonPosition.x, signUpButtonPosition.y, 300, 100 };
    const Rectangle exitButton = { exitButtonPosition.x, exitButtonPosition.y, 300, 100 };

    Texture2D background = LoadTexture("../images/startingScreen.png");

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();

        ClearBackground(RAYWHITE);


        //DrawText("Welcome to our game! Let's get into it", screenWidth / 2 - 365, screenHeight / 2 - 400, 40, BLACK);
        DrawTexture(background, 0, 0, WHITE);
        DrawText("Welcome to our game!", GetScreenWidth() / 2 + 325, GetScreenHeight() / 2 - 230, 50, BLACK);
        bool isMouseOverLoginButton = CheckCollisionPointRec(mousePosition, loginButton);
        DrawRectangleRounded(loginButton, 5, (int)2, (isMouseOverLoginButton ? DARKGRAY : BLACK));
        DrawText("Login", loginButtonPosition.x + 85, loginButtonPosition.y + 25, 50, WHITE);
        if (CheckCollisionPointRec(mousePosition, loginButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            login();
        }



        bool isMouseOverSignUpButton = CheckCollisionPointRec(mousePosition, signUpButton);
        DrawRectangleRounded(signUpButton, 5, (int)2, isMouseOverSignUpButton ? DARKGRAY : BLACK);
        DrawText("Sign up", signUpButtonPosition.x + 60, signUpButtonPosition.y + 25, 50, WHITE);
        if (CheckCollisionPointRec(mousePosition, signUpButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            signup();
        }

        bool isMouseOverExitButton = CheckCollisionPointRec(mousePosition, exitButton);
        DrawRectangleRounded(exitButton, 5, (int)2, (isMouseOverExitButton ? DARKGRAY : BLACK));
        DrawText("Exit", exitButtonPosition.x + 100, exitButtonPosition.y + 25, 50, WHITE);
        if (CheckCollisionPointRec(mousePosition, exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            return;
        }
        EndDrawing();
    }
}