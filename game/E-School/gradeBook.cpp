#include "gradeBook.h"

void drawSubjectAndGrade(const string& subject, const string& grade, int posY) {
    DrawText(subject.c_str(), 100, posY, 20, BLACK);
    DrawText(grade.c_str(), 250, posY, 20, BLACK);
}

void gradeBook()
{
	SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        ifstream file("../data/gradeBook.csv");
        string line;
        string storedUsername;
        int posY = 100; 

        while (getline(file, line)) {
            istringstream iss(line);
            if (getline(iss, storedUsername, ',')) {
                if (storedUsername == currentUser) {
                    std::string subject, grade;
                    if (getline(iss, subject, ',') && getline(iss, grade, ',')) {
                        
                        drawSubjectAndGrade(subject, grade, posY);
                        posY += 30; 
                    }
                }
            }
        }
        EndDrawing();
    }
}