#include <iostream>
#include <vector>
#include "arena.h"
#include <random>
#include "question.h"

void Arena(MyCharacter& person) {
    std::cout << "Welcome in Arena! Face your opponent! His level is: " << person.level << std::endl;

    std::string name = "Opponent";

    std::vector<double> data = RandomOpponentStats(person);
    MyCharacter opponent = MyCharacter(name, data[0], data[1], data[2], data[3], data[4], 0, 0, person.level, 0);

    double opponentHealth = opponent.health * 5;
    double personHealth = person.health * 5;

    double opponentDefense = opponent.defense / (opponent.level * 5);
    if (opponentDefense > 0.5) opponentDefense = 0.5;
    double personDefense = person.defense / (person.level * 5);
    if (personDefense > 0.5) personDefense = 0.5;

    double opponentPower = opponent.power - (opponent.power * personDefense);
    double personPower = person.power - (person.power * opponentDefense);

    double opponentLuck = opponent.luck / (opponent.level * 5);
    if (opponentLuck > 0.5) opponentLuck = 0.5;
    double personLuck = person.luck / (person.level * 5);
    if (personLuck > 0.5) personLuck = 0.5;

    double opponentAgility = opponent.agility / (opponent.level * 5);
    if (opponentAgility > 0.5) opponentAgility = 0.5;
    double personAgility = person.agility / (person.level * 5);
    if (personAgility > 0.5) personAgility = 0.5;

    int personCrit;
    int opponentCrit;

    std::cout << "And stats: " << std::endl;
    opponent.showStats();
    std::cout << std::endl;

    while (opponentHealth > 0 && personHealth > 0) {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(1, 100);
        
        personCrit = distribution(generator);
        opponentCrit = distribution(generator);

        if (personCrit < (personLuck * 100)) {
            std::cout << "Critical damage!" << std::endl;
            opponentHealth -= (2 * personPower);
            std::cout << "You hitted opponet for " << (2 * personPower) << std::endl;
            std::cout << "Opponent health: " << opponentHealth << std::endl;
        }
        else {
            opponentHealth -= personPower;
            std::cout << "You hitted opponet for " << personPower << std::endl;
            std::cout << "Opponent health: " << opponentHealth << std::endl;
        }

        if (opponentCrit < (opponentLuck * 100)) {
            std::cout << "Critical damage!" << std::endl;
            personHealth -= (2 * opponentPower);
            std::cout << "Opponent hitted you for " << (2 * opponentPower) << std::endl;
            std::cout << "Your health: " << personHealth << std::endl;
        }
        else {
            personHealth -= opponentPower;
            std::cout << "Opponent hitted you for " << opponentPower << std::endl;
            std::cout << "Your health: " << personHealth << std::endl;
        }
    }


    if (personHealth > opponentHealth || personHealth == opponentHealth) {

        person.xp += 2;
        if (person.xp > person.level) {
            person.xp = person.xp - person.level;
            person.level += 1;
        }
        std::cout
            << "You've won! If you answer my question correct you can gain 2 \n gold instead of 1, but if you are wrong, you will loose \n"
            "earnings for this fight! Your call!" << std::endl;
        std::pair<bool,bool> flags = questionHandler();
        if (flags.first) {
            if (flags.second) {
                person.gold += 2;
            }
        } else {
            person.gold += 1;
        }
    }
    else {
        std::cout << "You've lost! It will cost you 1 gold, unless you answer my question! Are you ready? " << std::endl;
        std::pair<bool,bool> flags = questionHandler();
        if (flags.first) {
            if (flags.second) {
                person.gold += 0;
            }
        } else {
            person.gold -= 1;
        }
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
    double luck = distribution(generator);

    power = power + person.power;
    agility = agility + person.agility;
    health = health + person.health;
    defense = defense + person.defense;
    luck = luck + person.luck;

    if (power <= 0) {
        power = 1;
    }
    if (agility <= 0) {
        agility = 1;
    }
    if (health <= 0) {
        health = 1;
    }
    if (defense <= 0) {
        defense = 1;
    }
    if (luck <= 0) {
        luck = 1;
    }

    data.push_back(power);
    data.push_back(agility);
    data.push_back(health);
    data.push_back(defense);
    data.push_back(luck);

    return data;
}

std::pair<bool,bool> questionHandler() {
    std::vector<std::string> options = { "Yes", "No" };
    int input;
    bool again = true;
    bool isCorrect;
    bool takeOffer;
    while (again) {
        for (int i = 0; i < 2; i++) {
            std::cout << i + 1 << " -> " << options[i] << std::endl;
        }
        std::cout << "Your choice: ";
        std::cin >> input;
        switch (input) {
            case 1:
                isCorrect = getQuestion();
                takeOffer = true;
                again = false;
                break;
            case 2:
                isCorrect = false;
                takeOffer = false;
                again = false;
                break;
            default:
                again = true;
                std::cout << "Wrong choice!" << std::endl;
                break;
        }
    }
    return std::make_pair(takeOffer,isCorrect);
}