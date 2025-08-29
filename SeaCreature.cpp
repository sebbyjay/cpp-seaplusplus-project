#include "SeaCreature.h"

SeaCreature::SeaCreature(const std::string& name, float size, bool hasEggs)
    : name(name), size(size), hasEggs(hasEggs) {}

std::string SeaCreature::getName() const {
    return name;
}

float SeaCreature::getSize() const {
    return size;
}

bool SeaCreature::eggStatus() const {
    return hasEggs;
}
