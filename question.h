#include <vector>
#include <string>

#ifndef QUESTION_H
#define QUESTION_H

extern std::vector <std::string> questions;
extern std::vector <std::string> answers;

void questionDataHandler();
bool getQuestion();

#endif
