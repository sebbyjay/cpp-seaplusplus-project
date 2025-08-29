#ifndef APP_H
#define APP_H

#include "SeaPlusPlusEngine.h"
#include "Angler.h"
#include <memory>

class App {
private:
    SeaPlusPlusEngine* engine;
    Angler currentAngler;

public:
    App();
    void run();
    void anglerInput();
    void validateCatch(SeaCreature* creature);

    // Make this class responsible for running the application
    static int main();  // Declare main as static so it can be called without an object
};

#endif // APP_H
