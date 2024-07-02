#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <limits>

#include "Person.hpp"
#include "Player.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tile.hpp"
#include "Board.hpp"
#include "Catan.hpp"

using namespace std;

Player::Player(const string name, int age, int color) : Person::Person(name, age), color(color), resources(5, 0){};

int Player::getPoints()
{
    return this->points;
}

/**
 * get index that display how much points to add
 */
void Player::setPoints(int increasePoints)
{
    this->points += increasePoints;
}

int Player::getColor()
{
    return this->color;
}

vector<int> Player::getResources()
{
    return this->resources;
}

int Player::getResourceFromString(string res)
{
    if (res == "brick")
        return brick;
    if (res == "lumber")
        return lumber;
    if (res == "iron")
        return iron;
    if (res == "wheat")
        return wheat;
    if (res == "wool")
        return wool;
    return -1;
}

vector<Edge *> Player::getRoads()
{
    return this->roads;
}

vector<Vertex *> Player::getSettlements()
{
    return this->settlements;
}

vector<Vertex *> Player::getCities()
{
    return this->cities;
}

/**
 * print description abot player
 */
void Player::printPlayer()
{
    cout << "Name: " << this->getName() << endl
         << "Age: " << this->getAge() << endl;
    if (color == 1)
        cout << "Color: Red" << endl;
    if (color == 2)
        cout << "Color: Orange" << endl;
    if (color == 3)
        cout << "Color: White" << endl;
    cout << "Points: " << this->getPoints() << endl;
    cout << endl;
}

/**
 * The function get two indexes of verteices that represening edge in the board.
 * If the build on this edge is available- build road.
 */
void Player::placeRoad(int junction1, int junction2, Board &b)
{
    Edge *e = b.findEdge(junction1, junction2);
    if (!isValidLane(e, b)) // If was not an exeption - go on
        __throw_invalid_argument("Building failed! You don't have any road, settlement or city that adjacent to lane");

    e->build();               // build on that lane
    e->setColor(this->color); // paint the lane to player's color
    roads.push_back(e);       // add the edge to player's vector of roads
    cout << this->getName() << " build new road on lane " << "(" << junction1 << "," << junction2 << ")" << endl
         << endl;
}

// get edge and return true if it's possible to build new settlement on that edge
bool Player::isValidLane(Edge *e, Board &b)
{
    // if the edge does not found
    if (e == NULL)
        __throw_invalid_argument("Failed indexes: No exist edge with these indexes in the board");

    // if the lane does not empty
    if (e->isEmpty() == false)
        __throw_invalid_argument("Building failed! The lane isn't empty");

    // First, check if there are settlemen or city-with the same color of the player-on any vertex of edge
    if (e->getV1Address()->getColor() == this->color || e->getV2Address()->getColor() == this->color)
        return true;

    // Second, check if there are roads-with the same color of the player-that intersection with any vertex of edge
    vector<Edge *> lanesNeighborhood1 = b.edgesIntersection(e->getV1Address());
    for (size_t i = 0; i < lanesNeighborhood1.size(); i++)
    {
        if (lanesNeighborhood1[i] != e && lanesNeighborhood1[i]->getColor() == this->color)
            return true;
    }
    vector<Edge *> lanesNeighborhood2 = b.edgesIntersection(e->getV2Address());
    for (size_t i = 0; i < lanesNeighborhood2.size(); i++)
    {
        if (lanesNeighborhood2[i] != e && lanesNeighborhood2[i]->getColor() == this->color)
            return true;
    }
    return false;
}

/**
 * The function get index of vertex and the board.
 * If the vertex exists in board and is empty - build settlement on that vertex
 */
void Player::placeSettlement(int junction, Board &b)
{
    Vertex *v = b.findVertex(junction); // v has the address of vertex that his index is junction in board

    if (!isValidJunction(v, b))
        __throw_invalid_argument("Building failed! You don't have any road that leads to junction");

    v->build();               // build on that junction
    v->setColor(this->color); // paint the lane to player's color
    points++;                 // take more point
    settlements.push_back(v); // add the vertex to player's vector of settlements
    cout << this->getName() << " build new settlement on junction " << v->getVertex() << endl;
    cout << endl;

    // get resources after place two settlements before the game start
    if (settlements.size() == 2)
        this->getBeginnersResource(b);
}

