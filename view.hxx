#pragma once


#include "model.hxx"
#include <string>

const int FONT_SIZE = 25;
const int HUD_BORDER = 50;
const int HUD_WALL = 75;


struct View
{
    ge211::Font const sans{"sans.ttf", FONT_SIZE};

    ge211::Text_sprite display_score       {"Tetris", sans},
            score_label {"Score:", sans},
            level_label {"Level:", sans},
            lines{"Lines Cleared:", sans};

    void draw(ge211::Sprite_set& set, int score, int level, int
    lines_cleared);

    ge211::Text_sprite score_sprite;
    ge211::Text_sprite level_sprite;
    ge211::Text_sprite lines_cleared_sprite;

    void add_text(ge211::Sprite_set &set) const;

    static ge211::Dims<int> initial_window_dimensions() ;

    std::string initial_window_title() const;

    explicit View(Game const& game);

    static int board_to_pixels_x(int x);
    static int board_to_pixels_y(int y);

private:
    const Game &game_;

    ge211::Rectangle_sprite const blue_sprite;
    ge211::Rectangle_sprite const red_sprite;
    ge211::Rectangle_sprite const green_sprite;
    ge211::Rectangle_sprite const yellow_sprite;
    ge211::Rectangle_sprite const magenta_sprite;
    ge211::Rectangle_sprite const cyan_sprite;
    ge211::Rectangle_sprite const white_sprite;

};