#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tile.hpp"
#include "Board.hpp"

using namespace std;

// constructor
Board::Board()
{
    // create all junctions in the board
    vector<Vertex *> vertices;
    for (size_t i = 0; i < 54; i++)
    {
        Vertex *v = new Vertex(i);
        vertices.push_back(v);
    }

    Edge *e0 = new Edge(vertices[0], vertices[1]);
    Edge *e1 = new Edge(vertices[1], vertices[2]);
    Edge *e2 = new Edge(vertices[2], vertices[3]);
    Edge *e3 = new Edge(vertices[3], vertices[4]);
    Edge *e4 = new Edge(vertices[4], vertices[5]);
    Edge *e5 = new Edge(vertices[5], vertices[0]);
    Edge *e6 = new Edge(vertices[2], vertices[6]);
    Edge *e7 = new Edge(vertices[6], vertices[7]);
    Edge *e8 = new Edge(vertices[7], vertices[8]);
    Edge *e9 = new Edge(vertices[8], vertices[9]);
    Edge *e10 = new Edge(vertices[9], vertices[3]);
    Edge *e11 = new Edge(vertices[7], vertices[10]);
    Edge *e12 = new Edge(vertices[10], vertices[11]);
    Edge *e13 = new Edge(vertices[11], vertices[12]);
    Edge *e14 = new Edge(vertices[12], vertices[13]);
    Edge *e15 = new Edge(vertices[13], vertices[8]);
    Edge *e16 = new Edge(vertices[12], vertices[14]);
    Edge *e17 = new Edge(vertices[14], vertices[15]);
    Edge *e18 = new Edge(vertices[15], vertices[16]);
    Edge *e19 = new Edge(vertices[16], vertices[17]);
    Edge *e20 = new Edge(vertices[17], vertices[13]);
    Edge *e21 = new Edge(vertices[17], vertices[18]);
    Edge *e22 = new Edge(vertices[18], vertices[19]);
    Edge *e23 = new Edge(vertices[19], vertices[9]);
    Edge *e24 = new Edge(vertices[19], vertices[20]);
    Edge *e25 = new Edge(vertices[20], vertices[21]);
    Edge *e26 = new Edge(vertices[21], vertices[4]);
    Edge *e27 = new Edge(vertices[21], vertices[22]);
    Edge *e28 = new Edge(vertices[22], vertices[23]);
    Edge *e29 = new Edge(vertices[23], vertices[28]);
    Edge *e30 = new Edge(vertices[28], vertices[5]);
    Edge *e31 = new Edge(vertices[23], vertices[27]);
    Edge *e32 = new Edge(vertices[22], vertices[24]);
    Edge *e33 = new Edge(vertices[24], vertices[25]);
    Edge *e34 = new Edge(vertices[25], vertices[26]);
    Edge *e35 = new Edge(vertices[26], vertices[27]);
    Edge *e36 = new Edge(vertices[20], vertices[29]);
    Edge *e37 = new Edge(vertices[29], vertices[30]);
    Edge *e38 = new Edge(vertices[30], vertices[24]);
    Edge *e39 = new Edge(vertices[18], vertices[31]);
    Edge *e40 = new Edge(vertices[31], vertices[32]);
    Edge *e41 = new Edge(vertices[32], vertices[29]);
    Edge *e42 = new Edge(vertices[16], vertices[33]);
    Edge *e43 = new Edge(vertices[33], vertices[34]);
    Edge *e44 = new Edge(vertices[34], vertices[31]);
    Edge *e45 = new Edge(vertices[15], vertices[35]);
    Edge *e46 = new Edge(vertices[35], vertices[36]);
    Edge *e47 = new Edge(vertices[36], vertices[37]);
    Edge *e48 = new Edge(vertices[37], vertices[33]);
    Edge *e49 = new Edge(vertices[37], vertices[38]);
    Edge *e50 = new Edge(vertices[38], vertices[39]);
    Edge *e51 = new Edge(vertices[39], vertices[40]);
    Edge *e52 = new Edge(vertices[40], vertices[34]);
    Edge *e53 = new Edge(vertices[40], vertices[41]);
    Edge *e54 = new Edge(vertices[41], vertices[42]);
    Edge *e55 = new Edge(vertices[42], vertices[32]);
    Edge *e56 = new Edge(vertices[42], vertices[43]);
    Edge *e57 = new Edge(vertices[43], vertices[44]);
    Edge *e58 = new Edge(vertices[44], vertices[30]);
    Edge *e59 = new Edge(vertices[44], vertices[45]);
    Edge *e60 = new Edge(vertices[45], vertices[46]);
    Edge *e61 = new Edge(vertices[46], vertices[25]);
    Edge *e62 = new Edge(vertices[43], vertices[47]);
    Edge *e63 = new Edge(vertices[47], vertices[48]);
    Edge *e64 = new Edge(vertices[48], vertices[49]);
    Edge *e65 = new Edge(vertices[49], vertices[45]);
    Edge *e66 = new Edge(vertices[41], vertices[50]);
    Edge *e67 = new Edge(vertices[50], vertices[51]);
    Edge *e68 = new Edge(vertices[51], vertices[47]);
    Edge *e69 = new Edge(vertices[39], vertices[52]);
    Edge *e70 = new Edge(vertices[52], vertices[53]);
    Edge *e71 = new Edge(vertices[53], vertices[50]);

    vector<Vertex *> junctions;
    vector<Edge *> lanes;
    int roll;
    Land land;

    // create tile 1
    junctions.push_back(vertices[0]);
    junctions.push_back(vertices[1]);
    for (size_t i = 2; i <= 5; i++)
    {
        junctions.push_back(vertices[i]); // create a vector at size 6 with the specifc junctions that on tile
    }
    lanes.push_back(e0); // create a vector at size 6 with the specufic lanes that on tile
    lanes.push_back(e1);
    lanes.push_back(e2);
    lanes.push_back(e3);
    lanes.push_back(e4);
    lanes.push_back(e5);
    roll = 10;                                              // the specific circle number of the tile
    land = Land::Mountain;                                  // the specific landof the tile
    this->tiles.emplace_back(junctions, lanes, roll, land); // create new tile on board with the members of this tile (include vertor of edges from the vector of vertices)
    junctions.clear();
    lanes.clear(); // clear the vector of junctions for the next tile

    // repeat on that act another 18 times
    // each tile with his unique members

    // create tile 2
    junctions.push_back(vertices[2]);
    for (size_t i = 6; i <= 9; i++)
    {
        junctions.push_back(vertices[i]);
    }
    junctions.push_back(vertices[3]);
    lanes.push_back(e6);
    lanes.push_back(e7);
    lanes.push_back(e8);
    lanes.push_back(e9);
    lanes.push_back(e10);
    lanes.push_back(e2);
    roll = 2;
    land = Land::Pasture;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 3
    junctions.push_back(vertices[7]);
    for (size_t i = 10; i <= 12; i++)
    {
        junctions.push_back(vertices[i]);
    }
    junctions.push_back(vertices[13]);
    junctions.push_back(vertices[8]);
    lanes.push_back(e11);
    lanes.push_back(e12);
    lanes.push_back(e13);
    lanes.push_back(e14);
    lanes.push_back(e15);
    lanes.push_back(e8);
    roll = 9;
    land = Land::Forest;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 4
    junctions.push_back(vertices[13]);
    junctions.push_back(vertices[12]);
    for (size_t i = 14; i <= 17; i++)
    {
        junctions.push_back(vertices[i]);
    }
    lanes.push_back(e14);
    lanes.push_back(e16);
    lanes.push_back(e17);
    lanes.push_back(e18);
    lanes.push_back(e19);
    lanes.push_back(e20);
    roll = 10;
    land = Land::Hill;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 5
    junctions.push_back(vertices[9]);
    junctions.push_back(vertices[8]);
    junctions.push_back(vertices[13]);
    for (size_t i = 17; i <= 19; i++)
    {
        junctions.push_back(vertices[i]);
    }
    lanes.push_back(e9);
    lanes.push_back(e15);
    lanes.push_back(e20);
    lanes.push_back(e21);
    lanes.push_back(e22);
    lanes.push_back(e23);
    roll = 4;
    land = Land::Pasture;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 6
    junctions.push_back(vertices[4]);
    junctions.push_back(vertices[3]);
    junctions.push_back(vertices[9]);
    junctions.push_back(vertices[19]);
    junctions.push_back(vertices[20]);
    junctions.push_back(vertices[21]);

    lanes.push_back(e3);
    lanes.push_back(e10);
    lanes.push_back(e23);
    lanes.push_back(e24);
    lanes.push_back(e25);
    lanes.push_back(e26);
    roll = 6;
    land = Land::Hill;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 7
    junctions.push_back(vertices[28]);
    junctions.push_back(vertices[5]);
    junctions.push_back(vertices[4]);
    for (size_t i = 21; i <= 23; i++)
    {
        junctions.push_back(vertices[i]);
    }
    lanes.push_back(e30);
    lanes.push_back(e4);
    lanes.push_back(e26);
    lanes.push_back(e27);
    lanes.push_back(e28);
    lanes.push_back(e29);
    roll = 12;
    land = Land::Field;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 8
    junctions.push_back(vertices[23]);
    junctions.push_back(vertices[22]);
    for (size_t i = 24; i <= 27; i++)
    {
        junctions.push_back(vertices[i]);
    }
    lanes.push_back(e31);
    lanes.push_back(e28);
    lanes.push_back(e32);
    lanes.push_back(e33);
    lanes.push_back(e34);
    lanes.push_back(e35);
    roll = 9;
    land = Land::Field;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 9
    junctions.push_back(vertices[22]);
    junctions.push_back(vertices[21]);
    junctions.push_back(vertices[20]);
    junctions.push_back(vertices[29]);
    junctions.push_back(vertices[30]);
    junctions.push_back(vertices[24]);

    lanes.push_back(e27);
    lanes.push_back(e25);
    lanes.push_back(e36);
    lanes.push_back(e37);
    lanes.push_back(e38);
    lanes.push_back(e32);
    roll = 11;
    land = Land::Forest;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 10
    junctions.push_back(vertices[20]);
    junctions.push_back(vertices[19]);
    junctions.push_back(vertices[18]);
    junctions.push_back(vertices[31]);
    junctions.push_back(vertices[32]);
    junctions.push_back(vertices[29]);

    lanes.push_back(e24);
    lanes.push_back(e22);
    lanes.push_back(e39);
    lanes.push_back(e40);
    lanes.push_back(e41);
    lanes.push_back(e36);
    this->tiles.emplace_back(junctions, lanes);
    junctions.clear();
    lanes.clear();

    // create tile 11
    junctions.push_back(vertices[18]);
    junctions.push_back(vertices[17]);
    junctions.push_back(vertices[16]);
    junctions.push_back(vertices[33]);
    junctions.push_back(vertices[34]);
    junctions.push_back(vertices[31]);

    lanes.push_back(e21);
    lanes.push_back(e19);
    lanes.push_back(e42);
    lanes.push_back(e43);
    lanes.push_back(e44);
    lanes.push_back(e39);
    roll = 3;
    land = Land::Forest;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 12
    junctions.push_back(vertices[16]);
    junctions.push_back(vertices[15]);
    junctions.push_back(vertices[35]);
    junctions.push_back(vertices[36]);
    junctions.push_back(vertices[37]);
    junctions.push_back(vertices[33]);

    lanes.push_back(e18);
    lanes.push_back(e45);
    lanes.push_back(e46);
    lanes.push_back(e47);
    lanes.push_back(e48);
    lanes.push_back(e42);
    roll = 8;
    land = Land::Mountain;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 13
    junctions.push_back(vertices[34]);
    junctions.push_back(vertices[33]);
    for (size_t i = 37; i <= 40; i++)
    {
        junctions.push_back(vertices[i]);
    }
    lanes.push_back(e43);
    lanes.push_back(e48);
    lanes.push_back(e49);
    lanes.push_back(e50);
    lanes.push_back(e51);
    lanes.push_back(e52);
    roll = 5;
    land = Land::Pasture;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 14
    junctions.push_back(vertices[32]);
    junctions.push_back(vertices[31]);
    junctions.push_back(vertices[34]);
    for (size_t i = 40; i <= 42; i++)
    {
        junctions.push_back(vertices[i]);
    }
    lanes.push_back(e40);
    lanes.push_back(e44);
    lanes.push_back(e52);
    lanes.push_back(e53);
    lanes.push_back(e54);
    lanes.push_back(e55);
    roll = 4;
    land = Land::Field;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 15
    junctions.push_back(vertices[30]);
    junctions.push_back(vertices[29]);
    junctions.push_back(vertices[32]);
    for (size_t i = 42; i <= 44; i++)
    {
        junctions.push_back(vertices[i]);
    }
    lanes.push_back(e37);
    lanes.push_back(e41);
    lanes.push_back(e55);
    lanes.push_back(e56);
    lanes.push_back(e57);
    lanes.push_back(e58);
    roll = 3;
    land = Land::Mountain;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 16
    junctions.push_back(vertices[25]);
    junctions.push_back(vertices[24]);
    junctions.push_back(vertices[30]);
    for (size_t i = 44; i <= 46; i++)
    {
        junctions.push_back(vertices[i]);
    }
    lanes.push_back(e33);
    lanes.push_back(e38);
    lanes.push_back(e58);
    lanes.push_back(e59);
    lanes.push_back(e60);
    lanes.push_back(e61);
    roll = 8;
    land = Land::Forest;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 17
    junctions.push_back(vertices[45]);
    junctions.push_back(vertices[44]);
    junctions.push_back(vertices[43]);
    for (size_t i = 47; i <= 49; i++)
    {
        junctions.push_back(vertices[i]);
    }
    lanes.push_back(e59);
    lanes.push_back(e57);
    lanes.push_back(e62);
    lanes.push_back(e63);
    lanes.push_back(e64);
    lanes.push_back(e65);
    roll = 5;
    land = Land::Hill;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 18
    junctions.push_back(vertices[43]);
    junctions.push_back(vertices[42]);
    junctions.push_back(vertices[41]);
    junctions.push_back(vertices[50]);
    junctions.push_back(vertices[51]);
    junctions.push_back(vertices[47]);

    lanes.push_back(e56);
    lanes.push_back(e54);
    lanes.push_back(e66);
    lanes.push_back(e67);
    lanes.push_back(e68);
    lanes.push_back(e62);
    roll = 6;
    land = Land::Field;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();

    // create tile 19
    junctions.push_back(vertices[41]);
    junctions.push_back(vertices[40]);
    junctions.push_back(vertices[39]);
    junctions.push_back(vertices[52]);
    junctions.push_back(vertices[53]);
    junctions.push_back(vertices[50]);

    lanes.push_back(e53);
    lanes.push_back(e51);
    lanes.push_back(e69);
    lanes.push_back(e70);
    lanes.push_back(e71);
    lanes.push_back(e66);
    roll = 11;
    land = Land::Pasture;
    this->tiles.emplace_back(junctions, lanes, roll, land);
    junctions.clear();
    lanes.clear();
}

