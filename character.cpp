#include <iostream>
#include <vector>
#include "character.h"

MyCharacter::MyCharacter(std::string& name, double power, double agility, double health, double defense, double luck, double gold, double xp, double level, double statsAdded) {
    this->name = name;
    this->power = power;
    this->agility = agility;
    this->health = health;
    this->defense = defense;
    this->luck = luck;
    this->gold = gold;
    this->xp = xp;
    this->level = level;
    this->statsAdded = statsAdded;
}


void MyCharacter::showStats() {
        std::cout << std::endl;
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Level " << this->level << std::endl;
        std::cout << "XP: " << this->xp << std::endl;
        std::cout << "Gold: " << this->gold << std::endl;
        std::cout << "Power: " << this->power << std::endl;
        std::cout << "Agility: " << this->agility << std::endl;
        std::cout << "Health: " << this->health << std::endl;
        std::cout << "Defense: " << this->defense << std::endl;
        std::cout << "Luck: " << this->luck << std::endl;
    }

void MyCharacter::AddStats() {
        bool again = true;
        int input = 0;
        double cost = 1 * this->statsAdded;
        if(this->gold >= cost){
            while (again) {
                std::cout << std::endl << "Which stat you want to increase: " << std::endl;;
                std::vector<std::string> options = { "Power","Agility","Health","Defense","Luck" };
                for (int i = 0; i < 5; i++) {
                    std::cout << i + 1 << " -> " << options[i] << std::endl;
                }
                std::cout << "Your choice: ";
                std::cin >> input;
                again = false;
                switch (input)
                {
                    case 1:
                        this->power += 1;
                        this->gold -= cost;
                        std::cout << "Statistics have been added" << std::endl;
                        this->statsAdded++;
                        break;
                    case 2:
                        this->agility += 1;
                        this->gold -= cost;
                        std::cout << "Statistics have been added" << std::endl;
                        this->statsAdded++;
                        break;
                    case 3:
                        this->health += 1;
                        this->gold -= cost;
                        std::cout << "Statistics have been added" << std::endl;
                        this->statsAdded++;
                        break;
                    case 4:
                        this->defense += 1;
                        this->gold -= cost;
                        std::cout << "Statistics have been added" << std::endl;
                        this->statsAdded++;
                        break;
                    case 5:
                        this->luck += 1;
                        this->gold -= cost;
                        std::cout << "Statistics have been added" << std::endl;
                        this->statsAdded++;
                        break;
                    default:
                        std::cout << "Wrong choice!" << std::endl;
                        again = true;
                        break;
                }
            }
        }
        else
        {
            std::cout << "You dont have enough gold for it." << std::endl;
            std::cout << "You need " << cost << " gold to add stat." << std::endl;
        }
};

void Character(MyCharacter &person) {
    person.showStats();
    bool again = true;
    int input = 0;
    std::vector<std::string> options = { "Add stats","Show stats","Back" };
    while (again) {
        again = false;
        std::cout << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << i + 1 << " -> " << options[i] << std::endl;
        }
        std::cout << "Your choice:";
        std::cin >> input;
        switch (input)
        {
            case 1:
                again = true;
                person.AddStats();
                break;
            case 2:
                person.showStats();
                again = true;
                break;
            case 3:
                again = false;
                break;
            default:
                again = true;
                std::cout << "Wrong choice!" << std::endl;
                break;
        }
    }
}

