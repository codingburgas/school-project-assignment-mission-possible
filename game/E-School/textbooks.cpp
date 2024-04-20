#include "textbooks.h"
#include "exams.h"

float distanceCalc(Vector3 a, Vector3 b) {
    float distanceX = b.x - a.x;
    float distanceY = b.y - a.y;
    float distanceZ = b.z - a.z;
    return sqrt(distanceX * distanceX + distanceY * distanceY + distanceZ * distanceZ);
}
void bioTextBook(Camera camera, bool examination)
{
    unsigned int pageNumber = 1;
    Vector3 cubePosition = { 0.0f, 1.5f, -7.5f };
    float distance = distanceCalc(camera.position, cubePosition);

	float elapsedTime = 0.0f;
	float updateInterval = 1.0f;

	int minutes = 1;
	int seconds = 0;

    Rectangle next = { 1800,900,100,50 };
    Rectangle previous = { 50,900,100,50 };

    bool timerIsZero = 0;

    if ((distance < 3.5f && IsKeyPressed(KEY_F)))
    {
        EnableCursor();
        EndMode3D();
        while (!WindowShouldClose())
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
            default:
                pageNumber = 1;
                break;
            }

			elapsedTime += GetFrameTime();

			if (elapsedTime >= updateInterval) {
				// Decrement the timer
				if (seconds == 0) {
					if (minutes == 0)
					{
                        timerIsZero = 1;
					}
					minutes--;
					seconds = 59;

				}
				else {
					seconds--;
				}

				elapsedTime = 0.0f; // Reset elapsed time
			}

			EndMode3D();
			// Draw timer
			DrawText(TextFormat("%02d:%02d", minutes, seconds), 930, 40, 50, RED);

            if (timerIsZero == 1)
            {
                DisableCursor();
				biologyExaminationAlert();
                break;
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), previous))
            {
                pageNumber--;
            }
            if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), next))
            {
                pageNumber++;
            }
            EndDrawing();
        }
    }
}

void prgTextBook(Camera camera,Vector3 cubePosition, bool examination)
{
	unsigned int pageNumber = 1;
	float distance = distanceCalc(camera.position, cubePosition);

	Rectangle gameButton = { 900,460,100,50 };
	Rectangle textButton = { 1100,460,100,50 };

	float elapsedTime = 0.0f;
	float updateInterval = 1.0f;

	int minutes = 1;
	int seconds = 0;
	bool menu = 1;
	bool game = 0;
	bool book = 0;
	Rectangle next = { 1800,900,100,50 };
	Rectangle previous = { 50,900,100,50 };

	bool timerIsZero = 0;

	if (distance < 3.5f && IsKeyPressed(KEY_F))
	{
		EnableCursor();
		EndMode3D();
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(WHITE);
			if (IsKeyPressed(KEY_B) || timerIsZero == 1)
			{
				DisableCursor();
				break;
			}
			if (menu == 1)
			{
              DrawRectangleRec(gameButton, RED);
			  DrawRectangleRec(textButton, BLUE);
			}
			
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), gameButton))
			{
				menu = 0;
				game = 1;
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), textButton))
			{
				menu = 0;
				book = 1;
			}
			if (game == 1)
			{
				pong();
			}
			if (book == 1)
			{
				DrawRectangleRec(previous, BLUE);
				DrawRectangleRec(next, BLUE);

				DrawText("previous", 50, 915, 20, BLACK);
				DrawText("next", 1800, 915, 20, BLACK);
				switch (pageNumber)
				{
				case 1:
					DrawText("Programming", 825, 100, 100, BLACK);
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
				default:
					pageNumber = 1;
					break;
				}

				elapsedTime += GetFrameTime();

				if (elapsedTime >= updateInterval) {
					// Decrement the timer
					if (seconds == 0) {
						if (minutes == 0)
						{
							timerIsZero = 1;
						}
						minutes--;
						seconds = 59;

					}
					else {
						seconds--;
					}

					elapsedTime = 0.0f; // Reset elapsed time
				}

				EndMode3D();
				// Draw timer
				DrawText(TextFormat("%02d:%02d", minutes, seconds), 930, 40, 50, RED);

				if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), previous))
				{
					pageNumber--;
				}
				if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), next))
				{
					pageNumber++;
				}
				
			
			}
			EndDrawing();
			bool menu = 1;
			bool game = 0;
			bool book = 0;
		}
	}
	DisableCursor();
}


