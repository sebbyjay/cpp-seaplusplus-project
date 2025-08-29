#ifndef ANGLER_H
#define ANGLER_H

#include <string>
#include <vector>
#include "SeaCreature.h"

class Angler {
private:
    std::string name;
    std::vector<SeaCreature*> catches;  // Stores the sea creatures caught by the angler

public:
    Angler(const std::string& name);
    ~Angler();  // Destructor to clean up dynamically allocated creatures

    void addCatch(SeaCreature* creature);
    std::string getName() const;
    std::vector<SeaCreature*> getCatches() const;
};

#endif