vector<Tile> &Board::getBoard()
{
    return this->tiles;
}

/**
 * print all tiles in board
 */

void Board::printBoard()
{
    for (size_t t = 0; t < tiles.size(); t++)
    {
        cout << "Tile Number " << t + 1 << endl;

        // print tile's vertices
        cout << "The junctions: ";
        for (size_t i = 0; i < TILE_LENGTH; i++)
        {
            cout << tiles[t].getJunctions()[i]->getVertex() << " ";
        }
        cout << endl
             << "The lanes: ";

        // print tile's edges (the shape-(v1, v2)-of the edge)
        for (size_t i = 0; i < TILE_LENGTH; i++)
        {
            cout << "(" << tiles[t].getLanes()[i]->getV1() << "," << tiles[t].getLanes()[i]->getV2() << ") ";
        }
        cout << endl;

        tiles[t].printTile(); // print tile's land and circle number
        cout << "*************" << endl;
    }
}

/**
 * The function get index and return the address of vertex with this index if exist in the board
 * else, print messagge and return null
 */
Vertex *Board::findVertex(int index)
{
    Vertex *addressOfIndex = NULL;

    for (size_t i = 0; i < this->tiles.size(); i++) // go over all tiles in board
    {
        for (size_t j = 0; j < TILE_LENGTH; j++) // go over all vertecis in tail
        {
            if (this->tiles[i].getJunctions()[j]->getVertex() == index)
            {
                // check if find the required vertex in board
                addressOfIndex = this->tiles[i].getJunctions()[j];
                return addressOfIndex;
            }
        }
    }
    return addressOfIndex;
}

