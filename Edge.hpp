#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

#include "Vertex.hpp"

using namespace std;

class Edge
{
private:
    Vertex* v1;
    Vertex* v2;
    int color = 0;
    bool clear = true;

public:
    Edge(Vertex* v1, Vertex* v2);
    int getV1();
    int getV2();
    Vertex* getV1Address();
    Vertex* getV2Address();
    int getColor();
    void setColor(int color);
    bool isEmpty();
    void build();
    bool isEqual(int index1, int index2);

};



#endif