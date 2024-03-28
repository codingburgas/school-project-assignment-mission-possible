#include "menu.h"

void menu()
{
	const int screenWidth = 1920;
	const int screenHeight = 975;
	InitWindow(screenWidth, screenHeight, "Mission: Possible");
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(WHITE);
		DrawText("Good luck at the project!", 500, 600,30, BLACK);
		EndDrawing();
	}
	CloseWindow();
}