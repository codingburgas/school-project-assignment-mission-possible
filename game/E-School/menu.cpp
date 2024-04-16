#include "menu.h"
#include "map.h"
#include "rules.h"

void menu()
{
	const int screenWidth = 1920;
	const int screenHeight = 975;

	int character = 1;

	Texture2D studentFront = LoadTexture("sprites/studentFrontMenu.png");
	Texture2D studentGirl = LoadTexture("sprites/girlSprite.png");
	const Rectangle girlPos = { 80,160,60,80 };
	 
	const Rectangle startButton = { (screenWidth / 2) + 340, (screenHeight / 2) - 30, 270, 90 };
	const Rectangle rulesButton = { (screenWidth / 2) + 340, (screenHeight / 2) + 125, 270, 90 };
	const Rectangle exitButton = { (screenWidth / 2) + 100, (screenHeight / 2) + 280, 270, 90 };

	const  Vector2 screenPos[2] = {
		{(screenWidth / 2) - 340, (screenHeight / 2) - 30 },
		{(screenWidth / 2) - 680, (screenHeight / 2) - 30 }
	};
	const Rectangle bounds[2] = {
		{(screenWidth / 2) - 720, (screenHeight / 2) - 30,150,325},
		{ (screenWidth / 2) - 250, (screenHeight / 2) - 30,125,325}
	};
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		Vector2 mousePosition = GetMousePosition();
		// Check if mouse is hovering the specific button
		bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, startButton);
		// Set new colors for hovering the button and draw text

		DrawTexturePro(studentGirl, girlPos, { (screenWidth / 2) + 340, (screenHeight / 2) + 430 ,150,350}, screenPos[0], 0.0, WHITE);
		DrawTextureEx(studentFront, screenPos[1],0.0f,5.0f, WHITE);

		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), bounds[0]))
		{
			character = 1;
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), bounds[1]))
		{
			character = 2;
		}
		DrawRectangleRec(startButton, (isMouseOverButtonStart ? SKYBLUE : BLUE));
		DrawText("Start", screenWidth / 2 + 400, screenHeight / 2 - 10, 50, WHITE);
		if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			initMap(character);
		}
		// Check if mouse is hovering the specific button
		bool isMouseOverButtonRules = CheckCollisionPointRec(mousePosition, rulesButton);
		// Set new colors for hovering the button and draw text
		DrawRectangleRec(rulesButton, (isMouseOverButtonRules ? SKYBLUE : BLUE));
		DrawText("Rules", screenWidth / 2 + 400, screenHeight / 2 + 142, 50, WHITE);
		// Handle click with the mouse over button
		if (isMouseOverButtonRules && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			rules();
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
		if (IsKeyPressed(KEY_ESCAPE))
		{
			CloseWindow();
		}
		EndDrawing();
	}
	

}