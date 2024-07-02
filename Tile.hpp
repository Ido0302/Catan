#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

#include "Vertex.hpp"
#include "Edge.hpp"

using namespace std;

//differene types of terrain hexes
enum class Resource
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
    vector<Vertex> junctions;
    vector<Edge> lanes;
    int rollDices; //2-12
    Resource resource ;


public:
Tile(vector<Vertex>& ver, int roll, Resource r);
Tile(vector<Vertex>& ver);
vector<Vertex>& getJunctions();
vector<Edge>& getLanes();
int getRollDices();
string getResource();

};

#endif