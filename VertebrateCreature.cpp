#include "VertebrateCreature.h"

VertebrateCreature::VertebrateCreature(const std::string& name, float size, bool hasEggs)
    : SeaCreature(name, size, hasEggs) {}

std::string VertebrateCreature::getType() const {
    return "Vertebrate";
}
