#include "exams.h"
#include "textbooks.h"
#include "rooms.h"
#include "map.h"
#include "menu.h"

#define MAXQUESTIONS 20
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

int gradeSystem(int score)
{
    if (score >= 9)
    {
        return 6;
    }
    if (score <9 && score <=8)
    {
        return 5;
    }
    if (score >= 7 && score < 8)
    {
        return 4;
    }
    if (score >= 6 && score < 7)
    {
        return 3;
    }
    if (score <6)
    {
        return 2;
    }
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


    int count = 1;
    int currentQuestion = GetRandomValue(0, 9);
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
                count++;
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

            currentQuestion = GetRandomValue(0, 9); // Move to the next question
            selectedOption = -1; // Reset selected option
            answered = false; // Reset answered flag
        }
        if (count >= 10)
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

void englishExam()
{
    Question questions[MAXQUESTIONS] = {
       {"Molly used to ... watching cartoons when she was young.",
        {"a) loving", "b) loved", "c) love", "d) have love"},
        2},
       {"First, he had dinner, then he ... the newspaper",
        {"a) read", "b) was reading", "c) had read", "d) is reading"},
        0},
       {"The Rossens ... abroad for fiteen years before they moved back to England.",
        {"a) lived", "b) have lived", "c) were living", "d) to live"},
        0},
       {"Peter was listening to his favourite CD when Paul ...",
        {"a) came in", "b) was coming it", "c) had come in", "d) came out"},
        0},
       {"You ... chew gum in class.",
        {"a)must ", "b) mustn't ", "c) needen't ", "d) need "},
        1},
       {"I think History is less interesting ... Geography.",
        {"a) from",
         "b) of",
         "c) than",
         "d) in"},
        2},
       {"Valerie was making the beds while Mark ... the floor",
        {"a) was sweeping",
         "b) swept",
         "c) had swept",
         "d) is sweeping"},
        0},
       {"You ... have a driving license in order to drive a car.",
        {"a)mustn't ",
         "b)needn't ",
         "c)must ",
         "d)need "},
        2},
       {"Brian isn't as ... as Richard.",
        {"a)friendly ",
         "b)friendlier ",
         "c)friendliest ",
         "d)friend "},
        0},
       {"My grandfather often ... old films. ",
        {"a)has watched ",
         "b)watches ",
         "c)had watched ",
         "d)had been watching "},
        1},
        {"Maria entered the room very quietly ... she didn't want to wake anyone up. ",
        {"a)while ",
         "b)so ",
         "c)as ",
         "d)when "},
        2},
        {"You ... feed the dog. I fed it this morning ",
        {"a)needn't ",
         "b)need ",
         "c)must",
         "d)have to "},
        0},
        {"Mary ... the house by the time it started to rain. ",
        {"a)reached ",
         "b)had reached ",
         "c)was reaching ",
         "d)is reaching"},
        1},
        {"George never ... eat vegetables when he was a teenager. ",
        {"a)didn't use to",
         "b)uses to ",
         "c)used to ",
         "d)use to"},
        2},
        {"I ... the ambulance siren wailing as I was walking through the city centre. ",
        {"a)heard ",
         "b)was hearing ",
         "c)had been hearing",
         "d)hear"},
        0},
        {"A:Is Jessica ... than Susie? B: No, I don't think so.",
        {"a)talented ",
         "b)as talented ",
         "c)more talanted ",
         "d)gifted"},
        2},
        {"Had you ... to San Francisco before? ",
        {"a)been ",
         "b)went ",
         "c)go ",
         "d)gone"},
        0},
        {"You ... make an appointment to see a doctor. The clinic is open 24 hours a day. ",
        {"a)need ",
         "b)needn't ",
         "c)mustn't ",
         "d)must"},
        1},
        {"She ... a book all night and was very sleepy the nexxt morning. ",
        {"a)is reading ",
         "b)had been reading ",
         "c)was reading ",
         "d)read"},
        1},
        {"Rachel was watering the plants while her children ... in the garden. ",
        {"a)was playing ",
         "b)were playing ",
         "c)play ",
         "d)had played"},
        1},
    };


    int count = 1;
    int currentQuestion = GetRandomValue(0, 9);
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
                count++;
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

            currentQuestion = GetRandomValue(0, 19); // Move to the next question
            selectedOption = -1; // Reset selected option
            answered = false; // Reset answered flag
        }
        if (count >= 10)
        {
            int grade = gradeSystem(score);
            english();
            break;
        }
        SetExitKey(KEY_ESCAPE);
    }

}

void englishExaminationAlert() {
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
            englishTextBook(camera);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? SKYBLUE : BLUE));
        DrawText("Start", GetScreenWidth() / 2 + 110, GetScreenHeight() / 2 + 5, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            englishExam();
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