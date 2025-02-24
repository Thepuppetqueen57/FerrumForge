use macroquad::prelude::*;

struct Button {
    text: String,
    x: i32,
    y: i32,
    width: u16,
    height: u16,
    is_disabled: bool
}

impl Button {
    fn draw(&self) {
        draw_rectangle(
            self.x as f32,
            self.y as f32,
            self.width as f32,
            self.height as f32,
            if self.is_disabled { BLACK } else { WHITE }
        );

        draw_rectangle_lines(
            self.x as f32,
            self.y as f32,
            self.width as f32,
            self.height as f32,
            20.0,
            if self.is_disabled { WHITE } else { BLACK }
        );

        draw_text(
            &self.text,
            self.x as f32 + self.width as f32 / 2.0 - get_text_length(&self.text, 40.0) / 2.0,
            self.y as f32 + self.height as f32 / 2.0,
            40.0,
            if self.is_disabled { WHITE } else { BLACK }
        );
    }

    fn is_clicked(&self) -> bool {
        if is_mouse_button_pressed(MouseButton::Left) 
        && Rect::new(self.x as f32, self.y as f32, self.width as f32, self.height as f32).contains(vec2(mouse_position().0, mouse_position().1)) {
            true
        } else {
            false
        }
    }
}

fn get_text_length(text: &str, font_size: f32) -> f32 {
    let text_dimensions = measure_text(text, None, font_size as u16, 1.0);
    text_dimensions.width
}

#[macroquad::main("FerrumForge")]
async fn main() {
    let mut play_games_button = Button {
        text: "Play Games".to_string(),
        x: screen_width() as i32 / 2 - 125,
        y: screen_height() as i32 / 2,
        width: 250,
        height: 100,
        is_disabled: false
    };

    loop {
        // Logic
        play_games_button.x = screen_width() as i32 / 2 - 100;
        play_games_button.y = screen_height() as i32 / 2;

        // Rendering
        clear_background(Color { r: 0.1, g: 0.1, b: 0.1, a: 1.0 });

        draw_text(
            "FerrumForge",
            screen_width() / 2.0 - get_text_length("FerrumForge", 75.0) / 2.0,
            screen_height() / 2.0 - 100.0,
            75.0,
            WHITE
        );

        play_games_button.draw();

        next_frame().await
    }
}