#include "gradeBook.h"
#include "map.h"
#include "menu.h"

void drawSubjectAndGrade(const string& subject, const string& grade, int posY) {
    DrawText(subject.c_str(), 850, posY, 20, BLACK);
    DrawText(grade.c_str(), 1000, posY, 20, BLACK);
}

void gradeBook() {
    Texture2D background = LoadTexture("../images/gradeBookBg.png");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(background, 0, 0, WHITE);
        ifstream file("../data/gradeBook.csv");
        string line;
        string storedUsername;
        string additionalWords = "'s gradebook";
        int posY = 225;
        while (getline(file, line)) {
            istringstream iss(line);
            if (getline(iss, storedUsername, ',')) {
                if (storedUsername == currentUser) {
                    string subject, grade;
                    if (getline(iss, subject, ',') && getline(iss, grade, ',')) {
                        drawSubjectAndGrade(subject, grade, posY);
                        posY += 30;
                    }
                }
            }
        }
        string currentUserWithAdditionalWords = currentUser + additionalWords;
        DrawText(currentUserWithAdditionalWords.c_str(), GetScreenWidth() / 2 - 240, GetScreenHeight() / 2 - 450, 50, BLACK);
        if (IsKeyPressed(KEY_ESCAPE)) {
            menu();
        }
        EndDrawing();
    }
    EnableCursor();
}
