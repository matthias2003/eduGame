#include <iostream>
#include <vector>
#include "character.h"
#include "arena.h"
#include "tavern.h"
#include "question.h"

MyCharacter Intro() {
    std::string name;
    std::cout << "Create your character" << std::endl << "Chose your name: ";
    std::cin >> name;
    int points = 10;
    int stat = 0;
    int loop = 0;
    std::vector<std::string> statsNames = { "Power","Health","Defense","Luck" };
    std::cout << std::endl;
    std::cout << "It's time to customize your character! You can spend points on this stats: " << std::endl;
    for (auto tmp : statsNames) {
        std::cout << tmp << std::endl;
    }
    std::vector<int> stats = { 1,1,1,1};
    while (points > 0) {
        std::cout << "You have " << points << " points." << std::endl;
        std::cout << "How much points you want to spend on " << statsNames[loop] << ": ";
        std::cin >> stat;
        if (stat <= points) {
            stats[loop] = stats[loop] + stat;
            points = points - stat;
            if (loop == 3) {
                loop = 0;
            }
            else {
                loop++;
            }
        }
    }
    MyCharacter person(name, stats[0], stats[1], stats[2], stats[3], 1, 0, 1, 1);
    return person;
}

void Menu(MyCharacter& person) {
    bool again = true;
    int input;
    while (again) {
        std::vector<std::string> options = { "Character","Arena","Tavern","Exit" };
        std::cout << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << i + 1 << " -> " << options[i] << std::endl;
        }
        std::cout << "Your choice: ";
        std::cin >> input;
        switch (input) {
            case 1:
                Character(person);
                break;
            case 2:
                Arena(person);
                break;
            case 3:
                Tavern();
                break;
            case 4:
                exit(123);
                break;
            default:
                std::cout << "Wrong choice!" << std::endl;
                break;
        }
    }
}

int main()
{
    questionDataHandler();
    for (int i = 0; i < 10; i++) std::cout << std::endl;
    for (int i = 0; i < 50; i++) std::cout << " ";
    std::cout << "Welcome in Edu RPG!";
    for (int i = 0; i < 10; i++) std::cout << std::endl;
    MyCharacter person = Intro();
    Menu(person);

    return 0;
}
