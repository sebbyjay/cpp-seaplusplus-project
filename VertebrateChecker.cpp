#include "VertebrateChecker.h"
#include <iostream>
#include <unordered_map>
#include <algorithm> // For transform()
#include <cctype>    // For isspace() and tolower()

// Helper function to trim leading and trailing spaces
static std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

// Helper function to convert string to lowercase
static std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c){ return std::tolower(c); });
    return lowerStr;
}

bool VertebrateChecker::check(SeaCreature* creature) {
    static const std::unordered_map<std::string, float> speciesSizeLimits = {
        {"australian bass", 35.0f},
        {"estuary perch", 0.0f},
        {"australian salmon", 0.0f},
        {"blue drummer", 0.0f},
        {"bonito", 0.0f},
        {"bream (black/southern)", 25.0f},
        {"bream (yellowfin)", 25.0f},
        {"tarwhine", 20.0f},
        {"cobia", 0.0f},
        {"hapuku (hapuka)", 0.0f},
        {"banded rock cod", 0.0f},
        {"bass groper", 0.0f},
        {"gemfish", 0.0f},
        {"blue-eye trevalla", 0.0f},
        {"dogfish (harrisson's)", 0.0f},
        {"dogfish (southern)", 0.0f},
        {"dogfish (all other)", 0.0f},
        {"eastern blue groper", 0.0f},
        {"mahi mahi (dolphinfish)", 60.0f},
        {"eels (shortfin)", 30.0f},
        {"eels (longfin)", 58.0f},
        {"flathead (dusky)", 36.0f},
        {"flathead (bluespotted)", 33.0f},
        {"flathead (tiger)", 0.0f},
        {"flounder", 25.0f},
        {"garfish", 0.0f},
        {"hairtail", 0.0f},
        {"leatherjacket", 0.0f},
        {"luderick", 27.0f},
        {"mackerel (spanish)", 75.0f},
        {"mackerel (spotted)", 60.0f},
        {"mangrove jack", 0.0f},
        {"marlin (striped)", 0.0f},
        {"marlin (black)", 0.0f},
        {"marlin (blue)", 0.0f},
        {"morwong (grey)", 30.0f},
        {"morwong (jackass)", 30.0f},
        {"morwong (red)", 30.0f},
        {"morwong (banded)", 0.0f},
        {"moses snapper", 0.0f},
        {"mullet (small)", 15.0f},
        {"mullet (sea)", 30.0f},
        {"mulloway", 70.0f},
        {"pearl perch", 30.0f},
        {"eastern red scorpionfish", 0.0f},
        {"rock blackfish", 30.0f},
        {"sailfish", 0.0f},
        {"samsonfish", 0.0f},
        {"amberjack", 0.0f},
        {"australian sawtail", 0.0f},
        {"shark (wobbegong)", 0.0f},
        {"shark (mako)", 0.0f},
        {"shark (school)", 91.0f},
        {"shark (whaler)", 0.0f},
        {"snapper", 30.0f},
        {"spearfish (shortbill)", 0.0f},
        {"swordfish", 0.0f},
        {"tailor", 30.0f},
        {"teraglin", 38.0f},
        {"trevallies (silver trevally only)", 30.0f},
        {"tuna (albacore) (≥90cm)", 90.0f},
        {"tuna (albacore) (<90cm)", 0.0f},
        {"tuna (bigeye)", 0.0f},
        {"tuna (longtail)", 0.0f},
        {"tuna (yellowfin)", 0.0f},
        {"tuna (southern bluefin)", 0.0f},
        {"wahoo", 0.0f},
        {"whiting (sand)", 27.0f},
        {"yellowtail kingfish", 65.0f}
    };

    std::string normalizedSpeciesName = toLower(trim(creature->getName()));

    auto it = speciesSizeLimits.find(normalizedSpeciesName);
    if (it != speciesSizeLimits.end()) {
        float sizeLimit = it->second;

        if (sizeLimit != 0 && creature->getSize() > sizeLimit) { // the size limits are ambiguous as to where it should be greater than or less than the creature. i have assumed size limits are maximum
            std::cout << "This vertebrate is too big, it needs to be returned." << std::endl;
            return false;
        }

        if (creature->eggStatus()) {
            std::cout << "This vertebrate is carrying eggs, it needs to be returned." << std::endl;
            return false;
        }

        std::cout << "This vertebrate is good to keep." << std::endl;
        return true;

    } else {
        std::cout << "This vertebrate species does not have a defined limit." << std::endl;
        return false;
    }
}

std::string VertebrateChecker::getCheckerType() const {
    return "Vertebrate";
}

