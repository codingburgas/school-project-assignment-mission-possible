#include "gradeBook.h"
#include "map.h"
#include "menu.h"

// Function to draw subject and corresponding grade on the screen
void drawSubjectAndGrade(const string& subject, const string& grade, int posY) {
    DrawText(subject.c_str(), 850, posY, 20, BLACK);
    DrawText(grade.c_str(), 1000, posY, 20, BLACK); 
}

// Function to display the grade book
void gradeBook() {
    Texture2D background = LoadTexture("../images/gradeBookBg.png");
    SetTargetFPS(60); 

    // Main loop to display grade book
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);
        DrawTexture(background, 0, 0, WHITE);

        ifstream file("../data/gradeBook.csv");
        string line; 
        string storedUsername;
        string additionalWords = "'s gradebook"; 
        int posY = 225; 

        // Loop through each line in the file
        while (getline(file, line)) {
            istringstream iss(line);

            // Check if the username matches the current user
            if (getline(iss, storedUsername, ',')) {
                if (storedUsername == currentUser) {
                    string subject, grade;

                    // Get subject and grade from the line
                    if (getline(iss, subject, ',') && getline(iss, grade, ',')) {
                        drawSubjectAndGrade(subject, grade, posY);
                        posY += 30;
                    }
                }
            }
        }

        // Display the current user's name with additional words
        string currentUserWithAdditionalWords = currentUser + additionalWords;
        DrawText(currentUserWithAdditionalWords.c_str(), GetScreenWidth() / 2 - 240, GetScreenHeight() / 2 - 450, 50, BLACK);

        // Check if the escape key is pressed to return to the main menu
        if (IsKeyPressed(KEY_ESCAPE)) {
            menu();
        }

        EndDrawing();
    }

    EnableCursor(); // Enable cursor after exiting the loop
}