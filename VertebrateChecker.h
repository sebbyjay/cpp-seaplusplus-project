#ifndef VERTEBRATECHECKER_H
#define VERTEBRATECHECKER_H

#include "SeaChecker.h"
#include "SeaCreature.h"

class VertebrateChecker : public SeaChecker {
public:
    bool check(SeaCreature* creature) override;
    std::string getCheckerType() const override;
};

#endif // VERTEBRATECHECKER_H
