#ifndef SEAPLUSPLUSENGINE_H
#define SEAPLUSPLUSENGINE_H

#include <vector>
#include <string>
#include "SeaChecker.h"
#include "SeaCreature.h"
#include "BagChecker.h"

class SeaPlusPlusEngine {
private:
    std::vector<SeaChecker*> checkers;
    Bag currentBag;
    BagChecker bagChecker;

public:
    SeaPlusPlusEngine();
    void regChecker(SeaChecker* checker);
    std::string validateCatch(SeaCreature* creature);
    void addToBag(SeaCreature* creature);
    std::string validateBag(Bag* bag);
};

#endif // SEAPLUSPLUSENGINE_H