void englishTextBook(Camera camera, bool examination)
{
	unsigned int pageNumber = 1;
	Vector3 cubePosition = { 0.0f, 1.5f, -7.5f };
	float distance = distanceCalc(camera.position, cubePosition);

	float elapsedTime = 0.0f;
	float updateInterval = 1.0f;

	int minutes = 1;
	int seconds = 0;

	Rectangle next = { 1800,900,100,50 };
	Rectangle previous = { 50,900,100,50 };

	bool timerIsZero = 0;

	if (distance < 3.5f && IsKeyPressed(KEY_F))
	{
		EnableCursor();
		EndMode3D();
		while (!WindowShouldClose())
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
			default:
				pageNumber = 1;
				break;
			}

			elapsedTime += GetFrameTime();

			if (elapsedTime >= updateInterval) {
				// Decrement the timer
				if (seconds == 0) {
					if (minutes == 0)
					{
						timerIsZero = 1;
					}
					minutes--;
					seconds = 59;

				}
				else {
					seconds--;
				}

				elapsedTime = 0.0f; // Reset elapsed time
			}

			EndMode3D();
			// Draw timer
			DrawText(TextFormat("%02d:%02d", minutes, seconds), 930, 40, 50, RED);

			if (timerIsZero == 1)
			{
				DisableCursor();
				englishExaminationAlert();
				break;
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), previous))
			{
				pageNumber--;
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), next))
			{
				pageNumber++;
			}
			EndDrawing();
		}
	}
}

void geographyTextBook(Camera camera, bool examination)
{
	unsigned int pageNumber = 1;
	Vector3 cubePosition = { 0.0f, 1.5f, -7.5f };
	float distance = distanceCalc(camera.position, cubePosition);

	float elapsedTime = 0.0f;
	float updateInterval = 1.0f;

	int minutes = 1;
	int seconds = 0;

	Rectangle next = { 1800,900,100,50 };
	Rectangle previous = { 50,900,100,50 };

	bool timerIsZero = 0;

	if (distance < 3.5f && IsKeyPressed(KEY_F))
	{
		EnableCursor();
		EndMode3D();
		while (!WindowShouldClose())
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
			default:
				pageNumber = 1;
				break;
			}

			elapsedTime += GetFrameTime();

			if (elapsedTime >= updateInterval) {
				// Decrement the timer
				if (seconds == 0) {
					if (minutes == 0)
					{
						timerIsZero = 1;
					}
					minutes--;
					seconds = 59;

				}
				else {
					seconds--;
				}

				elapsedTime = 0.0f; // Reset elapsed time
			}

			EndMode3D();
			// Draw timer
			DrawText(TextFormat("%02d:%02d", minutes, seconds), 930, 40, 50, RED);

			if (timerIsZero == 1)
			{
				DisableCursor();
				geographyExaminationAlert();
				break;
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), previous))
			{
				pageNumber--;
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), next))
			{
				pageNumber++;
			}
			EndDrawing();
		}
	}
}


