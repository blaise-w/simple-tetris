#pragma once

enum BlockType
{
    O, I, T, S, Z, L, J
};


class Block
{
public:

    Block();

    float x;
    float y;
    int rotation;
    BlockType block_type;
    int block_color;

    Block makeRandomBlock();

    static BlockType getRandomBlockType();

    static int getRandomColor();

    static int getCell(Block block, int u, int v);

    int getStartX(Block block) const;

    static int getStartY(Block block);

};