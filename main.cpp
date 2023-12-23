#include <iostream>
#include <vector>

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

    int input;
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

    }
}

int main()
{
    for (int i = 0; i < 10; i++) std::cout << std::endl;
    for (int i = 0; i < 50; i++) std::cout << " ";
    std::cout << "Welcome in Edu RPG!";
    for (int i = 0; i < 10; i++) std::cout << std::endl;


    Menu();

    return 0;
}
