#include "rooms.h"
#include "textbooks.h"
void drawCoordinates(Camera& camera)
{
    string positionString = "Camera Position: (" +
        to_string(camera.position.x) + ", " +
        to_string(camera.position.y) + ", " +
        to_string(camera.position.z) + ")";
    DrawText(positionString.c_str(), 10, 10, 20, GOLD);
}
bool checkCollision(const BoundingBox& box1, const BoundingBox& box2) {
    return (box1.min.x <= box2.max.x && box1.max.x >= box2.min.x) &&
        (box1.min.y <= box2.max.y && box1.max.y >= box2.min.y) &&
        (box1.min.z <= box2.max.z && box1.max.z >= box2.min.z);
}

void collisions(Camera& camera, Vector3 previousCameraPosition, BoundingBox cameraBox, BoundingBox wallBox)
{

    if (checkCollision(cameraBox, wallBox)) {

    }
    else {
        camera.position = previousCameraPosition;
    }
}

void collisionModels(Camera& camera, Vector3 previousCameraPosition, BoundingBox cameraBox, BoundingBox wallBox)
{

    if (!checkCollision(cameraBox, wallBox)) {

    }
    else {
        camera.position = previousCameraPosition;
    }
}

void drawFurnitures(Model chair, Model desk, Model deskChair, Model studentDesk, Model board, Model laptop, Camera& camera, Vector3 previousCameraPosition)
{
    BoundingBox cameraBox;
    BoundingBox deskBox;
    cameraBox.min = camera.position;
    cameraBox.max = camera.position;
    cameraBox.min.x -= 0.1f;
    cameraBox.min.y -= 0.1f;
    cameraBox.min.z -= 0.1f;
    cameraBox.max.x += 0.3f;
    cameraBox.max.y += 0.5f;
    cameraBox.max.z += 0.5f;
    int change = 0;

    for (int i = 0; i <= 16; i += 4)
    {
        for (int j = 0; j <= 8; j += 4) {
            DrawModel(chair, { -7.8f + i,0.1f,7.0f - j }, 0.03, WHITE);
            DrawModel(studentDesk, { -7.8f + i,-0.1f,6.5f - j }, 0.015, BLACK);
        }

    }
    DrawModel(desk, { 0.0f,0.2f,-7.0f }, 0.015, GRAY);
    DrawModel(laptop, { -0.5f,1.64f,-6.5f }, 4.0, GRAY);
    DrawModel(deskChair, { 0.0f,0.2f,-8.0f }, 0.6, BLACK);
    DrawModel(board, { 0.0f, 2.5f, -9.4f }, 1.0, WHITE);

    BoundingBox studentDeskBox[16];
    for (int i = 0; i < 3; i++)
    {
         studentDeskBox[i].min = { 7.25f, 0.2f, -2.0f+change };
         studentDeskBox[i].max = {8.9f,2.0f,0.0f+change};
         change += 4;
    }
    change = 0;
    for (int i = 3; i < 6; i++)
    {
        studentDeskBox[i].min = { 3.25f , 0.2f, -2.0f + change };
        studentDeskBox[i].max = { 4.8f ,2.0f,0.0f + change };
        change += 4;
    }
    change = 0;
    for (int i = 6; i < 9; i++)
    {
        studentDeskBox[i].min = { -0.4f ,0.2f,-2.0f + change };
        studentDeskBox[i].max = { 1.1f , 2.0f, 0.0f + change };
        change += 4;
    }
    change = 0;
    for (int i = 9; i < 12; i++)
    {
        studentDeskBox[i].min = { -4.5f ,0.2f,-2.0f + change };
        studentDeskBox[i].max = { -3.0f , 2.0f, 0.0f + change };
        change += 4;
    }
    change = 0;
    for (int i = 12; i < 15; i++)
    {
        studentDeskBox[i].min = { -8.5f ,0.2f,-2.0f + change };
        studentDeskBox[i].max = { -7.0f , 2.0f, 0.0f + change };
        change += 4;
    }
    for (int i = 0; i < 15; i++)
    {
        collisionModels(camera, previousCameraPosition, cameraBox, studentDeskBox[i]);
    }
    deskBox.min = { -1.0f ,0.2f,-8.5f };
    deskBox.max = { 1.0f ,5.0f,-11.0f };
    DrawBoundingBox(deskBox, RED);
    collisionModels(camera, previousCameraPosition, cameraBox, deskBox);
    
}
void drawTubes(Model tubes)
{
    for (int i = 0; i <= 16; i += 4)
    {
        for (int j = 0; j <= 8; j += 4) {
            DrawModel(tubes, { -8.0f + i,1.47f,6.5f - j }, 0.15, WHITE);
        }

    }
}
void drawFurnituresProgramming(Model desk, Model deskChair, Model chair, Model chairOther,Model workstation,Model computer ,Model computerRotated  , Camera& camera, Vector3 previousCameraPosition)
{
    BoundingBox cameraBox;
    cameraBox.min = camera.position;
    cameraBox.max = camera.position;
    cameraBox.min.x -= 0.1f;
    cameraBox.min.y -= 0.1f;
    cameraBox.min.z -= 0.1f;
    cameraBox.max.x += 0.3f;
    cameraBox.max.y += 0.5f;
    cameraBox.max.z += 0.5f;

    DrawModel(deskChair, { 20.5f,0.2f,7.0f }, 0.6, BLACK);
    DrawModel(desk, { 19.5f,0.2f,7.0f }, 0.015, GRAY);

    for (int i = 0; i <= 17.5; i += 2.5)
    {
        DrawModel(chair, { 15.0f - i,0.1f,7.0f }, 0.03, WHITE);
        DrawModel(workstation,  { 15.0f - i,0.1f,7.0f }, 1.5, GRAY);
        DrawModel(computer,  { 16.3f - i,1.2f,5.7f }, 1.5, BLACK);
    }

    for (int i = 0; i <= 17.5; i += 2.5)
    {
        DrawModel(chair, { 15.0f - i,0.1f,-4.5f }, 0.03, WHITE);
        DrawModel(workstation, { 15.0f - i,0.1f,-4.5f }, 1.5, GRAY);
        DrawModel(computer, { 16.3f - i,1.2f,-5.8f }, 1.5, BLACK);
    }
    for (int i = 0; i <= 17.5; i += 2.5)
    {
        DrawModel(chairOther, { 15.0f - i,0.1f,4.0f }, 0.03, WHITE);
        DrawModel(computerRotated, { 16.3f - i,1.2f,4.2f }, 1.5, BLACK);
    }

    for (int i = 0; i <= 17.5; i += 2.5)
    {
        DrawModel(chairOther, { 15.0f - i,0.1f,-7.5f }, 0.03, WHITE);   
        DrawModel(computerRotated, { 16.3f - i,1.2f,-7.5f }, 1.5, BLACK);
    }
    BoundingBox chairBox[2];
    chairBox[0].min = { -1.8f, 0.0f, -8.3f };
    chairBox[0].max = { 16.0f, 2.0f, -3.6f };
    DrawBoundingBox(chairBox[0], RED);
    chairBox[1].min = { -3.7f, 0.0f, 3.3f };
    chairBox[1].max = { 16.7f, 2.0f, 7.7f };
    DrawBoundingBox(chairBox[1], RED);
    collisionModels(camera, previousCameraPosition, cameraBox, chairBox[0]);
    collisionModels(camera, previousCameraPosition, cameraBox, chairBox[1]);

}

