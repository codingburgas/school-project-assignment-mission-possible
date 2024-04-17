#include "textbooks.h"


float distanceCalc(Vector3 a, Vector3 b) {
    float distanceX = b.x - a.x;
    float distanceY = b.y - a.y;
    float distanceZ = b.z - a.z;
    return sqrt(distanceX * distanceX + distanceY * distanceY + distanceZ * distanceZ);
}
void bioTextBook(Camera camera)
{
    unsigned int pageNumber = 1;
    Vector3 cubePosition = { 0.0f, 1.5f, -7.5f };
    float distance = distanceCalc(camera.position, cubePosition);

	float elapsedTime = 0.0f;
	float updateInterval = 1.0f;

	int minutes = 1;
	int seconds = 0;

    Rectangle next = { 1800,900,100,50 };
    Rectangle previous = { 50,900,100,50 };

    bool timerIsZero = 0;

    if (distance < 3.5f && IsKeyPressed(KEY_F))
    {
        EnableCursor();
        EndMode3D();
        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(WHITE);

            DrawRectangleRec(previous, BLUE);
            DrawRectangleRec(next, BLUE);

            DrawText("previous", 50, 915, 20, BLACK);
            DrawText("next", 1800, 915, 20, BLACK);
            switch (pageNumber)
            {
            case 1:
                DrawText("Biology", 825, 100, 100, BLACK);
                DrawText("Author: Kaloyan Ivanov", 875, 250, 25, BLACK);
                DrawText("1", 975, 900, 25, BLACK);
                break;
            case 2:
                DrawText("2", 975, 900, 25, BLACK);
                break;
            case 3:
                DrawText("3", 975, 900, 25, BLACK);
                break;
            case 4:
                DrawText("4", 975, 900, 25, BLACK);
                break;
            case 5:
                DrawText("5", 975, 900, 25, BLACK);
                break;
            default:
                pageNumber = 1;
                break;
            }

			elapsedTime += GetFrameTime();

			if (elapsedTime >= updateInterval) {
				// Decrement the timer
				if (seconds == 0) {
					if (minutes == 0)
					{
                        timerIsZero = 1;
					}
					minutes--;
					seconds = 59;

				}
				else {
					seconds--;
				}

				elapsedTime = 0.0f; // Reset elapsed time
			}

			EndMode3D();
			// Draw timer
			DrawText(TextFormat("%02d:%02d", minutes, seconds), 930, 40, 50, RED);

            if (timerIsZero == 1)
            {
                DisableCursor();
                break;
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), previous))
            {
                pageNumber--;
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), next))
            {
                pageNumber++;
            }
            EndDrawing();
        }
    }
}

