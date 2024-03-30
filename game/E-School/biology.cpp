#include "subjects.h"
#include "textbooks.h"

Camera camera = { 0 };

float distanceCalc(Vector3 a, Vector3 b) {
    float dx = b.x - a.x;
    float dy = b.y - a.y;
    float dz = b.z - a.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void bioTextBook()
{
    unsigned int pageNumber = 1;
    Vector3 cubePosition = { 0.0f, 1.5f, -7.5f };
    float distance = distanceCalc(camera.position, cubePosition);

    Rectangle previous = { 1800,900,100,50 };
    Rectangle next = {50,900,100,50};
   
    if (distance < 3.5f && IsKeyPressed(KEY_F))
    {
        EnableCursor();
        EndMode3D();
        while (true)
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
        }
    }
}

void biology()
{

    camera.position = { 0.0f, 2.0f, 4.0f };    // Camera position
    camera.target = { 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    int cameraMode = CAMERA_FIRST_PERSON;

    // Generates some random columns
    DisableCursor();                    // Limit cursor to relative movement inside the window

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {

        UpdateCamera(&camera, cameraMode);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 10.0f, 10.0f }, LIGHTGRAY);
        DrawCube({ -10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, BROWN);
        DrawCube({ 10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, BROWN);
        DrawCube({ 0.0f, 2.5f, 10.0f }, 21.0f, 8.3f, 1.0f, BROWN);
        DrawCube({ 0.0f, 2.5f, -10.0f }, 21.0f, 8.3f, 1.0f, BROWN);
        DrawCube({ 0.0f, 6.7f, 0.0f }, 21.0f, 0.2f, 21.0f, LIGHTGRAY);

        DrawCube({ 0.0f, 1.5f, -7.5f }, 1.0f, 1.0f, 1.0f, GOLD);

        EndMode3D();
        bioTextBook();
        EndDrawing();

    }

    SetExitKey(KEY_ESCAPE);
    EnableCursor();
}