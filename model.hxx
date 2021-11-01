#pragma once
#include "board.hxx"
#include <ge211.hxx>



class Game
{
private:

    Block block_;

public:
    // constructor
    explicit Game();

    // start
    void launch();

    // movement
    void move_right();

    void move_left();

    void move_down();

    void place_down();

    void rotate();

    void on_frame();

    void make_block();


    Block current;

    int score;

    void raise_score(int num);

    int lines_cleared;

    bool game_over;

    Board board_;

    int level;

    int drop_length();

    Block next;

};