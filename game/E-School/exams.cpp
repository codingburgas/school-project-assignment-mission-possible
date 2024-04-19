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
        {"3x + 1 > x - 5",
         {"a)-2 ", "b)-3 ", "c)-4 ", "d)none of the above "},
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
        SetExitKey(KEY_APOSTROPHE);
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
    Question questions[MAXQUESTIONS] = {
       {"Molly used to ... watching cartoons when she was young.",
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
       {"The Rossens ... abroad for fiteen years before they moved back to England.",
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
        SetExitKey(KEY_APOSTROPHE);
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
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
        {
            englishExam();

        }

        EndDrawing();
    }

}

void historyExam()
{
    Question questions[MAXQUESTIONS] = {
       {"When did World War II officially begin?",
        {"a) 1914",
        "b) 1939",
        "c) 1941",
        "d) 1945 "},
        1},
       {"Which country invaded Poland, triggering the start of World War II?",
        {"a) France",
        "b) United Kingdom",
        "c) Germany ",
        "d) Italy"},
        2},
       {"What was the code name for the Allied invasion of Normandy on June 6, 1944?",
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
       {"Which country was not part of the Axis Powers during World War II?",
        {"a) Japan",
         "b) Italy",
         "c) Soviet Union",
         "d) Hungary"},
        2},
       {"What was the name of the atomic bomb dropped on Hiroshima?",
        {"a) Fat Man",
         "b) Little Boy",
         "c) Tsar Bomba",
         "d) Trinity"},
        1},
       {"Who was the Supreme Commander of the Allied Forces in Europe during World War II?",
        {"a)Dwight D. Eisenhower ",
         "b)Douglas MacArthur ",
         "c)George S. Patton ",
         "d)Bernard Montgomery "},
        0},
       {"Which battle is considered the turning point of the war in the Pacific?",
        {"a)Battle of Midway ",
         "b)Battle of Okinawa ",
         "c)Battle of Iwo Jima ",
         "d)Battle of Guadalcanal "},
        0},
       {"Which country was invaded by Nazi Germany in 1940, leading to its evacuation at Dunkirk?",
        {"a)Belgium ",
         "b)France ",
         "c)Netherlands ",
         "d)Luxembourg "},
        1},
        {"What was the name of the German air force during World War II? ",
        {"a)Luftwaffe ",
         "b)Wehrmacht ",
         "c)Waffen-SS ",
         "d)Schutzstaffel"},
        0},
        {"Which of the following was not a major axis power during World War II?",
        {"a)Japan ",
         "b)Italy ",
         "c)Soviet Union",
         "d)Germany "},
        2},
        {"What was the name of the German offensive against the Soviet Union in 1941? ",
        {"a)Operation Overlord ",
         "b)Battle of the Bulge ",
         "c)Operation Barbarossa ",
         "d)D-Day"},
        2},
        {"Which battle marked the last major German offensive on the Western Front during World War II?",
        {"a)Battle of Stalingrad",
         "b)Battle of Midway ",
         "c)Battle of the Bulge ",
         "d)Battle of Kursk"},
        2},
        {"What was the name of the treaty that officially ended World War II in Europe? ",
        {"a)Treaty of Versailles",
         "b)Treaty of Paris",
         "c)Treaty of Berlin",
         "d)Treaty of Versailles II"},
        3},
        {"What was the main purpose of the Yalta Conference in 1945?",
        {"a)Plan for the invasion of Normandy ",
         "b)Establish the United Nations ",
         "c)Discuss post-war Europe ",
         "d)Negotiate peace with Japan"},
        2},
        {"Which country did Nazi Germany invade, breaking the Molotov-Ribbentrop Pact with the Soviet Union? ",
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
        {"What was the name of the Nazi concentration camp where more than one million people were killed? ",
        {"a)Auschwitz  ",
         "b)Dachau ",
         "c)Bergen-Belsen ",
         "d)Treblinka"},
        0},
        {"Who was the British Prime Minister during most of World War II? ",
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
            history();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}

void historyExaminationAlert() {
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
            historyTextBook(camera);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? SKYBLUE : BLUE));
        DrawText("Start", GetScreenWidth() / 2 + 110, GetScreenHeight() / 2 + 5, 40, WHITE);
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
    Question questions[MAXQUESTIONS] = {
       {"Who is considered one of the key figures of modernist literature?",
        {"a) William Shakespeare",
        "b) Virginia Woolf",
        "c) Charles Dickens",
        "d) Jane Austen "},
        1},
       {"Which literary work is often cited as a prime example of modernist stream-of-consciousness writing?",
        {"a) Pride and Prejudice",
        "b) Ulysses by James Joyce",
        "c) Moby-Dick by Herman Melville ",
        "d) Wuthering Heights by Emily Bronte"},
        1},
       {"Who wrote the modernist novel To the Lighthouse?",
        {"a) James Joyce",
        "b) T.S. Eliot",
        "c) Virginia Woolf",
        "d) F. Scott Fitzgerald"},
        2},
       {"Which literary movement is associated with the rejection of traditional forms and structures?",
        {"a)Romanticism",
        "b) Realism",
        "c)Modernism ",
        "d) Gothic literature"},
        2},
       {"What is the name of the protagonist in George Orwell's dystopian novel 1984?",
        {"a)Winston Smith",
        "b)Holden Caulfield",
        "c)Jay Gatsby",
        "d)Elizabeth Bennet"},
        0},
       {"Which author is known for his socialist themes and exploration of class struggle in his works?",
        {"a) F. Scott Fitzgerald",
         "b) George Orwell",
         "c) Ernest Hemingway",
         "d) William Faulkner"},
        1},
       {"What is the title of the influential modernist poem written by T.S. Eliot?",
        {"a) The Waste Land",
         "b) The Great Gatsby",
         "c) Invisible Man",
         "d) The Catcher in the Rye"},
        0},
       {"Who wrote the modernist novel Mrs.Dalloway?",
        {"a)James Joyce ",
         "b)Virginia Woolf ",
         "c)F. Scott Fitzgerald ",
         "d)Ernest Hemingway "},
        1},
       {"Which literary work explores the themes of socialism and the Russian Revolution?",
        {"a)The Great Gatsby ",
         "b)Brave New World ",
         "c)Animal Farm ",
         "d)The Sun Also Rises "},
        2},
       {"Who is the author of the modernist novel The Sound and the Fury?",
        {"a)William Faulkner ",
         "b)Virginia Woolf",
         "c)F. Scott Fitzgerald ",
         "d)Ernest Hemingway "},
        0},
        {"What is the title of the modernist play by Samuel Beckett featuring two characters waiting for someone named Godot? ",
        {"a)Waiting for Godot ",
         "b)Death of a Salesman ",
         "c)The Glass Menagerie ",
         "d)The Crucible"},
        0},
        {"Who wrote the novel Steppenwolf, which explores themes of existentialism and socialism?",
        {"a)Hermann Hesse ",
         "b)Franz Kafka ",
         "c)Albert Camus",
         "d)Jean-Paul Sartre "},
        0},
        {"Which literary work is known for its exploration of the effects of capitalism and industrialization on society?",
        {"a)The Grapes of Wrath by John Steinbeck",
         "b)Lord of the Flies ",
         "c)Catch-22 ",
         "d)The Bell Jar"},
        0},
        {"Who is the author of the modernist novel A Portrait of the Artist as a Young Man?",
        {"a)Virginia Woolf",
         "b)James Joyce ",
         "c)F. Scott Fitzgerald ",
         "d)Ernest Hemingway"},
        1},
        {"What is the title of the modernist novel by Franz Kafka, featuring a protagonist who wakes up transformed into a giant insect? ",
        {"a)Metamorphosis",
         "b)Crime and Punishment",
         "c)One Hundred Years of Solitude",
         "d)Infinite Jest"},
        0},
        {"Which literary work explores the impact of colonialism and imperialism on society?",
        {"a)Things Fall Apart by Chinua Achebe ",
         "b)The Old Man and the Sea ",
         "c)The Catcher in the Rye ",
         "d)The Lord of the Rings"},
        0},
        {"Who is the author of the modernist novel The Trial, which follows a man prosecuted by a mysterious authority? ",
        {"a)Albert Camus ",
         "b)Jean-Paul Sartre  ",
         "c)Franz Kafka ",
         "d)Hermann Hesse"},
        2},
        {"What is the title of the modernist novel by Zora Neale Hurston, which explores African American culture in the rural South?",
        {"a)Beloved ",
         "b)Their Eyes Were Watching God ",
         "c)Invisible Man ",
         "d)The Color Purple"},
        1},
        {"Who wrote the modernist poem The Love Song of J.Alfred Prufrock? ",
        {"a)T.S. Eliot  ",
         "b)Ezra Pound ",
         "c)W.B. Yeats ",
         "d)Wallace Stevens"},
        0},
        {"What is the title of the modernist novel by Jean-Paul Sartre, which explores existentialist themes? ",
        {"a)Nausea ",
         "b)The Stranger ",
         "c)In Search of Lost Time ",
         "d)Slaughterhouse-Five"},
        0},
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
            literature();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}

void literatureExaminationAlert() {
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
            literatureTextBook(camera);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? SKYBLUE : BLUE));
        DrawText("Start", GetScreenWidth() / 2 + 110, GetScreenHeight() / 2 + 5, 40, WHITE);
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
    Question questions[MAXQUESTIONS] = {
       {"What is the primary function of carbohydrates in living organisms?",
        {"a)Energy storage",
        "b) Structural support",
        "c) Cell communication",
        "d) Enzyme regulation "},
        3},
       {"Which molecule serves as the main energy currency of the cell?",
        {"a) DNA",
        "b) RNA",
        "c) ATP ",
        "d) Glucose"},
        2},
       {"What is the structural unit of proteins?",
        {"a) Nucleotide",
        "b) Amino acid",
        "c) Monosaccharide",
        "d) Fatty acid"},
        1},
       {"Which nutrient is essential for the formation of cell membranes and hormone synthesis?",
        {"a)Protein",
        "b) Carbohydrate",
        "c)Fat ",
        "d) Lipid "},
        3},
       {"What is the function of enzymes in biological systems?",
        {"a)Energy storage",
        "b)Structural support",
        "c)Catalyzing chemical reactions",
        "d)Cell communication"},
        2},
       {"Which of the following is a water-soluble vitamin essential for collagen synthesis and wound healing?",
        {"a) Vitamin A",
         "b) Vitamin C",
         "c) Vitamin D",
         "d) Vitamin K"},
        1},
       {"What is the primary function of lipids in the human body?",
        {"a) Energy storage and insulation",
         "b) Providing structural support",
         "c) Facilitating enzyme reactions",
         "d) Transporting oxygen in the blood"},
        0},
       {"Which organelle is responsible for the synthesis of proteins in eukaryotic cells?",
        {"a)Mitochondria",
         "b)Endoplasmic reticulum ",
         "c)Ribosome ",
         "d)Golgi apparatus "},
        2},
       {"What is the role of nucleic acids in living organisms?",
        {"a)Energy storage ",
         "b)Transmitting genetic information ",
         "c)Providing structural support ",
         "d)Catalyzing chemical reactions "},
        1},
       {"Which nutrient is the body's primary source of energy?",
        {"a)Protein ",
         "b)Carbohydrate",
         "c)Fat ",
         "d)Vitamin "},
        1},
        {"What is the function of DNA in cells?",
        {"a)Protein synthesis ",
         "b)Energy storage ",
         "c)Genetic information storage and transmission ",
         "d)Cell structure"},
        2},
        {"Which type of biomolecule contains the genetic code and serves as a template for protein synthesis?",
        {"a)Carbohydrate ",
         "b)Lipid ",
         "c)Nucleic acid",
         "d)Vitamin "},
        2},
        {"What is the role of RNA in protein synthesis?",
        {"a)RNA serves as a structural component of ribosomes.",
         "b)RNA carries genetic information from DNA to the ribosome. ",
         "c)RNA acts as a messenger between DNA and the ribosome, facilitating protein synthesis ",
         "d)RNA stores genetic information in the nucleus."},
        2},
        {"Which nutrient is essential for building and repairing tissues, and serves as enzymes and hormones?",
        {"a)Carbohydrate",
         "b)Protein ",
         "c)Fat ",
         "d)Vitamin"},
        1},
        {"What is the function of chlorophyll in plants? ",
        {"a)Energy storage",
         "b)Structural support",
         "c)Absorbing light energy for photosynthesis",
         "d)Enzyme regulation"},
        2},
        {"Which of the following is a micronutrient essential for blood clotting and bone health?",
        {"a)Vitamin C",
         "b)Vitamin D",
         "c)Vitamin K ",
         "d)Vitamin B12"},
        2},
        {"What is the primary function of carbohydrates during cellular respiration? ",
        {"a)Providing structural support ",
         "b)Acting as an enzyme ",
         "c)Serving as a source of energy ",
         "d)Aiding in DNA replication"},
        2},
        {"Which of the following is a water-soluble vitamin essential for red blood cell formation and neural function?",
        {"a)Vitamin A ",
         "b)Vitamin C ",
         "c)Vitamin D ",
         "d)Vitamin B12 "},
        3},
        {"What is the primary function of proteins in cell membranes? ",
        {"a)Energy storage  ",
         "b)Structural support ",
         "c)Facilitating transport of molecules ",
         "d)Enzyme regulation"},
        2},
        {"Which nutrient is crucial for maintaining proper fluid balance, nerve function, and muscle contraction? ",
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
            biology();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}

void biologyExaminationAlert() {
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
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            biologyExam();

        }

        EndDrawing();
    }

}

void geographyExam()
{
    Question questions[MAXQUESTIONS] = {
       {"What is the largest continent by land area?",
        {"a)North America",
        "b) Europe",
        "c) Asia",
        "d) Africa "},
        2},
       {"Which is the longest river in the world?",
        {"a) Nile",
        "b) Amazon",
        "c) Mississippi ",
        "d) Yangtze "},
        0},
       {"Which ocean is the largest by surface area?",
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
       {"Which mountain range is located in South America?",
        {"a)Rocky Mountains",
        "b)Andes",
        "c)Alps",
        "d)Himalayas"},
        1},
       {"Which desert is the largest in the world?",
        {"a) Sahara",
         "b) Gobi",
         "c) Kalahari",
         "d) Arabian"},
        0},
       {"Which country is known as the Land of the Rising Sun?",
        {"a) China",
         "b) Japan ",
         "c) South Korea",
         "d) India"},
        1},
       {"What is the tallest mountain in the world?",
        {"a)Mount Everest",
         "b)K2 ",
         "c)Kilimanjaro ",
         "d)Denali "},
        0},
       {"Which continent is home to the Amazon Rainforest?",
        {"a)Africa ",
         "b)South America ",
         "c)Asia ",
         "d)Australia "},
        1},
       {"What is the capital city of Australia?",
        {"a)Sydney ",
         "b)Melbourne",
         "c)Canberra  ",
         "d)Brisbane "},
        2},
        {"Which country is known as the Land of the Midnight Sun?",
        {"a)Norway ",
         "b)Canada ",
         "c)Russia ",
         "d)Sweden"},
        0},
        {"What is the longest mountain range in the world?",
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
        {"Which is the largest lake by surface area in Africa",
        {"a)Lake Victoria",
         "b)Lake Tanganyika ",
         "c)Lake Malawi ",
         "d)Lake Chad"},
        1},
        {"Which country is the largest by land area? ",
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
        {"Which island is known as the Pearl of the Indian Ocean ",
        {"a)Madagascar ",
         "b)Sri Lanka ",
         "c)Mauritius ",
         "d)Maldives"},
        1},
        {"What is the largest island in the Mediterranean Sea?",
        {"a)Sicily ",
         "b)Sardinia ",
         "c)Cyprus ",
         "d)Crete "},
        2},
        {"Which country is located on the Iberian Peninsula?",
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
            geography();
            break;
        }
        SetExitKey(KEY_APOSTROPHE);
    }

}

void geographyExaminationAlert() {
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
            geographyTextBook(camera);
        }
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, goToExamButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(goToExamButton, (isMouseOverButtonStart ? SKYBLUE : BLUE));
        DrawText("Start", GetScreenWidth() / 2 + 110, GetScreenHeight() / 2 + 5, 40, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            geographyExam();
        }

        EndDrawing();
    }

}