/**
 * The function get two indexes and return the address of edge with these indexes if exist in the board
 * else, print messagge and return null
 */

Edge *Board::findEdge(int index1, int index2)
{
    if (this->findVertex(index1) == NULL || this->findVertex(index2) == NULL)
        __throw_invalid_argument("Failed index: No exist vertex with that index in the board");

    Edge *addressOfEdge = NULL;

    for (size_t i = 0; i < this->tiles.size(); i++) // go over all tiles in board
    {
        for (size_t j = 0; j < TILE_LENGTH; j++) // go over all vertecis in tail
        {
            if (this->tiles[i].getLanes()[j]->isEqual(index1, index2))
            { // check if find the required vertex in board
                addressOfEdge = this->tiles[i].getLanes()[j];
                return addressOfEdge;
            }
        }
    }
    return addressOfEdge;
}

/**
 * The function get circleNumber and return vector of tiles that has this number
 */
vector<Tile> Board::findTiles(int rollNumber)
{
    vector<Tile> sameRollTiles;
    for (size_t i = 0; i < this->tiles.size(); i++)
    {
        if (tiles[i].getCircleNumber() == rollNumber)
            sameRollTiles.push_back(tiles[i]);
    }
    return sameRollTiles;
}

/**
 *
 */
vector<Edge *> Board::edgesIntersection(Vertex *v)
{
    vector<Edge *> intersection;
    for (size_t i = 0; i < this->tiles.size(); i++)
    {
        Tile t = tiles[i];
        for (size_t j = 0; j < TILE_LENGTH; j++)
        {
            Edge *e = t.getLanes()[j];
            if (e->getV1() == v->getVertex() || e->getV2() == v->getVertex())
            {
                if (intersection.size() == 0)
                    intersection.push_back(e);
                if (intersection.size() == 1 && intersection[0] != e)
                    intersection.push_back(e);
                if (intersection.size() == 2 && intersection[0] != e && intersection[1] != e)
                    intersection.push_back(e);
                if (intersection.size() == 3)
                    return intersection;
            }
        }
    }
    return intersection;
}

