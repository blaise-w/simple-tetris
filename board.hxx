#pragma once
#include "Block.hxx"

const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 20;

class Board
{
public:
    explicit Board();

    bool good_move(Block block) const;
    void add_block(Block block);
    int find_filled_lines();
    void clear_line(int y);

    bool game_over();

    bool inbounds(int x, int y) const;

    int grid[GRID_WIDTH][GRID_HEIGHT];
};
