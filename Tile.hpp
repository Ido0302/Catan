#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

#include "Vertex.hpp"
#include "Edge.hpp"

#define TILE_LENGTH 6

using namespace std;

//differene types of terrain hexes
enum class Land
{
    Hill,
    Forest,
    Mountain,
    Field,
    Pasture,
    Desert
};

class Tile
{
private:
    vector<Vertex*> junctions;
    vector<Edge*> lanes;
    int circleNumber; //2-12
    Land land ;


public:
Tile(vector<Vertex*>& ver, vector<Edge*>& edges, int roll, Land l);
Tile(vector<Vertex*>& ver, vector<Edge*>& edges);
~Tile();

vector<Vertex*>& getJunctions();
vector<Edge*>& getLanes();
int getCircleNumber();
Land getLand();
string getLandAsString();
void printTile();
bool foundVertex(Vertex* v);

};

#endif