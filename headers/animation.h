void AnimateTexture(Texture2D texture, Stopwatch *stopwatch, int maxFrames, int *frame, int x, int y, float scaleFactor)
{
    float frameWidth = texture.width / maxFrames;

    StopwatchUpdate(stopwatch);

    if (StopwatchIsDone(*stopwatch))
    {
        StopwatchReset(stopwatch);
        *frame += 1;
    }

    *frame = *frame % maxFrames;

    DrawTexturePro(texture,
                   (Rectangle){frameWidth * (*frame), 10, frameWidth, texture.height},
                   (Rectangle){x, y, frameWidth * scaleFactor, texture.height * scaleFactor},
                   (Vector2){0, 0},
                   0.0f,
                   RAYWHITE);

    DrawRectangleLines(x, y, frameWidth * scaleFactor, texture.height * scaleFactor, RED);
}