void maths()
{
    Model chair = LoadModel("objects/chair.obj");
    Model desk = LoadModel("objects/desk.obj");
    Model deskChair = LoadModel("objects/deskChair.obj");
    Model studentDesk = LoadModel("objects/studentDesk.obj");
    Model board = LoadModel("objects/board.obj");
    Model laptop = LoadModel("objects/laptop.obj");

    const int screenWidth = 1920;
    const int screenHeight = 975;

    Camera camera = { 0 };
    camera.position = { 8.0f, 2.0f, -7.0f };   // Camera position
    camera.target = { 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    int cameraMode = CAMERA_FIRST_PERSON;

    BoundingBox wallBox;
    wallBox.min = { -9.0f, 0.0f, -9.0f };
    wallBox.max = { 9.3f, 20.0f, 9.0f };

    BoundingBox cameraBox;
    cameraBox.min = camera.position;
    cameraBox.max = camera.position;
    cameraBox.min.x -= 0.1f;
    cameraBox.min.y -= 0.1f;
    cameraBox.min.z -= 0.1f;
    cameraBox.max.x += 0.3f;
    cameraBox.max.y += 0.5f;
    cameraBox.max.z += 0.5f;
    // Generates some random columns
    DisableCursor();                    // Limit cursor to relative movement inside the window

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        Vector3 previousCameraPosition = camera.position;
        UpdateCamera(&camera, cameraMode);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        cameraBox.min = camera.position;
        cameraBox.max = camera.position;

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 21.0f, 21.0f }, LIGHTGRAY);
        DrawCube({ -10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, BLUE);
        DrawCube({ 10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, LIME);
        DrawCube({ 0.0f, 2.5f, 10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 2.5f, -10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 6.7f, 0.0f }, 21.0f, 0.2f, 21.0f, LIGHTGRAY);

        drawFurnitures(chair, desk, deskChair, studentDesk, board,laptop,  camera, previousCameraPosition);
        collisions(camera, previousCameraPosition, cameraBox, wallBox);

        EndMode3D();
        drawCoordinates(camera);
        EndDrawing();
        
    }

    SetExitKey(KEY_ESCAPE);
    EnableCursor();

}

