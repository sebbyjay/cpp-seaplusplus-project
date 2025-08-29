#ifndef INVERTEBRATECHECKER_H
#define INVERTEBRATECHECKER_H

#include "SeaChecker.h"
#include "SeaCreature.h"

class InvertebrateChecker : public SeaChecker {
public:
    bool check(SeaCreature* creature) override;
    std::string getCheckerType() const override;
};

#endif // INVERTEBRATECHECKER_H
