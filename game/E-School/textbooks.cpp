#include "textbooks.h"


float distanceCalc(Vector3 a, Vector3 b) {
    float dx = b.x - a.x;
    float dy = b.y - a.y;
    float dz = b.z - a.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
void bioTextBook(Camera camera)
{
    unsigned int pageNumber = 1;
    Vector3 cubePosition = { 0.0f, 1.5f, -7.5f };
    float distance = distanceCalc(camera.position, cubePosition);

    Rectangle previous = { 1800,900,100,50 };
    Rectangle next = { 50,900,100,50 };

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
            }


            if (IsKeyPressed(KEY_B))
            {
                DisableCursor();
                break;
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), previous))
            {
                pageNumber++;
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), next))
            {
                pageNumber--;
            }
            EndDrawing();
            SetExitKey(KEY_ESCAPE);
        }
    }
}