void history()
{
    Model chair = LoadModel("objects/chair.obj");
    Model desk = LoadModel("objects/desk.obj");
    Model deskChair = LoadModel("objects/deskChair.obj");
    Model studentDesk = LoadModel("objects/studentDesk.obj");
    Model board = LoadModel("objects/board.obj");
    Model laptop = LoadModel("objects/laptop.obj");

    const int screenWidth = 1920;
    const int screenHeight = 975;

    Camera camera = { 0 };
    camera.position = { 8.0f, 2.0f, -7.0f };   // Camera position
    camera.target = { 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    int cameraMode = CAMERA_FIRST_PERSON;

    BoundingBox wallBox;
    wallBox.min = { -9.0f, 0.0f, -9.0f };
    wallBox.max = { 9.3f, 20.0f, 9.0f };

    BoundingBox cameraBox;
    cameraBox.min = camera.position;
    cameraBox.max = camera.position;
    cameraBox.min.x -= 0.1f;
    cameraBox.min.y -= 0.1f;
    cameraBox.min.z -= 0.1f;
    cameraBox.max.x += 0.3f;
    cameraBox.max.y += 0.5f;
    cameraBox.max.z += 0.5f;

    // Generates some random columns
    DisableCursor();                    // Limit cursor to relative movement inside the window

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        Vector3 previousCameraPosition = camera.position;
        UpdateCamera(&camera, cameraMode);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        cameraBox.min = camera.position;
        cameraBox.max = camera.position;

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 21.0f, 21.0f }, LIGHTGRAY);
        DrawCube({ -10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, BLUE);
        DrawCube({ 10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, LIME);
        DrawCube({ 0.0f, 2.5f, 10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 2.5f, -10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 6.7f, 0.0f }, 21.0f, 0.2f, 21.0f, LIGHTGRAY);

        drawFurnitures(chair, desk, deskChair, studentDesk, board, laptop, camera, previousCameraPosition);
        collisions(camera, previousCameraPosition, cameraBox, wallBox);

        EndMode3D();
        EndDrawing();

    }

    SetExitKey(KEY_ESCAPE);
    EnableCursor();

}
void physics()
{
    Model chair = LoadModel("objects/chair.obj");
    Model desk = LoadModel("objects/desk.obj");
    Model deskChair = LoadModel("objects/deskChair.obj");
    Model studentDesk = LoadModel("objects/studentDesk.obj");
    Model board = LoadModel("objects/board.obj");
    Model laptop = LoadModel("objects/laptop.obj");

    const int screenWidth = 1920;
    const int screenHeight = 975;

    Camera camera = { 0 };
    camera.position = { 8.0f, 2.0f, -7.0f };   // Camera position
    camera.target = { 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    int cameraMode = CAMERA_FIRST_PERSON;

    BoundingBox wallBox;
    wallBox.min = { -9.0f, 0.0f, -9.0f };
    wallBox.max = { 9.3f, 20.0f, 9.0f };

    BoundingBox cameraBox;
    cameraBox.min = camera.position;
    cameraBox.max = camera.position;
    cameraBox.min.x -= 0.1f;
    cameraBox.min.y -= 0.1f;
    cameraBox.min.z -= 0.1f;
    cameraBox.max.x += 0.3f;
    cameraBox.max.y += 0.5f;
    cameraBox.max.z += 0.5f;

    // Generates some random columns
    DisableCursor();                    // Limit cursor to relative movement inside the window

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        Vector3 previousCameraPosition = camera.position;
        UpdateCamera(&camera, cameraMode);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        cameraBox.min = camera.position;
        cameraBox.max = camera.position;

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 19.0f, 19.0f }, LIGHTGRAY);
        DrawCube({ -10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, BLUE);
        DrawCube({ 10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, LIME);
        DrawCube({ 0.0f, 2.5f, 10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 2.5f, -10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 6.7f, 0.0f }, 21.0f, 0.2f, 21.0f, LIGHTGRAY);
        drawFurnitures(chair, desk, deskChair, studentDesk, board, laptop, camera, previousCameraPosition);
        collisions(camera, previousCameraPosition, cameraBox, wallBox);

        EndMode3D();
        EndDrawing();

    }

    SetExitKey(KEY_ESCAPE);
    EnableCursor();

}
void literature()
{
    Model chair = LoadModel("objects/chair.obj");
    Model desk = LoadModel("objects/desk.obj");
    Model deskChair = LoadModel("objects/deskChair.obj");
    Model studentDesk = LoadModel("objects/studentDesk.obj");
    Model board = LoadModel("objects/board.obj");
    Model laptop = LoadModel("objects/laptop.obj");

    const int screenWidth = 1920;
    const int screenHeight = 975;

    Camera camera = { 0 };
    camera.position = { 8.0f, 2.0f, -7.0f };   // Camera position
    camera.target = { 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    int cameraMode = CAMERA_FIRST_PERSON;

    BoundingBox wallBox;
    wallBox.min = { -9.0f, 0.0f, -9.0f };
    wallBox.max = { 9.3f, 20.0f, 9.0f };

    BoundingBox cameraBox;
    cameraBox.min = camera.position;
    cameraBox.max = camera.position;
    cameraBox.min.x -= 0.1f;
    cameraBox.min.y -= 0.1f;
    cameraBox.min.z -= 0.1f;
    cameraBox.max.x += 0.3f;
    cameraBox.max.y += 0.5f;
    cameraBox.max.z += 0.5f;

    // Generates some random columns
    DisableCursor();                    // Limit cursor to relative movement inside the window

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        Vector3 previousCameraPosition = camera.position;
        UpdateCamera(&camera, cameraMode);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        cameraBox.min = camera.position;
        cameraBox.max = camera.position;

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 21.0f, 21.0f }, LIGHTGRAY);
        DrawCube({ -10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, BLUE);
        DrawCube({ 10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, LIME);
        DrawCube({ 0.0f, 2.5f, 10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 2.5f, -10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 6.7f, 0.0f }, 21.0f, 0.2f, 21.0f, LIGHTGRAY);

        drawFurnitures(chair, desk, deskChair, studentDesk, board, laptop, camera, previousCameraPosition);
        collisions(camera, previousCameraPosition, cameraBox, wallBox);

        EndMode3D();
        EndDrawing();

    }

    SetExitKey(KEY_ESCAPE);
    EnableCursor();

}
void chemistry()
{
    Model chair = LoadModel("objects/chair.obj");
    Model desk = LoadModel("objects/desk.obj");
    Model deskChair = LoadModel("objects/deskChair.obj");
    Model studentDesk = LoadModel("objects/studentDesk.obj");
    Model board = LoadModel("objects/board.obj");
    Model tubes = LoadModel("objects/tubes.obj");
    Model laptop = LoadModel("objects/laptop.obj");

    const int screenWidth = 1920;
    const int screenHeight = 975;

    Camera camera = { 0 };
    camera.position = { 8.0f, 2.0f, -7.0f };   // Camera position
    camera.target = { 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    int cameraMode = CAMERA_FIRST_PERSON;

    BoundingBox wallBox;
    wallBox.min = { -9.0f, 0.0f, -9.0f };
    wallBox.max = { 9.3f, 20.0f, 9.0f };

    BoundingBox cameraBox;
    cameraBox.min = camera.position;
    cameraBox.max = camera.position;
    cameraBox.min.x -= 0.1f;
    cameraBox.min.y -= 0.1f;
    cameraBox.min.z -= 0.1f;
    cameraBox.max.x += 0.3f;
    cameraBox.max.y += 0.5f;
    cameraBox.max.z += 0.5f;

    // Generates some random columns
    DisableCursor();                    // Limit cursor to relative movement inside the window

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        Vector3 previousCameraPosition = camera.position;
        UpdateCamera(&camera, cameraMode);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        cameraBox.min = camera.position;
        cameraBox.max = camera.position;

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 21.0f, 21.0f }, LIGHTGRAY);
        DrawCube({ -10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, BLUE);
        DrawCube({ 10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, LIME);
        DrawCube({ 0.0f, 2.5f, 10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 2.5f, -10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 6.7f, 0.0f }, 21.0f, 0.2f, 21.0f, LIGHTGRAY);
        
        drawFurnitures(chair, desk, deskChair, studentDesk, board, laptop, camera, previousCameraPosition);
        drawTubes(tubes);
        collisions(camera, previousCameraPosition, cameraBox, wallBox);

        EndMode3D();
        EndDrawing();

    }

    SetExitKey(KEY_ESCAPE);
    EnableCursor();

}
void english()
{
    Model chair = LoadModel("objects/chair.obj");
    Model desk = LoadModel("objects/desk.obj");
    Model deskChair = LoadModel("objects/deskChair.obj");
    Model studentDesk = LoadModel("objects/studentDesk.obj");
    Model board = LoadModel("objects/board.obj");
    Model laptop = LoadModel("objects/laptop.obj");

    const int screenWidth = 1920;
    const int screenHeight = 975;

    Camera camera = { 0 };
    camera.position = { 8.0f, 2.0f, -7.0f };    // Camera position
    camera.target = { 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;

    int cameraMode = CAMERA_FIRST_PERSON;

    BoundingBox wallBox;
    wallBox.min = { -9.0f, 0.0f, -9.0f };
    wallBox.max = { 9.3f, 20.0f, 9.0f };

    BoundingBox cameraBox;
    cameraBox.min = camera.position;
    cameraBox.max = camera.position;
    cameraBox.min.x -= 0.1f;
    cameraBox.min.y -= 0.1f;
    cameraBox.min.z -= 0.1f;
    cameraBox.max.x += 0.3f;
    cameraBox.max.y += 0.5f;
    cameraBox.max.z += 0.5f;

    // Generates some random columns
    DisableCursor();                    // Limit cursor to relative movement inside the window

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        Vector3 previousCameraPosition = camera.position;

        UpdateCamera(&camera, cameraMode);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        cameraBox.min = camera.position;
        cameraBox.max = camera.position;

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 19.0f, 19.0f }, LIGHTGRAY);
        DrawCube({ -10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, BLUE);
        DrawCube({ 10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, LIME);
        DrawCube({ 0.0f, 2.5f, 10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 2.5f, -10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 6.7f, 0.0f }, 21.0f, 0.2f, 21.0f, LIGHTGRAY);

        drawFurnitures(chair, desk, deskChair, studentDesk, board, laptop, camera, previousCameraPosition);

        collisions(camera, previousCameraPosition, cameraBox, wallBox);
        EndMode3D();
        EndDrawing();

    }

    SetExitKey(KEY_ESCAPE);
    EnableCursor();

}

