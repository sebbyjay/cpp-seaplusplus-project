#ifndef BAG_H
#define BAG_H

#include "SeaCreature.h"
#include <vector>
#include <string>

class Bag {
private:
    std::vector<SeaCreature*> creatures;  // A vector to hold the creatures in the bag
    
public:
    void addCreature(SeaCreature* creature);  // Method to add a creature to the bag
    std::vector<SeaCreature*> getCreatures() const;  // Getter for creatures
};

#endif // BAG_H
