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
	
	Rectangle gameButton = { 600,260,300,300 };
	Rectangle textButton = { 1000,260,300,300 };

	float elapsedTime = 0.0f;
	float updateInterval = 1.0f;


	int minutes = 1;
	int seconds = 0;
	bool menu = 1;
	bool game = 0;
	bool book1 = 0;
	Rectangle next = { 1800,900,100,50 };
	Rectangle previous = { 50,900,100,50 };

	bool timerIsZero = 0;
	

	if (distance < 3.5f && IsKeyPressed(KEY_F))
	{
		Texture2D bookPic = LoadTexture("textures/book.png");
		Texture2D gamePic = LoadTexture("textures/game.png");
		Texture2D book = LoadTexture("../images/book.png");
	    Font font = LoadFont("textures/font.ttf");
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

				DrawTexture(bookPic, 1000, 260, WHITE);
				DrawTexture(gamePic, 600, 300, WHITE);
			}

			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), gameButton))
			{
				menu = 0;
				game = 1;
			}
			if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) && CheckCollisionPointRec(GetMousePosition(), textButton))
			{
				menu = 0;
				book1 = 1;
			}
			if (game == 1)
			{
				selectGame();
			}
			if (book1 == 1)
			{
				DrawRectangleRec(previous, BLUE);
				DrawRectangleRec(next, BLUE);

				DrawTexture(book, 0, 0, WHITE);

				DrawTextEx(font, "previous", { 50, 915 }, 20, 1.5f, BLACK);
				DrawTextEx(font, "next", { 1800, 915 }, 20, 1.5f, BLACK);
				switch (pageNumber)
				{
				case 1:
					DrawTextEx(font, "Programming", { 785, 100 }, 100, 1.5f, BLACK);

					DrawTextEx(font, "1.Output Hello World in C++:", { 200, 320 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "To output Hello World in C++, you \n would typically use the `cout` statement from \n the `iostream` library. The correct syntax is \n cout << Hello World;.", { 255, 370 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "2.C++ is an alias of C#:", { 200, 530 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "C++ and C# are distinct programming \n languages with different syntax, semantics, \n and purposes. C++ is not an alias of C#.", { 255, 580 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "3.Insert COMMENTS in C++ code:", { 1100, 320 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, single-line comments \n are denoted by `//`, and multi-line comments are \n enclosed between `/*` and `*/`.", { 1100, 370 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "4.Data type for storing text:", { 1100, 520 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, the data type used to \n store text is `std::string`. So, the correct \n option is c) string.", { 1100, 570 }, 23, 1.5f, BLACK);
					break;
				case 2:
					DrawTextEx(font, "5.Create a variable with the numeric value 5:", { 200, 320 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "To create a variable with the numeric \n value 5, you would use the `int` data type. \n The correct syntax is `int x = 5;`.", { 255, 370 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "6.Create a variable with the floating number 2.8:", { 200, 530 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "To create a variable with the \n floating-point number 2.8, you would use the `double` \n data type. The correct syntax is \n `double x = 2.8;`.", { 255, 580 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "7.Method to find the length of a string:", { 1100, 320 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, you can find the length of a string \n using the `length()` method of the `std::string` \n class. So, the correct option is b) length().", { 1100, 370 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "8.Operator used to add two values:", { 1100, 520 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, the operator used to \n add two values is `+`.", { 1100, 570 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "2", { 975, 900 }, 25, 1.5f, BLACK);
					break;
				case 3:
					DrawTextEx(font, "9.String variable surrounded by single quotes:", { 200, 320 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, string literals are \n surrounded by double quotes (`" "`), not \n single quotes (`' '`).", { 255, 370 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "10.Header file for input and output objects:", { 200, 530 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, the header file for input and \n output objects is `<iostream>`. So, the correct option \n is d) #include <iostream>.", { 255, 580 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "11.Operator used to compare two values:", { 1100, 320 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, the operator used to compare \n two values for equality is `==`.", { 1100, 370 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "12.Index starting number:", { 1100, 520 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, array indices start from 0.", { 1100, 570 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "3", { 975, 900 }, 25, 1.5f, BLACK);
					break;
				case 4:
					DrawTextEx(font, "13.Keyword to create a class in C++:", { 200, 320 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, the keyword used to create a class is `class`.", { 255, 370 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "14.Inheritance in C++:", { 200, 530 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, it is possible to inherit attributes \n and methods from one class to another \n using inheritance.", { 255, 580 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "15.Operator to multiply numbers:", { 1100, 320 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, the operator used to \n multiply numbers is `*`.", { 1100, 370 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "16.Create a reference variable of an existing variable:", { 1100, 520 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "To create a reference variable of an \n existing variable in C++, you would \n use the `&` operator.", { 1100, 570 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "4", { 975, 900 }, 25, 1.5f, BLACK);
					break;
				case 5:
					DrawTextEx(font, "17.Start writing an if statement in C++:", { 200, 320 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "To start writing an if statement in C++, you \n would use the syntax `if (condition)`, where `condition` \n is the expression to be evaluated.", { 255, 370 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "18.Keyword to return a value inside a method:", { 200, 530 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, the keyword used \n to return a value inside a method \n is `return`.", { 255, 580 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "19.Statement to stop a loop:", { 1100, 320 }, 30, 1.5f, BLACK);
					DrawTextEx(font, "In C++, the `break` statement is \n used to exit a loop prematurely.", { 1100, 370 }, 23, 1.5f, BLACK);

					DrawTextEx(font, "5", { 975, 900 }, 25, 1.5f, BLACK);
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
	

	if ((distance < 3.5f && IsKeyPressed(KEY_F)) || examination == 1)
	{
		EnableCursor();
		EndMode3D();
        Texture2D book = LoadTexture("../images/book.png");

	    Font font = LoadFont("textures/font.ttf");
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(WHITE);

			DrawTexture(book, 0, 0, WHITE);

			DrawRectangleRec(previous, BLUE);
			DrawRectangleRec(next, BLUE);

			DrawTextEx(font, "previous", { 50, 915 }, 20, 1.5f, BLACK);
			DrawTextEx(font, "next", { 1800, 915 }, 20, 1.5f, BLACK);
			switch (pageNumber)
			{
			case 1:
				DrawTextEx(font, "English", { 815, 100 }, 100, 1.5f, BLACK);

				DrawTextEx(font, "1. Present Perfect Tense:", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Used to express actions that occurred \n at an unspecified time in the past, \n or actions with relevance to the present. \n Example: I have visited Paris.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2.Present Perfect Continuous Tense:", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Used to indicate actions that started in \n the past and continue up to the present moment. \n Example: He has been studying for two hours.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3. Past Continuous Tense:", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Used to describe actions that were \n ongoing in the past at a specific moment. \n Example: She was reading a book when the phone rang.", { 1100, 370 }, 23, 1.5f, BLACK);

				break;
			case 2:
				DrawTextEx(font, "4. Past Perfect Tense:", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Used to describe an action that \n occurred before another action in the past. \n Example: She had already left when I arrived.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "5. Past Perfect Continuous Tense:", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Used to express the duration of an activity that started \n in the past and continued up to a certain point in the past. \n Example: They had been waiting for over an hour \n when the train finally arrived.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "6. Future Continuous Tense:", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Used to describe actions that will \n be ongoing at a specific future time. \n Example: She will be sleeping when you arrive.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 3:
				DrawTextEx(font, "7. Future Perfect Tense:", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Used to describe actions that will be completed \n before a specific point in the future. \n Example: They will have finished the project by next week.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "8. Future Perfect Continuous Tense:", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Used to describe the duration of an activity \n that will be ongoing up to a certain point \n in the future. Example: By December, they \n will have been living \n in the city for ten years.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "9.Modal Verbs:", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Expresses necessity, possibility,\n ability, permission, obligation, or advice. \n Example: You should study for the exam.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 4:
				DrawTextEx(font, "10. Questions:", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Inverting the subject and auxiliary verb, or using \n question words such as who, what, where, when, why, how. \n Example: Have you finished your homework ? ", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "11. Passive Voice:", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Used when the focus is on the action, not the doer. \n Example: The report was written by Sarah.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "12. Reported Speech:", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Used to report what someone \n else said without quoting them directly. \n Example: He said that he was going to the store.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4", { 975, 900 }, 25, 1.5f, BLACK);
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
	

	if ((distance < 3.5f && IsKeyPressed(KEY_F)) || examination == 1)
	{
		EnableCursor();
		EndMode3D();
		Texture2D book = LoadTexture("../images/book.png");
	    Font font = LoadFont("textures/font.ttf");
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(WHITE);

			DrawTexture(book, 0, 0, WHITE);

			DrawRectangleRec(previous, BLUE);
			DrawRectangleRec(next, BLUE);

			DrawTextEx(font, "previous", { 50, 915 }, 20, 1.5f, BLACK);
			DrawTextEx(font, "next", { 1800, 915 }, 20, 1.5f, BLACK);
			switch (pageNumber)
			{
			case 1:
				DrawTextEx(font, "Geography", { 825, 100 }, 100, 1.5f, BLACK);

				DrawTextEx(font, "1. Largest Continent by Land Area", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Asia is the largest continent by land area, \n covering approximately 30% of the Earth's \n land surface.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2.Longest River in the World", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Nile River is the longest river \n in the world, with a length of approximately 6,650 \n kilometers (4,130 miles).", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3. Largest Ocean by Surface Area", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Pacific Ocean is the largest ocean by \n surface area, covering approximately 63 million square \n miles (165 million square kilometers).", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4. Capital City of France", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Paris is the capital city of France, known for \n its iconic landmarks such as the Eiffel \n Tower and Louvre Museum.", { 1100, 570 }, 23, 1.5f, BLACK);
				break;
			case 2:
				DrawTextEx(font, "5. Mountain Range in South America", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Andes is the longest continental \n mountain range in the world, stretching along the \n western coast of South America.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "6. Largest Desert in the World", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Sahara Desert is the largest hot desert \n in the world, covering much of North Africa and spanning \napproximately 9.2 million square kilometers \n (3.6 million square miles).", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "7. Land of the Rising Sun", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Japan is known as the Land of the Rising Sun, \n a nickname derived from its name in Japanese, \n Nihon or Nippon, which means origin of the sun.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "8. Tallest Mountain in the World", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Mount Everest is the tallest mountain in the world, \n with a peak elevation of 8,848.86 meters \n (29,031.7 feet) above sea level.", { 1100, 570 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 3:
				DrawTextEx(font, "9. Home to the Amazon Rainforest", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "South America is home to the Amazon Rainforest, \n the largest tropical rainforest in the world, \n known for its rich biodiversity.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "10. Capital City of Australia", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Canberra is the capital city of Australia, \n located in the Australian Capital Territory.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "11.Land of the Midnight Sun", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Norway is known as the Land of the Midnight Sun, \n as regions within the Arctic Circle experience continuous \n daylight during summer months.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "12. Longest Mountain Range in the World", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Mid-Atlantic Ridge is the longest mountain \n range in the world, extending for approximately \n 16,000 kilometers (10,000 miles) along \n the ocean floor.", { 1100, 570 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 4:
				DrawTextEx(font, "13. Capital City of Canada", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Ottawa is the capital city of Canada, located \n in the province of Ontario.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "14. Largest Lake by Surface Area in Africa", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Lake Victoria is the largest lake by surface area in Africa, \n spanning approximately 68,800 square kilometers \n (26,600 square miles).", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "15. Largest Country by Land Area", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Russia is the largest country by land area, \n covering approximately 17.1 million square kilometers \n (6.6 million square miles).", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "16. Capital City of Brazil", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Brasília is the capital city of Brazil, \n located in the Federal District.", { 1100, 570 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 5:
				DrawTextEx(font, "17. Pearl of the Indian Ocean", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Sri Lanka is known as the Pearl \n of the Indian Ocean for its natural beauty \n and cultural heritage.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "18. Largest Island in the Mediterranean Sea", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Cyprus is the largest island in \n the Mediterranean Sea, located in the eastern \n part of the basin.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "19. Country on the Iberian Peninsula", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Spain is located on the \n Iberian Peninsula, along with Portugal and a small \n portion of Andorra.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "20.Capital City of China", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Beijing is the capital city of China,\n  known for its historical landmarks  \n such as the Forbidden City and the \n Great Wall of China.", { 1100, 570 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "5", { 975, 900 }, 25, 1.5f, BLACK);
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
		Texture2D book = LoadTexture("../images/book.png");

		Font font = LoadFont("textures/font.ttf");
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(WHITE);

			DrawTexture(book, 0, 0, WHITE);

			DrawRectangleRec(previous, BLUE);
			DrawRectangleRec(next, BLUE);

			DrawTextEx(font, "previous", { 50, 915 }, 20, 1.5f, BLACK);
			DrawTextEx(font, "next", { 1800, 915 }, 20, 1.5f, BLACK);
			switch (pageNumber)
			{
			case 1:
				DrawTextEx(font, "History", { 825, 100 }, 100, 1.5f, BLACK);

				DrawTextEx(font, "1. Beginning of World War II", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "World War II officially began on September \n 1, 1939, when Germany invaded Poland.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2. Invasion of Poland", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The country that invaded Poland, triggering \n the start of World War II, was Germany.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3. Normandy Invasion", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The code name for the Allied invasion of Normandy on \n June 6, 1944, was Operation Overlord.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4. United States Entry into WW II", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The United States entered World War \n II after the attack on Pearl Harbor \n by Japan on December 7, 1941.", { 1100, 570 }, 23, 1.5f, BLACK);
				break;
			case 2:
				DrawTextEx(font, "5. Leader of Nazi Germany", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The leader of Nazi Germany \n during World War II was Adolf Hitler.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "6. Axis Powers", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Axis Powers during World War II consisted \n primarily of Germany, Italy, and Japan.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "7. Atomic Bomb", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The atomic bomb dropped on \n Hiroshima was named Little Boy.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "8. Supreme Commander of Allied \n Forces in Europe", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Supreme Commander of the Allied Forces \n in Europe during World War II was \n Dwight D. Eisenhower.", { 1100, 595 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 3:
				DrawTextEx(font, "9. Turning Point in the Pacific", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Battle of Midway is considered the \n turning point of the war in the Pacific.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "10. Evacuation at Dunkirk", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Nazi Germany invaded France in 1940, \n leading to the evacuation at Dunkirk.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "11. German Air Force", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The German air force during World War II \n was called the Luftwaffe.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "12. Major Axis Powers", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The major Axis Powers during \n World War II were Germany, Italy, and Japan.", { 1100, 570 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 4:
				DrawTextEx(font, "13. German Offensive Against the Soviet Union", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The German offensive against the Soviet \n Union in 1941 was named Operation Barbarossa.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "14. Last Major German Offensive", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Battle of the Bulge marked the \n last major German offensive on the Western \n Front during World War II.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "15. Treaty Ending WWII in Europe", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The treaty that officially ended \n World War II in Europe was the \n Treaty of Versailles II.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "16. Purpose of the Yalta Conference", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The main purpose of the Yalta Conference \n in 1945 was to discuss post-war Europe.", { 1100, 570 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 5:
				DrawTextEx(font, "17. Break of Molotov-Ribbentrop Pact", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Nazi Germany invaded Poland, breaking \n the Molotov-Ribbentrop Pact with \n the Soviet Union.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "18. Significance of the Battle of Britain", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Battle of Britain prevented a \n German invasion of Britain.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "19. Nazi Concentration Camp", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Nazi concentration camp where more \n than one million people were killed \n was Auschwitz.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "20. British Prime Minister", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The British Prime Minister during \n most of World War II was Winston \n Churchill.", { 1100, 570 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "5", { 975, 900 }, 25, 1.5f, BLACK);
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


	if ((distance < 3.5f && IsKeyPressed(KEY_F)) || examination == 1)
	{
		EnableCursor();
		EndMode3D();
		Texture2D book = LoadTexture("../images/book.png");
		Font font = LoadFont("textures/font.ttf");
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(WHITE);

			DrawTexture(book, 0, 0, WHITE);

			DrawRectangleRec(previous, BLUE);
			DrawRectangleRec(next, BLUE);

			DrawTextEx(font, "previous", { 50, 915 }, 20, 1.5f, BLACK);
			DrawTextEx(font, "next", { 1800, 915 }, 20, 1.5f, BLACK);
			switch (pageNumber)
			{
			case 1:
				DrawTextEx(font, "Literature", { 725, 100 }, 100, 1.5f, BLACK);

				DrawTextEx(font, "1. Key Figures of Modernist Literature", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Virginia Woolf is considered one of the key figures \n of modernist literature, known for her innovative \n narrative techniques and exploration of consciousness.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2. Modernist Stream-of-Consciousness Writing", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Ulysses by James Joyce is often cited as a \n prime example of modernist stream-of-consciousness writing, \n characterized by its interior monologue and \n fragmented narrative style.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3. To the Lighthouse", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "To the Lighthouse is a modernist novel written by \n Virginia Woolf, published in 1927. It explores themes \n of memory, perception, and the passage \n of time.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4. Rejection of Traditional Forms", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Modernism is associated with the rejection of traditional \n forms and structures in literature, art, and culture, \n emphasizing experimentation and individualism.", { 1100, 570 }, 23, 1.5f, BLACK);
				break;
			case 2:
				DrawTextEx(font, "5. 1984 Protagonist", { 200, 220 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The protagonist of George Orwell's \n dystopian novel 1984 is named Winston Smith.", { 255, 260 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "6. Authors with Socialist Themes", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "George Orwell is known for his socialist themes \n and exploration of class struggle in works such \n as Animal Farm and 1984.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "7. T.S. Eliot's Modernist Poem", { 1100, 220 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Waste Land is the influential \n modernist poem written by T.S. Eliot, \n published in 1922. It explores the fragmentation \n of modern life and the search \n for meaning in a post-war world.", { 1100, 260 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "8. Mrs. Dalloway Author", { 1100, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Mrs. Dalloway is a modernist novel \n written by Virginia Woolf, published in 1925. \n It follows a day in the life of Clarissa Dalloway as \n she prepares for a partyand reflects on her past.", { 1100, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 3:
				DrawTextEx(font, "9. Socialist Themes in Literature", { 200, 220 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Animal Farm by George Orwell is a literary \n work that explores themes of socialism and the \n Russian Revolution through the allegory \n of farm animals overthrowing \n their human masters.", { 255, 260 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "10. Waiting for Godot", { 200, 540 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Waiting for Godot is a modernist play written by \n Samuel Beckett, first premiered in 1953. It features two \n characters, Vladimir and Estragon, waiting for \n the arrival of someone \n named Godot, exploring themes of existentialismand the \n human condition.", { 255, 590 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "11. Steppenwolf Author", { 1100, 220 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Steppenwolf is a novel written by \n Hermann Hesse, published in 1927. It explores themes of \n existentialism and socialism through the journey of \n its protagonist, Harry Haller, as he grapples with his \n dual nature", { 1100, 260 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "12. Effects of Capitalism and Industrialization", { 1070, 550 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Grapes of Wrath by John Steinbeck is a literary \n work that explores the effects of \n capitalism and industrialization \n on society, particularly \n through the experiences of the \n Joad family during the \n Great Depression.", { 1100, 600 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 4:
				DrawTextEx(font, "13. The Sound and the Fury Author", { 200, 220 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Sound and the Fury is a modernist novel written by \n William Faulkner, published in 1929. It employs \n multiple narrators and nonlinear narrative \n structure to depict the decline of a Southern \n aristocratic family.", { 255, 260 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "14. A Portrait of the Artist as a Young Man", { 200, 540 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "A Portrait of the Artist as a Young Man is a modernist \n novel written by James Joyce, published in 1916. It follows \n the development of its protagonist, Stephen Dedalus,\n as he navigates the complexities of Irish \n society and his own artistic aspirations.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "15. Franz Kafka's Metamorphosis", { 1100, 220 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Metamorphosis is a modernist novella written \n by Franz Kafka, published in 1915. It follows the \n transformation of its protagonist, Gregor Samsa, into \n a giant insect and \n explores themes of alienation and \n existential dread", { 1100, 260 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "16. Colonialism and Imperialism in Literature", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Things Fall Apart by Chinua Achebe is a \n literary work that explores the impact \n of colonialism and imperialism on \n society, particularly through the lens of Igbo culture \n in Nigeria.", { 1100, 570 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 5:
				DrawTextEx(font, "17. The Trial Author", { 200, 220 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Trial is a modernist novel written by Franz Kafka, \n published posthumously in 1925. It follows the protagonist, \n Josef K., as he is prosecuted by a mysterious authority \n for a crime that is never revealed.", { 255, 260 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "18. Zora Neale Hurston's Novel", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Their Eyes Were Watching God is a modernist novel \n written by Zora Neale Hurston, published in 1937. It follows \n the life of its protagonist, Janie Crawford, as she \n navigates love, identity, and independence in the rural \n South.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "19. T.S. Eliot's The Love Song of \n J.Alfred Prufrock", { 1100, 220 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Love Song of J. Alfred Prufrock \n is a modernist poem written \n by T.S.Eliot, published in 1915. It explores themes \n of alienation, indecision, and \n the passage of time through \n the perspective of its titular character.", { 1100, 320 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "20. Jean-Paul Sartre's Nausea", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Nausea is a modernist novel written by Jean - Paul Sartre, \n published in 1938. It follows the existential crisis of \n its protagonist, Antoine Roquentin, as he grapples \n with the absurdity of existence and the nature of \n freedom.", { 1100, 570 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "5", { 975, 900 }, 25, 1.5f, BLACK);
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


	if ((distance < 3.5f && IsKeyPressed(KEY_F)) || examination == 1)
	{
		Texture2D book = LoadTexture("../images/book.png");
		Font font = LoadFont("textures/font.ttf");
		EnableCursor();
		EndMode3D();
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(WHITE);

			DrawTexture(book, 0, 0, WHITE);

			DrawRectangleRec(previous, BLUE);
			DrawRectangleRec(next, BLUE);

			DrawTextEx(font, "previous", { 50, 915 }, 20, 1.5f, BLACK);
			DrawTextEx(font, "next", { 1800, 915 }, 20, 1.5f, BLACK);
			switch (pageNumber)
			{
			case 1:
				DrawTextEx(font, "Biology", { 745, 100 }, 100, 1.5f, BLACK);

				DrawTextEx(font, "1. Function of Carbohydrates", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Carbohydrates primarily serve as a source of \n energy for living organisms. They are broken down \n into glucose, which is used as fuel for cellular processes.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2. Main Energy Currency of the Cell", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Adenosine triphosphate (ATP) serves \n as the main energy currency of the cell, storing and \n releasing energy for cellular processes.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3. Structural Unit of Proteins", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Amino acids are the structural units of \n proteins. They are linked together by peptide \n bonds to form polypeptide chains, which fold into \n specific three-dimensional structures.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4. Function of Lipids", { 1080, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Lipids serve multiple functions in the \n human body, including energy storage, insulation, \n and hormone synthesis. They also form the \n structural basis of cell membranes.", { 1100, 570 }, 23, 1.5f, BLACK);

				break;
			case 2:
				DrawTextEx(font, "5. Role of Enzymes", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Enzymes are biological catalysts that accelerate \n chemical reactions in living organisms. They lower \n the activation energy required for reactions to \n occur, thus speeding up metabolic processes.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "6. Water-Soluble Vitamin for Collagen Synthesis", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Vitamin C is a water-soluble vitamin \n essential for collagen synthesis, wound healing,\n and maintaining connective tissue health.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "7. Primary Function of Lipids", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Lipids primarily serve as energy storage \n molecules in the human body. They provide a \n concentrated source of energy and play \n a role in insulation and protection of vital organs.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "8. Organelle Responsible for Protein Synthesis", { 1100, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Ribosomes are the cellular organelles responsible \n for protein synthesis in eukaryotic cells. They are \n composed of RNA and protein and are found in \n the cytoplasm and on the rough endoplasmic reticulum.", { 1100, 570 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 3:
				DrawTextEx(font, "9. Role of Nucleic Acids", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Nucleic acids, such as DNA and RNA, serve as \n the genetic information storage and transmission molecules \n in living organisms. They encode the instructions for \n building proteins and regulate cellular processes.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "10. Body's Primary Source of Energy", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Carbohydrates are the body's primary \n source of energy, providing fuel \n for cellular activities and metabolic processes.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "11. Function of DNA", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "DNA (deoxyribonucleic acid) serves \n as the repository of genetic information in cells.\n It contains the instructions for synthesizing proteins and \n is passed from parent to offspring \n during reproduction.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "12. Structural Unit of Nucleic Acids", { 1080, 540 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Nucleic acids are composed of nucleotides, \n which consist of a sugar molecule, phosphate group,\n and nitrogenous base. These nucleotides polymerize \n to form DNA and RNA.", { 1100, 590 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 4:
				DrawTextEx(font, "13. Role of RNA in Protein Synthesis", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "RNA (ribonucleic acid) acts as a messenger \n between DNA and the ribosome during protein synthesis. \n It carries the genetic information encoded in DNA to the ribosome, \n where it is used to assemble proteins.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "14. Function of Proteins", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Proteins have diverse functions in the human body, \n including building and repairing tissues, serving \n as enzymes and hormones, and facilitating transport of molecules \n across cell membranes.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "15. Function of Chlorophyll", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Chlorophyll is a pigment found in chloroplasts \n that absorbs light energy for the process of \n photosynthesis in plants. It captures sunlight and converts \n it into chemical energy used to synthesize glucose from \n carbon dioxide and water.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "16. Role of Vitamin K", { 1080, 540 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Vitamin K is a fat-soluble vitamin essential \n for blood clotting and bone health. It plays \n a critical role in the synthesis of clotting factors and \n helps maintain bone density.", { 1100, 590 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 5:
				DrawTextEx(font, "17. Function of Carbohydrates in Cellular Respiration", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Carbohydrates serve as a primary source of \n energy during cellular respiration. Glucose, derived \n from carbohydrates, is broken down in the presence \n of oxygen to produce ATP, the energy currency of the cell.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "18. Function of Vitamin B12", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Vitamin B12 is a water-soluble vitamin \n essential for red blood cell formation and neural function. \n It is involved in DNA synthesis and plays a role in \n maintaining the health of the nervous system.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "19. Function of Proteins in Cell Membranes", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Proteins in cell membranes serve various functions, \n including facilitating transport of molecules across the membrane, \n cell signaling, and cell adhesion.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "20. Role of Electrolytes", { 1080, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Electrolytes are minerals that \n dissociate into ions in solution and play crucial \n roles in maintaining proper fluid balance, nerve function, \n and muscle contraction in the body.", { 1100, 570 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "5", { 975, 900 }, 25, 1.5f, BLACK);
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


	if ((distance < 3.5f && IsKeyPressed(KEY_F)) || examination == 1)
	{
		Texture2D book = LoadTexture("../images/book.png");
		Font font = LoadFont("textures/font.ttf");
		EnableCursor();
		EndMode3D();
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(WHITE);

			DrawTexture(book, 0, 0, WHITE);

			DrawRectangleRec(previous, BLUE);
			DrawRectangleRec(next, BLUE);

			DrawTextEx(font, "previous", { 50, 915 }, 20, 1.5f, BLACK);
			DrawTextEx(font, "next", { 1800, 915 }, 20, 1.5f, BLACK);
			switch (pageNumber)
			{
			case 1:
				DrawTextEx(font, "Chemistry", { 825, 100 }, 100, 1.5f, BLACK);

				DrawTextEx(font, "1. Chemical Symbol for Water", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The chemical symbol for water is H2O, \n representing two hydrogen atoms bonded \n to one oxygen atom.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2.Essential Element for Organic Life", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Carbon is essential for organic life and \n is the main component of organic molecules, forming \n the backbone of many biological compounds.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3. Smallest Unit of an Element", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "An atom is the smallest unit of an element that retains its \n chemical properties. Atoms consist of a nucleus containing \n protons and  neutrons, surrounded by electrons.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4. Chemical Symbol for Iron", { 1080, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The chemical symbol for iron is Fe, derived \n from its Latin name Ferrum.", { 1100, 590 }, 23, 1.5f, BLACK);
				break;
			case 2:
				DrawTextEx(font, "5. Process of Sublimation", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Sublimation is the process by which a solid \n changes directly into a gas without passing through the \n liquid state. Examples include dry ice (solid carbon dioxide) \n subliming into carbon dioxide gas.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "6. Chemical Formula for Carbon Dioxide", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The chemical formula for carbon dioxide is CO2, \n representing one carbon atom bonded \n to two oxygen atoms.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "7. Noble Gases", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Noble gases are a group of elements that are \n generally inert and have full valence electron shells.\n  These include helium (He), neon (Ne), argon (Ar), krypton (Kr), \n xenon (Xe), and radon (Rn).", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "8. pH Value of Pure Water", { 1080, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Pure water has a pH value of 7 \n at room temperature, indicating neutrality. It \n is neither acidic nor basic.", { 1100, 590 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 3:
				DrawTextEx(font, "9. Particle with Positive Charge", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The proton is a subatomic particle with a positive charge. \n It is found in the nucleus of an atom and \n contributes to its atomic number.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "10. Process of Evaporation", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Evaporation is the process by which a liquid changes into a gas \n at temperatures below its boiling point. \n It occurs at the surface of the liquid.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "11.Chemical Symbol for Gold", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The chemical symbol for gold is Au, \n derived from its Latin name Aurum.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "12. Chemical Formula for Table Salt", { 1080, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The chemical formula for table salt (sodium chloride) \n is NaCl, representing one sodium ion bonded \n to one chloride ion.", { 1100, 590 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 4:
				DrawTextEx(font, "13. Greenhouse Gas", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Carbon dioxide (CO2) is a greenhouse gas, \n contributing to the greenhouse effect and global \n warming when present in the atmosphere \n in high concentrations.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "14. Atomic Number of Oxygen", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The atomic number of oxygen is 8, \n indicating the number of protons \n in its nucleus.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "15. Chemical Formula for Methane", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The chemical formula for methane is \n CH4, representing one carbon atom \n bonded to four hydrogen atoms.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "16. Halogen", { 1080, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Chlorine (Cl) is a halogen element, \n belonging to Group 17 (Group VIIA) of \n the periodic table.", { 1100, 590 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 5:
				DrawTextEx(font, "17. Chemical Formula for Sulfuric Acid", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The chemical formula for sulfuric \n acid is H2SO4, representing two \n hydrogen atoms, one sulfur atom, and \n four oxygen atoms.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "18. Chemical Symbol for Lead", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The chemical symbol for lead \n is Pb, derived from its Latin name Plumbum.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "19. Particle with Neutral Charge", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The neutron is a subatomic particle \n with a neutral charge. It is found in the \n nucleus of an atom alongside protons.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "20.Chemical Formula for Hydrogen Peroxide", { 1080, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The chemical formula for hydrogen peroxide \n is H2O2, representing two hydrogen atoms \n bonded to two oxygen atoms.", { 1100, 590 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "5", { 975, 900 }, 25, 1.5f, BLACK);
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


	if ((distance < 3.5f && IsKeyPressed(KEY_F)) || examination == 1)
	{
		Texture2D book = LoadTexture("../images/book.png");
		Font font = LoadFont("textures/font.ttf");
		EnableCursor();
		EndMode3D();
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(WHITE);

			DrawTexture(book, 0, 0, WHITE);

			DrawRectangleRec(previous, BLUE);
			DrawRectangleRec(next, BLUE);

			DrawTextEx(font, "previous", { 50, 915 }, 20, 1.5f, BLACK);
			DrawTextEx(font, "next", { 1800, 915 }, 20, 1.5f, BLACK);
			switch (pageNumber)
			{
			case 1:
				DrawTextEx(font, "Physics", { 825, 100 }, 100, 1.5f, BLACK);

				DrawTextEx(font, "1. SI Unit of Force", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The SI unit of force is the Newton (N). One Newton is defined \n as the force required to accelerate a mass of one \n kilogram by one meter per second squared.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2.Acceleration Due to Gravity on Earth", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The acceleration due to gravity on Earth's surface \n is approximately 9.8 meters per second squared (m/s^2).", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3. Newton's First Law of Motion", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Newton's First Law of Motion states that an object at \n rest will remain at rest, and an object in motion will remain in motion \n with constant velocity unless acted upon by an external force.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4. Formula for Kinetic Energy", { 1080, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The formula for calculating kinetic energy \n (KE) is KE = 1/2mv^2, where m is the mass of the \n object and v is its velocity.", { 1100, 590 }, 23, 1.5f, BLACK);
				break;
			case 2:
				DrawTextEx(font, "5. Unit of Power", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The unit of power is the Watt (W), which is equivalent to one joule per second.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "6. Newton's Second Law of Motion", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Newton's Second Law of Motion states \n that the force acting on an object is equal to the mass of \n the object multiplied by its acceleration: F = ma.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "7. Law of Conservation of Energy", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Law of Conservation of Energy states that \n the total energy of an isolated system remains constant \n over time, implying that energy can neither be created \n nor destroyed, only transformed from one form \n to another.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "8. Formula for Gravitational Potential Energy", { 1080, 540 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The formula for calculating gravitational potential \n energy (PE) near the Earth's surface \n is PE = mgh, where m is the mass, g is the \n acceleration due to gravity, and h is the height \n above the reference point.", { 1100, 590 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 3:
				DrawTextEx(font, "9. Unit of Electric Charge", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The unit of electric charge is the Coulomb (C). \n One Coulomb is equivalent to the charge transported by \n a constant current of one ampere in one second.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "10. Speed of Light in Vacuum", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The speed of light in a vacuum \n is approximately 3 × 10^8 meters per \n second (m/s).", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "11.First Law of Thermodynamics", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The First Law of Thermodynamics, also known as the \n Law of Conservation of Energy, states that \n the total energy of an isolated system \n remains constant over time.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "12. Formula for Work Done", { 1080, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The formula for calculating work done (W) by a \n constant force on an object is W = Fd, where \n F is the magnitude of the force and \n d is the displacement of the object in the direction \n of the force.", { 1100, 590 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 4:
				DrawTextEx(font, "13. Unit of Electric Current", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The SI unit of electric current is the Ampere (A). \n One Ampere is defined as the flow of one \n Coulomb of charge per second.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "14. Newton's Third Law of Motion", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Newton's Third Law of Motion states that for \n every action, there is an equal and opposite reaction.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "15. Formula for Frequency of a Wave", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The formula for calculating the frequency (f) \n of a wave is f = 1/λ, where λ (lambda) is the \n wavelength of the wave.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "16. Law of Conservation of Charge", { 1080, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The Law of Conservation of Charge states that \n the total electric charge within a closed \n system remains constant over time.", { 1100, 590 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 5:
				DrawTextEx(font, "17. Unit of Electric Potential Difference", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The unit of electric potential difference \n is the Volt (V). One Volt is equivalent to one \n joule per Coulomb.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "18. Formula for Period of a Wave", { 200, 530 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The period (T) of a wave is the time \n taken for one complete cycle of the wave. The formula for \n calculating the period is T = 1/f, where f is the \n frequency of the wave.", { 255, 580 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "19. SI Unit of Pressure", { 1080, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "The SI unit of pressure is the Pascal (Pa).\n One Pascal is equal to one Newton per square meter.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "20. Boyle's Law", { 1080, 520 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Boyle's Law states that the pressure of a \n given mass of gas is inversely proportional to its \n volume at constant temperature.", { 1100, 590 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "5", { 975, 900 }, 25, 1.5f, BLACK);
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

void mathsTextBook(Camera camera, bool examination)
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
		Texture2D book = LoadTexture("../images/book.png");
		Font font = LoadFont("textures/font.ttf");
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(WHITE);

			DrawTexture(book, 0, 0, WHITE);

			DrawRectangleRec(previous, BLUE);
			DrawRectangleRec(next, BLUE);

			DrawTextEx(font, "previous", { 50, 915 }, 20, 1.5f, BLACK);
			DrawTextEx(font, "next", { 1800, 915 }, 20, 1.5f, BLACK);
			switch (pageNumber)
			{
			case 1:
				DrawTextEx(font, "Maths", { 825, 100 }, 100, 1.5f, BLACK);

				DrawTextEx(font, "1. Operations:", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "This involves basic arithmetic operations like addition, \n subtraction, multiplication, and division. Understanding \n the order of operations (PEMDAS/BODMAS) is essential \n for solving complex expressions.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2.Acceleration Due to Gravity on Earth", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Exponents represent repeated multiplication. \n Properties of exponents include multiplication/addition of \n exponents, division/subtraction of exponents, \n and exponentiation of exponentials.", { 1100, 370 }, 23, 1.5f, BLACK);

				break;
			case 2:
				DrawTextEx(font, "3. Inequalities", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Inequalities involve expressions that are not \n equal. Solving inequalities typically requires \n understanding how to manipulate expressions while \n maintaining the direction of the inequality.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4. Arithmetic:", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "This involves basic arithmetic concepts such as \n fractions, percentages, ratios, and proportions. \n Understanding arithmetic operations and their \n properties is crucial for solving numerical problems.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "2", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 3:
				DrawTextEx(font, "5. Algebraic Manipulation", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Algebraic manipulation includes simplifying expressions, solving equations, \n and rearranging formulas. It involves applying algebraic \n rules and properties to transform expressions \n or equations into simpler forms.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "6. Number Properties:", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "This includes understanding different types of numbers \n like whole numbers,  integers, \n rational numbers, and their properties. \n For example, prime numbers are numbers divisible \n only by 1 and themselves.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "3", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 4:
				DrawTextEx(font, "7. Geometry:", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Geometry deals with shapes, sizes, and properties of space. \n Understanding properties of geometric \n figures like quadrilaterals, \n triangles, circles, and their properties \n (e.g., diagonals, angles, side lengths) is \n essential.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "8. Unit Conversion", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Unit conversion involves converting \n measurements from one unit to another. \n For example, converting kilometers to meters, grams to kilograms, \n or dollars to another currency.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "4", { 975, 900 }, 25, 1.5f, BLACK);
				break;
			case 5:
				DrawTextEx(font, "9. Financial Calculations", { 200, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Financial calculations involve computations \n related to money, such as income, \n expenses, profit, interest, and percentage \n increase or decrease.", { 255, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "10. Squares and Square Roots", { 1100, 320 }, 30, 1.5f, BLACK);
				DrawTextEx(font, "Understanding squares (numbers multiplied by themselves) \n and square roots (the inverse operation of squaring) \n is important for solving problems \n involving areas, volumes, and geometric shapes, \n as well as for simplifying expressions.", { 1100, 370 }, 23, 1.5f, BLACK);

				DrawTextEx(font, "5", { 975, 900 }, 25, 1.5f, BLACK);
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