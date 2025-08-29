#include "InvertebrateChecker.h"
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
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

bool InvertebrateChecker::check(SeaCreature* creature) {
    // Hardcoded invertebrate species size limits (bag limits removed)
    static const std::unordered_map<std::string, float> invertebrateSizeLimits = {
        {"abalone", 11.7f},
        {"balmain bug", 10.0f},
        {"beach worms", 0.0f},
        {"all other worms", 0.0f},
        {"cockles", 0.0f},
        {"mussels", 0.0f},
        {"pipis", 0.0f},
        {"blue swimmer crab", 6.5f},
        {"mud crab", 8.5f},
        {"spanner crab", 9.3f},
        {"soldier crab", 0.0f},
        {"all other crabs", 0.0f},
        {"cunjevoi", 0.0f},
        {"eastern rock lobster", 10.4f},
        {"southern rock lobster (male)", 11.0f},
        {"southern rock lobster (female)", 10.5f},
        {"tropical rock lobster (painted and ornate)", 0.0f},
        {"slipper lobster (flat)", 0.0f},
        {"octopus", 0.0f},
        {"oysters (sydney rock, pacific, native)", 0.0f},
        {"prawns", 0.0f},
        {"saltwater nippers", 0.0f},
        {"scallops", 0.0f},
        {"sea urchin", 0.0f},
        {"squid", 0.0f},
        {"turban snails (sydney, military)", 7.5f},
        {"turban snails (all other molluscs)", 0.0f}
    };

    std::string normalizedSpeciesName = toLower(trim(creature->getName()));

    auto it = invertebrateSizeLimits.find(normalizedSpeciesName);
    if (it != invertebrateSizeLimits.end()) {
        float sizeLimit = it->second;

        if (sizeLimit != 0 && creature->getSize() > sizeLimit) { // the size limits are ambiguous as to where it should be greater than or less than the creature. i have assumed size limits are maximum
            std::cout << "This invertebrate is too big, it needs to be returned." << std::endl;
            return false;
        }
        if (creature->eggStatus() == true) {
            std::cout << "This invertebrate is carrying eggs, it needs to be returned." << std::endl;
            return false;
        }

        std::cout << "This invertebrate is good to keep." << std::endl;
        return true;
        
    } else {
        std::cout << "This invertebrate species does not have a defined size limit." << std::endl;
        return false;
    }
}

std::string InvertebrateChecker::getCheckerType() const {
    return "Invertebrate";
}