void biology()
{
    Model chair = LoadModel("objects/chair.obj");
    Model desk = LoadModel("objects/desk.obj");
    Model deskChair = LoadModel("objects/deskChair.obj");
    Model studentDesk = LoadModel("objects/studentDesk.obj");
    Model board = LoadModel("objects/board.obj");
    Model skeleton = LoadModel("objects/skeleton.obj");
    Model laptop = LoadModel("objects/laptop.obj");

    Camera camera = { 0 };
    camera.position = { 8.0f, 2.0f, -7.0f };    // Camera position
    camera.target = { 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    int cameraMode = CAMERA_FIRST_PERSON;

    BoundingBox wallBox;
    wallBox.min = { -9.0f, 0.0f, -9.0f };
    wallBox.max = { 9.3f, 20.0f, 9.3f };

    BoundingBox cameraBox;
    cameraBox.min = camera.position;
    cameraBox.max = camera.position;
    cameraBox.min.x -= 0.1f;
    cameraBox.min.y -= 0.1f;
    cameraBox.min.z -= 0.1f;
    cameraBox.max.x += 0.3f;
    cameraBox.max.y += 0.5f;
    cameraBox.max.z += 0.5f;

    // Generates some random columns
    DisableCursor();                    // Limit cursor to relative movement inside the window

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        Vector3 previousCameraPosition = camera.position;

        UpdateCamera(&camera, cameraMode);
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        cameraBox.min = camera.position;
        cameraBox.max = camera.position;


        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 19.0f, 19.0f }, LIGHTGRAY);
        DrawCube({ -10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, BROWN);
        DrawCube({ 10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, BROWN);
        DrawCube({ 0.0f, 2.5f, 10.0f }, 21.0f, 8.3f, 1.0f, BROWN);
        DrawCube({ 0.0f, 2.5f, -10.0f }, 21.0f, 8.3f, 1.0f, BROWN);
        DrawCube({ 0.0f, 6.7f, 0.0f }, 21.0f, 0.2f, 21.0f, LIGHTGRAY);

        DrawCube({ 0.0f, 1.5f, -7.5f }, 1.0f, 1.0f, 1.0f, GOLD);

        drawFurnitures(chair, desk, deskChair, studentDesk, board, laptop, camera, previousCameraPosition);
        DrawModel(skeleton, { 5.0f, 2.2f, -9.0f }, 0.01, WHITE);
        collisions(camera, previousCameraPosition, cameraBox, wallBox);;

        EndMode3D();

        bioTextBook(camera);
        DisableCursor();
        drawCoordinates(camera);

        EndDrawing();

    }

    SetExitKey(KEY_ESCAPE);
    EnableCursor();
}

