#include "characterSelect.h"
#include "map.h"
void select()
{
	Texture2D girl = LoadTexture("sprites/girlMainMenu.png");
	Texture2D boy = LoadTexture("sprites/studentFrontMenu.png");
	int character = 1;

	Rectangle girlPos[3] = {
		{0,0,200,250},
		{250,0,200,250},
		{0,250,200,250}
	};

	Rectangle choice[2] =
	{
		{700,400,100,300},
		{1050,400,150,300},
	};
	float i = 0;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		DrawText("Pick your character", 780, 300, 50, BLACK);
		DrawTextureEx(boy, { 700, 400 },1.0f,5.0f,WHITE );
		DrawTextureRec(girl, girlPos[int(i)], { 1000, 425 }, WHITE);
		i+=0.1;
		if (i >= 3)
		{
			i = 0;
		}
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