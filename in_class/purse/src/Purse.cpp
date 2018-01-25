#include "Purse.h"

Purse::Purse(int c, int s, int g)
{
    copper = silver = gold = 0;
    addGold(g);
    addSilver(s);
    addCopper(c);
}

void Purse::addCopper(int c)
{
    if(c < 0) c = 0;
    copper += c;
    if(copper >= 50) copperToSilver();
}

void Purse::copperToSilver()
{
    addSilver(copper / 50);
    copper %= 50;
}

void Purse::addSilver(int s)
{
    if(s < 0) s = 0;
    silver += s;
    if(silver >= 10) silverToGold();
}

void Purse::silverToGold()
{
    addGold(silver / 10);
    silver %= 10;
}

void Purse::addGold(int g)
{
    if(g < 0) g = 0;
    gold += g;
}

/**
 *  DEPRECATED
*/
void Purse::print()
{
    std::cout << "Gold: "   << gold   << std::endl
              << "Silver: " << silver << std::endl
              << "Copper: " << copper << std::endl;
}

Purse Purse::operator+(const int &c)
{
    Purse newPurse;
    newPurse.addGold(gold);
    newPurse.addSilver(silver);
    newPurse.addCopper(copper + c);

    return newPurse;
}

Purse Purse::operator+(const Purse &right)
{
    Purse newPurse;
    newPurse.addGold(gold + right.gold);
    newPurse.addSilver(silver + right.silver);
    newPurse.addCopper(copper + right.copper);

    return newPurse;
}

/**
 *  NOT ACCESSING PURSE NAMESPACE
*/
std::ostream& operator<<(std::ostream &o, const Purse &right)
{
    o << "[" << right.gold   << "G, " 
             << right.silver << "S, "
             << right.copper << "C]";

    return o;
}


