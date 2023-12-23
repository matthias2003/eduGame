#include <iostream>
#include <vector>



class MyCharacter {
    public:
        std::string name;
        int power, agility, health, defense, luck;
        MyCharacter(std::string &name, int power, int agility, int health, int defense, int luck){
            this-> name = name;
            this->power = power;
            this->agility = agility;
            this->health = health;
            this->defense = defense;
            this->luck = luck;
        }
};

MyCharacter Intro() {
    std::string name;
    std::cout << "Create your character" << std::endl << "Chose your name: ";
    std::cin >> name;
    MyCharacter person = MyCharacter(name,2,2,2,2,2);
    return person;
}

void Character() {

}

void Arena() {

}

void Tavern() {

}

void Story() {

}

void Menu() {
    std::vector<std::string> options = {"Character","Arena","Tavern","Story","Exit"};
    for (int i = 0; i < 5;i++) {
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
                Character();
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



//    Menu();

    return 0;
}
