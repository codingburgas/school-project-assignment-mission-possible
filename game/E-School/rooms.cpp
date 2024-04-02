#include "subjects.h"
#include "textbooks.h"

bool checkCollision(const BoundingBox& box1, const BoundingBox& box2) {
    return (box1.min.x <= box2.max.x && box1.max.x >= box2.min.x) &&
        (box1.min.y <= box2.max.y && box1.max.y >= box2.min.y) &&
        (box1.min.z <= box2.max.z && box1.max.z >= box2.min.z);
}
void collisions(Camera& camera, Vector3 previousCameraPosition,BoundingBox cameraBox, BoundingBox wallBox)
{

    if (checkCollision(cameraBox, wallBox)) {

    }
    else {
        camera.position = previousCameraPosition;
    }
}

void drawFurnitures(Model chair, Model desk, Model deskChair, Model chin)
{
    
    for(int i=0; i<=16;i+=4)
    {
        for (int j = 0; j <= 8; j += 4) {
          DrawModel(chair, { -7.8f+i,0.1f,7.0f-j }, 0.03, GOLD);
          DrawModel(chin, { -7.8f+i,-0.1f,6.5f-j }, 0.015, GOLD);
        }
        
    }
    DrawModel(desk, { 0.0f,0.2f,-7.0f }, 0.015, GRAY);
    DrawModel(deskChair, { 0.0f,0.2f,-8.0f }, 0.6, BLACK);
    
}


void maths()
{
    Model chair = LoadModel("objects/chair.obj");
    Model desk = LoadModel("objects/desk.obj");
    Model deskChair = LoadModel("objects/deskChair.obj");
    Model chin = LoadModel("objects/chin.obj");

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
        
        drawFurnitures(chair, desk, deskChair, chin);
        collisions(camera, previousCameraPosition, cameraBox, wallBox);

        EndMode3D();
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
    Model chin = LoadModel("objects/chin.obj");

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

        drawFurnitures(chair, desk, deskChair, chin);
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
    Model chin = LoadModel("objects/chin.obj");

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

        drawFurnitures(chair, desk, deskChair, chin);
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
    Model chin = LoadModel("objects/chin.obj");

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

        drawFurnitures(chair, desk, deskChair, chin);
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
    Model chin = LoadModel("objects/chin.obj");

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

        drawFurnitures(chair, desk, deskChair, chin);
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
    Model chin = LoadModel("objects/chin.obj");

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

        drawFurnitures(chair, desk, deskChair, chin);

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
    Model chin = LoadModel("objects/chin.obj");

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

        drawFurnitures(chair,desk, deskChair,chin);

        collisions(camera, previousCameraPosition,cameraBox, wallBox );;
        EndMode3D();

        bioTextBook(camera);
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
    Model chin = LoadModel("objects/chin.obj");

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

        drawFurnitures(chair, desk, deskChair, chin);

        collisions(camera, previousCameraPosition, cameraBox, wallBox);
        EndMode3D();
        EndDrawing();

    }

    SetExitKey(KEY_ESCAPE);
    EnableCursor();

}