void historyTextBook(Camera camera, bool examination)
{
	unsigned int pageNumber = 1;
	Vector3 cubePosition = { 0.0f, 1.5f, -7.5f };
	float distance = distanceCalc(camera.position, cubePosition);

	float elapsedTime = 0.0f;
	float updateInterval = 1.0f;

	int minutes = 1;
	int seconds = 0;

	Rectangle next = { 1800,900,100,50 };
	Rectangle previous = { 50,900,100,50 };

	bool timerIsZero = 0;

	if ((distance < 3.5f && IsKeyPressed(KEY_F)) || examination == 1)
	{
		EnableCursor();
		EndMode3D();
		while (!WindowShouldClose())
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
				DrawText("History", 825, 100, 100, BLACK);
				DrawText("Author: Stoyan Hristov", 590, 200, 70, BLACK);

				DrawText("1. Beginning of World War II", 200, 320, 30, BLACK);
				DrawText("World War II officially began on September 1, 1939, when Germany invaded Poland.", 255, 370, 23, BLACK);

				DrawText("2. Invasion of Poland", 200, 450, 30, BLACK);
				DrawText("The country that invaded Poland, triggering the start of World War II, was Germany.", 255, 500, 23, BLACK);

				DrawText("3. Normandy Invasion", 200, 570, 30, BLACK);
				DrawText("The code name for the Allied invasion of Normandy on June 6, 1944, was Operation Overlord.", 255, 620, 23, BLACK);

				DrawText("4. United States Entry into WW II", 200, 700, 30, BLACK);
				DrawText("The United States entered World War II after the attack on Pearl Harbor by Japan on December 7, 1941.", 255, 750, 23, BLACK);
				break;
			case 2:
				DrawText("5. Leader of Nazi Germany", 200, 240, 30, BLACK);
				DrawText("The leader of Nazi Germany during World War II was Adolf Hitler.", 255, 290, 23, BLACK);

				DrawText("6. Axis Powers", 200, 370, 30, BLACK);
				DrawText("The Axis Powers during World War II consisted primarily of Germany, Italy, and Japan.", 255, 420, 23, BLACK);

				DrawText("7. Atomic Bomb", 200, 490, 30, BLACK);
				DrawText("The atomic bomb dropped on Hiroshima was named Little Boy.", 255, 540, 23, BLACK);

				DrawText("8. Supreme Commander of Allied Forces in Europe", 200, 620, 30, BLACK);
				DrawText("The Supreme Commander of the Allied Forces in Europe during World War II was Dwight D. Eisenhower.", 255, 670, 23, BLACK);

				DrawText("2", 975, 900, 25, BLACK);
				break;
			case 3:
				DrawText("9. Turning Point in the Pacific", 200, 240, 30, BLACK);
				DrawText("The Battle of Midway is considered the turning point of the war in the Pacific.", 255, 290, 23, BLACK);

				DrawText("10. Evacuation at Dunkirk", 200, 370, 30, BLACK);
				DrawText("Nazi Germany invaded France in 1940, leading to the evacuation at Dunkirk.", 255, 420, 23, BLACK);

				DrawText("11. German Air Force", 200, 490, 30, BLACK);
				DrawText("The German air force during World War II was called the Luftwaffe.", 255, 540, 23, BLACK);

				DrawText("12. Major Axis Powers", 200, 620, 30, BLACK);
				DrawText("The major Axis Powers during World War II were Germany, Italy, and Japan.", 255, 670, 23, BLACK);

				DrawText("3", 975, 900, 25, BLACK);
				break;
			case 4:
				DrawText("13. German Offensive Against the Soviet Union", 200, 240, 30, BLACK);
				DrawText("The German offensive against the Soviet Union in 1941 was named Operation Barbarossa.", 255, 290, 23, BLACK);

				DrawText("14. Last Major German Offensive", 200, 370, 30, BLACK);
				DrawText("The Battle of the Bulge marked the last major German offensive on the Western Front during World War II.", 255, 420, 23, BLACK);

				DrawText("15. Treaty Ending WWII in Europe", 200, 490, 30, BLACK);
				DrawText("The treaty that officially ended World War II in Europe was the Treaty of Versailles II.", 255, 540, 23, BLACK);

				DrawText("16. Purpose of the Yalta Conference", 200, 620, 30, BLACK);
				DrawText("The main purpose of the Yalta Conference in 1945 was to discuss post-war Europe.", 255, 670, 23, BLACK);

				DrawText("4", 975, 900, 25, BLACK);
				break;
			case 5:
				DrawText("17. Break of Molotov-Ribbentrop Pact", 200, 240, 30, BLACK);
				DrawText("Nazi Germany invaded Poland, breaking the Molotov-Ribbentrop Pact with the Soviet Union.", 255, 290, 23, BLACK);

				DrawText("18. Significance of the Battle of Britain", 200, 370, 30, BLACK);
				DrawText("The Battle of Britain prevented a German invasion of Britain.", 255, 420, 23, BLACK);

				DrawText("19. Nazi Concentration Camp", 200, 490, 30, BLACK);
				DrawText("The Nazi concentration camp where more than one million people were killed was Auschwitz.", 255, 540, 23, BLACK);

				DrawText("20. British Prime Minister", 200, 620, 30, BLACK);
				DrawText("The British Prime Minister during most of World War II was Winston Churchill.", 255, 670, 23, BLACK);

				DrawText("5", 975, 900, 25, BLACK);
				break;
			default:
				pageNumber = 1;
				break;
			}

			elapsedTime += GetFrameTime();

			if (elapsedTime >= updateInterval) {
				// Decrement the timer
				if (seconds == 0) {
					if (minutes == 0)
					{
						timerIsZero = 1;
					}
					minutes--;
					seconds = 59;

				}
				else {
					seconds--;
				}

				elapsedTime = 0.0f; // Reset elapsed time
			}

			EndMode3D();
			// Draw timer
			DrawText(TextFormat("%02d:%02d", minutes, seconds), 930, 40, 50, RED);

			if (timerIsZero == 1)
			{
				historyExam();
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), previous))
			{
				pageNumber--;
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), next))
			{
				pageNumber++;
			}
			EndDrawing();
		}
	}
}

