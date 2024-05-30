#include <iostream>
#include <stdexcept>
#include <vector>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tile.hpp"

using namespace std;

// constructor
Tile::Tile(vector<Vertex> &vertices, int roll, Resource r)
{
    if (vertices.size() != 6)
        __throw_invalid_argument("Invalid tile: The tile should to be with six vertices.");
    this->junctions = vertices;

    for (size_t i = 0; i < 5; i++)
    {
        this->lanes.emplace_back(vertices[i], vertices[i + 1]);
    }
    this->lanes.emplace_back(vertices.back(), vertices.front());

    if (roll < 2 || roll > 12)
        __throw_invalid_argument("Invalid roll: the roll should be between 2 to 12");
    this->rollDices = roll;

    this->resource = r;
}

//constructor desert tile
Tile::Tile(vector<Vertex> &vertices)
{
    if (vertices.size() != 6)
        __throw_invalid_argument("Invalid tile: The tile should to be with six vertices.");
    this->junctions = vertices;

    for (size_t i = 0; i < 5; i++)
    {
        this->lanes.emplace_back(vertices[i], vertices[i + 1]);
    }
    this->lanes.emplace_back(vertices.back(), vertices.front());

    this->resource = Resource::Desert;
    this->rollDices = 0;
}

vector<Vertex> &Tile::getJunctions()
{
    return this->junctions;
}

vector<Edge> &Tile::getLanes()
{
    return this->lanes;
}

int Tile::getRollDices()
{
    return this->rollDices;
}

string Tile::getResource()
{
    switch (this->resource)
    {
    case Resource::Hill:
        return "Hill";
    case Resource::Forest:
        return "Forest";
    case Resource::Mountain:
        return "Mountain";
    case Resource::Field:
        return "Field";
    case Resource::Pasture:
        return "Pasture";
    }
    return "Desert";
}
