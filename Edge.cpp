#include <iostream>
#include <stdexcept>
#include <vector>

#include "Vertex.hpp"
#include "Edge.hpp"

using namespace std;

// constructor
Edge::Edge(Vertex *v1, Vertex *v2) : v1(v1), v2(v2){};

int Edge::getV1()
{
    return this->v1->getVertex();
}

int Edge::getV2()
{
    return this->v2->getVertex();
}

Vertex *Edge::getV1Address()
{
    return this->v1;
}

Vertex *Edge::getV2Address()
{
    return this->v2;
}

int Edge::getColor()
{
    return this->color;
}
void Edge::setColor(int color)
{
    this->color = color;
}

bool Edge::isEmpty()
{
    return this->clear;
}

void Edge::build()
{
    this->clear = false;
}

bool Edge::isEqual(int index1, int index2)
{
    if (index1 == this->getV1() && index2 == this->getV2() || index1 == this->getV2() && index2 == this->getV1())
        return true;
    return false;
}
