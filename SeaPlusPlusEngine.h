#ifndef SEAPLUSPLUSENGINE_H
#define SEAPLUSPLUSENGINE_H

#include <vector>
#include <string>
#include "SeaChecker.h"
#include "SeaCreature.h"

class SeaPlusPlusEngine {
private:
    std::vector<SeaChecker*> checkers;

public:
    SeaPlusPlusEngine();
    void regChecker(SeaChecker* checker);
    std::string validateCatch(SeaCreature* creature);
};

#endif // SEAPLUSPLUSENGINE_H
