#ifndef SEACHECKER_H
#define SEACHECKER_H

#include "SeaCreature.h"
#include <string>

class SeaChecker { // Absract class, so no cpp file, wierd
public:
    virtual ~SeaChecker() = default;
    virtual bool check(SeaCreature* creature) = 0;
    virtual std::string getCheckerType() const = 0;
};

#endif // SEACHECKER_H