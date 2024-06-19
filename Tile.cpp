#include <iostream>
#include <stdexcept>
#include <vector>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tile.hpp"

using namespace std;

// constructor
Tile::Tile(vector<Vertex *> &vertices, vector<Edge *> &edges, int circleNumber, Land l)
{
    // if the vector of vertices contains more than or less than 6 vertices
    if (vertices.size() != 6)
        __throw_invalid_argument("Invalid tile: The tile should to be with six vertices.");
    this->junctions = vertices;

    // if the vector of edges contains more than or less than 6 vertices
    if (edges.size() != 6)
        __throw_invalid_argument("Invalid tile: The tile should to be with six edges.");
    this->lanes = edges;

    // if the circle number isn't ideal roll
    if (circleNumber < 2 || circleNumber > 12)
        __throw_invalid_argument("Invalid roll: the roll should be between 2 to 12");
    this->circleNumber = circleNumber;

    this->land = l;
}

// constructor desert tile who doesn't include circle number or Land
Tile::Tile(vector<Vertex *> &vertices, vector<Edge *> &edges)
{
    if (vertices.size() != 6)
        __throw_invalid_argument("Invalid tile: The tile should to be with six vertices.");
    this->junctions = vertices;

    if (edges.size() != 6)
        __throw_invalid_argument("Invalid tile: The tile should to be with six edges.");
    this->lanes = edges;

    this->land = Land::Desert;
    this->circleNumber = 0;
}

Tile::~Tile(){}

vector<Vertex *> &Tile::getJunctions()
{
    return this->junctions;
}

vector<Edge *> &Tile::getLanes()
{
    return this->lanes;
}

int Tile::getCircleNumber()
{
    return this->circleNumber;
}

Land Tile::getLand()
{
    switch (this->land)
    {
    case Land::Hill:
        return Land::Hill;
    case Land::Forest:
        return Land::Forest;
    case Land::Mountain:
        return Land::Mountain;
    case Land::Field:
        return Land::Field;
    case Land::Pasture:
        return Land::Pasture;
    }
    return Land::Desert;
}

// get function that return the string of the Land
string Tile::getLandAsString()
{
    switch (this->land)
    {
    case Land::Hill:
        return "Hill";
    case Land::Forest:
        return "Forest";
    case Land::Mountain:
        return "Mountain";
    case Land::Field:
        return "Field";
    case Land::Pasture:
        return "Pasture";
    }
    return "Desert";
}

void Tile::printTile()
{
    cout << "The land: " << this->getLandAsString() << ". The circle number: " << this->circleNumber << endl;
}

/**
 * get vertex and return true if it's belong to tile. else rerurn false
 */
bool Tile::foundVertex(Vertex *v)
{
    for (size_t i = 0; i < TILE_LENGTH; i++)
    {
        if (junctions[i]->getVertex() == v->getVertex())
        {
            return true;
        }
    }
    return false;
}
