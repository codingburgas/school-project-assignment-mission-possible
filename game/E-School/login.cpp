#include "login.h"
#include "menu.h"


void login() 
{
    bool isAnswerTrue = false;

    char name[50] = "\0";
    int letterCount = 0;

    const Rectangle usernameBox = { GetScreenWidth() / 2 - 300, GetScreenHeight()/2 -235, 650, 65 };
    bool mouseOnText = false;

    int framesCounter = 0;
    const Rectangle loginButton = { GetScreenWidth() / 2 - 110, GetScreenHeight() / 2 + 350, 270, 90 };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
     
        if (CheckCollisionPointRec(mousePosition, usernameBox)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            int key = GetCharPressed();

            while (key > 0)
            {
                if ((key >= 32) && (key <= 125) && (letterCount <= 50))
                {
                    name[letterCount] = (char)key;
                    name[letterCount + 1] = '\0';
                    letterCount++;
                }

                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText) framesCounter++;
        else framesCounter = 0;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePosition, loginButton))
        {
            menu();
        }
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Welcome back! Log into your account!", GetScreenWidth() / 2 - 325, GetScreenHeight()/2  -400, 40, BLACK);

        bool isMouseOverButtonLogin = CheckCollisionPointRec(mousePosition, loginButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(loginButton, (isMouseOverButtonLogin ? GREEN : LIME));
        DrawText("Login", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 370, 50, WHITE);
        if (isMouseOverButtonLogin && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            login();
        }
        if (mouseOnText) DrawRectangleLines((int)usernameBox.x, (int)usernameBox.y, (int)usernameBox.width, (int)usernameBox.height, RED);
        else DrawRectangleLines((int)usernameBox.x, (int)usernameBox.y, (int)usernameBox.width, (int)usernameBox.height, DARKGRAY);

        DrawText(name, (int)usernameBox.x + 5, (int)usernameBox.y + 8, 40, BLACK);
        DrawText("Username:", GetScreenWidth() / 2 - 75, GetScreenHeight()/2 - 278, 40, BLACK);

        EndDrawing();
    }
}
void startingScreen()
{
	const int screenWidth = 1920;
	const int screenHeight = 975;
	InitWindow(screenWidth, screenHeight, "Mission: Possible");

	const Rectangle loginButton = { screenWidth / 2 - 450, screenHeight / 2 - 50, 270,90 };
	const Rectangle registerButton = { screenWidth / 2 + 220, screenHeight / 2 - 50, 270,90 };

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);
		Vector2 mousePosition = GetMousePosition();

		DrawText("Welcome to our game! Let's get into it",screenWidth/2 - 365, screenHeight/2 - 400, 40, BLACK);
		bool isMouseOverButtonLogin = CheckCollisionPointRec(mousePosition, loginButton);
		// Set new colors for hovering the button and draw text
		DrawRectangleRec(loginButton, (isMouseOverButtonLogin ? GREEN : LIME));
		DrawText("Login", screenWidth / 2 -385, screenHeight / 2 -30, 50, WHITE);
		if (isMouseOverButtonLogin && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			login();
		}
		bool isMouseOverButtonRegister = CheckCollisionPointRec(mousePosition, registerButton);
		// Set new colors for hovering the button and draw text
		DrawRectangleRec(registerButton, (isMouseOverButtonRegister ? GREEN : LIME));
		DrawText("Register", screenWidth / 2 + 250, screenHeight / 2 - 30, 50, WHITE);
		if (isMouseOverButtonRegister && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			CloseWindow();
		}
		EndDrawing();
	}

}