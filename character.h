#include <iostream>
#include <vector>

#ifndef CHARACTER_H
#define CHARACTER_H


class MyCharacter {
public:
    std::string name;
    int power, agility, health, defense, luck, gold, xp, level, statsAdded;
    MyCharacter(std::string& name, int power, int agility, int health, int defense, int luck, int gold, int xp, int level, int statsAdded);
    void showStats ();
    void AddStats();
};

void Character(MyCharacter &person);

#endif