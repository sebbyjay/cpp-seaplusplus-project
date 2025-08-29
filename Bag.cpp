#include "Bag.h"

void Bag::addCreature(SeaCreature* creature) {
    creatures.push_back(creature);  // Add the creature to the bag
}

std::vector<SeaCreature*> Bag::getCreatures() const {
    return creatures;  // Return the list of creatures in the bag
}
