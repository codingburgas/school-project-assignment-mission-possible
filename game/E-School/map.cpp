#include "map.h"

const Rectangle subjects[9] =
{
	{321, 428, 203, 173}, //prg
	{559, 160, 188, 266}, //bio
	{750, 160, 199, 266}, //physics
	{952, 160, 189, 265}, //chemistry
	{1144, 159, 186, 266}, //History
	{644, 528, 187, 159}, //literature
	{834, 528, 194, 159}, //english
	{1031, 528, 198, 160}, //math
	{1232, 528, 202, 159}, //Geography
};


void initMap()
{
	Texture2D map = LoadTexture("map.png");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		DrawTexture(map, 300, 100, WHITE);

		DrawRectangleRec(subjects[0], BLUE);
		DrawText("Programming", 330, 500, 30, BLACK);

		DrawRectangleRec(subjects[1], GREEN);
		DrawText("Biology", 595, 250, 30, BLACK);

		DrawRectangleRec(subjects[2], DARKBLUE);
		DrawText("Physics", 795, 250, 30, BLACK);

		DrawRectangleRec(subjects[3], PURPLE);
		DrawText("Chemistry", 975, 250, 30, BLACK);

		DrawRectangleRec(subjects[4], YELLOW);
		DrawText("History", 1175, 250, 30, BLACK);

		DrawRectangleRec(subjects[5], ORANGE);
		DrawText("Literature", 657, 585, 30, BLACK);

		DrawRectangleRec(subjects[6], RED);
		DrawText("English", 880, 587, 30, BLACK);

		DrawRectangleRec(subjects[7], BROWN);
		DrawText("Math", 1094, 592, 30, BLACK);

		DrawRectangleRec(subjects[8], DARKGREEN);
		DrawText("Geography", 1255, 592, 30, BLACK);
		

		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[0]))
		{
			;
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[1]))
		{
			;
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[2]))
		{
			;
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[3]))
		{
			;
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[4]))
		{
			;
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[5]))
		{
			;
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[6]))
		{
			;
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[7]))
		{
			;
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[8]))
		{
			;
		}
		EndDrawing();
	}

}