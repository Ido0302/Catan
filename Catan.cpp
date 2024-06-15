#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tile.hpp"
#include "Board.hpp"
#include "Catan.hpp"
#include "Player.hpp"

using namespace std;

// constructor
Catan::Catan(Player *p1, Player *p2, Player *p3)
{
    this->players.push_back(p1);
    this->players.push_back(p2);
    this->players.push_back(p3);

    this->currentTurn = 0;
}

vector<Player *> Catan::getPlayers()
{
    return this->players;
}

/**
 * return the index of oldest player
 */
size_t Catan::maxAge(vector<Player *> p)
{
    int age = p[0]->getAge();
    size_t index = 0;
    int max = age;
    for (size_t i = 1; i < p.size(); i++)
    {
        age = p[i]->getAge();
        if (age > max)
        {
            max = age;
            index = i;
        }
    }
    return index;
}

/**
 * sort the vector of players according their age (old->young)
 */
void Catan::chooseFirstPlayer()
{
    vector<Player *> p = this->players; // copy of vector

    size_t first = maxAge(p);        // return the index of the oldest player
    this->players[0] = p[first];     // place the oldest player in the beginning of verctor players
    p.erase(p.begin() + (int)first); // remove the player from copy

    size_t middle = maxAge(p);
    this->players[1] = p[middle];
    p.erase(p.begin() + (int)middle);

    this->players[2] = p[0]; // place the youngest player in the end of vector players

    cout << "The first player is: " << players[0]->getName() << endl;
    cout << "The second player is: " << players[1]->getName() << endl;
    cout << "The third player is: " << players[2]->getName() << endl;
    cout << endl;
}

void Catan::printPlayers()
{
    for (size_t i = 0; i < this->players.size(); i++)
    {
        this->players[i]->printPlayer();
    }
}

Board Catan::getBoard()
{
    Board b;
    return b;
}

void Catan::endTurn()
{
    currentTurn = (currentTurn + 1) % 3;
}

/**
 * The function get vector of players and rollNumber
 * The function finds who has settlemens or cities on junctions that limits with every tile with the rollNumber and add to player resources
 */
void Catan::shareResources(vector<Player *>& players, int rollNumber)
{
    vector<Tile> sameRollTiles = getBoard().findTiles(rollNumber);

    for (size_t i = 0; i < sameRollTiles.size(); i++) // go through all tiles with the current roll number
    {
        Tile t = sameRollTiles[i];
        for (size_t j = 0; j < players.size(); j++) // go through all players
        {
            Player *p = players[j];
            for (Vertex *v : p->getSettlements()) // go through all settlemens of player
            {
                if (t.foundVertex(v) == true)
                    p->addResource(t.getLand()); // add resource if one of the settlements is on tile
            }

            for (Vertex *v : p->getCities()) // go through all cities of player
            {
                if (t.foundVertex(v) == true)
                {
                    p->addResource(t.getLand()); // add double resorce if one of the cities is on tile
                    p->addResource(t.getLand());
                }
            }
        }
    }
}

/**
 * The function halve the count of each resource for all the players
 */
void Catan::giveBackResources(vector<Player*> &players)
{
    cout << "The new resources are:" << endl;
    size_t n = players[0]->getResources().size();
    vector<int> newResources(n, 0);

    for (size_t i = 0; i < players.size(); i++)
    {
        Player* p = players[i];
        int count = 0;

        // count all resources
        count += p->getResources()[brick];
        count += p->getResources()[lumber];
        count += p->getResources()[iron];
        count += p->getResources()[wheat];
        count += p->getResources()[wool];

        if (count > 7)
        {
            count % 2 ? (++count) /= 2 : count /= 2; // halve count. if odd - round up

            //make new resources's vector according the new count
            int r = 0;
            while (count > 0)
            {
                count--;
                newResources[(size_t)r]++;
                r < 4 ? ++r : r = 0;
            }

            //change the count of each resource to new count
            for (size_t j = 0; j < n; j++)
            {
                p->setResources(j, newResources[j]);
                newResources[j] = 0;
            }
        }
        p->printResources();
    }
}
