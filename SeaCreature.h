#ifndef SEACREATURE_H
#define SEACREATURE_H

#include <string>

class SeaCreature {
protected:
    std::string name;
    float size;
    bool hasEggs;

public:
    SeaCreature(const std::string& name, float size, bool hasEggs);
    virtual ~SeaCreature() = default; // Virtual destructor, kills the seaCreature :(

    std::string getName() const;
    float getSize() const;
    bool eggStatus() const;

    virtual std::string getType() const = 0; // Virtual method
};

#endif // SEACREATURE_H
