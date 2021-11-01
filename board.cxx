#include "board.hxx"

const int PIECE_DIMS = 5;

bool Board::good_move(Block block) const {
    if (block.getStartY(block) > block.y) return false;
    int x = block.x;
    int y = block.y;
    for (int j = 0; j < PIECE_DIMS; j++) {
        for (int i = 0; i < PIECE_DIMS; i++) {
            if (block.getCell(block, i, j) != 0) {
                if ((x + i) < 0 || (x + i) > GRID_WIDTH - 1
                    || (y + j) > GRID_HEIGHT - 1) {
                    return false;
                }
                if (grid[x + i][y + j] != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Board::add_block(Block block) {
    int x = block.x;
    int y = block.y;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (block.getCell(block, i, j) != 0)
                grid[x + i][y + j] = block.getCell(block, i, j);
        }
    }
}

void Board::clear_line(int y) {
    for (int j = y; j > 0; j--) {
        for (int i = 0; i < GRID_WIDTH; i++) {
            grid[i][j] = grid[i][j-1];
        }
    }
}


int Board::find_filled_lines() {
    int cleared = 0;
    for (int j = 0; j < GRID_HEIGHT; j++) {
        bool full = true;
        for (int i = 0; i < GRID_WIDTH; i++) {
            if (grid[i][j] == 0) full = false;
        }
        if (full) {
            clear_line(j);
            cleared++;
        }
    }
    return cleared;
}


bool Board::game_over() {
    for (int i = 0; i < GRID_WIDTH; i++) {
        if (grid[i][0] != 0)
            return true;
    }
    return false;
}

Board::Board()
{
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            grid[i][j] = 0;
        }
    }
}

bool Board::inbounds(int x, int y) const {
    return (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT);
}
