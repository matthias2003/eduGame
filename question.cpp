#include <iostream>
#include <fstream>
#include <string>
#include "question.h"

std::vector <std::string> questions;
std::vector <std::string> answers;
int pointer = 0;

void questionDataHandler() {
    int i = 0;
    std::string line;
    std::string element = "";
    std::ifstream MyReadFile("../questions.txt");
    while (getline (MyReadFile, line)) {
        if (i < 6) {
            element += line;
            element += "\n";
            i++;
        } else {
            i = 0;
            questions.push_back(element);
            element = "";
            answers.push_back(line);
        }
    }
}


bool getQuestion() {
    bool flag;
    char answer;
    std::pair set = std::make_pair(questions[pointer], answers[pointer]);
    pointer+=1;

    std::cout << set.first << std::endl << "Your answer: ";
    std::cin >> answer;
    if (toupper(answer) == set.second.back() || answer == set.second.back()) {
        std::cout << "Congratulations! " << set.second;
        flag = true;
    } else {
        std::cout << "Too bad! " << set.second;
        flag = false;
    }

    return flag;
}

