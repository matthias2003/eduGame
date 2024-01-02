#include <iostream>
#include <vector>
#include "arena.h"
#include <random>

void Arena(MyCharacter &person) {
    std::cout << "Welcome in Arena! Face your opponent! His level is: " << person.level << std::endl;

    std::string name = "Opponent";

    std::vector<double> data = RandomOpponentStats(person);
    MyCharacter opponent = MyCharacter(name, data[0], data[1], data[2], data[3], 0, 0, 0, person.level, 0);

    double opponentHealth = opponent.health * 10;
    double personHealth = person.health * 10;

    double opponentDefense = opponent.defense / ( opponent.level * 5);
    if (opponentDefense > 0.5) opponentDefense = 0.5;
    double personDefense = person.defense / ( person.level * 5);
    if (personDefense > 0.5) personDefense = 0.5;

    double opponentPower = opponent.power - (opponent.power * personDefense);
    double personPower = person.power - (person.power * opponentDefense);

    double opponentLuck = opponent.luck / ( opponent.level * 5);
    if (opponentLuck > 0.5) opponentLuck = 0.5;
    double personLuck= person.luck / ( person.level * 5);
    if (personLuck > 0.5) personLuck = 0.5;

    double opponentAgility = opponent.agility / ( opponent.level * 5);
    if (opponentAgility > 0.5) opponentAgility = 0.5;
    double personAgility= person.agility / ( person.level * 5);
    if (personAgility > 0.5) personAgility = 0.5;


    std::cout << opponentDefense;

    std::cout << "And stats: " << std::endl;
    opponent.showStats();
    std::cout << std::endl;

    while (opponentHealth > 0 && personHealth > 0) {
        opponentHealth -= personPower;
        personHealth -= opponentPower;
    }

    if (personHealth > opponentHealth || personHealth == opponentHealth) {
        person.xp += 2;
        if (person.xp > person.level) {
            person.xp = person.xp - person.level;
            person.level += 1;
        }
        person.gold += 1;
        std::cout
                << "You've won! If you answer my question correct you can gain \n additional gold, but if you are wrong, you will loose \n"
                   "earnings for this fight! Your call!" << std::endl;
        questionHandler();
    } else {
        std::cout << "You've lost! It will cost you gold, unless you answer my question! Are you ready? "; // zrobić te pytania w tym miejscu i będzie skończona arena
        questionHandler();
    }
}

std::vector <double> RandomOpponentStats(MyCharacter person) {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(-1, 1);

    double power = distribution(generator);
    double agility = distribution(generator);
    double health = distribution(generator);
    double defense = distribution(generator);

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

void questionHandler () {
    std::vector<std::string> options = {"Yes", "No"};
    int input;
    bool again = true;
    while (again) {
        for (int i = 0; i < 2; i++) {
            std::cout << i + 1 << " -> " << options[i] << std::endl;
        }
        std::cout << "Your choice: ";
        std::cin >> input;
        switch (input) {
            case 1:
                std::cout << "QUESTION HERE!";
                again = false;
                break;
            case 2:
                again = false;
                break;
            default:
                again = true;
                std::cout << "Wrong choice!" << std::endl;
                break;
        }
    }
}