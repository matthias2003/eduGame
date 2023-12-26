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
        std::cout << std::endl;
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
    std::cout << std::endl;
    std::cout << "It's time to customize your character! You can spend points on this stats: " << std::endl;
    for (auto tmp : statsNames) {
        std::cout << tmp << std::endl;
    }
    std::vector<int> stats = { 1,1,1,1,1 };
    while (points > 0) {

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

int Character(MyCharacter person) {
    person.showStats();

    bool again = true;
    int input = 0;
    std::vector<std::string> options = { "Add stats","Back" };
    while (again) {
        again = false;
        std::cout << std::endl;
        for (int i = 0; i < 2; i++) {
            std::cout << i + 1 << " -> " << options[i] << std::endl;
        }
        std::cout << "Your choice:";
        std::cin >> input;
        switch (input)
        {
        case 1:
            std::cout << "Tu bedzie dodawanie statystyk" << std::endl;
            return false;
            break;
        case 2:
            return true;
            break;
        default:
            again = true;
            std::cout << "Wrong choice!" << std::endl;
            break;
        }
    }
}

void Story() {

}

void Arena() {

}

void Tavern() {

}



void Menu(MyCharacter person) {
    bool again = true;
    int input;
    while (again) {
        std::vector<std::string> options = { "Character","Story","Arena","Tavern","Exit" };
        std::cout << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << i + 1 << " -> " << options[i] << std::endl;
        }
        again = false;
        std::cout << "Your choice:";
        std::cin >> input;
        switch (input) {
        case 1:
            again = Character(person);
            break;
        case 2:
            Story();
            break;
        case 3:
            Arena();
            break;
        case 4:
            Tavern();
            break;
        case 5:
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
