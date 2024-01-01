#include <iostream>
#include <vector>
#include "arena.h"
#include <random>

void Arena(MyCharacter &person) {
    //walka daje 2xp i 1 golda, każdy level to ilość xp które trzeba wbiać do kolejnego, czyli 1 level - 1xp zeby miec 2, 2 level - 2xp, 3 level - 3xp, żeby łatwiej było to napisac
    std::cout << "Welcome in Arena! Face your opponent! His level is: " << person.level << std::endl;

    std::string name = "Opponent";

    std::vector<int> data = RandomOpponentStats(person);
    MyCharacter opponent = MyCharacter(name,data[0],data[1],data[2],data[3],0,0,0,person.level,0);

    int opponentHealth = opponent.health * 10;
    int personHealth = person.health * 10;

    std::cout << "And stats: "  << std::endl;
    opponent.showStats();
    std::cout << std::endl;

    while (opponentHealth > 0 && personHealth > 0) {
        opponentHealth -= opponent.defense / 2 + person.power;
        personHealth -= person.defense / 2 + opponent.power;
    }
    if (personHealth > opponentHealth || personHealth == opponentHealth) {
        person.xp += 2;
        if (person.xp > person.level) {
            person.level += 1;
            person.xp = person.level - person.xp;
        }
        person.gold += 1;
        std::cout << "You've won! If you answer my question correct you can gain \n additional gold or even stats upgrade, but if you are wrong, you will loose \n"
                     "earnings for this fight! Your call!";
    } else std::cout << "You've lost! It will cost you gold, unless you answer my question! Are you ready? "; // zrobić te pytania w tym miejscu i będzie skończona arena
}

std::vector <int> RandomOpponentStats(MyCharacter person) {
    std::vector<int> data;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(-1, 1);

    int power = distribution(generator);
    int agility = distribution(generator);
    int health = distribution(generator);
    int defense = distribution(generator);

    power = power + person.power;
    agility = agility + person.agility;
    health = health + person.health;
    defense = person.defense;

    data.push_back(power);
    data.push_back(agility);
    data.push_back(health);
    data.push_back(defense);

    return data;
}
