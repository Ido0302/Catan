#include <iostream>
#include <stdexcept>
#include <vector>

#include "Vertex.hpp"

using namespace std;

// constructor
Vertex::Vertex(int index) : index(index)
{
    if (index < 0 || index > 53)
        __throw_invalid_argument("Invalid vertex: There are 54 vertices in board.");
}

Vertex::~Vertex(){}

int Vertex::getVertex()
{
    return this->index;
}


int Vertex::getColor()
{
    return this->color;
}

void Vertex::setColor(int color)
{
    this->color = color;
}

bool Vertex::isEmpty()
{
    return this->clear;
}

/**
 * "build settelment on vertex"
*/
void Vertex::build()
{
    this->clear = false;
}
