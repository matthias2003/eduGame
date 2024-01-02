#include <iostream>
#include <vector>

#ifndef CHARACTER_H
#define CHARACTER_H


class MyCharacter {
public:
    std::string name;
    double power, agility, health, defense, luck, gold, xp, level, statsAdded;
    MyCharacter(std::string& name, double power, double agility, double health, double defense, double luck, double gold, double xp, double level, double statsAdded);
    void showStats ();
    void AddStats();
};

void Character(MyCharacter &person);

#endif