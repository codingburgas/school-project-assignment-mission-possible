#include "map.h"
#include "subjects.h"

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

		DrawRectangleRec(subjects[0], CheckCollisionPointRec(GetMousePosition(), subjects[0]) ? SKYBLUE : BLUE);
		DrawText("Programming", 330, 500, 30, BLACK);

		DrawRectangleRec(subjects[1], CheckCollisionPointRec(GetMousePosition(), subjects[1]) ? GREEN : LIME);
		DrawText("Biology", 595, 250, 30, BLACK);

		DrawRectangleRec(subjects[2], CheckCollisionPointRec(GetMousePosition(), subjects[2]) ? BLUE : DARKBLUE);
		DrawText("Physics", 795, 250, 30, BLACK);

		DrawRectangleRec(subjects[3], CheckCollisionPointRec(GetMousePosition(), subjects[3]) ? PURPLE : VIOLET);
		DrawText("Chemistry", 975, 250, 30, BLACK);

		DrawRectangleRec(subjects[4], CheckCollisionPointRec(GetMousePosition(), subjects[4]) ? LIGHTGRAY : GRAY);
		DrawText("History", 1175, 250, 30, BLACK);

		DrawRectangleRec(subjects[5], CheckCollisionPointRec(GetMousePosition(), subjects[5]) ? GOLD : ORANGE);
		DrawText("Literature", 657, 585, 30, BLACK);

		DrawRectangleRec(subjects[6], CheckCollisionPointRec(GetMousePosition(), subjects[6]) ? PINK : RED);
		DrawText("English", 880, 587, 30, BLACK);

		DrawRectangleRec(subjects[7], CheckCollisionPointRec(GetMousePosition(), subjects[7]) ? BEIGE : BROWN);
		DrawText("Math", 1094, 592, 30, BLACK);

		DrawRectangleRec(subjects[8],CheckCollisionPointRec(GetMousePosition(), subjects[8]) ? GREEN : DARKGREEN);
		DrawText("Geography", 1255, 592, 30, BLACK);
		

		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[0]))
		{
			programming();
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[1]))
		{
			biology();
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[2]))
		{
			physics();
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[3]))
		{
			chemistry();
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[4]))
		{
			history();
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[5]))
		{
			literature();
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[6]))
		{
			english();
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[7]))
		{
			maths();
		}
		if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), subjects[8]))
		{
			geography();
		}
		EndDrawing();
	}

}