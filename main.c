#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "include/raylib.h"
#include "include/raymath.h"

// Compile with: gcc main.c -o test.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib -lraylib -lopengl32 -lgdi32 -lwinmm

#include "headers/stopwatch.h"
#include "headers/animation.h"

int main()
{
	srand(time(NULL));

	int screenConstant = 300;
	InitWindow(4 * screenConstant, 3 * screenConstant, "2D Plataformer");

	Texture2D textureKnightIdle = LoadTexture("images/_idle.png");

	Stopwatch animationStopwatch = StopwatchCreate(0.05f);

	int frame = 0;
	float frameWidth = (float)(textureKnightIdle.width / 10);
	int maxFrames = 10;

	float x = 300, y = 300;

	SetTargetFPS(144);
	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_D))
		{
			x += 200.0f * GetFrameTime();
		}

		if (IsKeyDown(KEY_A))
		{
			x -= 200.0f * GetFrameTime();
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		AnimateTexture(textureKnightIdle, &animationStopwatch, maxFrames, &frame, x, y);

		EndDrawing();
	}

	CloseWindow();
}
