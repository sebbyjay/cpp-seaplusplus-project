#include "App.h"
#include "VertebrateCreature.h"
#include "InvertebrateCreature.h"
#include "VertebrateChecker.h"
#include "InvertebrateChecker.h"
#include "BagChecker.h"
#include <iostream>
#include <limits>

App::App() : engine(new SeaPlusPlusEngine()), currentAngler("DefaultAngler") {
    engine->regChecker(new VertebrateChecker());
    engine->regChecker(new InvertebrateChecker());
}

void App::run() {
    std::cout << "Welcome to the Sea++ System" << std::endl;

    char continueInput = 'y';
    while (continueInput == 'y' || continueInput == 'Y') {
        anglerInput();
        std::cout << "Add another creature? (y/n): ";
        std::cin >> continueInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\nAll catches recorded.\n";

    // Create a temporary bag to check
    Bag tempBag;
    for (SeaCreature* c : currentAngler.getCatches()) {
        tempBag.addCreature(c);
    }

    // Check the bag for limits
    BagChecker bagChecker;
    if (bagChecker.check(&tempBag)) {
        std::cout << "Bag passed the bag limit check.\n";
    } else {
        std::cout << "Bag failed the bag limit check! Some species exceeded the bag limit.\n";
    }
}


void App::anglerInput() {
    std::string type, name;
    float size;
    char hasEggsChar;
    bool hasEggs;

    std::cout << "Enter creature type (vertebrate/invertebrate): ";
    std::cin >> type;

    std::cout << "Enter creature name: ";
    std::cin >> name;

    std::cout << "Enter size: ";
    std::cin >> size;

    std::cout << "Is the creature carrying eggs? (y/n): ";
    std::cin >> hasEggsChar;
    hasEggs = (hasEggsChar == 'y' || hasEggsChar == 'Y');

    SeaCreature* creature = nullptr;

    if (type == "vertebrate") {
        creature = new VertebrateCreature(name, size, hasEggs);
        validateCatch(creature);
    } else if (type == "invertebrate") {
        creature = new InvertebrateCreature(name, size, hasEggs);
        validateCatch(creature);
    }

    if (creature != nullptr) {
        currentAngler.addCatch(creature);
    } else {
        std::cout << "Invalid creature type entered." << std::endl;
    }
}

void App::validateCatch(SeaCreature* creature) {
    std::string result = engine->validateCatch(creature);
    std::cout << result << std::endl;
}

int App::main() {
    App app;
    app.run();
    return 0;
}
