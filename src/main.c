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

        DrawText("FerrumForge", 100, 100, 50, WHITE);

        EndDrawing();
    }

    CloseWindow();
}