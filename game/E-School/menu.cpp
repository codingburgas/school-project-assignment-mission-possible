#include "menu.h"
#include "map.h"

void menu()
{
	const int screenWidth = 1920;
	const int screenHeight = 975;


	const Rectangle startButton = { (screenWidth / 2) + 340, (screenHeight / 2) - 30, 270, 90 };
	const Rectangle rulesButton = { (screenWidth / 2) + 340, (screenHeight / 2) + 125, 270, 90 };
	const Rectangle exitButton = { (screenWidth / 2) + 340, (screenHeight / 2) + 280, 270, 90 };

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		Vector2 mousePosition = GetMousePosition();
		// Check if mouse is hovering the specific button
		bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, startButton);
		// Set new colors for hovering the button and draw text
		DrawRectangleRec(startButton, (isMouseOverButtonStart ? SKYBLUE : BLUE));
		DrawText("Start", screenWidth / 2 + 400, screenHeight / 2 - 10, 50, WHITE);
		if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			initMap();
		}
		// Check if mouse is hovering the specific button
		bool isMouseOverButtonRules = CheckCollisionPointRec(mousePosition, rulesButton);
		// Set new colors for hovering the button and draw text
		DrawRectangleRec(rulesButton, (isMouseOverButtonRules ? SKYBLUE : BLUE));
		DrawText("Rules", screenWidth / 2 + 400, screenHeight / 2 + 142, 50, WHITE);
		// Handle click with the mouse over button
		if (isMouseOverButtonRules && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			;
		}

		// Check if mouse is hovering the specific button
		bool isMouseOverButtonExit = CheckCollisionPointRec(mousePosition, exitButton);
		// Set new colors for hovering the button and draw text
		DrawRectangleRec(exitButton, (isMouseOverButtonExit ? SKYBLUE : BLUE));
		DrawText("Exit", screenWidth / 2 + 425, screenHeight / 2 + 300, 50, WHITE);
		// Handle click with the mouse over button
		if (isMouseOverButtonExit && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			CloseWindow();
		}
		EndDrawing();
	}

}