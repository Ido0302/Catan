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
    Vertex v1;
    Vertex v2;
    bool empty = true;

public:
    Edge(Vertex v1, Vertex v2);
    Vertex getV1();
    Vertex getV2();
    bool isEmpty();
    void build();

};



#endif