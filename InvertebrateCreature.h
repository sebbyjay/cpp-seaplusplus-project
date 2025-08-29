#ifndef INVERTEBRATECREATURE_H
#define INVERTEBRATECREATURE_H

#include "SeaCreature.h"

class InvertebrateCreature : public SeaCreature {
public:
    InvertebrateCreature(const std::string& name, float size, bool hasEggs);
    std::string getType() const override;
};

#endif
