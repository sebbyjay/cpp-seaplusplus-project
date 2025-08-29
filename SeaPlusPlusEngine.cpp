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

void SeaPlusPlusEngine::addToBag(SeaCreature* creature) {
    currentBag.addCreature(creature);  // Use addCreature instead of addCatch
}

std::string SeaPlusPlusEngine::validateBag(Bag* bag) {
    const std::vector<SeaCreature*>& creatures = bag->getCreatures();
    for (SeaCreature* creature : creatures) {
        bool valid = false;

        for (SeaChecker* checker : checkers) {
            if ((checker->getCheckerType() == "VertebrateChecker" && creature->getType() == "vertebrate") ||
                (checker->getCheckerType() == "InvertebrateChecker" && creature->getType() == "invertebrate")) {
                valid = checker->check(creature);
                break;
            }
        }

        if (!valid) {
            return "Invalid catch found in bag.";
        }
    }

    return "All catches in the bag are valid.";
}

