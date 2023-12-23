#include <iostream>
#include <vector>



class MyCharacter {
public:
    std::string name;
    int power, agility, health, defense, luck;
    MyCharacter(std::string& name, int power, int agility, int health, int defense, int luck) {
        this->name = name;
        this->power = power;
        this->agility = agility;
        this->health = health;
        this->defense = defense;
        this->luck = luck;
    }
    void showStats() {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Power: " << this->power << std::endl;
        std::cout << "Agility: " << this->agility << std::endl;
        std::cout << "Health: " << this->health << std::endl;
        std::cout << "Defense: " << this->defense << std::endl;
        std::cout << "Luck: " << this->luck << std::endl;
    }
};

MyCharacter Intro() {
    std::string name;
    std::cout << "Create your character" << std::endl << "Chose your name: ";
    std::cin >> name;
    int points = 10;
    int stat = 0;
    int loop = 0;
    std::vector<std::string> statsNames = { "Power","Agility","Health","Defense","Luck" };
    std::cout << "It's time to customize your character! You can spend points on this stats: " << std::endl;
    for (auto tmp:statsNames) {
        std::cout << tmp << std::endl;
    }
    std::vector<int> stats = {1,1,1,1,1};
    while(points > 0) {
        
        std::cout << "You have " << points << " points." << std::endl;
        std::cout << "How much points you want to spend on " << statsNames[loop] << ": ";
        std::cin >> stat;
        if (stat <= points) {
            stats[loop] = stats[loop] + stat;
            points = points - stat;
            if (loop == 4) {
                loop = 0;
            }
            else {
                loop++;
            }
        }
    }
    MyCharacter person(name, stats[0], stats[1], stats[2], stats[3], stats[4]);
    return person;
}

void Character(MyCharacter person) {
    person.showStats();
}

void Arena() {

}

void Tavern() {

}

void Story() {

}

void Menu(MyCharacter person) {
    std::vector<std::string> options = { "Character","Arena","Tavern","Story","Exit" };
    for (int i = 0; i < 5; i++) {
        std::cout << i << " -> " << options[i] << std::endl;
    }
    bool again = true;
    int input;
    while (again) {
        again = false;
        std::cout << "Your choice:";
        std::cin >> input;
        switch (input) {
        case 0:
            Character(person);
            break;
        case 1:
            Arena();
            break;
        case 2:
            Tavern();
            break;
        case 3:
            Story();
            break;
        case 4:
            exit(123);
            break;
        default:
            again = true;
            std::cout << "Wrong choice!" << std::endl;
            break;
        }
    }
}

int main()
{
    for (int i = 0; i < 10; i++) std::cout << std::endl;
    for (int i = 0; i < 50; i++) std::cout << " ";
    std::cout << "Welcome in Edu RPG!";
    for (int i = 0; i < 10; i++) std::cout << std::endl;

    MyCharacter person = Intro();

    
    Menu(person);

    return 0;
}
