#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Vertex
{
private:
    int index; //0-53
    bool empty = true;

public:
    Vertex(int index);
    int getVertex();
    bool isEmpty();
    void build();
};

#endif