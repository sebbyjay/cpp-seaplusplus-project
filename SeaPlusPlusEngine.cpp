#include "SeaPlusPlusEngine.h"
#include "VertebrateCreature.h"
#include "InvertebrateCreature.h"


SeaPlusPlusEngine::SeaPlusPlusEngine() {}

void SeaPlusPlusEngine::regChecker(SeaChecker* checker) { 
    checkers.push_back(checker);
}

std::string SeaPlusPlusEngine::validateCatch(SeaCreature* creature) {
    for (SeaChecker* checker : checkers) {
        if (dynamic_cast<VertebrateCreature*>(creature) &&
            checker->getCheckerType() == "Vertebrate") {
            if (checker->check(creature)) {
                return "Catch is allowed by VertebrateChecker";
            }
        } else if (dynamic_cast<InvertebrateCreature*>(creature) &&
                   checker->getCheckerType() == "Invertebrate") {
            if (checker->check(creature)) {
                return "Catch is allowed by InvertebrateChecker";
            }
        }
    }
    return "Catch is not allowed by any checker.";
}

