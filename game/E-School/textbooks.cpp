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

            if (IsKeyPressed(KEY_B) || timerIsZero == 1)
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
            SetExitKey(KEY_ESCAPE);
        }
    }
}
void testBio()
{
    Rectangle answer[4] = {
    {130, 415, 240, 50},
    {440, 415, 240, 50},
    {130, 525, 240, 50},
    {440, 525, 240, 50}
    };
    int points = 0;
    for (int i = 1; i <= 10; i++)
    {
        int questionNumber = GetRandomValue(1, 20);
        switch (questionNumber)
        {
        case 1:
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), answer[1]))
            {
                points++;
            }
            else if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && (CheckCollisionPointRec(GetMousePosition(), answer[0]) || CheckCollisionPointRec(GetMousePosition(), answer[2]) || CheckCollisionPointRec(GetMousePosition(), answer[3])))
            {
                points--;
            }
        break;
        }
    }
    
}