#ifndef VERTEBRATECREATURE_H
#define VERTEBRATECREATURE_H

#include "SeaCreature.h"

class VertebrateCreature : public SeaCreature {
public:
    VertebrateCreature(const std::string& name, float size, bool hasEggs);
    std::string getType() const override;
};

#endif