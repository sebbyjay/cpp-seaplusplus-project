#include "App.h"
#include "VertebrateCreature.h"
#include "InvertebrateCreature.h"
#include "VertebrateChecker.h"
#include "InvertebrateChecker.h"
#include <iostream>

App::App() : engine(new SeaPlusPlusEngine()), currentAngler("DefaultAngler") {
    engine->regChecker(new VertebrateChecker());
    engine->regChecker(new InvertebrateChecker()); // Start the checkers from the engine
}

void App::run() {
    std::cout << "Welcome to the Sea++ System" << std::endl;
    anglerInput();
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

    SeaCreature* creature = nullptr;  // Always initialize pointers for safety, otherwise bad stuff happens

    // Create the appropriate type of SeaCreature based on user input
    if (type == "vertebrate") {
        creature = new VertebrateCreature(name, size, hasEggs);
        validateCatch(creature);   
    } else if (type == "invertebrate") {
        creature = new InvertebrateCreature(name, size, hasEggs);
        validateCatch(creature);   
    }

    // nullptr check ensures that an invalid type won't be processed
    if (creature != nullptr) {              // Send creature to engine for validation via registered checkers
        currentAngler.addCatch(creature);    // Store the creature in the angler's catch list
    } else {
        std::cout << "Invalid creature type entered." << std::endl;
    }
}

void App::validateCatch(SeaCreature* creature) {
    std::string result = engine->validateCatch(creature);
    std::cout << result << std::endl;
}

// Static main function to run the application
int App::main() {
    // Create an instance of the App class
    App app;

    // Run the app
    app.run();

    return 0;
}
