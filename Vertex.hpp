#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

#define red 1
#define orange 2
#define white 3

class Vertex
{
private:
    int index; // 0-53
    int color = 0;
    bool clear = true;

public:
    Vertex(int index);
    ~Vertex();
    
    int getVertex();
    int getColor();
    void setColor(int color);
    bool isEmpty();
    void build();
};

#endif