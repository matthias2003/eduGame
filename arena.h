#include <vector>
#include "character.h"

#ifndef ARENA_H
#define ARENA_H

void Arena(MyCharacter &person);
std::vector <double> RandomOpponentStats(MyCharacter person);
std::pair<bool,bool> questionHandler();

#endif
