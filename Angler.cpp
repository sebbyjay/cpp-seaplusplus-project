#include "Angler.h"

Angler::Angler(const std::string& name)
    : name(name) {}

Angler::~Angler() {
    // Clean up the SeaCreatures, in the bin :(
    for (auto creature : catches) {
        delete creature;
    }
}

void Angler::addCatch(SeaCreature* creature) {
    catches.push_back(creature);
}

std::string Angler::getName() const {
    return name;
}

std::vector<SeaCreature*> Angler::getCatches() const {
    return catches;
}