void geography()
{
    Model chair = LoadModel("objects/chair.obj");
    Model desk = LoadModel("objects/desk.obj");
    Model deskChair = LoadModel("objects/deskChair.obj");
    Model studentDesk = LoadModel("objects/studentDesk.obj");
    Model board = LoadModel("objects/board.obj");
    Model globe = LoadModel("objects/globe.obj");
    Model laptop = LoadModel("objects/laptop.obj");

    const int screenWidth = 1920;
    const int screenHeight = 975;

    Camera camera = { 0 };
    camera.position = { 8.0f, 2.0f, -7.0f };    // Camera position
    camera.target = { 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    int cameraMode = CAMERA_FIRST_PERSON;

    BoundingBox wallBox;
    wallBox.min = { -9.0f, 0.0f, -9.0f };
    wallBox.max = { 9.3f, 20.0f, 9.0f };

    BoundingBox cameraBox;
    cameraBox.min = camera.position;
    cameraBox.max = camera.position;
    cameraBox.min.x -= 0.1f;
    cameraBox.min.y -= 0.1f;
    cameraBox.min.z -= 0.1f;
    cameraBox.max.x += 0.3f;
    cameraBox.max.y += 0.5f;
    cameraBox.max.z += 0.5f;

    // Generates some random columns
    DisableCursor();                    // Limit cursor to relative movement inside the window

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        Vector3 previousCameraPosition = camera.position;
        UpdateCamera(&camera, cameraMode);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        cameraBox.min = camera.position;
        cameraBox.max = camera.position;

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 21.0f, 21.0f }, LIGHTGRAY);
        DrawCube({ -10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, BLUE);
        DrawCube({ 10.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, LIME);
        DrawCube({ 0.0f, 2.5f, 10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 2.5f, -10.0f }, 21.0f, 8.3f, 1.0f, GOLD);
        DrawCube({ 0.0f, 6.7f, 0.0f }, 21.0f, 0.2f, 21.0f, LIGHTGRAY);

        drawFurnitures(chair, desk, deskChair, studentDesk, board, laptop, camera, previousCameraPosition);

        DrawModel(globe, { 0.65f,1.65f,-7.0f }, 0.4, GOLD);

        collisions(camera, previousCameraPosition, cameraBox, wallBox);

        EndMode3D();
        EndDrawing();

    }

    SetExitKey(KEY_ESCAPE);
    EnableCursor();

}

