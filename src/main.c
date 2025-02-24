#include <raylib.h>

void main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(
        800,
        600,
        "FerrumForge"
    );

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText(
            "FerrumForge",
            GetScreenWidth() / 2 - MeasureText("FerrumForge", 50) / 2,
            GetScreenHeight() / 2 - 100,
            50,
            WHITE
        );

        EndDrawing();
    }

    CloseWindow();
}