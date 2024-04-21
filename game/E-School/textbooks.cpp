#include "textbooks.h"
#include "exams.h"

float distanceCalc(Vector3 a, Vector3 b) {
    float distanceX = b.x - a.x;
    float distanceY = b.y - a.y;
    float distanceZ = b.z - a.z;
    return sqrt(distanceX * distanceX + distanceY * distanceY + distanceZ * distanceZ);
}


void prgTextBook(Camera camera, bool examination)
{
	Vector3 cubePosition = { 19.5f,0.2f,7.0f };
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
				DrawText("English", 825, 100, 100, BLACK);
				DrawText("Author: Stoyan Hristov", 590, 200, 70, BLACK);

				DrawText("1. Present Perfect Tense:", 200, 320, 30, BLACK);
				DrawText("Used to express actions that occurred at an unspecified time in the past, or actions with relevance to the present. \n Example: I have visited Paris.", 255, 370, 23, BLACK);

				DrawText("2.Present Perfect Continuous Tense:", 200, 450, 30, BLACK);
				DrawText("Used to indicate actions that started in the past and continue up to the present moment. \n Example: He has been studying for two hours.", 255, 500, 23, BLACK);

				DrawText("3. Past Continuous Tense:", 200, 570, 30, BLACK);
				DrawText("Used to describe actions that were ongoing in the past at a specific moment. \n Example: She was reading a book when the phone rang.", 255, 620, 23, BLACK);

				break;
			case 2:
				DrawText("4. Past Perfect Tense:", 200, 240, 30, BLACK);
				DrawText("Used to describe an action that occurred before another action in the past. \n Example: She had already left when I arrived.", 255, 290, 23, BLACK);

				DrawText("5. Past Perfect Continuous Tense:", 200, 370, 30, BLACK);
				DrawText("Used to express the duration of an activity that started in the past and continued up to a certain point in the past. \n Example: They had been waiting for over an hour when the train finally arrived.", 255, 420, 23, BLACK);

				DrawText("6. Future Continuous Tense:", 200, 490, 30, BLACK);
				DrawText("Used to describe actions that will be ongoing at a specific future time. \n Example: She will be sleeping when you arrive.", 255, 540, 23, BLACK);

				DrawText("2", 975, 900, 25, BLACK);
				break;
			case 3:
				DrawText("7. Future Perfect Tense:", 200, 240, 30, BLACK);
				DrawText("Used to describe actions that will be completed before a specific point in the future. \n Example: They will have finished the project by next week.", 255, 290, 23, BLACK);

				DrawText("8. Future Perfect Continuous Tense:", 200, 370, 30, BLACK);
				DrawText("Used to describe the duration of an activity that will be ongoing up to a certain point in the future. \n Example: By December, they will have been living in the city for ten years.", 255, 420, 23, BLACK);

				DrawText("9.Modal Verbs:", 200, 490, 30, BLACK);
				DrawText("Expresses necessity, possibility, ability, permission, obligation, or advice. \n Example: You should study for the exam.", 255, 540, 23, BLACK);

				DrawText("3", 975, 900, 25, BLACK);
				break;
			case 4:
				DrawText("10. Questions:", 200, 240, 30, BLACK);
				DrawText("Inverting the subject and auxiliary verb, or using question words such as who, what, where, when, why, how. \n Example: Have you finished your homework ? ", 255, 290, 23, BLACK);

				DrawText("11. Passive Voice:", 200, 370, 30, BLACK);
				DrawText("Used when the focus is on the action, not the doer. \n Example: The report was written by Sarah.", 255, 420, 23, BLACK);

				DrawText("12. Reported Speech:", 200, 490, 30, BLACK);
				DrawText("Used to report what someone else said without quoting them directly. \n Example: He said that he was going to the store.", 255, 540, 23, BLACK);

				DrawText("4", 975, 900, 25, BLACK);
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
				DrawText("Geography", 825, 100, 100, BLACK);
				DrawText("Author: Stoyan Hristov", 590, 200, 70, BLACK);

				DrawText("1. Largest Continent by Land Area", 200, 320, 30, BLACK);
				DrawText("Asia is the largest continent by land area, covering approximately 30% of the Earth's land surface.", 255, 370, 23, BLACK);

				DrawText("2.Longest River in the World", 200, 450, 30, BLACK);
				DrawText("The Nile River is the longest river in the world, with a length of approximately 6,650 kilometers (4,130 miles).", 255, 500, 23, BLACK);

				DrawText("3. Largest Ocean by Surface Area", 200, 570, 30, BLACK);
				DrawText("The Pacific Ocean is the largest ocean by surface area, covering approximately 63 million square miles (165 million square kilometers).", 255, 620, 23, BLACK);

				DrawText("4. Capital City of France", 200, 700, 30, BLACK);
				DrawText("Paris is the capital city of France, known for its iconic landmarks such as the Eiffel Tower and Louvre Museum.", 255, 750, 23, BLACK);
				break;
			case 2:
				DrawText("5. Mountain Range in South America", 200, 240, 30, BLACK);
				DrawText("The Andes is the longest continental mountain range in the world, stretching along the western coast of South America.", 255, 290, 23, BLACK);

				DrawText("6. Largest Desert in the World", 200, 370, 30, BLACK);
				DrawText("The Sahara Desert is the largest hot desert in the world, covering much of North Africa and spanning approximately 9.2 million square kilometers (3.6 million square miles).", 255, 420, 23, BLACK);

				DrawText("7. Land of the Rising Sun", 200, 490, 30, BLACK);
				DrawText("Japan is known as the Land of the Rising Sun, a nickname derived from its name in Japanese, Nihon or Nippon, which means origin of the sun.", 255, 540, 23, BLACK);

				DrawText("8. Tallest Mountain in the World", 200, 620, 30, BLACK);
				DrawText("Mount Everest is the tallest mountain in the world, with a peak elevation of 8,848.86 meters (29,031.7 feet) above sea level.", 255, 670, 23, BLACK);

				DrawText("2", 975, 900, 25, BLACK);
				break;
			case 3:
				DrawText("9. Home to the Amazon Rainforest", 200, 240, 30, BLACK);
				DrawText("South America is home to the Amazon Rainforest, the largest tropical rainforest in the world, known for its rich biodiversity.", 255, 290, 23, BLACK);

				DrawText("10. Capital City of Australia", 200, 370, 30, BLACK);
				DrawText("Canberra is the capital city of Australia, located in the Australian Capital Territory.", 255, 420, 23, BLACK);

				DrawText("11.Land of the Midnight Sun", 200, 490, 30, BLACK);
				DrawText("Norway is known as the Land of the Midnight Sun, as regions within the Arctic Circle experience continuous daylight during summer months.", 255, 540, 23, BLACK);

				DrawText("12. Longest Mountain Range in the World", 200, 620, 30, BLACK);
				DrawText("The Mid-Atlantic Ridge is the longest mountain range in the world, extending for approximately 16,000 kilometers (10,000 miles) along the ocean floor.", 255, 670, 23, BLACK);

				DrawText("3", 975, 900, 25, BLACK);
				break;
			case 4:
				DrawText("13. Capital City of Canada", 200, 240, 30, BLACK);
				DrawText("Ottawa is the capital city of Canada, located in the province of Ontario.", 255, 290, 23, BLACK);

				DrawText("14. Largest Lake by Surface Area in Africa", 200, 370, 30, BLACK);
				DrawText("Lake Victoria is the largest lake by surface area in Africa, spanning approximately 68,800 square kilometers (26,600 square miles).", 255, 420, 23, BLACK);

				DrawText("15. Largest Country by Land Area", 200, 490, 30, BLACK);
				DrawText("Russia is the largest country by land area, covering approximately 17.1 million square kilometers (6.6 million square miles).", 255, 540, 23, BLACK);

				DrawText("16. Capital City of Brazil", 200, 620, 30, BLACK);
				DrawText("Brasília is the capital city of Brazil, located in the Federal District.", 255, 670, 23, BLACK);

				DrawText("4", 975, 900, 25, BLACK);
				break;
			case 5:
				DrawText("17. Pearl of the Indian Ocean", 200, 240, 30, BLACK);
				DrawText("Sri Lanka is known as the Pearl of the Indian Ocean for its natural beauty and cultural heritage.", 255, 290, 23, BLACK);

				DrawText("18. Largest Island in the Mediterranean Sea", 200, 370, 30, BLACK);
				DrawText("Cyprus is the largest island in the Mediterranean Sea, located in the eastern part of the basin.", 255, 420, 23, BLACK);

				DrawText("19. Country on the Iberian Peninsula", 200, 490, 30, BLACK);
				DrawText("Spain is located on the Iberian Peninsula, along with Portugal and a small portion of Andorra.", 255, 540, 23, BLACK);

				DrawText("20.Capital City of China", 200, 620, 30, BLACK);
				DrawText("Beijing is the capital city of China, known for its historical landmarks such as the Forbidden City and the Great Wall of China.", 255, 670, 23, BLACK);

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
				DisableCursor();
				historyExaminationAlert();
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
				literatureExaminationAlert();
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

	if ((distance < 3.5f && IsKeyPressed(KEY_F)) || examination==1)
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
				DrawText("Biology", 725, 100, 100, BLACK);
				DrawText("Author: Stoyan Hristov", 590, 200, 70, BLACK);

				DrawText("1. Function of Carbohydrates", 200, 320, 30, BLACK);
				DrawText("Carbohydrates primarily serve as a source of energy for living organisms. They are broken down into glucose, which is used as fuel for cellular processes.", 255, 370, 23, BLACK);

				DrawText("2. Main Energy Currency of the Cell", 200, 450, 30, BLACK);
				DrawText("Adenosine triphosphate (ATP) serves as the main energy currency of the cell, storing and releasing energy for cellular processes.", 255, 500, 23, BLACK);

				DrawText("3. Structural Unit of Proteins", 200, 570, 30, BLACK);
				DrawText("Amino acids are the structural units of proteins. They are linked together by peptide bonds to form polypeptide chains, which fold into specific three-dimensional structures.", 255, 620, 23, BLACK);

				DrawText("4. Function of Lipids", 200, 700, 30, BLACK);
				DrawText("Lipids serve multiple functions in the human body, including energy storage, insulation, and hormone synthesis. They also form the structural basis of cell membranes.", 255, 750, 23, BLACK);
				break;
			case 2:
				DrawText("5. Role of Enzymes", 200, 240, 30, BLACK);
				DrawText("Enzymes are biological catalysts that accelerate chemical reactions in living organisms. They lower the activation energy required for reactions to occur, thus speeding up metabolic processes.", 255, 290, 23, BLACK);

				DrawText("6. Water-Soluble Vitamin for Collagen Synthesis", 200, 370, 30, BLACK);
				DrawText("Vitamin C is a water-soluble vitamin essential for collagen synthesis, wound healing, and maintaining connective tissue health.", 255, 420, 23, BLACK);

				DrawText("7. Primary Function of Lipids", 200, 490, 30, BLACK);
				DrawText("Lipids primarily serve as energy storage molecules in the human body. They provide a concentrated source of energy and play a role in insulation and protection of vital organs.", 255, 540, 23, BLACK);

				DrawText("8. Organelle Responsible for Protein Synthesis", 200, 620, 30, BLACK);
				DrawText("Ribosomes are the cellular organelles responsible for protein synthesis in eukaryotic cells. They are composed of RNA and protein and are found in the cytoplasm and on the rough endoplasmic reticulum.", 255, 670, 23, BLACK);

				DrawText("2", 975, 900, 25, BLACK);
				break;
			case 3:
				DrawText("9. Role of Nucleic Acids", 200, 240, 30, BLACK);
				DrawText("Nucleic acids, such as DNA and RNA, serve as the genetic information storage and transmission molecules in living organisms. They encode the instructions for building proteins and regulate cellular processes.", 255, 290, 23, BLACK);

				DrawText("10. Body's Primary Source of Energy", 200, 370, 30, BLACK);
				DrawText("Carbohydrates are the body's primary source of energy, providing fuel for cellular activities and metabolic processes.", 255, 420, 23, BLACK);

				DrawText("11. Function of DNA", 200, 520, 30, BLACK);
				DrawText("DNA (deoxyribonucleic acid) serves as the repository of genetic information in cells. It contains the instructions for synthesizing proteins and is passed from parent to offspring during reproduction.", 255, 570, 23, BLACK);

				DrawText("12. Structural Unit of Nucleic Acids", 200, 630, 30, BLACK);
				DrawText("Nucleic acids are composed of nucleotides, which consist of a sugar molecule, phosphate group, and nitrogenous base. These nucleotides polymerize to form DNA and RNA.", 255, 680, 23, BLACK);

				DrawText("3", 975, 900, 25, BLACK);
				break;
			case 4:
				DrawText("13. Role of RNA in Protein Synthesis", 200, 240, 30, BLACK);
				DrawText("RNA (ribonucleic acid) acts as a messenger between DNA and the ribosome during protein synthesis. It carries the genetic information encoded in DNA to the ribosome, where it is used to assemble proteins.", 255, 290, 23, BLACK);

				DrawText("14. Function of Proteins", 200, 400, 30, BLACK);
				DrawText("Proteins have diverse functions in the human body, including building and repairing tissues, serving as enzymes and hormones, and facilitating transport of molecules across cell membranes.", 255, 450, 23, BLACK);

				DrawText("15. Function of Chlorophyll", 200, 540, 30, BLACK);
				DrawText("Chlorophyll is a pigment found in chloroplasts that absorbs light energy for the process of photosynthesis in plants. It captures sunlight and converts it into chemical energy used to synthesize glucose from carbon dioxide and water.", 255, 580, 23, BLACK);

				DrawText("16. Role of Vitamin K", 200, 660, 30, BLACK);
				DrawText("Vitamin K is a fat-soluble vitamin essential for blood clotting and bone health. It plays a critical role in the synthesis of clotting factors and helps maintain bone density.", 255, 710, 23, BLACK);

				DrawText("4", 975, 900, 25, BLACK);
				break;
			case 5:
				DrawText("17. Function of Carbohydrates in Cellular Respiration", 200, 240, 30, BLACK);
				DrawText("Carbohydrates serve as a primary source of energy during cellular respiration. Glucose, derived from carbohydrates, is broken down in the presence of oxygen to produce ATP, the energy currency of the cell.", 255, 290, 23, BLACK);

				DrawText("18. Function of Vitamin B12", 200, 370, 30, BLACK);
				DrawText("Vitamin B12 is a water-soluble vitamin essential for red blood cell formation and neural function. It is involved in DNA synthesis and plays a role in maintaining the health of the nervous system.", 255, 420, 23, BLACK);

				DrawText("19. Function of Proteins in Cell Membranes", 200, 490, 30, BLACK);
				DrawText("Proteins in cell membranes serve various functions, including facilitating transport of molecules across the membrane, cell signaling, and cell adhesion.", 255, 540, 23, BLACK);

				DrawText("20. Role of Electrolytes", 200, 620, 30, BLACK);
				DrawText("Electrolytes are minerals that dissociate into ions in solution and play crucial roles in maintaining proper fluid balance, nerve function, and muscle contraction in the body.", 255, 670, 23, BLACK);

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
				literatureExaminationAlert();
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


void chemistryTextBook(Camera camera, bool examination)
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
				DrawText("Chemistry", 825, 100, 100, BLACK);
				DrawText("Author: Stoyan Hristov", 590, 200, 70, BLACK);

				DrawText("1. Chemical Symbol for Water", 200, 320, 30, BLACK);
				DrawText("The chemical symbol for water is H2O, representing two hydrogen atoms bonded to one oxygen atom.", 255, 370, 23, BLACK);

				DrawText("2.Essential Element for Organic Life", 200, 450, 30, BLACK);
				DrawText("Carbon is essential for organic life and is the main component of organic molecules, forming the backbone of many biological compounds.", 255, 500, 23, BLACK);

				DrawText("3. Smallest Unit of an Element", 200, 570, 30, BLACK);
				DrawText("An atom is the smallest unit of an element that retains its chemical properties. Atoms consist of a nucleus containing protons and neutrons, surrounded by electrons.", 255, 620, 23, BLACK);

				DrawText("4. Chemical Symbol for Iron", 200, 700, 30, BLACK);
				DrawText("The chemical symbol for iron is Fe, derived from its Latin name Ferrum.", 255, 750, 23, BLACK);
				break;
			case 2:
				DrawText("5. Process of Sublimation", 200, 240, 30, BLACK);
				DrawText("Sublimation is the process by which a solid changes directly into a gas without passing through the liquid state. Examples include dry ice (solid carbon dioxide) subliming into carbon dioxide gas.", 255, 290, 23, BLACK);

				DrawText("6. Chemical Formula for Carbon Dioxide", 200, 370, 30, BLACK);
				DrawText("The chemical formula for carbon dioxide is CO2, representing one carbon atom bonded to two oxygen atoms.", 255, 420, 23, BLACK);

				DrawText("7. Noble Gases", 200, 490, 30, BLACK);
				DrawText("Noble gases are a group of elements that are generally inert and have full valence electron shells. These include helium (He), neon (Ne), argon (Ar), krypton (Kr), xenon (Xe), and radon (Rn).", 255, 540, 23, BLACK);

				DrawText("8. pH Value of Pure Water", 200, 620, 30, BLACK);
				DrawText("Pure water has a pH value of 7 at room temperature, indicating neutrality. It is neither acidic nor basic.", 255, 670, 23, BLACK);

				DrawText("2", 975, 900, 25, BLACK);
				break;
			case 3:
				DrawText("9. Particle with Positive Charge", 200, 240, 30, BLACK);
				DrawText("The proton is a subatomic particle with a positive charge. It is found in the nucleus of an atom and contributes to its atomic number.", 255, 290, 23, BLACK);

				DrawText("10. Process of Evaporation", 200, 370, 30, BLACK);
				DrawText("Evaporation is the process by which a liquid changes into a gas at temperatures below its boiling point. It occurs at the surface of the liquid.", 255, 420, 23, BLACK);

				DrawText("11.Chemical Symbol for Gold", 200, 490, 30, BLACK);
				DrawText("The chemical symbol for gold is Au, derived from its Latin name Aurum.", 255, 540, 23, BLACK);

				DrawText("12. Chemical Formula for Table Salt", 200, 620, 30, BLACK);
				DrawText("The chemical formula for table salt (sodium chloride) is NaCl, representing one sodium ion bonded to one chloride ion.", 255, 670, 23, BLACK);

				DrawText("3", 975, 900, 25, BLACK);
				break;
			case 4:
				DrawText("13. Greenhouse Gas", 200, 240, 30, BLACK);
				DrawText("Carbon dioxide (CO2) is a greenhouse gas, contributing to the greenhouse effect and global warming when present in the atmosphere in high concentrations.", 255, 290, 23, BLACK);

				DrawText("14. Atomic Number of Oxygen", 200, 370, 30, BLACK);
				DrawText("The atomic number of oxygen is 8, indicating the number of protons in its nucleus.", 255, 420, 23, BLACK);

				DrawText("15. Chemical Formula for Methane", 200, 490, 30, BLACK);
				DrawText("The chemical formula for methane is CH4, representing one carbon atom bonded to four hydrogen atoms.", 255, 540, 23, BLACK);

				DrawText("16. Halogen", 200, 620, 30, BLACK);
				DrawText("Chlorine (Cl) is a halogen element, belonging to Group 17 (Group VIIA) of the periodic table.", 255, 670, 23, BLACK);

				DrawText("4", 975, 900, 25, BLACK);
				break;
			case 5:
				DrawText("17. Chemical Formula for Sulfuric Acid", 200, 240, 30, BLACK);
				DrawText("The chemical formula for sulfuric acid is H2SO4, representing two hydrogen atoms, one sulfur atom, and four oxygen atoms.", 255, 290, 23, BLACK);

				DrawText("18. Chemical Symbol for Lead", 200, 370, 30, BLACK);
				DrawText("The chemical symbol for lead is Pb, derived from its Latin name Plumbum.", 255, 420, 23, BLACK);

				DrawText("19. Particle with Neutral Charge", 200, 490, 30, BLACK);
				DrawText("The neutron is a subatomic particle with a neutral charge. It is found in the nucleus of an atom alongside protons.", 255, 540, 23, BLACK);

				DrawText("20.Chemical Formula for Hydrogen Peroxide", 200, 620, 30, BLACK);
				DrawText("The chemical formula for hydrogen peroxide is H2O2, representing two hydrogen atoms bonded to two oxygen atoms.", 255, 670, 23, BLACK);

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
				chemistryExaminationAlert();
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

void physicsTextBook(Camera camera, bool examination)
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
				DrawText("Physics", 825, 100, 100, BLACK);
				DrawText("Author: Stoyan Hristov", 590, 200, 70, BLACK);

				DrawText("1. SI Unit of Force", 200, 320, 30, BLACK);
				DrawText("The SI unit of force is the Newton (N). One Newton is defined as the force required to accelerate a mass of one kilogram by one meter per second squared.", 255, 370, 23, BLACK);

				DrawText("2.Acceleration Due to Gravity on Earth", 200, 450, 30, BLACK);
				DrawText("The acceleration due to gravity on Earth's surface is approximately 9.8 meters per second squared (m/s^2).", 255, 500, 23, BLACK);

				DrawText("3. Newton's First Law of Motion", 200, 570, 30, BLACK);
				DrawText("Newton's First Law of Motion states that an object at rest will remain at rest, and an object in motion will remain in motion with constant velocity unless acted upon by an external force.", 255, 620, 23, BLACK);

				DrawText("4. Formula for Kinetic Energy", 200, 700, 30, BLACK);
				DrawText("The formula for calculating kinetic energy (KE) is KE = 1/2mv^2, where m is the mass of the object and v is its velocity.", 255, 750, 23, BLACK);
				break;
			case 2:
				DrawText("5. Unit of Power", 200, 240, 30, BLACK);
				DrawText("The unit of power is the Watt (W), which is equivalent to one joule per second.", 255, 290, 23, BLACK);

				DrawText("6. Newton's Second Law of Motion", 200, 370, 30, BLACK);
				DrawText("Newton's Second Law of Motion states that the force acting on an object is equal to the mass of the object multiplied by its acceleration: F = ma.", 255, 420, 23, BLACK);

				DrawText("7. Law of Conservation of Energy", 200, 490, 30, BLACK);
				DrawText("The Law of Conservation of Energy states that the total energy of an isolated system remains constant over time, implying that energy can neither be created nor destroyed, only transformed from one form to another.", 255, 540, 23, BLACK);

				DrawText("8. Formula for Gravitational Potential Energy", 200, 620, 30, BLACK);
				DrawText("The formula for calculating gravitational potential energy (PE) near the Earth's surface is PE = mgh, where m is the mass, g is the acceleration due to gravity, and h is the height above the reference point.", 255, 670, 23, BLACK);

				DrawText("2", 975, 900, 25, BLACK);
				break;
			case 3:
				DrawText("9. Unit of Electric Charge", 200, 240, 30, BLACK);
				DrawText("The unit of electric charge is the Coulomb (C). One Coulomb is equivalent to the charge transported by a constant current of one ampere in one second.", 255, 290, 23, BLACK);

				DrawText("10. Speed of Light in Vacuum", 200, 370, 30, BLACK);
				DrawText("The speed of light in a vacuum is approximately 3 × 10^8 meters per second (m/s).", 255, 420, 23, BLACK);

				DrawText("11.First Law of Thermodynamics", 200, 490, 30, BLACK);
				DrawText("The First Law of Thermodynamics, also known as the Law of Conservation of Energy, states that the total energy of an isolated system remains constant over time.", 255, 540, 23, BLACK);

				DrawText("12. Formula for Work Done", 200, 620, 30, BLACK);
				DrawText("The formula for calculating work done (W) by a constant force on an object is W = Fd, where F is the magnitude of the force and d is the displacement of the object in the direction of the force.", 255, 670, 23, BLACK);

				DrawText("3", 975, 900, 25, BLACK);
				break;
			case 4:
				DrawText("13. Unit of Electric Current", 200, 240, 30, BLACK);
				DrawText("The SI unit of electric current is the Ampere (A). One Ampere is defined as the flow of one Coulomb of charge per second.", 255, 290, 23, BLACK);

				DrawText("14. Newton's Third Law of Motion", 200, 370, 30, BLACK);
				DrawText("Newton's Third Law of Motion states that for every action, there is an equal and opposite reaction.", 255, 420, 23, BLACK);

				DrawText("15. Formula for Frequency of a Wave", 200, 490, 30, BLACK);
				DrawText("The formula for calculating the frequency (f) of a wave is f = 1/λ, where λ (lambda) is the wavelength of the wave.", 255, 540, 23, BLACK);

				DrawText("16. Law of Conservation of Charge", 200, 620, 30, BLACK);
				DrawText("The Law of Conservation of Charge states that the total electric charge within a closed system remains constant over time.", 255, 670, 23, BLACK);

				DrawText("4", 975, 900, 25, BLACK);
				break;
			case 5:
				DrawText("17. Unit of Electric Potential Difference", 200, 240, 30, BLACK);
				DrawText("The unit of electric potential difference is the Volt (V). One Volt is equivalent to one joule per Coulomb.", 255, 290, 23, BLACK);

				DrawText("18. Formula for Period of a Wave", 200, 370, 30, BLACK);
				DrawText("The period (T) of a wave is the time taken for one complete cycle of the wave. The formula for calculating the period is T = 1/f, where f is the frequency of the wave.", 255, 420, 23, BLACK);

				DrawText("19. SI Unit of Pressure", 200, 490, 30, BLACK);
				DrawText("The SI unit of pressure is the Pascal (Pa). One Pascal is equal to one Newton per square meter.", 255, 540, 23, BLACK);

				DrawText("20. Boyle's Law", 200, 620, 30, BLACK);
				DrawText("Boyle's Law states that the pressure of a given mass of gas is inversely proportional to its volume at constant temperature.", 255, 670, 23, BLACK);

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
				physicsExaminationAlert();
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