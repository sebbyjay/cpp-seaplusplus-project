#ifndef BAGCHECKER_H
#define BAGCHECKER_H

#include "Bag.h"
#include <string>

class BagChecker {
public:
    bool check(Bag* bag);  // Method for Bag checking
    std::string getCheckerType() const;
};

#endif // BAGCHECKER_H
