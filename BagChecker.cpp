#include "BagChecker.h"
#include "Bag.h"
#include <iostream>
#include <map>

// Static bag limits map
static const std::map<std::string, int> bagLimits = {
    {"Australian Bass", 2},
    {"Estuary Perch", -1},
    {"Australian Salmon", 5},
    {"Blue Drummer", 0},
    {"Bonito", 10},
    {"Bream (Black/Southern)", 10},
    {"Bream (Yellowfin)", -1},
    {"Tarwhine", -1},
    {"Cobia", 5},
    {"Hapuku (Hapuka)", 5},
    {"Banded Rock Cod", -1},
    {"Bass Groper", -1},
    {"Gemfish", -1},
    {"Blue-Eye Trevalla", -1},
    {"Dogfish (Harrisson's)", 0},
    {"Dogfish (Southern)", 0},
    {"Dogfish (All other)", 2},
    {"Eastern Blue Groper", 0},
    {"Mahi Mahi (Dolphinfish)", 10},
    {"Eels (Shortfin)", 10},
    {"Eels (Longfin)", 10},
    {"Flathead (Dusky)", 5},
    {"Flathead (Bluespotted)", 10},
    {"Flathead (Tiger)", 10},
    {"Flounder", 20},
    {"Garfish", 20},
    {"Hairtail", 10},
    {"Leatherjacket", 20},
    {"Luderick", 10},
    {"Mackerel (Spanish)", 5},
    {"Mackerel (Spotted)", -1},
    {"Mangrove Jack", 5},
    {"Marlin (Striped)", 1},
    {"Marlin (Black)", 1},
    {"Marlin (Blue)", 1},
    {"Morwong (Grey)", 10},
    {"Morwong (Jackass)", 10},
    {"Morwong (Red)", 5},
    {"Morwong (Banded)", 5},
    {"Moses Snapper", 5},
    {"Mullet (Small)", 20},
    {"Mullet (Sea)", 20},
    {"Mulloway", 1},
    {"Pearl Perch", 5},
    {"Eastern Red Scorpionfish", 5},
    {"Rock Blackfish", 10},
    {"Sailfish", 1},
    {"Samsonfish", 5},
    {"Amberjack", 5},
    {"Australian Sawtail", 5},
    {"Shark (Wobbegong)", 0},
    {"Shark (Mako)", 5},
    {"Shark (School)", -1},
    {"Shark (Whaler)", -1},
    {"Snapper", 10},
    {"Spearfish (Shortbill)", 1},
    {"Swordfish", 1},
    {"Tailor", 10},
    {"Teraglin", 5},
    {"Trevallies (silver trevally only)", 10},
    {"Tuna (Albacore) (≥90cm)", 2},
    {"Tuna (Albacore) (<90cm)", 5},
    {"Tuna (Bigeye)", 1},
    {"Tuna (Longtail)", 1},
    {"Tuna (Yellowfin)", 1},
    {"Tuna (Southern Bluefin)", 1},
    {"Wahoo", 5},
    {"Whiting (Sand)", 20},
    {"Yellowtail Kingfish", 5},
    {"Abalone", 2},
    {"Balmain Bug", 20},
    {"Beach Worms", 20},
    {"All other worms", 100},
    {"Cockles", 50},
    {"Mussels", 50},
    {"Pipis", 50},
    {"Blue Swimmer Crab", 10},
    {"Mud Crab", 5},
    {"Spanner Crab", 10},
    {"Soldier Crab", 100},
    {"All other crabs", 10},
    {"Cunjevoi", 20},
    {"Eastern Rock Lobster", 3},
    {"Southern Rock Lobster (male)", 3},
    {"Southern Rock Lobster (female)", 3},
    {"Tropical Rock Lobster (Painted and Ornate)", 2},
    {"Slipper Lobster (Flat)", 2},
    {"Octopus", 10},
    {"Oysters (Sydney Rock, Pacific, Native)", 50},
    {"Prawns", 10},
    {"Saltwater Nippers", 100},
    {"Scallops", 50},
    {"Sea Urchin", 10},
    {"Squid", 20},
    {"Turban Snails (Sydney, Military)", 20},
    {"Turban Snails (All other molluscs)", 20}
};

bool BagChecker::check(Bag* bag) {
    std::vector<SeaCreature*> creatures = bag->getCreatures();
    std::map<std::string, int> speciesCount;

    for (SeaCreature* creature : creatures) {
        std::string name = creature->getName();
        speciesCount[name]++;
    }

    for (const auto& entry : speciesCount) {
        const std::string& name = entry.first;
        int count = entry.second;

        auto it = bagLimits.find(name);
        if (it != bagLimits.end()) {
            int allowed = it->second;
            if (allowed >= 0 && count > allowed) {
                std::cout << "Bag limit exceeded for: " << name
                          << ". Allowed: " << allowed << ", Found: " << count << std::endl;
                return false;
            }
        } else {
            std::cout << "Warning: No bag limit data for " << name << ". Skipping check for this species." << std::endl;
        }
    }

    return true;
}

std::string BagChecker::getCheckerType() const {
    return "Bag";
}