// get a vertex and return true if it's possible to build on that vertex
bool Player::isValidJunction(Vertex *v, Board &b)
{
    // if vertex not found
    if (v == NULL)
        __throw_invalid_argument("Failed index: No exist vertex with this index in the board");

    // if junction is not empty
    if (v->isEmpty() == false)
        __throw_invalid_argument("Building failed: The lane is not empty");

    // Distance Rule - check if does not exist settlements or cities that adjacent to v
    vector<Edge *> lanesNeighborhood = b.edgesIntersection(v);
    for (size_t i = 0; i < lanesNeighborhood.size(); i++)
    {
        if (lanesNeighborhood[i]->getV1Address()->isEmpty() == false || lanesNeighborhood[i]->getV2Address()->isEmpty() == false)
            __throw_invalid_argument("Building failed according 'Distance Rule'");
    }

    // If this is build of the begin of game
    if (settlements.size() + cities.size() < 2)
        return true;

    // Finally, check if there are exist roads that leads to v
    for (size_t i = 0; i < lanesNeighborhood.size(); i++)
    {
        if (lanesNeighborhood[i]->getColor() == this->color)
            return true;
    }
    return false;
}

/**
 * Each player get resources from lands that his settlememts limits them
 */
void Player::getBeginnersResource(Board &b)
{
    for (size_t i = 0; i < this->settlements.size(); i++)
    {
        vector<Tile> intersection = b.tilesIntersection(settlements[i]);
        for (size_t i = 0; i < intersection.size(); i++)
        {
            addResource(intersection[i].getLand());
        }
    }
    printResources();
}

void Player::setResources(int typeResource, int newCount)
{
    resources[(size_t)typeResource] = newCount;
}

/**
 * The function get land and increase the count of the resource that belongs to land at player's vector of resources
 */
void Player::addResource(Land land)
{
    switch (land)
    {
    case Land::Hill:
    {
        resources[brick]++;
        return;
    }
    case Land::Forest:
    {
        resources[lumber]++;
        return;
    }
    case Land::Mountain:
    {
        resources[iron]++;
        return;
    }
    case Land::Field:
    {
        resources[wheat]++;
        return;
    }
    case Land::Pasture:
    {
        resources[wool]++;
        return;
    }
    }
    return;
}

void Player::printResources()
{
    cout << this->getName() << " has the resources:";
    size_t i = 0;
    cout << " Brick: " << resources[i++];
    cout << ", Lumber: " << resources[i++];
    cout << ", Iron: " << resources[i++];
    cout << ", Wheat: " << resources[i++];
    cout << ", Wool: " << resources[i++];
    cout << endl
         << endl;
}

// return number in range(1,6)
int Player::rollCube()
{
    // Scale and shift the random number to the desired range (1 to 6)
    return 1 + (rand() % 6);
}

/**
 * random number in range(2,12)
 * if it's 7 - call giveBackResources
 * else - call shareResources
 */
void Player::rollDice(Catan &catan, vector<Player *> &p)
{

    if (this->getName() != catan.getPlayers()[catan.currentTurn]->getName())
        __throw_invalid_argument("Roll failed. It's not your turn!");

    int cube1 = rollCube();
    int cube2 = rollCube();

    int result = cube1 + cube2;
    cout << "The result is: " << result << endl
         << endl;

    if (result == 7)
    {
        cout << "All players need to divide them resources" << endl;
        catan.giveBackResources(p);
    }
    else
        catan.shareResources(p, result);
}

// get two indexes that represent edge and build new road on it(if possible)
void Player::buildRoad(int junction1, int junction2, Board &b)
{
    if (resources[brick] < 1 || resources[lumber] < 1)
    {
        cout << "You have not enough resources to build new road" << endl;
        return;
    }
    placeRoad(junction1, junction2, b);
    resources[brick]--;
    resources[lumber]--;
}

// get index represens vertes and build new settlement on it(if possible)
void Player::buildSettlement(int junction, Board &b)
{

    if (resources[brick] < 1 || resources[lumber] < 1 || resources[wheat] < 1 || resources[wool] < 1)
    {
        cout << "You have not enough resources to build new settlement" << endl;
        return;
    }
    placeSettlement(junction, b);
    resources[brick]--;
    resources[lumber]--;
    resources[wheat]--;
    resources[wool]--;
}

