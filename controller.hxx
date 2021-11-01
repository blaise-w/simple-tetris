#pragma once

#include "model.hxx"
#include "view.hxx"

struct Controller : public ge211::Abstract_game
{

    void draw(ge211::Sprite_set& set) override;
    ge211::Dims<int> initial_window_dimensions() const override;
    std::string initial_window_title() const override;

    void on_key(ge211::Key) override;

    void on_frame(double dt) override;

    Game& game;

    View view;

    explicit Controller(Game&);
};