void programming()
{
    Model computer = LoadModel("objects/computer.obj");
    Model computerRotated = LoadModel("objects/computerRotated.obj");
    Model chair = LoadModel("objects/chair.obj");
    Model chairOther = LoadModel("objects/chairRotated.obj");
    Model desk = LoadModel("objects/deskRotated.obj");
    Model deskChair = LoadModel("objects/deskChairRotated.obj");
    Model workstation = LoadModel("objects/workstation.obj");

    const int screenWidth = 1920;
    const int screenHeight = 975;

    Camera camera = { 0 };
    camera.position = { 18.7f, 2.0f, -6.5f };    // Camera position
    camera.target = { 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    int cameraMode = CAMERA_FIRST_PERSON;

    BoundingBox wallBox;
    wallBox.min = { -7.0f, 0.0f, -9.0f };
    wallBox.max = { 22.0f, 20.0f, 10.5f };

    BoundingBox cameraBox;
    cameraBox.min = camera.position;
    cameraBox.max = camera.position;
    cameraBox.min.x -= 0.1f;
    cameraBox.min.y -= 0.1f;
    cameraBox.min.z -= 0.1f;
    cameraBox.max.x += 0.3f;
    cameraBox.max.y += 0.5f;
    cameraBox.max.z += 0.5f;

    // Generates some random columns
    DisableCursor();                    // Limit cursor to relative movement inside the window

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        Vector3 previousCameraPosition = camera.position;
        UpdateCamera(&camera, cameraMode);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        cameraBox.min = camera.position;
        cameraBox.max = camera.position;

        DrawPlane({ 7.5f, 0.0f, 0.0f }, { 28.5f, 20.0f }, LIGHTGRAY);
        DrawCube({ -7.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, BLUE);
        DrawCube({ 22.0f, 2.5f, 0.0f }, 1.0f, 8.3f, 21.0f, LIME);
        DrawCube({ 7.5f, 2.5f, 10.0f }, 28.5f, 8.3f, 1.0f, GOLD);
        DrawCube({ 7.5f, 2.5f, -10.0f }, 28.5f, 8.3f, 1.0f, GOLD);
        DrawCube({ 7.5f, 6.7f, 0.0f }, 28.5f, 0.2f, 21.0f, LIGHTGRAY);

        drawFurnituresProgramming(desk, deskChair, chair, chairOther,workstation,computer, computerRotated ,camera,previousCameraPosition);
        DrawBoundingBox(wallBox, RED);
        collisions(camera, previousCameraPosition, cameraBox, wallBox);
        Vector3 cubePosition = { 19.5f,0.2f,7.0f };
        prgTextBook(camera, cubePosition);
        EndMode3D();
        drawCoordinates(camera);
        EndDrawing();
    }
    EnableCursor();

}