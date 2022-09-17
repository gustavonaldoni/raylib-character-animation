void AnimateTexture(Texture2D texture, Stopwatch *stopwatch, int maxFrames, int *frame, int x, int y)
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
                   (Rectangle){x, y, frameWidth * 6, texture.height * 6},
                   (Vector2){0, 0},
                   0.0f,
                   RAYWHITE);
}
