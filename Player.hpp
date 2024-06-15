#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>  
#include <limits>


#include "Person.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tile.hpp"
#include "Board.hpp"

class Catan;
using namespace std;

#define brick 0
#define lumber 1
#define iron 2
#define wheat 3
#define wool 4


class Player : public Person
{
private:
    int points = 0;
    int color;
    vector<int> resources;
    vector<Edge*> roads;
    vector<Vertex*> settlements;
    vector<Vertex*> cities;

public:

    Player(string name, int age, int color);
    void printPlayer();

    int getPoints();
    void setPoints(int increasePoints);
    int getColor();

    vector<int> getResources();                           // return player's resources
    int getResourceFromString(string r);                      // get resource at int and return it as string   
    void setResources(int typeResource, int newCount);    // get resource and change the count of it
    void addResource(Land land);                          //get land and add the product to player's resources
    void getBeginnersResource(Board &b);                  //add resources according the places of settlements
    void printResources();

    vector<Edge*> getRoads();            //return player's roads
    vector<Vertex*> getSettlements();    //return player's settlements
    vector<Vertex*> getCities();         //return player's cities

    void placeRoad(int junction1, int junction2, Board& b);
    bool isValidLane(Edge* e, Board& b);

    void placeSettlement(int junction, Board& b);
    bool isValidJunction(Vertex* v, Board& b);

    int rollCube();
    void rollDice(Catan& catan, vector<Player*>& p);

    void buildRoad(int junction1, int junction2, Board& b);
    void buildSettlement(int junction, Board& b);
    void buildCity(int junction, Board& b);

    void trade(Player* p, string wantedResource, int countReceive, string unwantedResource, int countGive);

};

#endif