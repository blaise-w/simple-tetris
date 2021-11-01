#include "view.hxx"
#include <string>

const int BLOCK_SIZE = 40;
const int PIECE_DIMS = 5;

using Color = ge211::Color;


View::View(const Game & game)
        :game_(game),
         blue_sprite({BLOCK_SIZE, BLOCK_SIZE}, Color::medium_blue()),
         red_sprite({BLOCK_SIZE, BLOCK_SIZE}, Color::medium_red()),
         green_sprite({BLOCK_SIZE, BLOCK_SIZE}, Color::medium_green()),
         yellow_sprite({BLOCK_SIZE, BLOCK_SIZE}, Color::medium_yellow()),
         magenta_sprite({BLOCK_SIZE, BLOCK_SIZE}, Color::medium_magenta()),
         cyan_sprite({BLOCK_SIZE, BLOCK_SIZE}, Color::medium_cyan()),
         white_sprite({BLOCK_SIZE, BLOCK_SIZE}, Color::white())
{}


void View::draw(ge211::Sprite_set& set, int score, int level, int
lines_cleared) {
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            int x = board_to_pixels_x(i);
            int y = board_to_pixels_y(j);
            if (!game_.board_.inbounds(i, j)) continue;
            if (game_.board_.grid[i][j] == 1)
                set.add_sprite(blue_sprite, {x, y});
            if (game_.board_.grid[i][j] == 2)
                set.add_sprite(red_sprite, {x, y});
            if (game_.board_.grid[i][j] == 3)
                set.add_sprite(green_sprite, {x, y});
            if (game_.board_.grid[i][j] == 4)
                set.add_sprite(yellow_sprite, {x, y});
            if (game_.board_.grid[i][j] == 5)
                set.add_sprite(magenta_sprite, {x, y});
            if (game_.board_.grid[i][j] == 6)
                set.add_sprite(cyan_sprite, {x, y});
            if (game_.board_.grid[i][j] == 7)
                set.add_sprite(white_sprite, {x, y});
        }
    }
    for (int i = 0; i < PIECE_DIMS; i++) {
        for (int j = 0; j < PIECE_DIMS; j++) {
            int u = board_to_pixels_x(game_.current.x + i);
            int v = board_to_pixels_y(game_.current.y + j);
            if (!game_.board_.inbounds(i, j)) continue;
            if (game_.current.getCell(game_.current, i, j) == 1) {
                set.add_sprite(blue_sprite, {u, v});
            }
            if (game_.current.getCell(game_.current, i, j) == 2) {
                set.add_sprite(red_sprite, {u, v});
            }
            if (game_.current.getCell(game_.current, i, j) == 3) {
                set.add_sprite(green_sprite, {u, v});
            }
            if (game_.current.getCell(game_.current, i, j) == 4) {
                set.add_sprite(yellow_sprite, {u, v});
            }
            if (game_.current.getCell(game_.current, i, j) == 5) {
                set.add_sprite(magenta_sprite, {u, v});
            }
            if (game_.current.getCell(game_.current, i, j) == 6) {
                set.add_sprite(cyan_sprite, {u, v});
            }
            if (game_.current.getCell(game_.current, i, j) == 7) {
                set.add_sprite(white_sprite, {u, v});
            }
        }
    }
    add_text(set);
    ge211::Text_sprite::Builder score_builder(sans);
    score_builder.color(Color::white()) << score;
    score_sprite.reconfigure(score_builder);
    set.add_sprite(score_sprite, {100, FONT_SIZE});

    ge211::Text_sprite::Builder level_builder(sans);
    level_builder.color(Color::white()) << level;
    level_sprite.reconfigure(level_builder);
    set.add_sprite(level_sprite, {100, HUD_BORDER});

    ge211::Text_sprite::Builder lines_builder(sans);
    lines_builder.color(Color::white()) << lines_cleared;
    lines_cleared_sprite.reconfigure(lines_builder);
    set.add_sprite(lines_cleared_sprite, {190, HUD_WALL});

}

void View::add_text(ge211::Sprite_set &set) const
{
    set.add_sprite(display_score, {10, 0}, 5);
    set.add_sprite(score_label, {10, FONT_SIZE}, 5);
    set.add_sprite(level_label, {10, HUD_BORDER}, 5);
    set.add_sprite(lines, {10, HUD_WALL}, 5);
}


ge211::Dims<int> View::initial_window_dimensions() {
    return {GRID_WIDTH * BLOCK_SIZE, GRID_HEIGHT * BLOCK_SIZE};
}

std::string
View::initial_window_title() const
{
    while (!game_.game_over) {
        return ("Tetris");
    }
    return ("Game Over");
}

int View::board_to_pixels_x(int x) {
    return x * BLOCK_SIZE;
}

int View::board_to_pixels_y(int y) {
    return y * BLOCK_SIZE;
}


