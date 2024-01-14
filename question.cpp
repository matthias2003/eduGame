#include <iostream>
#include <fstream>
#include <string>
#include "question.h"


std::vector <std::string> questions;
std::vector <std::string> answers;
int pointer = 0;

void questionDataHandler() {

        questions.push_back("1. Mathematics: What is the value of π(pi) ?  A) 3.14  B) 2.71  C) 1.62  D) 4.20");
        questions.push_back("2. Biology: What is the powerhouse of the cell ? A) Nucleus  B) Mitochondria  C) Chloroplast  D) Ribosome");
        questions.push_back("3. History:In which year did Christopher Columbus reach the Americas ? A) 1492 B) 1588 C) 1620 D) 1776");
        questions.push_back("4. Physics : What is the SI unit of force ? A) Watt  B) Joule  C) Newton  D) Pascal");
        questions.push_back("5. Geography : Which is the longest river in the world ?  A) Amazone 7  B) Nile  C) Yangtze   D) Mississippi");
        questions.push_back("6. Literature : Who wrote the play Romeo and Juliet ? A) William Shakespeare  B) Jane Austen  C) Charles Dickens  D) Mark Twain");
        questions.push_back(" 8. General Knowledge :Which planet is known as the Red Planet ?A) Venus  B) Mars  C) Jupiter  D) Saturn");
        questions.push_back(" 9. Economics :What does GDP stand for ?  A) General Domestic Product  B) Gross Domestic Product  C) Global Development Process  D) General Development Protocol");
        questions.push_back(" 10. Political Science :What is the term for a system of government where the power is held by the people, either directly or through elected representatives ? A) Monarchy  B) Oligarchy  C) Democracy  D) Autocracy");
        questions.push_back(" 11. Computer Science :Which programming language is known for its use in web development and is often associated with front - end development ?  A) Java  B) Python  C) HTML  D) C++");
        questions.push_back(" 12. Art : Who painted the Mona Lisa ?  A) Vincent van Gogh  B) Pablo Picasso  C) Leonardo da Vinci  D) Claude Monet");
        questions.push_back(" 13. Environmental Science : What is the primary gas responsible for the greenhouse effect on Earth ? A) Oxygen B) Nitrogen C) Carbon Dioxide D) Methane");
        questions.push_back(" 14. Psychology : According to Maslow's hierarchy of needs, which needs are considered the most basic and fundamental? A) Self - esteem needs B) Safety needs C) Physiological needs D) Love and belongingness needs");
        questions.push_back(" 15. Astronomy : What is the name of the largest moon of Jupiter ?  A) Europa   B) Ganymede   C) Io   D) Callisto");

        answers.push_back("Correct Answer: A");
        answers.push_back("Correct Answer: B");
        answers.push_back("Correct Answer : A");
        answers.push_back("Correct Answer : C");
        answers.push_back("Correct Answer : B");
        answers.push_back("Correct Answer : A");
        answers.push_back("Correct Answer : B");
        answers.push_back("Correct Answer : B");
        answers.push_back("Correct Answer : B");
        answers.push_back("Correct Answer : C");
        answers.push_back("Correct Answer : C");
        answers.push_back("Correct Answer : C");
        answers.push_back("Correct Answer : C");
        answers.push_back("Correct Answer : C");
        answers.push_back("Correct Answer : B");
}


bool getQuestion() {
    bool flag;
    char answer;
    std::vector <std::string> set;
    
    if ((pointer) < questions.size()+1) {
        set.push_back(questions[pointer]);
        set.push_back(answers[pointer]);
        pointer += 1;
    }
    else {
        pointer = 0;
        set.push_back(questions[pointer]);
        set.push_back(answers[pointer]);
    }

    std::cout << set[0] << std::endl << "Your answer: ";
    std::cin >> answer;
    if (toupper(answer) == set[1].back() || answer == set[1].back()) {
        std::cout << "Congratulations! " << set[1];
        flag = true;
    }
    else {
        std::cout << "Too bad! " << set[1];
        flag = false;
    }
    return flag;
}