void prgTextBook(Camera camera,Vector3 cubePosition)
{
	unsigned int pageNumber = 1;
	float distance = distanceCalc(camera.position, cubePosition);

	Rectangle gameButton = { 900,460,100,50 };
	Rectangle textButton = { 1100,460,100,50 };

	float elapsedTime = 0.0f;
	float updateInterval = 1.0f;

	int minutes = 1;
	int seconds = 0;
	bool menu = 1;
	bool game = 0;
	bool book = 0;
	Rectangle next = { 1800,900,100,50 };
	Rectangle previous = { 50,900,100,50 };

	bool timerIsZero = 0;

	if (distance < 3.5f && IsKeyPressed(KEY_F))
	{
		EnableCursor();
		EndMode3D();
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(WHITE);
			if (IsKeyPressed(KEY_B) || timerIsZero == 1)
			{
				DisableCursor();
				break;
			}
			if (menu == 1)
			{
              DrawRectangleRec(gameButton, RED);
			  DrawRectangleRec(textButton, BLUE);
			}
			
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), gameButton))
			{
				menu = 0;
				game = 1;
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), textButton))
			{
				menu = 0;
				book = 1;
			}
			if (game == 1)
			{
				pong();
			}
			if (book == 1)
			{
				DrawRectangleRec(previous, BLUE);
				DrawRectangleRec(next, BLUE);

				DrawText("previous", 50, 915, 20, BLACK);
				DrawText("next", 1800, 915, 20, BLACK);
				switch (pageNumber)
				{
				case 1:
					DrawText("Programming", 825, 100, 100, BLACK);
					DrawText("Author: Kaloyan Ivanov", 875, 250, 25, BLACK);
					DrawText("1", 975, 900, 25, BLACK);
					break;
				case 2:
					DrawText("2", 975, 900, 25, BLACK);
					break;
				case 3:
					DrawText("3", 975, 900, 25, BLACK);
					break;
				case 4:
					DrawText("4", 975, 900, 25, BLACK);
					break;
				case 5:
					DrawText("5", 975, 900, 25, BLACK);
					break;
				default:
					pageNumber = 1;
					break;
				}

				elapsedTime += GetFrameTime();

				if (elapsedTime >= updateInterval) {
					// Decrement the timer
					if (seconds == 0) {
						if (minutes == 0)
						{
							timerIsZero = 1;
						}
						minutes--;
						seconds = 59;

					}
					else {
						seconds--;
					}

					elapsedTime = 0.0f; // Reset elapsed time
				}

				EndMode3D();
				// Draw timer
				DrawText(TextFormat("%02d:%02d", minutes, seconds), 930, 40, 50, RED);

				if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), previous))
				{
					pageNumber--;
				}
				if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), next))
				{
					pageNumber++;
				}
				
			
			}
			EndDrawing();
			bool menu = 1;
			bool game = 0;
			bool book = 0;
		}
	}
	DisableCursor();
}


void englishTextBook(Camera camera)
{
	unsigned int pageNumber = 1;
	Vector3 cubePosition = { 0.0f, 1.5f, -7.5f };
	float distance = distanceCalc(camera.position, cubePosition);

	float elapsedTime = 0.0f;
	float updateInterval = 1.0f;

	int minutes = 1;
	int seconds = 0;

	Rectangle next = { 1800,900,100,50 };
	Rectangle previous = { 50,900,100,50 };

	bool timerIsZero = 0;

	if (distance < 3.5f && IsKeyPressed(KEY_F))
	{
		EnableCursor();
		EndMode3D();
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(WHITE);

			DrawRectangleRec(previous, BLUE);
			DrawRectangleRec(next, BLUE);

			DrawText("previous", 50, 915, 20, BLACK);
			DrawText("next", 1800, 915, 20, BLACK);
			switch (pageNumber)
			{
			case 1:
				DrawText("Biology", 825, 100, 100, BLACK);
				DrawText("Author: Kaloyan Ivanov", 875, 250, 25, BLACK);
				DrawText("1", 975, 900, 25, BLACK);
				break;
			case 2:
				DrawText("2", 975, 900, 25, BLACK);
				break;
			case 3:
				DrawText("3", 975, 900, 25, BLACK);
				break;
			case 4:
				DrawText("4", 975, 900, 25, BLACK);
				break;
			case 5:
				DrawText("5", 975, 900, 25, BLACK);
				break;
			default:
				pageNumber = 1;
				break;
			}

			elapsedTime += GetFrameTime();

			if (elapsedTime >= updateInterval) {
				// Decrement the timer
				if (seconds == 0) {
					if (minutes == 0)
					{
						timerIsZero = 1;
					}
					minutes--;
					seconds = 59;

				}
				else {
					seconds--;
				}

				elapsedTime = 0.0f; // Reset elapsed time
			}

			EndMode3D();
			// Draw timer
			DrawText(TextFormat("%02d:%02d", minutes, seconds), 930, 40, 50, RED);

			if (timerIsZero == 1)
			{
				DisableCursor();
				break;
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), previous))
			{
				pageNumber--;
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), next))
			{
				pageNumber++;
			}
			EndDrawing();
		}
	}
}