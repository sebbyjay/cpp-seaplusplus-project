#include "InvertebrateCreature.h"

InvertebrateCreature::InvertebrateCreature(const std::string& name, float size, bool hasEggs)
    : SeaCreature(name, size, hasEggs) {}

std::string InvertebrateCreature::getType() const {
    return "Invertebrate";
}
