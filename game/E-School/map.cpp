#include "map.h"
#include "rooms.h"

void initMap(int character)
{
	const int screenWidth = 1920;
	const int screenHeight = 975;
	float studentX = 435;
	float studentY = 700;

	Rectangle subjects[9] =
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

	Texture2D map = LoadTexture("map.png");
	Texture2D studentBack = LoadTexture("sprites/studentBack.png");
	Texture2D studentLeft = LoadTexture("sprites/studentLeft.png");
	Texture2D studentRight = LoadTexture("sprites/studentRight.png");
	Texture2D studentFront = LoadTexture("sprites/studentFront.png");
	Texture2D studentGirl = LoadTexture("sprites/girlSprite.png");

	Rectangle student = { studentX, studentY, 50, 50 };

	Rectangle spriteGirl[10] =
	{
		{0,0,55,80}, //1
		{80,0,55,80},//2
		{160,0,55,80},//3
		{0,80,60,80},//4
		{80,80,60,80},//5
		{160,80,60,80},//6
		{0,160,60,80},//7
		{80,160,60,80},//8
		{160,160,60,80},//9
		{0,240,60,75},//10
	};


	int currentFrame = 8;
	float frameCounter = 0;

	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
		{
			studentY -= 3.0f;
			student.y = studentY;
			currentFrame = 8 + (int)(GetTime() * 5) % 2; // Animation for walking forward
		}

		if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
		{
			studentY += 3.0f;
			student.y = studentY;
			currentFrame = 6 + (int)(GetTime() * 5) % 2; // Animation for walking back
		}

		if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
		{
			studentX -= 3.0f;
			student.x = studentX;
			currentFrame = 2 + (int)(GetTime() * 5) % 2; // Animation for walking left
		}

		if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
		{
			studentX += 3.0f;
			student.x = studentX;
			currentFrame = 4 + (int)(GetTime() * 5) % 2; // Animation for walking right
		}


		BeginDrawing();
		ClearBackground(WHITE);
		DrawTexture(map, 300, 100, WHITE);

		DrawRectangleRec(subjects[0], CheckCollisionRecs(student, subjects[0]) ? SKYBLUE : BLUE);
		DrawText("Programming", 330, 500, 30, BLACK);

		DrawRectangleRec(subjects[1], CheckCollisionRecs(student, subjects[1]) ? GREEN : LIME);
		DrawText("Biology", 595, 250, 30, BLACK);

		DrawRectangleRec(subjects[2], CheckCollisionRecs(student, subjects[2]) ? BLUE : DARKBLUE);
		DrawText("Physics", 795, 250, 30, BLACK);

		DrawRectangleRec(subjects[3], CheckCollisionRecs(student, subjects[3]) ? PURPLE : VIOLET);
		DrawText("Chemistry", 975, 250, 30, BLACK);

		DrawRectangleRec(subjects[4], CheckCollisionRecs(student, subjects[4]) ? LIGHTGRAY : GRAY);
		DrawText("History", 1175, 250, 30, BLACK);

		DrawRectangleRec(subjects[5], CheckCollisionRecs(student, subjects[5]) ? GOLD : ORANGE);
		DrawText("Literature", 657, 585, 30, BLACK);

		DrawRectangleRec(subjects[6], CheckCollisionRecs(student, subjects[6]) ? PINK : RED);
		DrawText("English", 880, 587, 30, BLACK);

		DrawRectangleRec(subjects[7], CheckCollisionRecs(student, subjects[7]) ? BEIGE : BROWN);
		DrawText("Math", 1094, 592, 30, BLACK);

		DrawRectangleRec(subjects[8], CheckCollisionRecs(student, subjects[8]) ? GREEN : DARKGREEN);
		DrawText("Geography", 1255, 592, 30, BLACK);

		if (character == 1) {
			if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
			{
				DrawTexture(studentBack, studentX, studentY, WHITE);
			}

			if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
			{
				DrawTexture(studentFront, studentX, studentY, WHITE);
			}

			if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
			{
				DrawTexture(studentLeft, studentX, studentY, WHITE);
			}

			if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
			{
				DrawTexture(studentRight, studentX, studentY, WHITE);
			}

			if (IsKeyUp(KEY_W) && IsKeyUp(KEY_S) && IsKeyUp(KEY_A) && IsKeyUp(KEY_D))
			{
				DrawTexture(studentBack, studentX, studentY, WHITE);
			}

		}
		else if (character == 2)
		{
			DrawTextureRec(studentGirl, spriteGirl[currentFrame], { studentX,studentY }, WHITE);
			frameCounter += 0.5f;

			if (frameCounter >= 5)
			{
				frameCounter = 0;
				currentFrame++;

				if (currentFrame > 9)
				{
					currentFrame = 0;
				}
			}
		}
		
			if (CheckCollisionRecs(student, subjects[0]))
			{
				DrawText("Press ENTER to enter.", 435, 700, 30, BLACK);
				if (IsKeyDown(KEY_ENTER))
				{
					programming();
					studentX = 435;
					studentY = 700;
					student.x = studentX;
					student.y = studentY;
				}
			}

			if (CheckCollisionRecs(student, subjects[1]))
			{
				DrawText("Press ENTER to enter.", 435, 700, 30, BLACK);
				if (IsKeyDown(KEY_ENTER))
				{
					biology();
					studentX = 435;
					studentY = 700;
					student.x = studentX;
					student.y = studentY;
				}
			}

			if (CheckCollisionRecs(student, subjects[2]))
			{
				DrawText("Press ENTER to enter.", 435, 700, 30, BLACK);
				if (IsKeyDown(KEY_ENTER))
				{
					physics();
					studentX = 435;
					studentY = 700;
					student.x = studentX;
					student.y = studentY;
				}
			}

			if (CheckCollisionRecs(student, subjects[3]))
			{
				DrawText("Press ENTER to enter.", 435, 700, 30, BLACK);
				if (IsKeyDown(KEY_ENTER))
				{
					chemistry();
					studentX = 435;
					studentY = 700;
					student.x = studentX;
					student.y = studentY;
				}
			}

			if (CheckCollisionRecs(student, subjects[4]))
			{
				DrawText("Press ENTER to enter.", 435, 700, 30, BLACK);
				if (IsKeyDown(KEY_ENTER))
				{
					history();
					studentX = 435;
					studentY = 700;
					student.x = studentX;
					student.y = studentY;
				}
			}

			if (CheckCollisionRecs(student, subjects[5]))
			{
				DrawText("Press ENTER to enter.", 435, 700, 30, BLACK);
				if (IsKeyDown(KEY_ENTER))
				{
					literature();
					studentX = 435;
					studentY = 700;
					student.x = studentX;
					student.y = studentY;
				}
			}

			if (CheckCollisionRecs(student, subjects[6]))
			{
				DrawText("Press ENTER to enter.", 435, 700, 30, BLACK);
				if (IsKeyDown(KEY_ENTER))
				{
					english();
					studentX = 435;
					studentY = 700;
					student.x = studentX;
					student.y = studentY;
				}
			}

			if (CheckCollisionRecs(student, subjects[7]))
			{
				DrawText("Press ENTER to enter.", 435, 700, 30, BLACK);
				if (IsKeyDown(KEY_ENTER))
				{
					maths();
					studentX = 435;
					studentY = 700;
					student.x = studentX;
					student.y = studentY;
				}
			}

			if (CheckCollisionRecs(student, subjects[8]))
			{
				DrawText("Press ENTER to enter.", 435, 700, 30, BLACK);
				if (IsKeyDown(KEY_ENTER))
				{
					geography();
					studentX = 435;
					studentY = 700;
					student.x = studentX;
					student.y = studentY;
				}
			}
		

		EndDrawing();
		currentFrame = 8;
		if (IsKeyPressed(KEY_F))
		{
			cout << "Character: (" << student.x << ", " << student.y << "), width: " << student.width << ", height: " << student.height << endl;

			for (int i = 0; i < 9; ++i) {
				cout << "Subject " << i << ": (" << subjects[i].x << ", " << subjects[i].y << "), width: " << subjects[i].width << ", height: " << subjects[i].height << endl;
			}

			cout << "Collision with subject 0: " << (CheckCollisionRecs(student, subjects[0]) ? "Yes" : "No") << endl;
		}
	}

}