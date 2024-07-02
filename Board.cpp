#include <iostream>
#include <stdexcept>
#include <vector>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tile.hpp"
#include "Board.hpp"

using namespace std;

// constructor
Board::Board()
{

    // create all junctions in the board

    vector<Vertex> vertices;
    for (size_t i = 0; i < 54; i++)
    {
        vertices.emplace_back(i);
    }

    vector<Vertex> junctions;
    int roll;
    Resource resource;

    // create tile 1
    for (size_t i = 0; i <= 5; i++)
    {
        junctions.push_back(vertices[i]);
    }
    roll = 10;
    resource = Resource::Mountain;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 2
    junctions.push_back(vertices[2]);
    for (size_t i = 6; i <= 9; i++)
    {
        junctions.push_back(vertices[i]);
    }
    junctions.push_back(vertices[3]);
    roll = 2;
    resource = Resource::Pasture;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 3
    junctions.push_back(vertices[7]);
    for (size_t i = 10; i <= 12; i++)
    {
        junctions.push_back(vertices[i]);
    }
    junctions.push_back(vertices[13]);
    junctions.push_back(vertices[8]);
    roll = 9;
    resource = Resource::Forest;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 4
    junctions.push_back(vertices[13]);
    junctions.push_back(vertices[12]);
    for (size_t i = 14; i <= 17; i++)
    {
        junctions.push_back(vertices[i]);
    }
    roll = 10;
    resource = Resource::Hill;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 5
    junctions.push_back(vertices[9]);
    junctions.push_back(vertices[8]);
    junctions.push_back(vertices[13]);
    for (size_t i = 17; i <= 19; i++)
    {
        junctions.push_back(vertices[i]);
    }
    roll = 4;
    resource = Resource::Pasture;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 6
    junctions.push_back(vertices[4]);
    junctions.push_back(vertices[3]);
    junctions.push_back(vertices[9]);
    junctions.push_back(vertices[19]);
    junctions.push_back(vertices[20]);
    junctions.push_back(vertices[21]);
    roll = 6;
    resource = Resource::Hill;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 7
    junctions.push_back(vertices[16]);
    junctions.push_back(vertices[5]);
    junctions.push_back(vertices[4]);
    for (size_t i = 21; i <= 23; i++)
    {
        junctions.push_back(vertices[i]);
    }
    roll = 12;
    resource = Resource::Field;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 8
    junctions.push_back(vertices[23]);
    junctions.push_back(vertices[22]);
    for (size_t i = 24; i <= 27; i++)
    {
        junctions.push_back(vertices[i]);
    }
    roll = 9;
    resource = Resource::Field;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 9
    junctions.push_back(vertices[22]);
    junctions.push_back(vertices[21]);
    junctions.push_back(vertices[20]);
    junctions.push_back(vertices[29]);
    junctions.push_back(vertices[30]);
    junctions.push_back(vertices[24]);
    roll = 11;
    resource = Resource::Forest;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 10
    junctions.push_back(vertices[20]);
    junctions.push_back(vertices[19]);
    junctions.push_back(vertices[18]);
    junctions.push_back(vertices[31]);
    junctions.push_back(vertices[32]);
    junctions.push_back(vertices[29]);
    this->tiles.emplace_back(junctions);
    junctions.clear();

    // create tile 11
    junctions.push_back(vertices[18]);
    junctions.push_back(vertices[17]);
    junctions.push_back(vertices[16]);
    junctions.push_back(vertices[33]);
    junctions.push_back(vertices[34]);
    junctions.push_back(vertices[31]);
    roll = 3;
    resource = Resource::Forest;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 12
    junctions.push_back(vertices[16]);
    junctions.push_back(vertices[15]);
    junctions.push_back(vertices[35]);
    junctions.push_back(vertices[36]);
    junctions.push_back(vertices[37]);
    junctions.push_back(vertices[33]);
    roll = 8;
    resource = Resource::Mountain;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 13
    junctions.push_back(vertices[34]);
    junctions.push_back(vertices[33]);
    for (size_t i = 37; i <= 40; i++)
    {
        junctions.push_back(vertices[i]);
    }
    roll = 5;
    resource = Resource::Pasture;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 14
    junctions.push_back(vertices[32]);
    junctions.push_back(vertices[31]);
    junctions.push_back(vertices[34]);
    for (size_t i = 40; i <= 42; i++)
    {
        junctions.push_back(vertices[i]);
    }
    roll = 4;
    resource = Resource::Field;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 15
    junctions.push_back(vertices[30]);
    junctions.push_back(vertices[29]);
    junctions.push_back(vertices[32]);
    for (size_t i = 42; i <= 44; i++)
    {
        junctions.push_back(vertices[i]);
    }
    roll = 3;
    resource = Resource::Mountain;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 16
    junctions.push_back(vertices[25]);
    junctions.push_back(vertices[24]);
    junctions.push_back(vertices[30]);
    for (size_t i = 44; i <= 46; i++)
    {
        junctions.push_back(vertices[i]);
    }
    roll = 8;
    resource = Resource::Forest;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 17
    junctions.push_back(vertices[45]);
    junctions.push_back(vertices[44]);
    junctions.push_back(vertices[43]);
    for (size_t i = 47; i <= 49; i++)
    {
        junctions.push_back(vertices[i]);
    }
    roll = 5;
    resource = Resource::Hill;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 18
    junctions.push_back(vertices[43]);
    junctions.push_back(vertices[42]);
    junctions.push_back(vertices[41]);
    junctions.push_back(vertices[50]);
    junctions.push_back(vertices[51]);
    junctions.push_back(vertices[47]);
    roll = 6;
    resource = Resource::Field;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();

    // create tile 19
    junctions.push_back(vertices[41]);
    junctions.push_back(vertices[40]);
    junctions.push_back(vertices[39]);
    junctions.push_back(vertices[52]);
    junctions.push_back(vertices[53]);
    junctions.push_back(vertices[50]);
    roll = 11;
    resource = Resource::Pasture;
    this->tiles.emplace_back(junctions, roll, resource);
    junctions.clear();
}

vector<Tile> &Board::getBoard()
{
    return this->tiles;
}

void Board::printBoard()
{

    for (size_t t = 0; t < tiles.size(); t++)
    {
        cout << "Tile Number " << t + 1 << endl;
        cout << "The vertices: ";
        for (size_t i = 0; i < 6; i++)
        {
            cout << tiles[t].getJunctions()[i].getVertex() << " ";
        }

        cout << endl
        << "The edges: ";
        for (size_t i = 0; i < 6; i++)
        {
            cout << "(" << tiles[t].getLanes()[i].getV1().getVertex() << "," << tiles[t].getLanes()[i].getV2().getVertex() << ") ";
        }
        cout << endl
             << "The resource: " << tiles[t].getResource() << ". The circle number: " << tiles[t].getRollDices() << endl;
        cout << "*************" << endl;
    }
}