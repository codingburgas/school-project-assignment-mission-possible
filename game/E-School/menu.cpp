#include "menu.h"


void menu()
{
	const int screenWidth = 1920;
	const int screenHeight = 975;
	InitWindow(screenWidth, screenHeight, "Mission: Possible");

	bool exitGame = WindowShouldClose();

	const Rectangle startButton = { (screenWidth / 2) - 105, (screenHeight / 2) - 200, 270, 90 };
	const Rectangle rulesButton = { (screenWidth / 2) - 105, (screenHeight / 2) - 30, 270, 90 };
	const Rectangle exitButton = { (screenWidth / 2) - 105, (screenHeight / 2) + 140, 270, 90 };

	while (!exitGame)
	{
		BeginDrawing();
		ClearBackground(WHITE);
		Vector2 mousePosition = GetMousePosition();
		// Check if mouse is hovering the specific button
		bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, startButton);
		// Set new colors for hovering the button and draw text
		DrawRectangleRec(startButton, (isMouseOverButtonStart ? SKYBLUE : BLUE));
		DrawText("Start", screenWidth / 2 - 45, screenHeight / 2 - 180, 50, WHITE);
		// Handle click with the mouse over button
		if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			;
		}
		// Check if mouse is hovering the specific button
		bool isMouseOverButtonRules = CheckCollisionPointRec(mousePosition, rulesButton);
		// Set new colors for hovering the button and draw text
		DrawRectangleRec(rulesButton, (isMouseOverButtonRules ? SKYBLUE : BLUE));
		DrawText("Rules", screenWidth / 2 - 45, screenHeight / 2 - 10, 50, WHITE);
		// Handle click with the mouse over button
		if (isMouseOverButtonRules && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			;
		}

		// Check if mouse is hovering the specific button
		bool isMouseOverButtonExit = CheckCollisionPointRec(mousePosition, exitButton);
		// Set new colors for hovering the button and draw text
		DrawRectangleRec(exitButton, (isMouseOverButtonExit ? SKYBLUE : BLUE));
		DrawText("Exit", screenWidth / 2 - 20, screenHeight / 2 + 160, 50, WHITE);
		// Handle click with the mouse over button
		if (isMouseOverButtonExit && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			exitGame = true;
		}

		EndDrawing();
	}

}