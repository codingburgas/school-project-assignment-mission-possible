#include "exams.h"
#include "textbooks.h"
#include "rooms.h"
#include "map.h"
#include "menu.h"
#include "accessData.h"


#define MAXQUESTIONS 20
#define MAXOPTIONS 4

struct Question {
    string question;
    vector<string> options; // Array of options
    int correctOption;
};



int CheckMouseClickOnOption(int optionIndex, int mouseY) {
    Rectangle answers[4] = {
        { 135, 535, 455, 125},
        { 1335, 535, 455, 125},
        { 135, 735, 455, 125},
        { 1335, 735,455, 125},
    };
    int i = 0;
    if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), answers[0]))
    {
        i = 2;
    }
    if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), answers[1]))
    {
        i = 2;
    }
    if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), answers[2]))
    {
        i = 2;
    }
    if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), answers[3]))
    {
        i = 2;
    }
    if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), answers[optionIndex]))
    {
        i = 1;
    }
    return i;
}

int gradeSystem(int score)
{
    if (score >= 9)
    {
        return 6;
    }
    if (score == 8)
    {
        return 5;
    }
    if (score == 7)
    {
        return 4;
    }
    if (score == 6)
    {
        return 3;
    }
    if (score < 6)
    {
        return 2;
    }
}
void mathsExam()
{
    Texture2D background = LoadTexture("textures/mathsExam.png");
    // Array of questions with their options and correct answers
    Question questions[MAXQUESTIONS] = {
        {"What is: 1^0 + 1?",
         {"a) 2", "b) 1", "c) -1", "d) 0"},
         0},
        {"What is 8 x 2 - 2 x (2 + 3)?",
         {"a) 19", "b) 5", "c) -6", "d) 6"},
         2},
        {"3x + 1 > x - 5",
         {"a)-2 ", "b)-3 ", "c)-4 ", "d)none of the above "},
         1},
        {"What is: 2^3 + 16 - 23?",
         {"a) 1", "b) 20", "c) 26", "d) -2"},
         0},
        {"Determine the solution of the system of \nequations 2x−y = 4 and x + 2y = 2.",
         {"a) (0, 2)", "b)(2, 0) ", "c) (2, −1)", "d) (1, 2)"},
         1},
        {"What is three fifth of 100?",
         {"a) 3",
          "b) 5",
          "c) 20",
          "d) 60"},
         3},
        {"What is the value of x if x^2 = 169",
         {"a) 1",
          "b) 13",
          "c) 169",
          "d) 338"},
         1},
        {"10^-2 means ………….",
         {"a) milli",
          "b) centi",
          "c) micro",
          "d) deci"},
         1},
        {"All natural numbers and 0 are called\n the ……………….. numbers",
         {"a) whole",
          "b) prime",
          "c) integer",
          "d) rational"},
         0},
        {" What is the sum of 5x^3 – 3x^2 - 1 and 3x^2 + 1?",
         {"a) 5x^3",
          "b) 6x^2",
          "c)5x ",
          "d) 3x^2"},
         0},
         {" Which of the following numbers gives 240\n when added to its own square?",
         {"a) 15",
          "b) 16",
          "c)18",
          "d) 20"},
         0},
         {" A car can cover a distance of 522 km on 36 liters\n of petrol. How far can it travel on\n 14 liters of petrol?",
         {"a) 213 km",
          "b) 223 km",
          "c) 203 km",
          "d) 302 km"},
         2},
         {"(4)^2 + (3)^2 = (……..)^2.",
         {"a) 5",
          "b) 14",
          "c) 25",
          "d) 7"},
         0},
         {" What percentage should be added to 40 to make it 50?",
         {"a) 15",
          "b) 25",
          "c) 75",
          "d) 80"},
         1},
         {" The difference between the smallest number of four \ndigits and the largest number of three digits is ……. ",
         {"a) 1",
          "b) 100",
          "c) 0",
          "d) 999"},
         0},
         {" Simplify :150 ÷ (6 + 3 x 8) - 5 ",
         {"a) 2",
          "b) 5",
          "c) 0",
          "d) none of the above"},
         2},
         {" What is the largest two digits prime number? ",
         {"a) 96",
          "b) 97",
          "c) 98",
          "d) 99"},
         1},
         {" How many diagonals are there in a quadrilateral ",
         {"a) 2",
          "b) 3",
          "c) 4",
          "d) No diagonals"},
         0},
         {" How much water is added to 750 g milk to\n get 1 kilogram mixture of liquid? ",
         {"a) 2.5kg",
          "b) 0.25kg",
          "c) 20.5kg",
          "d) 25.0 kg"},
         1},
         {" Annual income of A is 10% more than of B whereas income of B is \n20% more than that of C. If monthly income of C is $ 2000 then\n what is the sum of monthly incomes of A, B and C? (1$ = 1,83bgn)",
         {"a) 12595.72leva",
          "b) 12914.64leva",
          "c) 14245.33leva",
          "d) 12903.64leva"},
         3},
    };


    int count = 1;
    int currentQuestion = GetRandomValue(0, 19);
    int selectedOption = -1;
    bool answered = false;
    int score = 0;
    EnableCursor();
    bool correctOption = false;
    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if (answered == 0)
        {
            // If the selected option is correct, increment the score
            if (CheckMouseClickOnOption(questions[currentQuestion].correctOption, GetMouseY()) == 1) {

                score++;
                answered = true; // Mark the question as answered
                count++;
                correctOption = true;
            }
            else if (CheckMouseClickOnOption(questions[currentQuestion].correctOption, GetMouseY()) == 2)
            {
                answered = true; // Mark the question as answered
                count++;
            }
        }



        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE); // Clear the screen
        DrawTexture(background, 0, 0, WHITE);

        // Display the current question
        DrawText(questions[currentQuestion].question.c_str(), 600, 200, 30, BLACK);

        // Display the options for the current question
        int questionNumer = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
            {
                DrawText(questions[currentQuestion].options[questionNumer].c_str(), 200 + (1200 * j), 570 + 200 * i, 30, BLACK);
                questionNumer++;
            }
        }
        questionNumer = 0;
        // Display feedback for answered question
        if (answered) {

            // If the selected option is correct, display "Correct!", otherwise display "Incorrect!"
            if (correctOption == 1) {
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
            correctOption = false;
        }
        if (count >= 10)
        {
            string subject = "maths";
            DataAccess accessData;
            int grade = gradeSystem(score);
            accessData.addGrade(subject, to_string(grade));
            maths();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}
void mathsExaminationAlert()
{
    Camera camera = { 0 };
    Texture2D background = LoadTexture("../images/examAlertBackground.png");
    const Rectangle reviseButton = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 30, 140, 80 };
    const Rectangle goToExamButton = { GetScreenWidth() / 2 + 50, GetScreenHeight() / 2 - 30, 140, 80 };
    EnableCursor();

    int character = GetRandomValue(1, 2);
    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        bool isMouseOverButtonRevise = CheckCollisionPointRec(mousePosition, reviseButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(reviseButton, (isMouseOverButtonRevise ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Revise", GetScreenWidth() / 2 - 143, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonRevise && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            bioTextBook(camera, 1);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Start", GetScreenWidth() / 2 + 65, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            mathsExam();
            if (IsKeyPressed(KEY_M))
            {
                initMap(character);

            }
        }

        EndDrawing();
    }

}

void englishExam()
{
    Texture2D background = LoadTexture("textures/englishExam.png");
    Question questions[MAXQUESTIONS] = {
       {"Molly used to ... watching \ncartoons when she was young.",
        {"a) loving",
        "b) loved",
        "c) love",
        "d) have love"},
        2},
       {"First, he had dinner, then he ... the newspaper",
        {"a) read",
        "b) was reading",
        "c) had read",
        "d) is reading"},
        0},
       {"The Rossens ... abroad for fiteen years\n before they moved back to England.",
        {"a) lived",
        "b) have lived",
        "c) were living",
        "d) to live"},
        0},
       {"Peter was listening to his favourite CD when Paul ...",
        {"a) came in",
        "b) was coming it",
        "c) had come in",
        "d) came out"},
        0},
       {"You ... chew gum in class.",
        {"a)must ",
        "b) mustn't ",
        "c) needen't ",
        "d) need "},
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
        {"Maria entered the room very quietly ... she\n didn't want to wake anyone up. ",
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
        {"I ... the ambulance siren wailing as I was walking\n through the city centre. ",
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
        {"You ... make an appointment to see a doctor. The \nclinic is open 24 hours a day. ",
        {"a)need ",
         "b)needn't ",
         "c)mustn't ",
         "d)must"},
        1},
        {"She ... a book all night and was very sleepy\n the next morning. ",
        {"a)is reading ",
         "b)had been reading ",
         "c)was reading ",
         "d)read"},
        1},
        {"Rachel was watering the plants while her\n children ... in the garden. ",
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
    EnableCursor();

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
        DrawTexture(background, 0, 0, WHITE);
        // Display the current question

        // Display the options for the current question
        DrawText(questions[currentQuestion].question.c_str(), 600, 200, 30, BLACK);

        // Display the options for the current question
        int questionNumer = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
            {
                DrawText(questions[currentQuestion].options[questionNumer].c_str(), 200 + (1200 * j), 570 + 200 * i, 30, BLACK);
                questionNumer++;
            }
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
            string subject = "english";
            DataAccess accessData;
            int grade = gradeSystem(score);
            accessData.addGrade(subject, to_string(grade));
            english();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}

void englishExaminationAlert() {
    Camera camera = { 0 };
    Texture2D background = LoadTexture("../images/examAlertBackground.png");
    const Rectangle reviseButton = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 30, 140, 80 };
    const Rectangle goToExamButton = { GetScreenWidth() / 2 + 50, GetScreenHeight() / 2 - 30, 140, 80 };
    EnableCursor();

    int character = GetRandomValue(1, 2);
    while (!WindowShouldClose())
    {

        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        bool isMouseOverButtonRevise = CheckCollisionPointRec(mousePosition, reviseButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(reviseButton, (isMouseOverButtonRevise ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Revise", GetScreenWidth() / 2 - 143, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonRevise && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            englishTextBook(camera, 1);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Start", GetScreenWidth() / 2 + 65, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            englishExam();

        }

        EndDrawing();
    }

}

void historyExam()
{
    Texture2D background = LoadTexture("textures/historyExam.png");

    Question questions[MAXQUESTIONS] = {
       {"When did World War II officially begin?",
        {"a) 1914",
        "b) 1939",
        "c) 1941",
        "d) 1945 "},
        1},
       {"Which country invaded Poland, \ntriggering the start of World War II?",
        {"a) France",
        "b) United Kingdom",
        "c) Germany ",
        "d) Italy"},
        2},
       {"What was the code name for the\n Allied invasion of Normandy on June 6, 1944?",
        {"a) Operation Overlord",
        "b) Operation Barbarossa",
        "c) Operation Market Garden",
        "d) Operation Torch"},
        0},
       {"Which event led to the United States entering World War II?",
        {"a)Attack on Pearl Harbor",
        "b) Battle of Stalingrad",
        "c)Invasion of Poland",
        "d) D-Day"},
        0},
       {"Who was the leader of Nazi Germany during World War II?",
        {"a)Winston Churchill",
        "b)Benito Mussolini",
        "c)Joseph Stalin",
        "d)Adolf Hitler"},
        3},
       {"Which country was not part of\n the Axis Powers during World War II?",
        {"a) Japan",
         "b) Italy",
         "c) Soviet Union",
         "d) Hungary"},
        2},
       {"What was the name of the atomic \nbomb dropped on Hiroshima?",
        {"a) Fat Man",
         "b) Little Boy",
         "c) Tsar Bomba",
         "d) Trinity"},
        1},
       {"Who was the Supreme Commander of the \nAllied Forces in Europe during World War II?",
        {"a)Dwight D. Eisenhower ",
         "b)Douglas MacArthur ",
         "c)George S. Patton ",
         "d)Bernard Montgomery "},
        0},
       {"Which battle is considered the turning\n point of the war in the Pacific?",
        {"a)Battle of Midway ",
         "b)Battle of Okinawa ",
         "c)Battle of Iwo Jima ",
         "d)Battle of Guadalcanal "},
        0},
       {"Which country was invaded by Nazi Germany\n in 1940, leading to its evacuation at Dunkirk?",
        {"a)Belgium ",
         "b)France ",
         "c)Netherlands ",
         "d)Luxembourg "},
        1},
        {"What was the name of the German air \nforce during World War II? ",
        {"a)Luftwaffe ",
         "b)Wehrmacht ",
         "c)Waffen-SS ",
         "d)Schutzstaffel"},
        0},
        {"Which of the following was not a \nmajor axis power during World War II?",
        {"a)Japan ",
         "b)Italy ",
         "c)Soviet Union",
         "d)Germany "},
        2},
        {"What was the name of the German offensive\n against the Soviet Union in 1941? ",
        {"a)Operation Overlord ",
         "b)Battle of the Bulge ",
         "c)Operation Barbarossa ",
         "d)D-Day"},
        2},
        {"Which battle marked the last major German\n offensive on the Western Front during World War II?",
        {"a)Battle of Stalingrad",
         "b)Battle of Midway ",
         "c)Battle of the Bulge ",
         "d)Battle of Kursk"},
        2},
        {"What was the name of the treaty \nthat officially ended World War II in Europe? ",
        {"a)Treaty of Versailles",
         "b)Treaty of Paris",
         "c)Treaty of Berlin",
         "d)Treaty of Versailles II"},
        3},
        {"What was the main purpose of the\n Yalta Conference in 1945?",
        {"a)Plan for the invasion of Normandy ",
         "b)Establish the United Nations ",
         "c)Discuss post-war Europe ",
         "d)Negotiate peace with Japan"},
        2},
        {"Which country did Nazi Germany invade, breaking\n the Molotov-Ribbentrop Pact with the Soviet Union? ",
        {"a)France ",
         "b)Poland  ",
         "c)Norway ",
         "d)Greece"},
        1},
        {"What was the significance of the Battle of Britain? ",
        {"a)It marked the beginning of the Holocaust ",
         "b)It was the first battle of World War II ",
         "c)It prevented a German invasion of Britain ",
         "d)It led to the fall of France"},
        2},
        {"What was the name of the Nazi concentration \ncamp where more than one million people were killed? ",
        {"a)Auschwitz  ",
         "b)Dachau ",
         "c)Bergen-Belsen ",
         "d)Treblinka"},
        0},
        {"Who was the British Prime Minister \nduring most of World War II? ",
        {"a)Neville Chamberlain ",
         "b)Winston Churchill ",
         "c)Clement Attlee ",
         "d)Harold Macmillan"},
        1},
    };

    int count = 1;
    int currentQuestion = GetRandomValue(0, 9);
    int selectedOption = -1;
    bool answered = false;
    int score = 0;
    EnableCursor();

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
        DrawTexture(background, 0, 0, WHITE);
        // Display the current question
        DrawText(questions[currentQuestion].question.c_str(), 100, 100, 20, BLACK);

        // Display the options for the current question
        DrawText(questions[currentQuestion].question.c_str(), 600, 200, 30, BLACK);

        // Display the options for the current question
        int questionNumer = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
            {
                DrawText(questions[currentQuestion].options[questionNumer].c_str(), 200 + (1200 * j), 570 + 200 * i, 30, BLACK);
                questionNumer++;
            }
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
            string subject = "history";
            DataAccess accessData;
            int grade = gradeSystem(score);
            accessData.addGrade(subject, to_string(grade));
            history();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}

void historyExaminationAlert() {
    Camera camera = { 0 };
    Texture2D background = LoadTexture("../images/examAlertBackground.png");
    const Rectangle reviseButton = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 30, 140, 80 };
    const Rectangle goToExamButton = { GetScreenWidth() / 2 + 50, GetScreenHeight() / 2 - 30, 140, 80 };
    EnableCursor();
    int character = GetRandomValue(1, 2);
    while (!WindowShouldClose())
    {

        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        bool isMouseOverButtonRevise = CheckCollisionPointRec(mousePosition, reviseButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(reviseButton, (isMouseOverButtonRevise ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Revise", GetScreenWidth() / 2 - 143, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonRevise && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            historyTextBook(camera, 1);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Start", GetScreenWidth() / 2 + 65, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            historyExam();

        }

        EndDrawing();
    }

}

void literatureExam()
{
    Texture2D background = LoadTexture("textures/literatureExam.png");

    Question questions[MAXQUESTIONS] = {
       {"Who is considered one of the key \nfigures of modernist literature?",
        {"a) William Shakespeare",
        "b) Virginia Woolf",
        "c) Charles Dickens",
        "d) Jane Austen "},
        1},
       {"Which literary work is often cited as a prime \nexample of modernist stream-of\n-consciousness writing?",
        {"a) Pride and Prejudice",
        "b) Ulysses by \nJames Joyce",
        "c) Moby-Dick by \nHerman Melville ",
        "d) Wuthering Heights\n by Emily Bronte"},
        1},
       {"Who wrote the modernist novel To \nthe Lighthouse?",
        {"a) James Joyce",
        "b) T.S. Eliot",
        "c) Virginia Woolf",
        "d) F. Scott \nFitzgerald"},
        2},
       {"Which literary movement is associated \nwith the rejection of traditional \nforms and structures?",
        {"a)Romanticism",
        "b) Realism",
        "c)Modernism ",
        "d) Gothic literature"},
        2},
       {"What is the name of the protagonist in George \nOrwell's dystopian novel 1984?",
        {"a)Winston Smith",
        "b)Holden Caulfield",
        "c)Jay Gatsby",
        "d)Elizabeth Bennet"},
        0},
       {"Which author is known for his\n socialist themes and exploration\n of class struggle in his works?",
        {"a) F. Scott Fitzgerald",
         "b) George Orwell",
         "c) Ernest Hemingway",
         "d) William Faulkner"},
        1},
       {"What is the title of the influential\n modernist poem written by T.S. Eliot?",
        {"a) The Waste Land",
         "b) The Great Gatsby",
         "c) Invisible Man",
         "d) The Catcher in the Rye"},
        0},
       {"Who wrote the modernist novel Mrs.Dalloway?",
        {"a)James Joyce ",
         "b)Virginia Woolf ",
         "c)F. Scott \nFitzgerald ",
         "d)Ernest \nHemingway "},
        1},
       {"Which literary work explores the themes\n of socialism and the Russian Revolution?",
        {"a)The Great Gatsby ",
         "b)Brave New World ",
         "c)Animal Farm ",
         "d)The Sun Also Rises "},
        2},
       {"Who is the author of the modernist\n novel The Sound and the Fury?",
        {"a)William Faulkner ",
         "b)Virginia Woolf",
         "c)F. Scott\n Fitzgerald ",
         "d)Ernest \nHemingway "},
        0},
        {"What is the title of the modernist\n play by Samuel Beckett featuring two \ncharacters waiting for someone named Godot? ",
        {"a)Waiting for Godot ",
         "b)Death of \na Salesman ",
         "c)The Glass \nMenagerie ",
         "d)The Crucible"},
        0},
        {"Who wrote the novel Steppenwolf,\n which explores themes of existentialism \nand socialism?",
        {"a)Hermann Hesse ",
         "b)Franz Kafka ",
         "c)Albert Camus",
         "d)Jean-Paul \nSartre "},
        0},
        {"Which literary work is known for its \n exploration of the effects of \ncapitalism and industrialization on society?",
        {"a)The Grapes of Wrath\n by John Steinbeck",
         "b)Lord of the Flies ",
         "c)Catch-22 ",
         "d)The Bell Jar"},
        0},
        {"Who is the author of the \n modernist novel A Portrait of the \n Artist as a Young Man?",
        {"a)Virginia Woolf",
         "b)James Joyce ",
         "c)F. Scott Fitzgerald ",
         "d)Ernest Hemingway"},
        1},
        {"What is the title of the \n modernist novel by Franz Kafka, featuring a \n protagonist who wakes up transformed into \n a giant insect? ",
        {"a)Metamorphosis",
         "b)Crime and \nPunishment",
         "c)One Hundred \nYears of Solitude",
         "d)Infinite Jest"},
        0},
        {"Which literary work \n explores the impact of colonialism and \n imperialism on society?",
        {"a)Things Fall \nApart by Chinua Achebe ",
         "b)The Old Man \nand the Sea ",
         "c)The Catcher \nin the Rye ",
         "d)The Lord of \nthe Rings"},
        0},
        {"Who is the author of the \n modernist novel The Trial, which \n follows a man prosecuted by a \n mysterious authority? ",
        {"a)Albert Camus ",
         "b)Jean-Paul\n Sartre  ",
         "c)Franz Kafka ",
         "d)Hermann Hesse"},
        2},
        {"What is the title of \n the modernist novel \n by Zora Neale Hurston, \n which explores African American \n culture in the rural South?",
        {"a)Beloved ",
         "b)Their Eyes \nWere Watching God ",
         "c)Invisible Man ",
         "d)The Color \nPurple"},
        1},
        {"Who wrote the modernist \n poem The Love Song of \n J.Alfred Prufrock? ",
        {"a)T.S. Eliot  ",
         "b)Ezra Pound ",
         "c)W.B. Yeats ",
         "d)Wallace\n Stevens"},
        0},
        {"What is the title of the \n modernist novel by Jean-Paul Sartre, \n which explores existentialist themes? ",
        {"a)Nausea ",
         "b)The Stranger ",
         "c)In Search \nof Lost Time ",
         "d)Slaughterhouse-Five"},
        0},
    };


    int count = 1;
    int currentQuestion = GetRandomValue(0, 9);
    int selectedOption = -1;
    bool answered = false;
    int score = 0;
    EnableCursor();

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
        DrawTexture(background, 0, 0, WHITE);
        // Display the current question
        DrawText(questions[currentQuestion].question.c_str(), 600, 200, 30, BLACK);

        // Display the options for the current question
        int questionNumer = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
            {
                DrawText(questions[currentQuestion].options[questionNumer].c_str(), 200 + (1200 * j), 570 + 200 * i, 30, BLACK);
                questionNumer++;
            }
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
            string subject = "literature";
            DataAccess accessData;
            int grade = gradeSystem(score);
            accessData.addGrade(subject, to_string(grade));
            literature();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}

void literatureExaminationAlert() {
    Camera camera = { 0 };
    Texture2D background = LoadTexture("../images/examAlertBackground.png");
    const Rectangle reviseButton = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 30, 140, 80 };
    const Rectangle goToExamButton = { GetScreenWidth() / 2 + 50, GetScreenHeight() / 2 - 30, 140, 80 };
    EnableCursor();

    int character = GetRandomValue(1, 2);
    while (!WindowShouldClose())
    {

        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        bool isMouseOverButtonRevise = CheckCollisionPointRec(mousePosition, reviseButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(reviseButton, (isMouseOverButtonRevise ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Revise", GetScreenWidth() / 2 - 143, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonRevise && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            literatureTextBook(camera, 1);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Start", GetScreenWidth() / 2 + 65, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            literatureExam();

        }

        EndDrawing();
    }

}

void biologyExam()
{
    Texture2D background = LoadTexture("textures/biologyExam.png");
    Question questions[MAXQUESTIONS] = {
       {"What is the primary function \n of carbohydrates in living organisms?",
        {"a)Energy storage",
        "b) Structural\n support",
        "c) Cell communication",
        "d) Enzyme regulation "},
        3},
       {"Which molecule serves as the \n main energy currency of the cell?",
        {"a) DNA",
        "b) RNA",
        "c) ATP ",
        "d) Glucose"},
        2},
       {"What is the structural\n unit of proteins?",
        {"a) Nucleotide",
        "b) Amino acid",
        "c) Monosaccharide",
        "d) Fatty acid"},
        1},
       {"Which nutrient is essential \n for the formation of cell membranes \n and hormone synthesis?",
        {"a)Protein",
        "b) Carbohydrate",
        "c)Fat ",
        "d) Lipid "},
        3},
       {"What is the function of \n enzymes in biological systems?",
        {"a)Energy storage",
        "b)Structural support",
        "c)Catalyzing chemical \nreactions",
        "d)Cell communication"},
        2},
       {"Which of the following \n is a water-soluble vitamin \n essential for collagen synthesis \n and wound healing?",
        {"a) Vitamin A",
         "b) Vitamin C",
         "c) Vitamin D",
         "d) Vitamin K"},
        1},
       {"What is the primary function \n of lipids in the human body?",
        {"a) Energy storage\n and insulation",
         "b) Providing structural\n support",
         "c) Facilitating enzyme \nreactions",
         "d) Transporting oxygen\n in the blood"},
        0},
       {"Which organelle is responsible \n for the synthesis of proteins in \n eukaryotic cells?",
        {"a)Mitochondria",
         "b)Endoplasmic\n reticulum ",
         "c)Ribosome ",
         "d)Golgi apparatus "},
        2},
       {"What is the role of nucleic \n acids in living organisms?",
        {"a)Energy storage ",
         "b)Transmitting genetic\n information ",
         "c)Providing structural \nsupport ",
         "d)Catalyzing chemical\n reactions "},
        1},
       {"Which nutrient is the body's \n primary source of energy?",
        {"a)Protein ",
         "b)Carbohydrate",
         "c)Fat ",
         "d)Vitamin "},
        1},
        {"What is the function \n of DNA in cells?",
        {"a)Protein synthesis ",
         "b)Energy storage ",
         "c)Genetic information\n storage and transmission ",
         "d)Cell structure"},
        2},
        {"Which type of biomolecule contains \n the genetic code and serves as a \n template for protein synthesis?",
        {"a)Carbohydrate ",
         "b)Lipid ",
         "c)Nucleic acid",
         "d)Vitamin "},
        2},
        {"What is the role of RNA \n in protein synthesis?",
        {"a)RNA serves as a \nstructural component\n of ribosomes.",
         "b)RNA carries genetic\n information from \nDNA to the ribosome. ",
         "c)RNA acts as a messenger\n between DNA and \nthe ribosome, \nfacilitating protein synthesis ",
         "d)RNA stores genetic information in the nucleus."},
        2},
        {"Which nutrient is essential for \n building and repairing tissues, and \n serves as enzymes and hormones?",
        {"a)Carbohydrate",
         "b)Protein ",
         "c)Fat ",
         "d)Vitamin"},
        1},
        {"What is the function\n of chlorophyll in plants? ",
        {"a)Energy storage",
         "b)Structural support",
         "c)Absorbing light\n energy for photosynthesis",
         "d)Enzyme regulation"},
        2},
        {"Which of the following is a \n micronutrient essential for blood \n clotting and bone health?",
        {"a)Vitamin C",
         "b)Vitamin D",
         "c)Vitamin K ",
         "d)Vitamin B12"},
        2},
        {"What is the primary function \n of carbohydrates during cellular \n respiration? ",
        {"a)Providing structural\n support ",
         "b)Acting as an\n enzyme ",
         "c)Serving as a \nsource of energy ",
         "d)Aiding in DNA\n replication"},
        2},
        {"Which of the following is a \n water-soluble vitamin essential \n for red blood cell formation and \n neural function?",
        {"a)Vitamin A ",
         "b)Vitamin C ",
         "c)Vitamin D ",
         "d)Vitamin B12 "},
        3},
        {"What is the primary function \n of proteins in cell membranes? ",
        {"a)Energy storage  ",
         "b)Structural\n support ",
         "c)Facilitating transport\n of molecules ",
         "d)Enzyme regulation"},
        2},
        {"Which nutrient is crucial for maintaining \n proper fluid balance, nerve function,\n and muscle contraction? ",
        {"a)Carbohydrate ",
         "b)Protein ",
         "c)Fat ",
         "d)Electrolytes"},
        3},
    };

    int count = 1;
    int currentQuestion = GetRandomValue(0, 9);
    int selectedOption = -1;
    bool answered = false;
    int score = 0;
    EnableCursor();

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
        DrawTexture(background, 0, 0, WHITE);
        // Display the current question
        DrawText(questions[currentQuestion].question.c_str(), 600, 200, 30, BLACK);

        // Display the options for the current question
        int questionNumer = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
            {
                DrawText(questions[currentQuestion].options[questionNumer].c_str(), 200 + (1200 * j), 570 + 200 * i, 30, BLACK);
                questionNumer++;
            }
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
            string subject = "biology";
            DataAccess accessData;
            int grade = gradeSystem(score);
            accessData.addGrade(subject, to_string(grade));
            biology();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}

void biologyExaminationAlert() {
    Camera camera = { 0 };
    Texture2D background = LoadTexture("../images/examAlertBackground.png");
    const Rectangle reviseButton = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 30, 140, 80 };
    const Rectangle goToExamButton = { GetScreenWidth() / 2 + 50, GetScreenHeight() / 2 - 30, 140, 80 };
    EnableCursor();
    int character = GetRandomValue(1, 2);
    while (!WindowShouldClose())
    {

        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        bool isMouseOverButtonRevise = CheckCollisionPointRec(mousePosition, reviseButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(reviseButton, (isMouseOverButtonRevise ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Revise", GetScreenWidth() / 2 - 143, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonRevise && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            bioTextBook(camera, 1);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Start", GetScreenWidth() / 2 + 65, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            biologyExam();

        }

        EndDrawing();
    }

}

void geographyExam()
{
    Texture2D background = LoadTexture("textures/geographyExam.png");

    Question questions[MAXQUESTIONS] = {
       {"What is the largest continent by \n land area?",
        {"a)North America",
        "b) Europe",
        "c) Asia",
        "d) Africa "},
        2},
       {"Which is the longest river \nin the world?",
        {"a) Nile",
        "b) Amazon",
        "c) Mississippi ",
        "d) Yangtze "},
        0},
       {"Which ocean is the largest by \n surface area?",
        {"a) Pacific",
        "b) Atlantic",
        "c) Indian",
        "d) Southern"},
        0},
       {"What is the capital city of France?",
        {"a)Berlin",
        "b) Rome",
        "c) Paris ",
        "d) Madrid "},
        2},
       {"Which mountain range is located \n in South America?",
        {"a)Rocky Mountains",
        "b)Andes",
        "c)Alps",
        "d)Himalayas"},
        1},
       {"Which desert is the largest\n in the world?",
        {"a) Sahara",
         "b) Gobi",
         "c) Kalahari",
         "d) Arabian"},
        0},
       {"Which country is known as the \n Land of the Rising Sun?",
        {"a) China",
         "b) Japan ",
         "c) South Korea",
         "d) India"},
        1},
       {"What is the tallest mountain \nin the world?",
        {"a)Mount Everest",
         "b)K2 ",
         "c)Kilimanjaro ",
         "d)Denali "},
        0},
       {"Which continent is home to \n the Amazon Rainforest?",
        {"a)Africa ",
         "b)South America ",
         "c)Asia ",
         "d)Australia "},
        1},
       {"What is the capital city \nof Australia?",
        {"a)Sydney ",
         "b)Melbourne",
         "c)Canberra  ",
         "d)Brisbane "},
        2},
        {"Which country is known as the \n Land of the Midnight Sun?",
        {"a)Norway ",
         "b)Canada ",
         "c)Russia ",
         "d)Sweden"},
        0},
        {"What is the longest mountain \n range in the world?",
        {"a)Andes ",
         "b)Himalayas ",
         "c)Rockies",
         "d)Mid-Atlantic Ridge "},
        3},
        {"What is the capital city of Canada?",
        {"a)Toronto",
         "b)Ottawa ",
         "c)Vancouver ",
         "d)Montreal"},
        1},
        {"Which is the largest lake \n by surface area in Africa",
        {"a)Lake Victoria",
         "b)Lake Tanganyika ",
         "c)Lake Malawi ",
         "d)Lake Chad"},
        1},
        {"Which country is the largest \nby land area? ",
        {"a)Russia",
         "b)China",
         "c)United States",
         "d)Canada"},
        0},
        {"What is the capital city of Brazil?",
        {"a)Rio de Janeiro",
         "b)Sao Paulo",
         "c)Brasilia ",
         "d)Salvador"},
        2},
        {"Which island is known as the \n Pearl of the Indian Ocean ",
        {"a)Madagascar ",
         "b)Sri Lanka ",
         "c)Mauritius ",
         "d)Maldives"},
        1},
        {"What is the largest island \n in the Mediterranean Sea?",
        {"a)Sicily ",
         "b)Sardinia ",
         "c)Cyprus ",
         "d)Crete "},
        2},
        {"Which country is located \n on the Iberian Peninsula?",
        {"a)Italy  ",
         "b)Greece ",
         "c)Spain ",
         "d)Turkey"},
        2},
        {"What is the capital city of China? ",
        {"a)Beijing ",
         "b)Shanghai ",
         "c)Hong Kong ",
         "d)Taipei"},
        0},
    };


    int count = 1;
    int currentQuestion = GetRandomValue(0, 9);
    int selectedOption = -1;
    bool answered = false;
    int score = 0;
    EnableCursor();

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
        DrawTexture(background, 0, 0, WHITE);
        // Display the current question
        DrawText(questions[currentQuestion].question.c_str(), 600, 200, 30, BLACK);

        // Display the options for the current question
        int questionNumer = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
            {
                DrawText(questions[currentQuestion].options[questionNumer].c_str(), 200 + (1200 * j), 570 + 200 * i, 30, BLACK);
                questionNumer++;
            }
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
            string subject = "geography";
            DataAccess accessData;
            int grade = gradeSystem(score);
            accessData.addGrade(subject, to_string(grade));
            geography();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}

void geographyExaminationAlert() {
    Camera camera = { 0 };
    Texture2D background = LoadTexture("../images/examAlertBackground.png");
    const Rectangle reviseButton = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 30, 140, 80 };
    const Rectangle goToExamButton = { GetScreenWidth() / 2 + 50, GetScreenHeight() / 2 - 30, 140, 80 };
    EnableCursor();

    int character = GetRandomValue(1, 2);
    while (!WindowShouldClose())
    {

        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        bool isMouseOverButtonRevise = CheckCollisionPointRec(mousePosition, reviseButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(reviseButton, (isMouseOverButtonRevise ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Revise", GetScreenWidth() / 2 - 143, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonRevise && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            geographyTextBook(camera, 1);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Start", GetScreenWidth() / 2 + 65, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            geographyExam();
        }

        EndDrawing();
    }

}

void programmingExam()
{
    Texture2D background = LoadTexture("textures/programmingExam.png");

    Question questions[MAXQUESTIONS] = {
       {"What is a correct syntax to output\n Hello World in C++?",
        {"a)Console.WriteLine\n(Hello World);",
        "b)  System.out.println\n(Hello World); ",
        "c) cout << Hello \nworld;",
        "d) print\n(Hello world); "},
        2},
       {"C++ is an alias of C#",
        {"a) True",
        "b) False",
        " ",
        " "},
        1},
       {"How do you insert\n COMMENTS in C++ code?",
        {"a) // ",
        "b) /* ",
        "c) # ",
        " "},
        0},
       {"Which data type is used to create \n a variable that should store text?",
        {"a)String",
        "b) txt",
        "c) string ",
        "d) myString "},
        3},
       {"How do you create a variable \n with the numeric value 5?",
        {"a)double\n x = 5;",
        "b)int = 5;",
        "c)num x = 5;",
        "d)x = 5;"},
        1},
       {"How do you create a variable \n with the floating number 2.8?",
        {"a) x = 2.8;",
         "b) double \nx = 2.8;",
         "c) int \nx = 2.8;",
         "d) byte\n x = 2.8;"},
        1},
       {"Which method can be used to \n find the length of a string?",
        {"a) len()",
         "b) length() ",
         "c) getSize() ",
         "d) getLength() "},
        1},
       {"Which operator is used to add\n together two values?",
        {"a)+",
         "b)& ",
         "c)* ",
         "d)^"},
        0},
       {"The value of a string variable \n can be surrounded by single quotes.",
        {"a)True ",
         "b)False ",
         " ",
         " "},
        1},
       {"Which header file lets us work with \n input and output objects?",
        {"a)#include \n<inputstr>",
         "b)#include \n<iosstring>",
         "c)#include \n<stream>  ",
         "d)#include \n<iostream> "},
        3},
        {"Which operator can be \n used to compare two values?",
        {" a) <> ",
         "b)= ",
         "c)== ",
         "d)><"},
        2},
        {"At which number do indexes start?",
        {"a)1 ",
         "b)2 ",
         "c)0",
         "d)-1 "},
        2},
        {"Which keyword is used to \n create a class in C++??",
        {"a)className",
         "b)myClass ",
         "c)class ",
         "d)class()"},
        2},
        {"Which keyword is used to \n create a class in C++?",
        {"a)class myObj \n= new MyClass();",
         "b) class MyClass\n = new myObj(); ",
         "c) MyClass myObj; ",
         "d) new myObj\n= MyClass();"},
        2},
        {"In C++, it is possible to inherit \n attributes and methods from \n one class to another. ",
        {"a)True",
         "b)False",
         " ",
         " "},
        0},
        {"Which operator is used \n to multiply numbers?",
        {"a)x",
         "b)%",
         "c)* ",
         "d)#"},
        2},
        {"How do you create a reference \n variable of an existing variable? ",
        {"a)* ",
         "b)& ",
         "c)REF ",
         "d)ref"},
        1},
        {"How do you start writing \n an if statement in C++?",
        {"a)if x > y ",
         "b)if x > y then; ",
         "c)if (x > y)",
         "d)if x > y :  "},
        2},
        {"Which keyword is used to return \n a value inside a method?",
        {"a)void  ",
         "b)return  ",
         "c)get ",
         "d)break "},
        1},
        {"Which statement is used to stop a loop? ",
        {"a)void  ",
         "b)return  ",
         "c)get ",
         "d)break "},
        3},
    };

    int count = 1;
    int currentQuestion = GetRandomValue(0, 9);
    int selectedOption = -1;
    bool answered = false;
    int score = 0;
    EnableCursor();

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
        DrawTexture(background, 0, 0, WHITE);
        // Display the current question
        DrawText(questions[currentQuestion].question.c_str(), 600, 200, 30, BLACK);

        // Display the options for the current question
        int questionNumer = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
            {
                DrawText(questions[currentQuestion].options[questionNumer].c_str(), 200 + (1200 * j), 570 + 200 * i, 30, BLACK);
                questionNumer++;
            }
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
            string subject = "programming";
            DataAccess accessData;
            int grade = gradeSystem(score);
            accessData.addGrade(subject, to_string(grade));
            geography();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}

void programmingExaminationAlert() {
    Camera camera = { 0 };
    Texture2D background = LoadTexture("../images/examAlertBackground.png");
    const Rectangle reviseButton = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 30, 140, 80 };
    const Rectangle goToExamButton = { GetScreenWidth() / 2 + 50, GetScreenHeight() / 2 - 30, 140, 80 };
    EnableCursor();

    int character = GetRandomValue(1, 2);
    while (!WindowShouldClose())
    {

        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        bool isMouseOverButtonRevise = CheckCollisionPointRec(mousePosition, reviseButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(reviseButton, (isMouseOverButtonRevise ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Revise", GetScreenWidth() / 2 - 143, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonRevise && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            prgTextBook(camera, 1);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Start", GetScreenWidth() / 2 + 65, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            programmingExam();
        }

        EndDrawing();
    }

}

void chemistryExam()
{
    Texture2D background = LoadTexture("textures/chemistryExam.png");

    Question questions[MAXQUESTIONS] = {
       {"What is the chemical symbol for water?",
        {"a) Wa",
        "b)  H2O",
        "c) Hy",
        "d) O2"},
        1},
       {"Which element is essential for organic \n life and is the main component of \n organic molecules?",
        {"a) Carbon",
        "b) Oxygen",
        "c) Hydrogen",
        "d) Nitrogen"},
        0},
       {"What is the smallest unit of an element \n that retains its chemical properties?",
        {"a) Atom ",
        "b) Molecule ",
        "c) Compound ",
        "d) Ion "},
        0},
       {"What is the chemical symbol for iron?",
        {"a) Ir ",
        "b) Fe",
        "c) Io ",
        "d) In "},
        1},
       {"What is the process by which a \n solid changes directly into a gas without passing \n through the liquid state?",
        {"a) Condensation",
        "b) Condensation",
        "c) Evaporation",
        "d) Melting"},
        1},
       {"What is the chemical \n formula for carbon dioxide?",
        {"a) CO2",
         "b) CO",
         "c) O2",
         "d) C2O"},
        0},
       {"Which of the following is a noble gas?",
        {"a) Helium",
         "b) Neon",
         "c) Argon",
         "d) All of the above "},
        3},
       {"What is the pH value of \n pure water at room temperature?",
        {"a) 0",
         "b) 7 ",
         "c) 14 ",
         "d) 10"},
        1},
       {"Which subatomic particle \n has a positive charge?",
        {"a) Proton ",
         "b) Neutron ",
         "c) Electron",
         "d) Ion"},
        0},
       {"What is the process by \n which a liquid changes into a gas at \n temperatures below its boiling point?",
        {"a) Evaporation",
         "b) Condensation",
         "c) Sublimation",
         "d) Vaporization"},
        0},
        {"What is the chemical symbol for gold?",
        {"a) Go ",
         "b) Au",
         "c) Ag ",
         "d) Gd"},
        1},
        {"What is the chemical \n formula for table salt?",
        {"a) NaCl ",
         "b) H2O ",
         "c) CO2",
         "d) CaCO3 "},
        0},
        {"Which of the following \n is a greenhouse gas?",
        {"a) Oxygen",
         "b) Carbon \ndioxide ",
         "c) Nitrogen ",
         "d) Hydrogen"},
        1},
        {"What is the atomic number of oxygen?",
        {"a) 8",
         "b) 1",
         "c) 16 ",
         "d) 32"},
        0},
        {"What is the chemical \n formula for methane? ",
        {"a) CH4",
         "b) CO2",
         "c) H2O",
         "d) NH3"},
        0},
        {"Which of the following \n is a halogen?",
        {"a)Chlorine",
         "b) Sodium",
         "c)Calcium ",
         "d)Potassium"},
        0},
        {"What is the chemical \n formula for sulfuric acid? ",
        {"a) H2SO3 ",
         "b) H2SO4 ",
         "c) HCl ",
         "d) HNO3"},
        1},
        {"What is the chemical symbol for lead?",
        {"a)Ld ",
         "b)Pb ",
         "c)Pd ",
         "d)Pt "},
        1},
        {"Which subatomic particle \n has a neutral charge?",
        {"a)Neutron  ",
         "b)Proton ",
         "c)Electron ",
         "d)Ion"},
        0},
        {"What is the chemical formula \n for hydrogen peroxide? ",
        {"a)H2O ",
         "b)HO ",
         "c)H2O2 ",
         "d)H3O+"},
        1},
    };


    int count = 1;
    int currentQuestion = GetRandomValue(0, 9);
    int selectedOption = -1;
    bool answered = false;
    int score = 0;
    EnableCursor();

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
        DrawTexture(background, 0, 0, WHITE);
        // Display the current question
        DrawText(questions[currentQuestion].question.c_str(), 600, 200, 30, BLACK);

        // Display the options for the current question
        int questionNumer = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
            {
                DrawText(questions[currentQuestion].options[questionNumer].c_str(), 200 + (1200 * j), 570 + 200 * i, 30, BLACK);
                questionNumer++;
            }
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
            string subject = "chemistry";
            DataAccess accessData;
            int grade = gradeSystem(score);
            accessData.addGrade(subject, to_string(grade));
            geography();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}

void chemistryExaminationAlert() {
    Camera camera = { 0 };
    Texture2D background = LoadTexture("../images/examAlertBackground.png");
    const Rectangle reviseButton = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 30, 140, 80 };
    const Rectangle goToExamButton = { GetScreenWidth() / 2 + 50, GetScreenHeight() / 2 - 30, 140, 80 };
    EnableCursor();
    int character = GetRandomValue(1, 2);
    while (!WindowShouldClose())
    {

        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        bool isMouseOverButtonRevise = CheckCollisionPointRec(mousePosition, reviseButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(reviseButton, (isMouseOverButtonRevise ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Revise", GetScreenWidth() / 2 - 143, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonRevise && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            chemistryTextBook(camera, 1);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Start", GetScreenWidth() / 2 + 65, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            chemistryExam();
        }

        EndDrawing();
    }

}


void physicsExam()
{
    Texture2D background = LoadTexture("textures/physicsExam.png");

    Question questions[MAXQUESTIONS] = {
       {"What is the SI unit of force?",
        {"a) Joule",
        "b)  Newton",
        "c) Watt",
        "d) Kilogram"},
        1},
       {"What is the acceleration due to gravity \n on Earth's surface (approximately)?",
        {"a) 10 m/s^2",
        "b) 9.8 m/s^2 ",
        "c) 5 m/s^2",
        "d) 20 m/s^2"},
        1},
       {"Which law of motion states that an object at \n rest will remain at rest, and an object in \n motion will remain in motion unless \n acted upon by an external force?",
        {"a) Newton's First\n Law of Motion ",
        "b) Newton's Second \nLaw of Motion ",
        "c) Newton's Third \nLaw of Motion ",
        "d) Law of Universal\n Gravitation "},
        0},
       {"What is the formula for calculating \n kinetic energy?",
        {"a) KE = mv ",
        "b) KE = 1/2mv^2 ",
        "c) KE = mgh ",
        "d) KE = Fd "},
        1},
       {"Which of the following \nis a unit of power?",
        {"a) Joule",
        "b) Watt ",
        "c) Newton",
        "d) Kilogram-meter"},
        1},
       {"What is the relationship between \n force, mass, and acceleration as \n described by Newton's Second \n Law of Motion?",
        {"a) Force = mass\n × acceleration",
         "b) Force = mass \n÷ acceleration",
         "c) Force = \nacceleration ÷ mass",
         "d) Force = \nmass + acceleration"},
        0},
       {"What is the law that states that \n the total energy of an isolated system remains constant \n over time, even though energy within the system \n can change forms?",
        {"a) Law of \nConservation of Momentum",
         "b) Law of \nConservation of Mass",
         "c) Law of \nConservation of Energy",
         "d) Law of \nUniversal Gravitation "},
        2},
       {"What is the formula for calculating gravitational \n potential energy near the Earth's surface?",
        {"a) PE = mgh ",
         "b) PE = 1/2mv^2 ",
         "c) PE = Fd ",
         "d) PE = KE × mg"},
        0},
       {"Which of the following is a \n unit of electric charge?",
        {"a) Coulomb ",
         "b) Volt ",
         "c) Ohm",
         "d) Ampere"},
        0},
       {"What is the speed of light \n in a vacuum (approximately)?",
        {"a) 300,000 m/s",
         "b) 100,000 m/s",
         "c) 3 × 10^8 m/s",
         "d) 30,000 m/s"},
        2},
        {"Which law of thermodynamics states \n that energy cannot be created or destroyed, \n only transformed from one form to another?",
        {"a) First Law \nof Thermodynamics ",
         "b) Second Law\n of Thermodynamics",
         "c) Third Law \nof Thermodynamics ",
         "d) Zeroth Law \nof Thermodynamics"},
        0},
        {"What is the formula for \ncalculating work done by a constant\n force on an object?",
        {"a) Work = \nforce × distance ",
         "b) Work = \nforce ÷ distance ",
         "c) Work = \nmass × acceleration",
         "d) Work = \nenergy × time "},
        0},
        {"What is the SI unit of electric current?",
        {"a) Volt",
         "b) Ampere ",
         "c) Coulomb ",
         "d) Ohm"},
        1},
        {"What is the law that states \n that for every action, there is an equal \n and opposite reaction?",
        {"a) Newton's \nFirst Law of Motion",
         "b) Newton's \nSecond Law of Motion",
         "c) Newton's \nThird Law of Motion ",
         "d) Law of Universal\n Gravitation "},
        2},
        {"What is the formula for \n calculating the frequency of a wave? ",
        {"a) f = v/λ",
         "b) f = λ/v ",
         "c) f = v × λ",
         "d) f = v - λ"},
        1},
        {"What is the principle that states \n that the total electric charge within a \n closed system is constant over time?",
        {"a) Law of \nConservation of Charge",
         "b) Coulomb's Law",
         "c) Ohm's Law",
         "d) Kirchhoff's\n Law"},
        0},
        {"Which of the following is a unit \n of electric potential difference? ",
        {"a) Ampere ",
         "b) Volt ",
         "c) Ohm ",
         "d) Coulomb "},
        1},
        {"What is the formula for calculating \n the period of a wave?",
        {"a) T = f × λ ",
         "b) T = 1/f ",
         "c) T = f/λ ",
         "d) T = λ/f "},
        1},
        {"What is the SI unit of pressure?",
        {"a)Pascal  ",
         "b)Newton ",
         "c)Joule ",
         "d)Ohm "},
        0},
        {"What is the law that states that the pressure \n of a given mass of gas is inversely proportional \n to its volume at constant temperature? ",
        {"a)Boyle's \nLaw ", 
         "b)Charles's \nLaw ",
         "c)H2O2 ",
         "d)H3O+"},
        1},
    };

    int count = 1;
    int currentQuestion = GetRandomValue(0, 9);
    int selectedOption = -1;
    bool answered = false;
    int score = 0;
    EnableCursor();

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
        DrawTexture(background, 0, 0, WHITE);
        // Display the current question
        DrawText(questions[currentQuestion].question.c_str(), 600, 200, 30, BLACK);

        // Display the options for the current question
        int questionNumer = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
            {
                DrawText(questions[currentQuestion].options[questionNumer].c_str(), 200 + (1200 * j), 570 + 200 * i, 30, BLACK);
                questionNumer++;
            }
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
            string subject = "physics";
            DataAccess accessData;
            int grade = gradeSystem(score);
            accessData.addGrade(subject, to_string(grade));
            geography();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}

void physicsExaminationAlert() {
    Camera camera = { 0 };
    Texture2D background = LoadTexture("../images/examAlertBackground.png");
    const Rectangle reviseButton = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 30, 140, 80 };
    const Rectangle goToExamButton = { GetScreenWidth() / 2 + 50, GetScreenHeight() / 2 - 30, 140, 80 };
    EnableCursor();
    int character = GetRandomValue(1, 2);
    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        bool isMouseOverButtonRevise = CheckCollisionPointRec(mousePosition, reviseButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(reviseButton, (isMouseOverButtonRevise ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Revise", GetScreenWidth() / 2 - 143, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonRevise && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            physicsTextBook(camera, 1);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? Color{ 250,122,255,255 } : Color{ 255, 109, 194, 255 }));
        DrawText("Start", GetScreenWidth() / 2 + 65, GetScreenHeight() / 2 - 10, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            physicsExam();
        }

        EndDrawing();
    }

}