#include "map.h"
#include "rooms.h"

void initMap()
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
	Texture2D studentBack = LoadTexture("studentBack.png");
	Texture2D studentFront = LoadTexture("studentFront.png");
	Texture2D studentLeft = LoadTexture("studentLeft.png");
	Texture2D studentRight = LoadTexture("studentRight.png");

	Rectangle student = { studentX, studentY, studentBack.width, studentBack.height };

	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
		{
			studentY -= 3.0f;
			student.y = studentY;
		}

		if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
		{
			studentY += 3.0f;
			student.y = studentY;
		}

		if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
		{
			studentX -= 3.0f;
			student.x = studentX;
		}

		if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
		{
			studentX += 3.0f;
			student.x = studentX;
		}

		BeginDrawing();

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
	}

}