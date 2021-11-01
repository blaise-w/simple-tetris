#include "controller.hxx"


Controller::Controller(Game& game)
        :game(game),
         view(game)
{}

void Controller::on_key(ge211::Key key) {
    if (key == ge211::Key::code('q')) {
        quit();
    }

    if (key == ge211::Key::left()) {
        game.move_left();
    }

    if (key == ge211::Key::right()) {
        game.move_right();
    }

    if (key == ge211::Key::down()) {
        game.move_down();
    }

    if (key == ge211::Key::code(' ')) {
        game.place_down();
    }

    if (key == ge211::Key::code('x')) {
        game.rotate();
    }
}

void Controller::draw(ge211::Sprite_set& set) {
    view.draw(set, game.score, game.level, game.lines_cleared);
}

ge211::Dims<int> Controller::initial_window_dimensions() const {
    return view.initial_window_dimensions();
}

std::string Controller::initial_window_title() const {
    return view.initial_window_title();
}

void Controller::on_frame(double dt) {
    game.on_frame();
}

