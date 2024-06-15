#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tile.hpp"

using namespace std;

class Board
{

private:
    vector<Tile> tiles;

public:
    Board();
    // void initializeBoard();
    vector<Tile> &getBoard();
    void printBoard();
    Vertex *findVertex(int index);             // get index and return the address of vertex with this index
    Edge *findEdge(int index1, int index2);    // get 2 indexes and return the address of edge with these indexes
    vector<Tile> findTiles(int rollNumber);    // get number of roll and return all tiles with this number

    vector<Edge*> edgesIntersection(Vertex *v);      // get vertex and return all edge that meet in this vertex
    vector<Tile> tilesIntersection(Vertex *v);       // get vertex and retun all tile that meet in this vertex
};

#endif