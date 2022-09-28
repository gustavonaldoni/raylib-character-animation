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
	Stopwatch animationIdleStopwatch = StopwatchCreate(0.05f);

	int frameIdle = 0;
	int maxIdleFrames = 10;

	Texture2D textureKnightAttackNoMove = LoadTexture("images/_Attack2NoMovement.png");
	Stopwatch animationAttackNoMoveStopwatch = StopwatchCreate(0.03f);

	int frameAttackNoMove = 0;
	int maxAttackNoMoveFrames = 6;

	Texture2D textureKnightRunRight = LoadTexture("images/_RunRight.png");
	Stopwatch animationRunRightStopwatch = StopwatchCreate(0.05f);

	int frameRunRight = 0;
	int maxRunRightFrames = 10;

	Texture2D textureKnightRunLeft = LoadTexture("images/_RunLeft.png");
	Stopwatch animationRunLeftStopwatch = StopwatchCreate(0.05f);

	int frameRunLeft = 0;
	int maxRunLeftFrames = 10;


	float x = 300, y = 300;

	SetTargetFPS(144);
	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_D))
		{
			x += 300.0f * GetFrameTime();
		}

		if (IsKeyDown(KEY_A))
		{
			x -= 300.0f * GetFrameTime();
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			AnimateTexture(textureKnightAttackNoMove, &animationAttackNoMoveStopwatch, maxAttackNoMoveFrames,  &frameAttackNoMove, x, y, 5.0);
		}

		else if (IsKeyDown(KEY_A))
		{
			AnimateTexture(textureKnightRunLeft, &animationRunLeftStopwatch, maxRunLeftFrames,  &frameRunLeft, x, y, 5.0);
		}

		else if (IsKeyDown(KEY_D))
		{
			AnimateTexture(textureKnightRunRight, &animationRunRightStopwatch, maxRunRightFrames,  &frameRunRight, x, y, 5.0);
		}

		else 
		{
			AnimateTexture(textureKnightIdle, &animationIdleStopwatch, maxIdleFrames, &frameIdle, x, y, 5.0);
		}

		EndDrawing();
	}

	CloseWindow();
}
