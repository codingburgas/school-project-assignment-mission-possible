#include "exams.h"
#include "textbooks.h"
#include "rooms.h"
#include "map.h"
#include "menu.h"

#define MAXQUESTIONS 10
#define MAXOPTIONS 4

struct Question {
    string question;
    vector<string> options; // Array of options
    int correctOption;
};

bool CheckMouseClickOnOption(int optionIndex, int mouseY) {
    // Check if the mouse is within the bounding box of the option and left mouse button is pressed
    return (GetMouseX() >= 100 && GetMouseX() <= 300 && GetMouseY() >= 150 + 30 * optionIndex && GetMouseY() <= 150 + 30 * optionIndex + 20 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}


void mathsExam()
{
        // Array of questions with their options and correct answers
        Question questions[MAXQUESTIONS] = {
            {"What is: 1^0 + 1?",
             {"a) 2", "b) 1", "c) -1", "d) 0"},
             1},
            {"What is 8 x 2 - 2 x (2 + 3)?",
             {"a) 19", "b) 5", "c) -6", "d) 6"},
             2},
            {"",
             {"a) ", "b) ", "c) ", "d) "},
             1},
            {"What is: 2^3 + 16 - 23?",
             {"a) 1", "b) 20", "c) 26", "d) -2"},
             0},
            {"",
             {"a) ", "b) ", "c) ", "d) "},
             2},
            {"",
             {"a) ",
              "b) ",
              "c) ",
              "d) "},
             1},
            {"",
             {"a) ",
              "b) ",
              "c) ",
              "d) "},
             1},
            {"",
             {"a) ",
              "b) ",
              "c) ",
              "d) "},
             1},
            {"",
             {"a) ",
              "b) ",
              "c) ",
              "d) "},
             2},
            {" ",
             {"a) ",
              "b) ",
              "c) ",
              "d) "},
             2}
        };



        int currentQuestion = 0;
        int selectedOption = -1;
        bool answered = false;
        int score = 0;
    
        // Main game loop
        while (!WindowShouldClose()) {

            // Update
            if (!answered) {
                // Check if the mouse clicked on any option
                for (int i = 0; i < MAXOPTIONS; i++) {
                    if (CheckMouseClickOnOption(i, GetMouseY())) {
                        selectedOption = i; // Update the selected option
                        break;
                    }
                }
                // Check if an option is selected
                if (selectedOption >= 0) {
                    // If the selected option is correct, increment the score
                    if (selectedOption == questions[currentQuestion].correctOption) {
                        score++;
                    }
                    answered = true; // Mark the question as answered
                }
            }

            // Draw
            BeginDrawing();
            ClearBackground(RAYWHITE); // Clear the screen

            // Display the current question
            DrawText(questions[currentQuestion].question.c_str(), 100, 100, 20, BLACK);

            // Display the options for the current question
            for (int i = 0; i < MAXOPTIONS; i++) {
                DrawText(questions[currentQuestion].options[i].c_str(), 100, 150 + 30 * i, 20, BLACK);
            }

            // Display feedback for answered question
            if (answered) {

                // If the selected option is correct, display "Correct!", otherwise display "Incorrect!"
                if (selectedOption == questions[currentQuestion].correctOption) {
                    DrawText("Correct!", 100, 400, 20, GREEN);
                }
                else {
                    DrawText("Incorrect!", 100, 400, 20, RED);
                }
            }

            EndDrawing(); // End drawing frame

            // Reset if answer was given
            if (answered && IsKeyPressed(KEY_ENTER)) {

                currentQuestion++; // Move to the next question
                selectedOption = -1; // Reset selected option
                answered = false; // Reset answered flag
            }
            if (currentQuestion >= MAXQUESTIONS)
            { 
                
                maths(); 
                break;
            }
            SetExitKey(KEY_ESCAPE);
        }

}
void mathsExaminationAlert()
{
    Camera camera = { 0 };
  

    const Rectangle reviseButton = { GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, 140, 80 };
    const Rectangle goToExamButton = { GetScreenWidth() / 2 + 100, GetScreenHeight() / 2, 140, 80 };

    int character = GetRandomValue(1, 2);
    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        bool isMouseOverButtonRevise = CheckCollisionPointRec(mousePosition, reviseButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(reviseButton, (isMouseOverButtonRevise ? SKYBLUE : BLUE));
        DrawText("Revise", GetScreenWidth() / 2 - 110, GetScreenHeight() / 2 + 5, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonRevise && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            bioTextBook(camera);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? SKYBLUE : BLUE));
        DrawText("Start", GetScreenWidth() / 2 + 110, GetScreenHeight() / 2 + 5, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            mathsExam();
            if (IsKeyPressed(KEY_ESCAPE))
            {
                initMap(character);
                if (IsKeyPressed(KEY_ESCAPE))
                {
                    menu();
                }
            }
        }
     
        EndDrawing();
    }
    
}