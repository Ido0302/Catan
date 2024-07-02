#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tile.hpp"

using namespace std;

class Board{
    private:
    vector<Tile> tiles;

    public:
    Board();
    vector<Tile>& getBoard();
    void printBoard();

};

#endif