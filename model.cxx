#include "model.hxx"

Game::Game()
        :score(0),
         lines_cleared(0),
         game_over(false),
         board_(),
         level(1),
         next(block_.makeRandomBlock())
{
    launch();
}

void Game::move_right() {
    Block temp = current;
    temp.x++;

    if (board_.good_move(temp)) current.x++;
}

void Game::move_left() {
    Block temp = current;
    temp.x--;

    if (board_.good_move(temp)) current.x--;
}

void Game::move_down() {
    int drop_length = Game::drop_length(); //
    if (drop_length > 0) current.y++;
}


void Game::make_block() {
    if (board_.good_move(current))
        board_.add_block(current);
    raise_score(board_.find_filled_lines());

    if (!board_.good_move(next)) return;
    current = next;
    next = block_.makeRandomBlock();
}

void Game::place_down() {
    int drop_length = Game::drop_length();
    while (drop_length > 0) {
        current.y++;
        drop_length = Game::drop_length();
    }
}

void Game::rotate() {
    Block temp = current;
    if (temp.rotation > 2) temp.rotation = 0;
    else temp.rotation++;

    if (board_.good_move(temp)) {
        current = temp;
    }
}

void Game::raise_score(int num) {
    lines_cleared += num;
    score += 10 * num;
    if (score % 100 == 0 && score != 0) {
        level++;
    }
}

int Game::drop_length() {
    int length = 0;
    Block temp = current;
    for (; board_.good_move(temp); length++) {
        temp.y++;
    }
    return length - 1;
}


void Game::on_frame() {

    if (board_.game_over()) game_over = true;
    if (game_over) return;
    int drop_length = Game::drop_length();
    if (drop_length > 0) current.y += level * 0.005;
    if (drop_length == 0) {
        make_block();
    }
}

void Game::launch() {
    make_block();
}

