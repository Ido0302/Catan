#include <iostream>
#include <stdexcept>
#include <vector>

#include "Vertex.hpp"

using namespace std;

//constructor
Vertex::Vertex(int index) : index(index) {
    if (index < 0 || index > 53)
        __throw_invalid_argument("Invalid vertex: There are 54 vertices in board.");
}

int Vertex::getVertex()
{
    return this->index;
}

bool Vertex::isEmpty()
{
    return this->empty;
}

void Vertex::build()
{
    if (isEmpty()){
        this->empty = false;
        cout << "The place is empty" << endl;
    }
    else
        cout << "Can not build here" << endl;
}
