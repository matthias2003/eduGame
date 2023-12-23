#include <iostream>
#include <vector>
#include <cstdlib>

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
        case 4:
            exit(123);
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