void literatureTextBook(Camera camera, bool examination)
{
	unsigned int pageNumber = 1;
	Vector3 cubePosition = { 0.0f, 1.5f, -7.5f };
	float distance = distanceCalc(camera.position, cubePosition);

	float elapsedTime = 0.0f;
	float updateInterval = 1.0f;

	int minutes = 1;
	int seconds = 0;

	Rectangle next = { 1800,900,100,50 };
	Rectangle previous = { 50,900,100,50 };

	bool timerIsZero = 0;

	if (distance < 3.5f && IsKeyPressed(KEY_F))
	{
		EnableCursor();
		EndMode3D();
		while (!WindowShouldClose())
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
				DrawText("Literature", 725, 100, 100, BLACK);
				DrawText("Author: Stoyan Hristov", 590, 200, 70, BLACK);

				DrawText("1. Key Figures of Modernist Literature", 200, 320, 30, BLACK);
				DrawText("Virginia Woolf is considered one of the key figures of modernist literature, known for her innovative \n narrative techniques and exploration of consciousness.", 255, 370, 23, BLACK);

				DrawText("2. Modernist Stream-of-Consciousness Writing", 200, 450, 30, BLACK);
				DrawText("Ulysses by James Joyce is often cited as a prime example of modernist stream-of-consciousness writing, \n characterized by its interior monologue and fragmented narrative style.", 255, 500, 23, BLACK);

				DrawText("3. To the Lighthouse", 200, 570, 30, BLACK);
				DrawText("To the Lighthouse is a modernist novel written by Virginia Woolf, published in 1927. It explores themes of memory, \n perception, and the passage of time.", 255, 620, 23, BLACK);

				DrawText("4. Rejection of Traditional Forms", 200, 700, 30, BLACK);
				DrawText("Modernism is associated with the rejection of traditional forms and structures in literature, art, and culture, \n emphasizing experimentation and individualism.", 255, 750, 23, BLACK);
				break;
			case 2:
				DrawText("5. 1984 Protagonist", 200, 240, 30, BLACK);
				DrawText("The protagonist of George Orwell's dystopian novel 1984 is named Winston Smith.", 255, 290, 23, BLACK);

				DrawText("6. Authors with Socialist Themes", 200, 370, 30, BLACK);
				DrawText("George Orwell is known for his socialist themes and exploration \n of class struggle in works such as Animal Farm and 1984.", 255, 420, 23, BLACK);

				DrawText("7. T.S. Eliot's Modernist Poem", 200, 490, 30, BLACK);
				DrawText("The Waste Land is the influential modernist poem written by T.S. Eliot, \n published in 1922. It explores the fragmentation of modern life and the search for meaning in a post-war world.", 255, 540, 23, BLACK);

				DrawText("8. Mrs. Dalloway Author", 200, 620, 30, BLACK);
				DrawText("Mrs. Dalloway is a modernist novel written by Virginia Woolf, published in 1925. \n It follows a day in the life of Clarissa Dalloway as she prepares for a partyand reflects on her past.", 255, 670, 23, BLACK);

				DrawText("2", 975, 900, 25, BLACK);
				break;
			case 3:
				DrawText("9. Socialist Themes in Literature", 200, 240, 30, BLACK);
				DrawText("Animal Farm by George Orwell is a literary work that explores themes of socialism and the \n  Russian Revolution through the allegory of farm animals overthrowing their human masters.", 255, 290, 23, BLACK);

				DrawText("10. Waiting for Godot", 200, 370, 30, BLACK);
				DrawText("Waiting for Godot is a modernist play written by Samuel Beckett, first premiered in 1953.\n It features two characters, Vladimir and Estragon, \n waiting for the arrival of someone named Godot, exploring themes of existentialismand the human condition.", 255, 420, 23, BLACK);

				DrawText("11. Steppenwolf Author", 200, 520, 30, BLACK);
				DrawText("Steppenwolf is a novel written by Hermann Hesse, published in 1927. It explores themes of \n existentialism and socialism through the journey of its protagonist, Harry Haller, as he grapples with his dual nature", 255, 570, 23, BLACK);

				DrawText("12. Effects of Capitalism and Industrialization", 200, 630, 30, BLACK);
				DrawText("The Grapes of Wrath by John Steinbeck is a literary work that explores the effects of \n capitalism and industrialization on society, particularly through the experiences of the Joad family during the Great Depression.", 255, 680, 23, BLACK);

				DrawText("3", 975, 900, 25, BLACK);
				break;
			case 4:
				DrawText("13. The Sound and the Fury Author", 200, 240, 30, BLACK);
				DrawText("The Sound and the Fury is a modernist novel written by William Faulkner, published in 1929. \n It employs multiple narrators and nonlinear narrative structure to depict the decline of a Southern aristocratic family.", 255, 290, 23, BLACK);

				DrawText("14. A Portrait of the Artist as a Young Man", 200, 400, 30, BLACK);
				DrawText("A Portrait of the Artist as a Young Man is a modernist novel written by James Joyce, published in 1916.\n It follows the development of its protagonist, Stephen Dedalus,\n as he navigates the complexities of Irish society and his own artistic aspirations.", 255, 450, 23, BLACK);

				DrawText("15. Franz Kafka's Metamorphosis", 200, 540, 30, BLACK);
				DrawText("Metamorphosis is a modernist novella written by Franz Kafka, published in 1915. It follows the transformation of \n its protagonist, Gregor Samsa, into a giant insect and explores themes of alienation and existential dread", 255, 580, 23, BLACK);

				DrawText("16. Colonialism and Imperialism in Literature", 200, 660, 30, BLACK);
				DrawText("Things Fall Apart by Chinua Achebe is a literary work that explores the impact of colonialism and imperialism on \n society, particularly through the lens of Igbo culture in Nigeria.", 255, 710, 23, BLACK);

				DrawText("4", 975, 900, 25, BLACK);
				break;
			case 5:
				DrawText("17. The Trial Author", 200, 240, 30, BLACK);
				DrawText("The Trial is a modernist novel written by Franz Kafka, published posthumously in 1925. It follows the protagonist, \n Josef K., as he is prosecuted by a mysterious authority for a crime that is never revealed.", 255, 290, 23, BLACK);

				DrawText("18. Zora Neale Hurston's Novel", 200, 370, 30, BLACK);
				DrawText("Their Eyes Were Watching God is a modernist novel written by Zora Neale Hurston, published in 1937. It follows the \n life of its protagonist, Janie Crawford, as she navigates love, identity, and independence in the rural South.", 255, 420, 23, BLACK);

				DrawText("19. T.S. Eliot's The Love Song of J.Alfred Prufrock", 200, 490, 30, BLACK);
				DrawText("The Love Song of J. Alfred Prufrock is a modernist poem written by T.S.Eliot, published in 1915. It explores themes \n of alienation, indecision, and the passage of time through the perspective of its titular character.", 255, 540, 23, BLACK);

				DrawText("20. Jean-Paul Sartre's Nausea", 200, 620, 30, BLACK);
				DrawText("Nausea is a modernist novel written by Jean - Paul Sartre, published in 1938. It follows the existential crisis of \n its protagonist, Antoine Roquentin, as he grapples with the absurdity of existence and the nature of freedom.", 255, 670, 23, BLACK);

				DrawText("5", 975, 900, 25, BLACK);
				break;
			default:
				pageNumber = 1;
				break;
			}

			elapsedTime += GetFrameTime();

			if (elapsedTime >= updateInterval) {
				// Decrement the timer
				if (seconds == 0) {
					if (minutes == 0)
					{
						timerIsZero = 1;
					}
					minutes--;
					seconds = 59;

				}
				else {
					seconds--;
				}

				elapsedTime = 0.0f; // Reset elapsed time
			}

			EndMode3D();
			// Draw timer
			DrawText(TextFormat("%02d:%02d", minutes, seconds), 930, 40, 50, RED);

			if (timerIsZero == 1)
			{
				DisableCursor();
				break;
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), previous))
			{
				pageNumber--;
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), next))
			{
				pageNumber++;
			}
			EndDrawing();
		}
	}
}