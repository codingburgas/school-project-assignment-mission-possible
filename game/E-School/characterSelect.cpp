#include "characterSelect.h"
#include "map.h"

void select()
{
	// Load textures for girl, boy, and arrow
	Texture2D girl = LoadTexture("Textures/girlMainMenu.png");
	Texture2D boy = LoadTexture("Textures/boyMainMenu.png");
	Texture2D arrow = LoadTexture("Textures/arrow.png");

	// Load background textures for each scene
	Texture2D background1 = LoadTexture("../images/selectionBackground1.png");
	Texture2D background2 = LoadTexture("../images/selectionBackground2.png");
	Texture2D background3 = LoadTexture("../images/selectionBackground3.png");

	// Initialize variables
	int backgroundScene;
	int character = 1;
	float arrowX = 800;
	float arrowY = 700;

	// Define rectangles for girl and boy character positions
	Rectangle girlPos[3] = {
		{0,0,200,250},
		{250,0,200,250},
		{0,250,200,250}
	};

	Rectangle boyPos[3] = {
		{0,0,200,250},
		{250,0,200,250},
		{0,250,200,250}
	};

	// Define rectangles for choice buttons
	Rectangle choice[2] =
	{
		{700,400,200,350},
		{1050,400,200,350},
	};

	// Randomly select background scene
	backgroundScene = (rand() % 3) + 1;
	float i = 0;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		// Draw background based on selected scene
		if (backgroundScene == 1)
		{
			DrawTexture(background1, 0, 0, WHITE);
			i += 0.05;
			if (i >= 3)
			{
				i = 0;
			}
			// Draw arrow based on mouse position over choice buttons
			if (CheckCollisionPointRec(GetMousePosition(), choice[0]))
			{
				arrowX = 800;
				DrawRectangle(0, 0, 960, 975, { 117, 123, 156, 175 });
				DrawTexture(arrow, arrowX, arrowY, WHITE);
			}
			if (CheckCollisionPointRec(GetMousePosition(), choice[1]))
			{
				arrowX = 1100;
				DrawRectangle(960, 0, 960, 975, { 157, 111, 142, 175 });
				DrawTexture(arrow, arrowX, arrowY, WHITE);
			}
		}
		else if (backgroundScene == 2)
		{
			DrawTexture(background2, 0, 0, WHITE);
			i += 0.05;
			if (i >= 3)
			{
				i = 0;
			}
			if (CheckCollisionPointRec(GetMousePosition(), choice[0]))
			{
				arrowX = 800;
				DrawRectangle(0, 0, 960, 975, { 117, 123, 156, 175 });
				DrawTexture(arrow, arrowX, arrowY, WHITE);
			}
			if (CheckCollisionPointRec(GetMousePosition(), choice[1]))
			{
				arrowX = 1100;
				DrawRectangle(960, 0, 960, 975, { 157, 111, 142, 175 });
				DrawTexture(arrow, arrowX, arrowY, WHITE);
			}
		}
		else
		{
			DrawTexture(background3, 0, 0, WHITE);
			i += 0.05;
			if (i >= 3)
			{
				i = 0;
			}
			if (CheckCollisionPointRec(GetMousePosition(), choice[0]))
			{
				arrowX = 800;
				DrawRectangle(0, 0, 960, 975, { 117, 123, 156, 175 });
				DrawTexture(arrow, arrowX, arrowY, WHITE);
			}
			if (CheckCollisionPointRec(GetMousePosition(), choice[1]))
			{
				arrowX = 1100;
				DrawRectangle(960, 0, 960, 975, { 157, 111, 142, 175 });
				DrawTexture(arrow, arrowX, arrowY, WHITE);
			}
		}

		// Draw text and character images
		DrawTextureRec(girl, girlPos[int(i)], { 1000, 425 }, WHITE);
		DrawTextureRec(boy, boyPos[int(i)], { 700, 425 }, WHITE);

		// Check for button clicks and initialize map based on choice
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), choice[0]))
		{
			initMap(1);
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), choice[1]))
		{
			initMap(2);
		}

		EndDrawing();
	}
}
