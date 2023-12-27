#include <iostream>
#include <vector>

class MyCharacter {
public:
    std::string name;
    int power, agility, health, defense, luck, gold, xp, level, statsAdded;
    MyCharacter(std::string& name, int power, int agility, int health, int defense, int luck, int gold, int xp, int level, int statsAdded) {
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
    void showStats () {
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

    bool AddStats() {
        bool again = true;
        int input = 0;
        int cost = 1 * this->statsAdded;
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
                    return true;
                    break;
                case 2:
                    this->agility += 1;
                    this->gold -= cost;
                    break;
                case 3:
                    this->health += 1;
                    this->gold -= cost;
                    break;
                case 4:
                    this->defense += 1;
                    this->gold -= cost;
                    break;
                case 5:
                    this->luck += 1;
                    this->gold -= cost;
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
    MyCharacter person(name, stats[0], stats[1], stats[2], stats[3], stats[4], 1, 0, 1, 1);
    return person;
}

bool Character(MyCharacter &person) {
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
            again = person.AddStats();
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



void Menu(MyCharacter &person) {
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