/**
 * The function get vertex and return vector of the tiles that intersect in this vertex
 */
vector<Tile> Board::tilesIntersection(Vertex *v)
{
    vector<Tile> intersection;
    for (size_t i = 0; i < this->tiles.size(); i++)
    {
        Tile t = tiles[i];
        for (size_t j = 0; j < TILE_LENGTH; j++)
        {
            if (t.getJunctions()[j]->getVertex() == v->getVertex())
            {
                intersection.push_back(t);
                break;
            }
        }
    }
    return intersection;
}

/**
 * Because all vertices and edges allocated maualy we should a specific function in order to free the memory manualy.
 * The function over tile by tile in order to avoid from duplicate free
 */
void Board::clearBoard()
{ 
    // delete tile 1
    for (size_t j = 0; j < TILE_LENGTH; j++)
    {
        delete (tiles[0].getJunctions()[j]);
        delete (tiles[0].getLanes()[j]);
    }

    // delete tiles 2,3
    for (size_t i = 1; i < 3; i++)
    {

        for (size_t j = 1; j < 5; j++)
        {
            delete (tiles[i].getJunctions()[j]);
            delete (tiles[i].getLanes()[j - 1]);
        }
        delete (tiles[i].getLanes()[4]);
    }

    // delete tile 4,5,6,7
    delete (tiles[3].getJunctions()[2]);
    delete (tiles[3].getLanes()[1]);
    for (size_t i = 3; i < 7; i++)
    {
        delete (tiles[i].getLanes()[2]);
    }
    delete (tiles[6].getJunctions()[0]);
    delete (tiles[6].getLanes()[0]);
    delete (tiles[6].getLanes()[5]);

    // delete tile 8
    for (size_t j = 0; j < TILE_LENGTH; j++)
    {
        delete (tiles[7].getJunctions()[j]);
        delete (tiles[7].getLanes()[j]);
    }

    // delete tiles 9,10,11,12
    for (size_t i = 8; i < 12; i++)
    {
        for (size_t j = 1; j < 5; j++)
        {
            delete (tiles[i].getJunctions()[j]);
            delete (tiles[i].getLanes()[j - 1]);
        }
        delete (tiles[i].getLanes()[4]);
    }

    // delete tiles 13,14,15,16
    delete (tiles[12].getJunctions()[3]);
    delete (tiles[12].getLanes()[2]);
    delete (tiles[12].getLanes()[3]);
    for (size_t i = 12; i < 16; i++)
    {
        delete (tiles[i].getLanes()[5]);
    }
    delete (tiles[15].getJunctions()[5]);
    delete (tiles[15].getLanes()[4]);

    // delete tiles 17,18,19
    delete (tiles[16].getJunctions()[0]);
    delete (tiles[16].getJunctions()[5]);
    delete (tiles[16].getLanes()[5]);
    for (size_t i = 16; i < 19; i++)
    {
        for (size_t j = 1; j < 5; j++)
        {
            delete (tiles[i].getJunctions()[j]);
            delete (tiles[i].getLanes()[j - 1]);
        }
        delete (tiles[i].getLanes()[4]);
    }

    for(Tile t : tiles)
    {
        t.getJunctions().clear();
        t.getLanes().clear();
    }
    tiles.clear();
}
