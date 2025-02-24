#include <raylib.h>

typedef struct {
    int x, y, width, height, is_disabled
} Button;

bool is_clicked(Button *self) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(), (Rectangle){ self->x, self->y, self->width, self->height })) {
        return true;
    }
    return false;
}

void draw_button(Button *self, char text[]) {
    DrawRectangle(
        self->x,
        self->y,
        self->width,
        self->height,
        WHITE
    );

    struct Rectangle hey_bitch = { self->x, self->y, self->width, self->height };
    DrawRectangleLinesEx(
        hey_bitch,
        10.0,
        BLACK
    );

    DrawText(
        text,
        self->x + MeasureText(text, 20) / 2,
        self->y + 20 * 2,
        20,
        BLACK
    );
}

void main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(
        800,
        600,
        "FerrumForge"
    );

    SetTargetFPS(60);

    Button play_button = {
        GetScreenWidth() / 2 - 100,
        GetScreenHeight() / 2 - 100,
        200,
        100,
        false
    };

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground((Color) { 20, 20, 20, 255 });

        DrawText(
            "FerrumForge",
            GetScreenWidth() / 2 - MeasureText("FerrumForge", 50) / 2,
            GetScreenHeight() / 2 - 200,
            50,
            WHITE
        );

        draw_button(&play_button, "Play Games!");

        EndDrawing();
    }

    CloseWindow();
}