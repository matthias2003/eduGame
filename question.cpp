#include <iostream>
#include <fstream>
#include <string>
#include "question.h"

std::vector <std::string> questions;
std::vector <std::string> answers;

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

//
//std::pair<std::string,std::string> getQuestion() {
//
//
//    return std::make_pair(num2, num1);
//}
//
