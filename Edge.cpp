#include <iostream>
#include <stdexcept>
#include <vector>

#include "Vertex.hpp"
#include "Edge.hpp"

using namespace std;

// constructor
Edge::Edge(Vertex v1, Vertex v2) : v1(v1), v2(v2){};

Vertex Edge::getV1()
{
    return this->v1;
}

Vertex Edge::getV2()
{
    return this->v2;
}

bool Edge::isEmpty()
{
    return this->empty;
}

void Edge::build()
{
    if (isEmpty())
    {
        this->empty = false;
        cout << "The place is empty" << endl;
    }
    else
        cout << "Can not build here" << endl;
}
