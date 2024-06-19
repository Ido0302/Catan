#ifndef PROGRESSCARD_HPP
#define PROGRESSCARD_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <memory>

#include "DevelopmentCard.hpp"
#include "Player.hpp"

class Player;

using namespace std;

class ProgressCard : public DevelopmentCard
{
private:
    string progressType;
public:
    ProgressCard(string progressType);
    string getProgressType();
    string getDevelopmentType() override;
    void playCard(vector<Player*>& p, size_t i, Board& b) override;

    void roadBuilding(Player* p, Board& b);
    void plentyYear(Player* p);
    void monopoly(vector<Player*>&p, size_t i);

};

#endif