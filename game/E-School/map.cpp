#include "map.h"

const Rectangle subjects[9] =
{
	{23, 325, 200, 180}, //prg
	{260, 60, 185, 265}, //bio
	{452, 60, 195, 265}, //physics
	{655, 60, 185, 265}, //chemistry
	{846, 60, 185, 265}, //History
	{345, 430, 185, 155}, //literature
	{535, 430, 190, 155}, //english
	{735, 430, 190, 155}, //math
	{935, 430, 195, 155}, //Geography
};


void initMap()
{
	Texture2D map = LoadTexture("map.png");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		DrawTexture(map, 0, 0, WHITE);

		DrawRectangleRec(subjects[0], BLACK);
		DrawText("Programming", 33, 425, 20, WHITE);

		DrawRectangleRec(subjects[1], BLACK);
		DrawText("Biology", 260, 100, 20, WHITE);

		DrawRectangleRec(subjects[2], BLACK);
		DrawText("Physics", 455, 100, 20, WHITE);

		DrawRectangleRec(subjects[3], BLACK);
		DrawText("Chemistry", 660, 100, 20, WHITE);

		DrawRectangleRec(subjects[4], BLACK);
		DrawText("Chemistry", 850, 100, 20, WHITE);

		DrawRectangleRec(subjects[5], BLACK);
		DrawText("Literature", 350, 460, 20, WHITE);

		DrawRectangleRec(subjects[6], BLACK);
		DrawText("English", 550, 460, 20, WHITE);

		DrawRectangleRec(subjects[7], BLACK);
		DrawText("Math", 750, 460, 20, WHITE);

		DrawRectangleRec(subjects[8], BLACK);
		DrawText("Geography", 950, 460, 20, WHITE);

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