// get index represens vertex of settlement and build new city on it(if possible)
void Player::buildCity(int junction, Board &b)
{
    if (resources[iron] < 3 || resources[wheat] < 2)
    {
        cout << "You have not enough resources to build new city" << endl;
        return;
    }

    Vertex *v = b.findVertex(junction);
    if (v->getColor() != this->color)
        __throw_invalid_argument("Build failed! You cann't build city here because you haven't settlement on this junction");

    points += 1;         // take more 1 points
    cities.push_back(v); // add the vertex to player's vector of cities
    // remove the vertex from player's vector of settlements
    size_t i = 0;
    // Vertex* u = this->settlements[0];
    // while (u->getVertex() != v->getVertex())
    // {
    //     i++;
    //     u = this->settlements[i];
    // }
    // this->settlements.;

    if (this->settlements.size() == 1)
    {
        auto it = this->settlements.begin();
        this->settlements.erase(it);
    }
    else
    {
        for (auto it = this->settlements.begin(); it != this->settlements.end(); ++it)
        {
            if ((*it) == v)
                it = this->settlements.erase(it);
        }
    }
    resources[iron] -= 3;
    resources[wheat] -= 2;

    cout << this->getName() << " build new city on junction " << v->getVertex() << endl;
    cout << endl;
}

/**
 * The function get player, resource to trade, resource to take and their count.
 * The functin ask the player if he agree to trade (if possible)
 */
void Player::trade(Player *p, string yourResource, int countReceive, string myResource, int countGive)
{
    size_t wantedResource = (size_t)p->getResourceFromString(yourResource);
    size_t unwantedResource = (size_t)this->getResourceFromString(myResource);

    if (this->resources[unwantedResource] < countGive || p->resources[wantedResource] < countReceive)
    {
        cout << "Deal Failed! You don't have resources enough" << endl;
        return;
    }

    cout << p->getName() << ", do you want to trade " << countReceive << " " << yourResource << " instead of " << countGive << " " << myResource << " with " << this->getName() << "? [Y/n] ";
    char answer = getchar(); // get answer (Yes/No) from the player

    if (answer == 'Y')
    {
        this->resources[wantedResource] += countReceive;
        this->resources[unwantedResource] -= countGive;
        p->setResources(wantedResource, p->getResources()[wantedResource] - countReceive);
        p->setResources(unwantedResource, p->getResources()[unwantedResource] + countGive);

        cout << endl
             << this->getName() << " and " << p->getName() << " have a deal!" << endl;
        cout << "The new resources are:" << endl;
        this->printResources();
        p->printResources();
    }

    else
        cout << p->getName() << " didn't agree to the deal" << endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clean the buffer for the next trade
}

int Player::getKnights() { return this->knights; }
void Player::addKnights() { this->knights++; }
bool Player::hasLargestArmy() { return largestArmy;}
void Player::lossLargestArmy() { this->largestArmy = false; }

/**
 * Every time that player get development card from type "knights" he called to this function.
 * The function check if the player has 3 or more knights more over each other player.
 * If he has, the function uodate the boolean varriable "largestArmy" for all players
 * and the generall boolean variable "largestArmy"
 */
void Player::reachLargestArmy(Catan &catan, vector<Player *> &p)
{
    if (this->knights >= 3 && this->knights > catan.mostKnights)
    {
        cout << this->getName() << " acheive the largest army" << endl;
        catan.mostKnights = this->knights;
        for (size_t i = 0; i < p.size(); i++)
        {
            if (p[i]->getName() == this->getName())
                this->largestArmy = true;
            else
                p[i]->lossLargestArmy();
        }
    }
}

/**
 * The function random number between 1 to 5
 * The number represents the index of the decelopment cards which in catan's vector of cards 
 * If the number is index of developmend card "knights" - check if the player get the "largest army"
 * If the player has not resources enough - return
 */
void Player::buyDevelopmentCard(Catan &catan, vector<Player *> &p, Board &b)
{
    if (resources[iron] < 1 || resources[wheat] < 1 || resources[wool] < 1)
    {
        cout << "You have not enough resources to buy a development card" << endl;
        return;
    }

    int randomCard = (rand() % 5); // random number(1,5) that represents index in catan's vector of develpment cards
    catan.getCards()[(size_t)randomCard]->playCard(p, catan.currentTurn, b);

    if (randomCard == 1) // if the card is a knight
        this->reachLargestArmy(catan, p);
}


void Player::cleanPlayer()
{
    roads.clear();
    settlements.clear();
    cities.clear();
}
