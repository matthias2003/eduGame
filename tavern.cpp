#include <iostream>
#include <vector>
#include "question.h"

void Tavern() {
    std::cout << "Welcome to Tavern! Place in where you can find answers to your questions! " << std::endl
              <<   "Obviously not the ones you are supposed to answer yourself!"  << std::endl;
    bool again = true;
    int input;

    std::vector<std::string> options = { "Game guide","Random question","Back" };


    while(again) {
        for (int i = 0; i < 3; i++) {
            std::cout << i + 1 << " -> " << options[i] << std::endl;
        }
        std::cout << "Your choice: ";
        std::cin >> input;
        switch(input) {
            case 1:
                std::cout << "Rules are simple! Fight your way trough enemies to victory! You have 4 options." << std::endl << std::endl
                << "Character -> place where you can upgrade your stats and see them, your xp and level progress" << std::endl << std::endl
                << "Story -> you face up with greatest enemies of the whole world, fighting to claim the glory. \n But you have to be cautious."
                << "If you die there, you lose everything, and start from the beginning." << std::endl << std::endl
                << "Arena -> fight to gain Xp and gold to level up and face bigger threats in Story mode. \n"
                << "If you die, you only need to pay your medical bills, which is all of your gold" << std::endl << std::endl
                << "Tavern -> grab a seat and enjoy. The game guide (which you are reading right now) will help you understand the game. \n"
                << "Question hints gives to advices how to approach questions. Random questions allows you to train before fights" << std::endl << std::endl
                << "In this journey you will face greatest enemies and hardest questions, if you answer correctly, be sure it will gifted " << std::endl;
                break;
            case 2:
                getQuestion();
                std::cout << std::endl;
                break;
            case 3:
                again = false;
                break;
            default:
                std::cout << "Wrong choice!" << std::endl;
                break;
        }
    }
}